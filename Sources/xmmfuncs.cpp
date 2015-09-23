/**************************************************************************************************************

    NAME
        xmmfuncs.cpp

    DESCRIPTION
        Fast memory functions usings the SSE instructions.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/09]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include		"stdafx.h"
# include		"Vroom.h"
# include		"sys/asm.h"
# include		"memcpy.h"


// Shortcut macros
# define		XMMLOAD(reg,ofs)		asm MOVAPS  reg, [ESI + ofs ]
# define		XMMSTORE(reg,ofs)		asm MOVAPS  [EDI + ofs], reg
# define		XMMCOPY(reg,ofs)		XMMLOAD ( reg, ofs )		XMMSTORE ( reg, ofs )

# define		XMMLOAD1(ofs)			XMMLOAD ( XMM0, ofs + 0 )
# define		XMMLOAD2(ofs)			XMMLOAD1(ofs)			XMMLOAD ( XMM1, ofs + 0x10 )
# define		XMMLOAD3(ofs)			XMMLOAD2(ofs)			XMMLOAD ( XMM2, ofs + 0x20 )
# define		XMMLOAD4(ofs)			XMMLOAD3(ofs)			XMMLOAD ( XMM3, ofs + 0x30 )
# define		XMMLOAD5(ofs)			XMMLOAD4(ofs)			XMMLOAD ( XMM4, ofs + 0x40 )
# define		XMMLOAD6(ofs)			XMMLOAD5(ofs)			XMMLOAD ( XMM5, ofs + 0x50 )
# define		XMMLOAD7(ofs)			XMMLOAD6(ofs)			XMMLOAD ( XMM6, ofs + 0x60 )
# define		XMMLOAD8(ofs)			XMMLOAD7(ofs)			XMMLOAD ( XMM7, ofs + 0x70 )


# define		XMMSTORE1(ofs)			XMMSTORE ( XMM0, ofs + 0 )
# define		XMMSTORE2(ofs)			XMMSTORE1(ofs)			XMMSTORE ( XMM1, ofs + 0x10 )
# define		XMMSTORE3(ofs)			XMMSTORE2(ofs)			XMMSTORE ( XMM2, ofs + 0x20 )
# define		XMMSTORE4(ofs)			XMMSTORE3(ofs)			XMMSTORE ( XMM3, ofs + 0x30 )
# define		XMMSTORE5(ofs)			XMMSTORE4(ofs)			XMMSTORE ( XMM4, ofs + 0x40 )
# define		XMMSTORE6(ofs)			XMMSTORE5(ofs)			XMMSTORE ( XMM5, ofs + 0x50 )
# define		XMMSTORE7(ofs)			XMMSTORE6(ofs)			XMMSTORE ( XMM6, ofs + 0x60 )
# define		XMMSTORE8(ofs)			XMMSTORE7(ofs)			XMMSTORE ( XMM7, ofs + 0x70 )

# define		XMMCOPY1			XMMLOAD1(0)			XMMSTORE1(0)
# define		XMMCOPY2			XMMLOAD2(0)			XMMSTORE2(0)
# define		XMMCOPY3			XMMLOAD3(0)			XMMSTORE3(0)
# define		XMMCOPY4			XMMLOAD4(0)			XMMSTORE4(0)
# define		XMMCOPY5			XMMLOAD4(0)			XMMSTORE4(0)			\
							XMMLOAD1(0x40)			XMMSTORE1(0x40)
# define		XMMCOPY6			XMMLOAD4(0)			XMMSTORE4(0)			\
							XMMLOAD2(0x40)			XMMSTORE2(0x40)
# define		XMMCOPY7			XMMLOAD4(0)			XMMSTORE4(0)			\
							XMMLOAD3(0x40)			XMMSTORE3(0x40)
# define		XMMCOPY8			XMMLOAD4(0)			XMMSTORE4(0)			\
							XMMLOAD4(0x40)			XMMSTORE4(0x40)

# define		XMMNEXT				asm ADD ESI, 0x80		asm ADD EDI, 0x80

# define		XMMUNROLLED			XMMCOPY8			XMMNEXT

BEGIN_C_CALLING_CONVENTION


#pragma region vroom_xmmcpy()
/*==============================================================================================================
 *
 *   NAME
 *	vroom_xmmcpy - memcpy function using SSE instructions.
 *
 *   PROTOTYPE
 *	vroom_xmmcpy ( void *  dst, void *  src, size_t  count ) ;
 *
 *   DESCRIPTION
 *	Copies [count] XMM words from [src] to [dst].
 *
 *   PARAMETERS
 *	void *  dst -
 *		Copy destination. This pointer must be aligned on a 16-bytes boundary.
 *
 *	void *  src -
 *		Copy origin. This pointer must be aligned on a 16-bytes boundary.
 *
 *	size_t  count -
 *		Number of XMM words (16 bytes) to be copied.
 *
 *   RETURN VALUE
 *	The return value of this function is undefined. Its return type is provided just to have the same
 *	signature as the standard memcpy function.
 *
 *   NOTES
 *	. Both [dst] and [src] MUST be aligned on a 16-bytes boundary.
 *	. [count] is a number of 16-bytes XMM words, NOT a byte count.
 *
 *==============================================================================================================*/
exported naked void * fastcall		vroom_xmmcpy ( void *  dst, void *  src, size_t  count )
   {
	asm
	   {
		; Get parameters
		MOV		EDI, ECX			; EDI = [dst]
		MOV		ESI, EDX			; ESI = [src]
		MOV		ECX, [ESP + 4]			; ECX = [count]

		; For quantities less than or equal to 32, a jump table is used that points to the code that performs the copy
		; of 0 to 32 bytes. We just need to index this jump table by ECX (each jump in this table takes 5 bytes)
		CMP		ECX, 64
		JLE		UseJumpTable

		; Unrolled copy of quantities larger than 32 items
		MOV		EDX, ECX			; Save [count] into ECX
		AND		ECX, 0x3F			; Keep in ECX [count] % 64
		SHR		EDX, 6				; And divide EDX by 64 : this way, 

UnrolledCopy :
		XMMUNROLLED					; Copy 64 XMM words
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED

		DEC		EDX				; Count 64 words less
		JZ		UseJumpTable
		JMP		UnrolledCopy

		; Compute the offset within the jump table corresponding to the quantity stored in ECX
UseJumpTable :
		LEA		EBX, JumpTable
		MOV		EDX, ECX			; EDX = [count]
		SHL		EDX, 2				; We need to multiply [count] by 5 since every element in JumpTable is 5 bytes long
		ADD		EDX, ECX
		ADD		EBX, EDX			; Then add the computed offset to the start of the jump table
		
		JMP		EBX				; The big jump !


		#pragma region Jump table
		; Jump table to the real copy code. Jump #0 is for a quantity of zero, jump #1 for a quantity of 1, and so on
JumpTable :
		JMP		Copy_00
		JMP		Copy_01
		JMP		Copy_02
		JMP		Copy_03
		JMP		Copy_04
		JMP		Copy_05
		JMP		Copy_06
		JMP		Copy_07
		JMP		Copy_08
		JMP		Copy_09
		JMP		Copy_10
		JMP		Copy_11
		JMP		Copy_12
		JMP		Copy_13
		JMP		Copy_14
		JMP		Copy_15
		JMP		Copy_16
		JMP		Copy_17
		JMP		Copy_18
		JMP		Copy_19
		JMP		Copy_20
		JMP		Copy_21
		JMP		Copy_22
		JMP		Copy_23
		JMP		Copy_24
		JMP		Copy_25
		JMP		Copy_26
		JMP		Copy_27
		JMP		Copy_28
		JMP		Copy_29
		JMP		Copy_30
		JMP		Copy_31
		JMP		Copy_32
		JMP		Copy_33
		JMP		Copy_34
		JMP		Copy_35
		JMP		Copy_36
		JMP		Copy_37
		JMP		Copy_38
		JMP		Copy_39
		JMP		Copy_40
		JMP		Copy_41
		JMP		Copy_42
		JMP		Copy_43
		JMP		Copy_44
		JMP		Copy_45
		JMP		Copy_46
		JMP		Copy_47
		JMP		Copy_48
		JMP		Copy_49
		JMP		Copy_50
		JMP		Copy_51
		JMP		Copy_52
		JMP		Copy_53
		JMP		Copy_54
		JMP		Copy_55
		JMP		Copy_56
		JMP		Copy_57
		JMP		Copy_58
		JMP		Copy_59
		JMP		Copy_60
		JMP		Copy_61
		JMP		Copy_62
		JMP		Copy_63
		JMP		Copy_64
		NOP128				; Force jumps to be NEAR jumps
		#pragma endregion


		#pragma region Code for copying
		; Copy code
Copy_00 :
		RET	4

Copy_01 :
		XMMCOPY1
		RET	4

Copy_02 :
		XMMCOPY2
		RET	4

Copy_03 :
		XMMCOPY3
		RET	4

Copy_04 :
		XMMCOPY4
		RET	4

Copy_05 :
		XMMCOPY5
		RET	4

Copy_06 :
		XMMCOPY6
		RET	4

Copy_07 :
		XMMCOPY7
		RET	4

Copy_08 :
		XMMCOPY8
		RET	4

Copy_09 :
		XMMUNROLLED
		XMMCOPY1
		RET	4

Copy_10 :
		XMMUNROLLED
		XMMCOPY2
		RET	4

Copy_11 :
		XMMUNROLLED
		XMMCOPY3
		RET	4

Copy_12 :
		XMMUNROLLED
		XMMCOPY4
		RET	4

Copy_13 :
		XMMUNROLLED
		XMMCOPY5
		RET	4

Copy_14 :
		XMMUNROLLED
		XMMCOPY6
		RET	4

Copy_15 :
		XMMUNROLLED
		XMMCOPY7
		RET	4

Copy_16 :
		XMMUNROLLED
		XMMCOPY8
		RET	4

Copy_17 :
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY1
		RET	4

Copy_18 :
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY2
		RET	4

Copy_19 :
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY3
		RET	4

Copy_20 :
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY4
		RET	4

Copy_21 :
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY5
		RET	4

Copy_22 :
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY6
		RET	4

Copy_23 :
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY7
		RET	4

Copy_24 :
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY8
		RET	4

Copy_25 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY1
		RET	4

Copy_26 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY2
		RET	4

Copy_27 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY3
		RET	4

Copy_28 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY4
		RET	4

Copy_29 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY5
		RET	4

Copy_30 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY6
		RET	4

Copy_31 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY7
		RET	4

Copy_32 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY8
		RET	4

Copy_33 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY1
		RET	4

Copy_34 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY2
		RET	4

Copy_35 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY3
		RET	4

Copy_36 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY4
		RET	4

Copy_37 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY5
		RET	4

Copy_38 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY6
		RET	4

Copy_39 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY7
		RET	4

Copy_40 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY8
		RET	4

Copy_41 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY1
		RET	4

Copy_42 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY2
		RET	4

Copy_43 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY3
		RET	4

Copy_44 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY4
		RET	4

Copy_45 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY5
		RET	4

Copy_46 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY6
		RET	4

Copy_47 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY7
		RET	4

Copy_48 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY8
		RET	4

Copy_49 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY1
		RET	4

Copy_50 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY2
		RET	4

Copy_51 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY3
		RET	4

Copy_52 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY4
		RET	4

Copy_53 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY5
		RET	4

Copy_54 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY6
		RET	4

Copy_55 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY7
		RET	4

Copy_56 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY8
		RET	4

Copy_57 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY1
		RET	4

Copy_58 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY2
		RET	4

Copy_59 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY3
		RET	4

Copy_60 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY4
		RET	4

Copy_61 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY5
		RET	4

Copy_62 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY6
		RET	4

Copy_63 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY7
		RET	4

Copy_64 :
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMUNROLLED
		XMMCOPY8
		RET	4

		#pragma endregion
	    }
    }
#pragma endregion

END_C_CALLING_CONVENTION