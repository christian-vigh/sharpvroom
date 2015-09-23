/**************************************************************************************************************

    NAME
        Math.cpp

    DESCRIPTION
        Miscellaneous math functions.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/21]     [Author : CV]
        Initial version.

 **************************************************************************************************************/


# include		"stdafx.h"
# include		"Vroom.h"
# include		"sys/asm.h"
# include		"fastmath.h"


BEGIN_C_CALLING_CONVENTION


#pragma region vroom_math_ipow2ge() 
/*==============================================================================================================
 *
 *   NAME
 *	vroom_math_ipow2ge - Computes the power of two immediately following the specified value.
 *
 *   PROTOTYPE
 *	unsigned int	vroom_math_ipow2ge ( unsigned int  value ) ;
 *
 *   DESCRIPTION
 *	Computes the power of two immediately following the specified value. If the value is already a power of
 *	two, it will be returned as is.
 *
 *   PARAMETERS
 *	unsigned int  value -
 *		Value whose closest next power of two is to be computed.
 *
 *   RETURN VALUE
 *	Returns the next power of two of the specified value, or :
 *	- 0 if an overflow occurred (ie, value >= 0x80000000)
 *	- 1 if value is zero.
 *
 *==============================================================================================================*/
exported naked unsigned int fastcall	vroom_math_ipow2ge ( unsigned int   value )
   {
	asm
	   {
		; Check if the specified value is zero
		AND	ECX, ECX
		JNZ	NoUnderflow		; If not, continue

		XOR	EAX, EAX		; Value is zero. The next power of two is 1
		INC	AL
		RET

NoUnderflow :
		; Value is non-zero
		MOV	EBX, ECX		; CL will be used in a shift instruction so move [value] to EBX
		BSR	ECX, EBX		; Find the leftmost bit set to one

		CMP	CL, 0x1F		; If highest bit is not set...
		JNE	NoOverflow		; ... then compute next power of two

		XOR	EAX, EAX		; Otherwise, simply return zero
		RET	

NoOverflow :
		; Value is neither zero nor has its highest significant bit set : compute the next power of two of [value]
		XOR	EAX, EAX		; EAX = 1
		INC	AL
		SHL	EAX, CL

		CMP	EAX, EBX		; Test if the value is not a power of two
		JE	Return

		SHL	EAX, 1			; If not, then compute the next power of two

Return :
		RET 
	    }
    }
#pragma endregion


#pragma region vroom_math_ipow2gt()
/*==============================================================================================================
 *
 *   NAME
 *	vroom_math_ipow2gt - Computes the power of two immediately following the specified value.
 *
 *   PROTOTYPE
 *	unsigned int	vroom_math_ipow2gt ( unsigned int  value ) ;
 *
 *   DESCRIPTION
 *	Computes the power of two immediately following the specified value.
 *
 *   PARAMETERS
 *	unsigned int  value -
 *		Value whose next power of two is to be computed.
 *
 *   RETURN VALUE
 *	Returns the next power of two of the specified value, or :
 *	- 0 if an overflow occurred (ie, value >= 0x80000000)
 *	- 1 if value is zero.
 *
 *==============================================================================================================*/
exported naked unsigned int fastcall	vroom_math_ipow2gt ( unsigned int   value )
   {
	asm
	   {
		; Check if the specified value is zero
		AND	ECX, ECX
		JNZ	NoUnderflow		; If not, continue

		XOR	EAX, EAX		; Value is zero. The next power of two is 1
		INC	AL
		RET

NoUnderflow :
		; Value is non-zero
		MOV	EBX, ECX		; CL will be used in a shift instruction so move [value] to EBX
		BSR	ECX, EBX		; Find the leftmost bit set to one

		CMP	CL, 0x1F		; If highest bit is not set...
		JNE	NoOverflow		; ... then compute next power of two

		XOR	EAX, EAX		; Otherwise, simply return zero
		RET	

NoOverflow :
		; Value is neither zero nor has its highest significant bit set : compute the next power of two of [value]
		XOR	EAX, EAX		; EAX = 1
		INC	AL
		INC	CL			; Next power of two (result of the BSR instruction)
		SHL	EAX, CL			; Shift the return value (1) by the adequate number of places to produce the next power of 2
		RET 
	    }
    }
#pragma endregion


#pragma region vroom_math_ipow2ceiling()
/*==============================================================================================================
 *
 *   NAME
 *	vroom_math_ipow2ceiling - Rounds a value up to the specified power of two.
 *
 *   PROTOTYPE
 *	unsigned int vroom_math_ipow2ceiling ( unsigned int  value, unsigned int  power ) ;
 *
 *   DESCRIPTION
 *	Rounds a value up to the specified power of two. If ( value % power ) is zero, then no rounding occurs.
 *
 *   PARAMETERS
 *	unsigned int  value -
 *		Value to be rounded.
 *
 *	unsigned int  power -
 *		Rounding value. Must be a power of two, otherwise the results are unpredicatble.
 *
 *   RETURN VALUE
 *	The "value" parameter, rounded by "power" units.
 *
 *==============================================================================================================*/
exported naked unsigned int fastcall  vroom_math_ipow2ceiling ( unsigned int  value, unsigned int  power )
   {
	asm
	   {
		MOV		EAX, ECX		; EAX = [value]
		MOV		EBX, EDX		; EBX = [power]
		DEC		EBX			; [power] = [power] - 1
		AND		ECX, EBX		; [value] = [value] & ( [power] - 1 )

		NOT		EBX			; [power] =  ~[power]
		AND		EAX, EBX		; [value] = ( [value] & ~[power] )
		
		AND		ECX, ECX		; Is [value] & ( [power] - 1 ) zero ?
		JZ		Return			; Yes : the value is already rounded

		ADD		EAX, EDX		; No, add the rounding value to [value] & ( [power] - 1 )

Return :
		RET
	    }
    }
#pragma endregion


END_C_CALLING_CONVENTION