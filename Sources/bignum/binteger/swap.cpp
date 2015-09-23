/**************************************************************************************************************

    NAME
        swap.cpp

    DESCRIPTION
        description.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/28]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include	"stdafx.h"
# include	"Vroom.h"
# include	"math/bignum.h"
# include	"sys/asm.h"


BEGIN_C_CALLING_CONVENTION

/*==============================================================================================================
 *
 *   NAME
 *	binteger_swap - Swaps two bintegers.
 *
 *   PROTOTYPE
 *	void  binteger_swap ( binteger *  bi1, binteger *  b2 ) ;
 *
 *   DESCRIPTION
 *	Swaps two bintegers.
 *
 *   PARAMETERS
 *	binteger *  bi1 -
 *		First binteger to be swapped.
 *
 *	binteger *  bi2 -
 *		Second binteger to be swapped.
 *
 *==============================================================================================================*/
# if ( TARGET  ==  PORTABLE )  ||  INTEL64
exported void fastcall  binteger_swap ( binteger *  bi1, binteger *  bi2 )
   {
	bn_ucell_t *		bi1_cells ;
	bn_ucell_t *		bi2_cells ;
	bn_ssize_t		bi1_size, bi2_size ;
	bn_usize_t		bi1_allocated, bi2_allocated ;

	
	bi1_cells		=  bi1 -> cells ;
	bi2_cells		=  bi2 -> cells ;
	bi1 -> cells		=  bi2_cells ;
	bi2 -> cells		=  bi1_cells ;

	bi1_size		=  bi1 -> size ;
	bi2_size		=  bi2 -> size ;
	bi1 -> size		=  bi2_size ;
	bi2 -> size		=  bi1_size ; 

	bi1_allocated		=  bi1 -> allocated ;
	bi2_allocated		=  bi2 -> allocated ;
	bi1 -> allocated		=  bi2_allocated ;
	bi2 -> allocated		=  bi1_allocated ; 
    }
# elif  ( INTEL32 )
exported naked void fastcall  binteger_swap ( binteger *  bi1, binteger *  bi2 )
   {
	asm
	   {
		MOV		EDI, ECX		; EDI = [bi1]
		MOV		ESI, EDX		; ESI = [bi2]

		; Instructions are ordered so that we can use the pipelining facilities of the processor :
		; Instruction (n) does no use any register used by instruction (n-1)
		MOV		EAX, [EDI]		; EAX = bi1 -> allocated
		MOV		EBX, [ESI]		; EBX = bi2 -> allocated
		MOV		ECX, [EDI + 4]		; ECX = bi1 -> size
		MOV		EDX, [ESI + 4]		; EDX = bi2 -> size
		MOV		[EDI], EBX		; bi1 -> allocated = bi2 -> allocated (EBX)
		MOV		[ESI], EAX		; bi2 -> allocated = bi1 -> allocated (EAX)
		MOV		EAX, [EDI + 8]		; EAX = bi1 -> cells
		MOV		EBX, [ESI + 8]		; EBX = bi2 -> cells
		MOV		[EDI + 4], EDX		; bi1 -> size = bi2 -> size (EDX)
		MOV		[ESI + 4], ECX		; bi2 -> size = bi1 -> size (ECX)
		MOV		[EDI + 8], EBX		; bi1 -> cells = bi2 -> cells (EBX)
		MOV		[ESI + 8], EAX		; bi2 -> cells = bi1 -> cells (EAX)

		RET
	    }
    }
# endif

END_C_CALLING_CONVENTION
