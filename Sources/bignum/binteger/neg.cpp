/**************************************************************************************************************

    NAME
        neg.cpp

    DESCRIPTION
        Negates a binteger.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/28]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include	"stdafx.h"
# include	"Vroom.h"
# include	"math/bignum.h"


BEGIN_C_CALLING_CONVENTION

/*==============================================================================================================
 *
 *   NAME
 *	binteger_neg - Negates a binteger.
 *
 *   PROTOTYPE
 *	void  binteger_neg ( binteger *  dst, const binteger *  src ) ;
 *
 *   DESCRIPTION
 *	Sets [dst] to be the negated value of [src].
 *
 *   PARAMETERS
 *	binteger *  dst -
 *		Destination value.
 *
 *	binteger *  src -
 *		Source value, whose negated value is to be computed.
 *
 *==============================================================================================================*/
exported void fastcall		binteger_neg ( binteger *  dst, const binteger *  src )
   {
	bn_ssize_t		nsize ;
	bn_usize_t		size ;
	bn_usize_t		size_in_bytes ;


	nsize		=  - src -> size ;
	size		=  BN_ABS ( nsize ) ;
	size_in_bytes	=  size * BN_BYTES_PER_CELL ;

	if  ( dst  !=  src )
	   {
		if  ( dst -> allocated  <  size )
		   {
			dst -> cells		=  ( bn_ucell_t * ) bni_memrealloc ( dst -> cells, 
							dst -> allocated * BN_BYTES_PER_CELL, size_in_bytes ) ;
			dst -> allocated		=  size ;
		    }
	    }

	memcpy ( dst -> cells, src -> cells, size_in_bytes ) ;
	dst -> size	=  nsize ;
    }

END_C_CALLING_CONVENTION
