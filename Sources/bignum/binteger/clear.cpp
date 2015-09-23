/**************************************************************************************************************

    NAME
        clear.cpp

    DESCRIPTION
        Functions for clearing a binteger or array of bintegers.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/27]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include	"stdafx.h"
# include	"Vroom.h"
# include	"math/bignum.h"


BEGIN_C_CALLING_CONVENTION

/*==============================================================================================================
 *
 *   NAME
 *	binteger_clear - Clears a binteger.
 *
 *   PROTOTYPE
 *	void	binteger_clear ( binteger *  bi ) ;
 *
 *   DESCRIPTION
 *	Clears a binteger and frees any allocated memory.
 *
 *   PARAMETERS
 *	binteger *  bi -
 *		binteger or array of bintegers allocated through the binteger_ainit_xxx functions.
 *
 *==============================================================================================================*/
exported void fastcall	binteger_clear ( binteger *  bi )
   {
	if  ( bi -> allocated )
	   {
		bni_memfree ( bi -> cells, bi -> allocated * BN_BYTES_PER_CELL ) ;
		bi -> allocated		=  0 ;
		bi -> size		=  0 ;
	    }
    }


/*==============================================================================================================
 *
 *   NAME
 *	binteger_vclear - Clears a list of bintegers.
 *
 *   PROTOTYPE
 *	void	binteger_vclear ( binteger *  bi, ... ) ;
 *
 *   DESCRIPTION
 *	Clears a list of bintegers and frees any allocated memory.
 *
 *   PARAMETERS
 *	binteger *  bi (...) -
 *		List of binteger or array of bintegers allocated through the binteger_ainit_xxx functions.
 *
 *==============================================================================================================*/
exported void fastcall binteger_vclear ( binteger *  bi, ... )
   {
	va_list			ap ;
	binteger *		p ;

	va_start ( ap, bi ) ;

	while  ( ( p = va_arg ( ap, binteger * ) )  !=  NULL )
	   {
		if  ( p -> allocated )
		   {
			bni_memfree ( p -> cells, p -> allocated * BN_BYTES_PER_CELL ) ;
			p -> allocated		=  0 ;
			p -> size		=  0 ;
		    }
	    }

	va_end ( ap ) ;
    }

END_C_CALLING_CONVENTION
