/**************************************************************************************************************

    NAME
        set.cpp

    DESCRIPTION
        binteger initialization functions from existing values.

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


#pragma region binteger_set()
/*==============================================================================================================
 *
 *   NAME
 *	binteger_set - Assigns a binteger to an existing one.
 *
 *   PROTOTYPE
 *	void  binteger_set ( binteger *  dst, const binteger *  src ) ;
 *
 *   DESCRIPTION
 *	Assigns the value of an existing binteger to another one.
 *
 *   PARAMETERS
 *	binteger *  dst -
 *		Destination binteger.
 *
 *	binteger *  src -
 *		Source binteger.
 *
 *==============================================================================================================*/
exported void fastcall	binteger_set ( binteger *  dst, const binteger *  src )
   {
	bn_usize_t		size ;
	bn_ssize_t		src_size ;
	bn_usize_t		size_in_bytes ;


	src_size	=  src -> size ;
	size		=  BN_ABS ( src_size ) ;
	size_in_bytes	=  size * BN_BYTES_PER_CELL ;

	// If destination size is less than source size, perform a reallocation
	if  ( dst -> allocated  <  size )
	   {
		dst -> allocated		=  size ;
		dst -> cells		=  ( bn_ucell_t * ) bni_memrealloc ( dst -> cells, 
						dst -> allocated * BN_BYTES_PER_CELL, size_in_bytes ) ;
	    }

	// Original mpz_set() version used the GMP MPN_COPY() macro, but VS memcpy should operate even faster
	memcpy ( dst -> cells, src -> cells, size_in_bytes ) ;

	dst -> size		=  src_size ;
    }
#pragma endregion


#pragma region binteger_set_xxx() functions from integral type
/*==============================================================================================================
 *
 *   NAME
 *	binteger_set_xxx - Assigns an integral value to an existing binteger.
 *
 *   PROTOTYPE
 *	void  binteger_set_uint  ( binteger *  dst, unsigned int   src ) ;
 *	void  binteger_set_int   ( binteger *  dst, signed   int   src ) ;
 *	void  binteger_set_ulong ( binteger *  dst, unsigned long  src ) ;
 *	void  binteger_set_long  ( binteger *  dst, signed   long  src ) ;
 *
 *   DESCRIPTION
 *	Assigns an integral value to an existing binteger.
 *
 *   PARAMETERS
 *	binteger *  dst -
 *		Destination binteger.
 *
 *	(integral type)  src -
 *		Source integral value.
 *
 *==============================================================================================================*/
exported void fastcall	binteger_set_uint ( binteger *  dst, unsigned int  src )
   {
	dst -> cells [0]		=  ( bn_ucell_t ) src ;
	dst -> size		=  1 ;
    }


exported void fastcall	binteger_set_int ( binteger *  dst, signed int  src )
   {
	dst -> cells [0]		=  ( bn_ucell_t ) src ;
	dst -> size		=  ( src  >=  0 ) ?  1 : -1 ;
    }


exported void fastcall	binteger_set_ulong ( binteger *  dst, unsigned long int  src )
   {
	bn_ssize_t		size ;

	if  ( BN_ULONG_BITS  ==  BN_UINT_BITS )
	   {
		dst -> cells [0]		=  ( bn_ucell_t ) ( src  & BN_UINT_MASK ) ;
		size			=  1 ;
	    }
	else
	   {
		if  ( dst -> allocated  <  2 )
		   {
			dst -> cells		=  ( bn_ucell_t * ) bni_memrealloc ( dst -> cells, 
							dst -> allocated * BN_BYTES_PER_CELL, 2 * BN_BYTES_PER_CELL ) ;
			dst -> allocated		=  2 ;
		    }

		#pragma warning ( disable : 4293 )
		dst -> cells [0]		=  ( bn_ucell_t ) ( src  &  BN_UINT_MASK ) ;
		dst -> cells [1]		=  ( bn_ucell_t ) ( src  >>  BN_UINT_BITS ) ;
		#pragma warning ( default : 4293 )

		size			=  2 ;
	    }

	dst -> size	=  size ;
    }

exported void fastcall	binteger_set_long ( binteger *  dst, signed long int  src )
   {
	bn_ssize_t		size ;


	if  ( BN_ULONG_BITS  ==  BN_UINT_BITS )
	   {
		dst -> cells [0]		=  ( bn_ucell_t ) ( src  & BN_UINT_MASK ) ;
		size			=  1 ;
	    }
	else
	   {
		if  ( dst -> allocated  <  2 )
		   {
			dst -> cells		=  ( bn_ucell_t * ) bni_memrealloc ( dst -> cells, 
							BN_BYTES_PER_CELL, 2 * BN_BYTES_PER_CELL ) ;
			dst -> allocated		=  2 ;
		    }

		#pragma warning ( disable : 4293 )
		dst -> cells [0]		=  ( bn_ucell_t ) ( src  &  BN_UINT_MASK ) ;
		dst -> cells [1]		=  ( bn_ucell_t ) ( src  >>  BN_UINT_BITS ) ;
		#pragma warning ( default : 4293 ) 

		size			=  2 ;
	    }

	dst -> size	=  ( src  >=  0 ) ?  size : - size ;
    }
#pragma endregion


END_C_CALLING_CONVENTION