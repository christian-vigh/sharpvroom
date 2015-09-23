/**************************************************************************************************************

    NAME
        Memory.cpp

    DESCRIPTION
        Fast memory functions.

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


BEGIN_C_CALLING_CONVENTION
#pragma warning ( disable : 4102 )


#pragma region  vroom_stdmemcpy()
/*==============================================================================================================
 *
 *   NAME
 *	stdmemcpy - Allows for calling the memcpy intrinsic function.
 *
 *   DESCRITION
 *	Allows for calling the intrinsic memcpy function. This is not as fast as calling memcpy from a CPP
 *	application, since there seems to be some overhead when calling a DLL procedure.
 *
 *==============================================================================================================*/
exported naked void *	 fastcall vroom_stdmemcpy ( void *  dst, const void *  src, size_t  size )
   {
	asm
	   {
		// Since we are in a naked fastcall function, EDX contains the source and ECX the destination
		// We just have to load [size] from the stack
		MOV		EAX, DWORD PTR [ESP+4]

		// Push arguments
		PUSH		EAX
		PUSH		EDX
		PUSH		ECX

		// Call the function and clean up the stack
		CALL		memcpy
		ADD		ESP, 0x0C

		// All done, return (popping off the stack the [size] parameter that was pushed by the caller)
		RET		4		; EAX holds the return value from memcpy()
	    }
    }
#pragma endregion


#pragma region  vroom_memcpy()
/*==============================================================================================================
 *
 *   NAME
 *	vroom_memcpy - A try-to-beat-native-memcpy experience.
 *
 *   DESCRIPTION
 *
 *==============================================================================================================*/

# define	SMALL_QUANTITY_MAX		127

# define	COPY(reg,offset)		asm MOV reg, [ESI + offset]		asm MOV [EDI + offset], reg
#define		XMMCOPY(reg,offset)		asm MOVDQA  reg, [ESI + offset]		asm MOVDQU  [EDI + offset], reg
# define	JUMPRETURN			asm RET 4


exported naked void *	 fastcall vroom_memcpy ( void *  dst, const void *  src, size_t  size )
   {
	asm
	   {
		; Since we are in a naked fastcall function, EDX contains the source and ECX the destination
		; We just have to load [size] from the stack
		MOV		EAX, DWORD PTR [ESP+4]
		MOV		ESI, EDX		; EDX <- [src]
		MOV		EDI, ECX		; ECX <- [dst]

		// For values > 16, we need to take into account the alignment
		CMP		EAX, SMALL_QUANTITY_MAX
		JG		DetermineAlignment


		/*==============================================================================================================
		
			Copy for small quantities <= 16, whatever the alignment : the result is always faster than memcpy.

		  ==============================================================================================================*/

SmallQuantities :
		; We use a near jump table, where each jump is 5 bytes long, and each entry has 8 jumps.
		; The address of the appropriate jump entry should be :
		;	addressof(JumpTable) + ( 16 * 5 * ( [size] )
		MOV		EBX, EAX		; Put [size] into EBX
		SHL		EBX, 6			; Multiply by 64. EBX is now [size] * 64

		MOV		ECX, EAX		; Compute [size] * 16
		SHL		ECX, 4
		
		ADD		EBX, ECX		; EBX = [size] * ( 64 + 16 )

		LEA		EDX, SVJumpTable	; Then compute effective address of the jump corresponding to this size
		ADD		EDX, EBX

		MOV		ECX, ESI		; Add the index correction to call the appropriate routine for ESI alignment
		AND		ECX, 0x0000000F		; We have specialized copy routines for alignments from 0 to 15
		MOV		EBX, ECX
		SHL		ECX, 2
		ADD		ECX, EBX		; Multiply the byte offset by 5 ; this will give us the index of the appropriate entry
							; for the specified size
		ADD		EDX, ECX		; Adjust the pointer

		JMP		EDX			; and jump !


		/*==============================================================================================================
		
			Determine alignment. The action taken will depend on how [src] and [dst] are aligned :

			[src]		[dst]		Action
			16		16		Use fast movdqa instructions
			x		x		( x != 16 ) Copy bytes until x reaches a 16-bytes boundary, then use
							movdqa instructions for both reading and writing.
			x		y		Worst case : Copy bytes until y reaches a 16-bytes boundary, then use
							movdqu for reading and movdqa for writing.

		  ==============================================================================================================*/
DetermineAlignment :
		


		#pragma region Jump table for small quantities
		# include	"memory/memcpy/svjump.h"
		#pragma endregion


UnalignedJumpTable :


AlignedJumpTable :

	   }
    }
#pragma endregion


#pragma warning ( default : 4102 )
END_C_CALLING_CONVENTION