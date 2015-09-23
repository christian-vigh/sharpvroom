/**************************************************************************************************************

    NAME
        init.cpp

    DESCRIPTION
        Initializes a binteger.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/27]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include		"stdafx.h"
# include		"Vroom.h"
# include		"math/bignum.h"



BEGIN_C_CALLING_CONVENTION


#pragma region  biginteger_init()
/*==============================================================================================================
 *
 *   NAME
 *	binteger_init - Initializes a binteger value.
 *
 *   PROTOTYPE
 *	void  binteger_init		( binteger *  dst ) ;
 *
 *   DESCRIPTION
 *	Initializes a binteger value. A default of BN_CELLS_PER_ALLOCATION cells is allocated.
 *
 *   PARAMETERS
 *	binteger *  dst -
 *		binteger value to be initialized. 
 *
 *==============================================================================================================*/
exported void fastcall	binteger_init ( binteger *  dst )
   {
	dst -> allocated		=  BN_CELLS_PER_ALLOCATION ;
	dst -> size		=  0 ;
	dst -> cells		=  ( bn_ucell_t * ) bni_memalloc ( BN_BYTES_PER_ALLOCATION ) ;
    }
#pragma endregion


#pragma region binteger_init_cells()
/*==============================================================================================================
 *
 *   NAME
 *	binteger_init_cells - Initializes a binteger value.
 *
 *   PROTOTYPE
 *	void  binteger_init_cells	( binteger *  dst, bn_usize_t  cellcount ) ;
 *
 *   DESCRIPTION
 *	Initializes a binteger value, making sure it can hold at least [cellcount] cells.
 *
 *   PARAMETERS
 *	binteger *  dst -
 *		binteger value to be initialized.
 *
 *	bn_usize_t  cellcount -
 *		Initial number of allocated cells. If zero, A default of 1 cell is allocated.
 *
 *==============================================================================================================*/
exported void fastcall  binteger_init_cells ( binteger *  dst, bn_usize_t  cellcount )
   {
	// Add 1 if cellcount is zero
	cellcount  +=  ( cellcount  ==  0 ) ;

	// Initialize
	dst -> allocated		=  cellcount ;
	dst -> size		=  0 ;
	dst -> cells		=  ( bn_ucell_t * ) bni_memalloc ( cellcount * BN_BYTES_PER_CELL ) ;
    }
#pragma endregion


#pragma region binteger_init_bytes()
/*==============================================================================================================
 *
 *   NAME
 *	binteger_init_bytes - Initializes a binteger value.
 *
 *   PROTOTYPE
 *	void  binteger_init_bytes	( binteger *  dst, bn_usize_t  bytecount ) ;
 *
 *   DESCRIPTION
 *	Initializes a binteger value, making sure it can hold at least [bytecount] bytes.
 *
 *   PARAMETERS
 *	binteger *  dst -
 *		binteger value to be initialized.
 *
 *	bn_usize_t  bytecount -
 *		Initial number of allocated bytes. This value will be rounded up to be a multiple of
 *		BN_BYTES_PER_CELL. If zero, it will default to 1 cell.
 *
 *==============================================================================================================*/
exported void fastcall  binteger_init_bytes ( binteger *  dst, bn_usize_t  bytecount )
   {
	bn_usize_t	cellcount ;


	// Add 1 if bytecount is zero
	bytecount      +=  ( bytecount  ==  0 ) ;

	// Convert to cell count
	cellcount	=  ( bytecount + BN_BYTES_PER_CELL - 1 ) / BN_BYTES_PER_CELL ;

	// Initialize
	dst -> allocated		=  cellcount ;
	dst -> size		=  0 ;
	dst -> cells		=  ( bn_ucell_t * ) bni_memalloc ( cellcount * BN_BYTES_PER_CELL ) ;
    }
#pragma endregion


#pragma region biginteger_init_bits()
/*==============================================================================================================
 *
 *   NAME
 *	binteger_init_bits - Initializes a binteger value.
 *
 *   PROTOTYPE
 *	void  binteger_init_bits	( binteger *  dst, bn_bitcnt_t  bitcount ) ;
 *
 *   DESCRIPTION
 *	Initializes a binteger value, making sure it can hold at least [bitcount] bits.
 *
 *   PARAMETERS
 *	binteger *  dst -
 *		binteger value to be initialized.
 *
 *	bn_bitcnt_t  bitcount -
 *		Initial number of allocated bits. This value will be rounded up to be a multiple of
 *		( BN_BYTES_PER_CELL * BITSPERBYTE ). If zero, it will default to 1 cell.
 *
 *==============================================================================================================*/
exported void fastcall  binteger_init_bits ( binteger *  dst, bn_bitcnt_t  bitcount )
   {
	bn_usize_t	bytecount ;
	bn_usize_t	cellcount ;


	// Add 1 if bytecount is zero
	bitcount  +=  ( bitcount  ==  0 ) ;

	// Convert to cell count
	bytecount	=  ( bn_usize_t ) ( ( bitcount + BITSPERBYTE - 1 ) / BITSPERBYTE ) ;
	cellcount	=  ( bytecount + BN_BYTES_PER_CELL - 1 ) / BN_BYTES_PER_CELL ;

	// Initialize
	dst -> allocated		=  cellcount ;
	dst -> size		=  0 ;
	dst -> cells		=  ( bn_ucell_t * ) bni_memalloc ( cellcount * BN_BYTES_PER_CELL ) ;
    }
#pragma endregion


#pragma region binteger_vinit()
/*==============================================================================================================
 *
 *   NAME
 *	binteger_vinit - Initializes a list of binteger values.
 *
 *   PROTOTYPE
 *	void  binteger_vinit		( binteger *  dst, ... ) ;
 *
 *   DESCRIPTION
 *	Initializes a list of binteger values. A default of BN_CELLS_PER_ALLOCATION cells is allocated.
 *
 *   PARAMETERS
 *	binteger *  dst (...) -
 *		binteger values to be initialized. 
 *
 *==============================================================================================================*/
exported void   binteger_vinit ( binteger *  dst, ... )
   {
	va_list		ap ;
	binteger *	bi ;

	va_start ( ap, dst ) ;

	while  ( ( bi = va_arg ( ap, binteger * ) )  !=  NULL )
		binteger_init ( bi ) ;

	va_end ( ap ) ;
    }
#pragma endregion


#pragma region binteger_ainit()
/*==============================================================================================================
 *
 *   NAME
 *	binteger_ainit - Initializes an array of binteger values.
 *
 *   PROTOTYPE
 *	void  binteger_ainit		( binteger *  array, size_t  array_size ) ;
 *
 *   DESCRIPTION
 *	Initializes an array of binteger values. A default of BN_CELLS_PER_ALLOCATION cells is allocated for 
 *	each array element.
 *
 *   PARAMETERS
 *	binteger *  array -
 *		Array of binteger values to be initialized. 
 *
 *	size_t  array_size -
 *		Number of bintegers in the array.
 *
 *==============================================================================================================*/
exported void fastcall	binteger_ainit ( binteger *  array, size_t  array_size )
   {
	bn_ucell_t *		bip ;


	bip	=  ( bn_ucell_t * ) bni_memalloc ( array_size * BN_BYTES_PER_ALLOCATION ) ;

	while  ( array_size -- )
	   {
		array -> allocated	=  BN_CELLS_PER_ALLOCATION ;
		array -> size		=  0 ;
		array -> cells		=  bip ;
		
		array ++ ;
		bip += BN_BYTES_PER_ALLOCATION ;
	    }
    }
#pragma endregion


#pragma region binteger_ainit_cells()
/*==============================================================================================================
 *
 *   NAME
 *	binteger_ainit_cells - Initializes an array of binteger values.
 *
 *   PROTOTYPE
 *	void  binteger_ainit_cells	( binteger *  array, size_t  array_size, bn_usize_t  cellcount ) ;
 *
 *   DESCRIPTION
 *	Initializes an array of binteger values. Each array element will hold at least [cellcount] cells.
 *
 *   PARAMETERS
 *	binteger *  array -
 *		Array of binteger values to be initialized. 
 *
 *	size_t  array_size -
 *		Number of bintegers in the array.
 *
 *	bn_usize_t  cellcount -
 *		Initial number of allocated cells. If zero, A default of 1 cell is allocated for each element.
 *
 *==============================================================================================================*/
exported void fastcall	binteger_ainit_cells ( binteger *  array, size_t  array_size, bn_usize_t  cellcount )
   {
	bn_ucell_t *	bip ;

	
	cellcount	+=  ( cellcount  ==  0 ) ;
	bip		 =  ( bn_ucell_t * ) bni_memalloc ( array_size * cellcount * BN_BYTES_PER_CELL ) ;

	while  ( array_size -- )
	   {
		array -> allocated	=  cellcount ;
		array -> size		=  0 ;
		array -> cells		=  bip ;
		
		array ++ ;
		bip += cellcount ;
	    }
    }
#pragma endregion


#pragma region binteger_ainit_bytes()
/*==============================================================================================================
 *
 *   NAME
 *	binteger_ainit_bytes - Initializes an array of binteger values.
 *
 *   PROTOTYPE
 *	void  binteger_ainit		( binteger *  array, size_t  array_size, bn_usize_t  bytecount ) ;
 *
 *   DESCRIPTION
 *	Initializes an array of binteger values. Each array element will have enough cells to hold at least
 *	[bytecount] bytes.
 *
 *   PARAMETERS
 *	binteger *  array -
 *		Array of binteger values to be initialized. 
 *
 *	size_t  array_size -
 *		Number of bintegers in the array.
 *
 *	bn_usize_t  bytecount -
 *		Initial number of allocated bytes. This value will be rounded up to be a multiple of
 *		BN_BYTES_PER_CELL. If zero, it will default to 1 cell.
 *
 *==============================================================================================================*/
exported void fastcall	binteger_ainit_bytes ( binteger *  array, size_t  array_size, bn_usize_t  bytecount )
   {
	bn_ucell_t *	bip ;
	bn_usize_t	cellcount ;


	bytecount	+=  ( bytecount  ==  0 ) ;
        cellcount	 =  ( bytecount + BN_BYTES_PER_CELL - 1 ) / BN_BYTES_PER_CELL ;
	bip		 =  ( bn_ucell_t * ) bni_memalloc ( array_size * bytecount ) ;

	while  ( array_size -- )
	   {
		array -> allocated	=  cellcount ;
		array -> size		=  0 ;
		array -> cells		=  bip ;
		
		array ++ ;
		bip += cellcount ;
	    }
    }
#pragma endregion


#pragma region binteger_ainit_bytes()
/*==============================================================================================================
 *
 *   NAME
 *	binteger_ainit_bytes - Initializes an array of binteger values.
 *
 *   PROTOTYPE
 *	void  binteger_ainit		( binteger *  array, size_t  array_size, bn_bitcnt_t  bitcount ) ;
 *
 *   DESCRIPTION
 *	Initializes an array of binteger values. Each array element will have enough cells to hold at least
 *	[bitcount] bytes.
 *
 *   PARAMETERS
 *	binteger *  array -
 *		Array of binteger values to be initialized. 
 *
 *	size_t  array_size -
 *		Number of bintegers in the array.
 *
 *	bn_bitcnt_t  bitcount -
 *		Initial number of allocated bits. This value will be rounded up to be a multiple of
 *		BN_BYTES_PER_CELL * BITSPERBYTE. If zero, it will default to 1 cell.
 *
 *==============================================================================================================*/
exported void fastcall	binteger_ainit_bits ( binteger *  array, size_t  array_size, bn_bitcnt_t  bitcount )
   {
	bn_ucell_t *	bip ;
	bn_usize_t	bytecount ;
	bn_usize_t	cellcount ;


	bitcount	+=  ( bitcount  ==  0 ) ;
	bytecount	 =  ( bn_usize_t ) ( ( bitcount + BITSPERBYTE - 1 ) / BITSPERBYTE ) ;
	cellcount	 =  ( bytecount + BN_BYTES_PER_CELL - 1 ) / BN_BYTES_PER_CELL ;
	bip		 =  ( bn_ucell_t * ) bni_memalloc ( array_size * bytecount ) ;

	while  ( array_size -- )
	   {
		array -> allocated	=  cellcount ;
		array -> size		=  0 ;
		array -> cells		=  bip ;
		
		array ++ ;
		bip += cellcount ;
	    }
    }
#pragma endregion


END_C_CALLING_CONVENTION