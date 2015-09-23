/**************************************************************************************************************

    NAME
        memory/default.cpp

    DESCRIPTION
        Default memory allocation handler.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/27]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include		"stdafx.h"
# include		"Vroom.h"
# include		"math/bignum.h"


# define		SENTINEL_DATA			0xfadedbee


BEGIN_C_CALLING_CONVENTION

/*==============================================================================================================

    default_alloc_function -
        Default memory allocation function. Calls malloc().

  ==============================================================================================================*/
static void *	default_alloc_function ( size_t  size )
   {
	void *		result ;

# if	DEBUG
	bn_ucell_t *		cp ;
	bn_usize_t		cellcount ;

	size +=	2 * BN_BYTES_PER_CELL ;
# endif

	result	=  malloc ( size ) ;

	if  ( result  ==  NULL )
		bni_error ( "(mmdefault) alloc : failed to allocate %u bytes.", size ) ;

# if	DEBUG
	cp			=  ( bn_ucell_t * ) result ;

	cellcount		=  size / BN_BYTES_PER_CELL ;
	cp [0]			=  SENTINEL_DATA ;
	cp [ cellcount - 1 ]	=  SENTINEL_DATA ;

	result			=  cp + 1 ;
# endif

	return ( result ) ;
    }


/*==============================================================================================================

    default_realloc_function -
        Default memory reallocation function. Calls realloc().

  ==============================================================================================================*/
static void *	default_realloc_function ( void *  oldptr, size_t  oldsize, size_t  newsize )
   {
	void *		result ;


# if	DEBUG
	bn_ucell_t *	cp ;
	bn_usize_t	cellcount ;

	cp		=  ( bn_ucell_t * ) oldptr ;
	cellcount	=  newsize / BN_BYTES_PER_CELL ;

	if ( cp [-1]  !=  SENTINEL_DATA )
		bni_error ( "(mmdefault) realloc : corrupted data found before the start of memory block at 0x%.8X.", oldptr ) ;

	if  ( cp [ cellcount - 1 ]  !=  SENTINEL_DATA )
		bni_error ( "(mmdefault) realloc : corrupted data found after the end of memory block at 0x%.8X.", oldptr ) ;

	newsize += 2 * BN_BYTES_PER_CELL ;
# endif

	result	=  realloc ( oldptr, newsize ) ;

	if  ( result  ==  NULL )
		bni_error ( "(mmdefault) alloc : failed to allocate %u bytes.", newsize ) ;
	

# if	DEBUG
	cp			=  ( bn_ucell_t * ) result ;

	cp [0]			=  SENTINEL_DATA ;
	cp [ cellcount - 1 ]	=  SENTINEL_DATA ;

	result			=  cp + 1 ;
# endif

	return ( result ) ;
    }


/*==============================================================================================================

    default_free_function -
        Default memory freeing function. Calls free().

  ==============================================================================================================*/
static void    default_free_function ( void *  ptr, size_t  oldsize ) 
   {
# if	DEBUG
	bn_ucell_t *		cp ;
	bn_usize_t		cellcount ;


	cp		=  ( bn_ucell_t * ) ptr ;
	cellcount	=  oldsize / BN_BYTES_PER_CELL ;
	
	if ( cp [-1]  !=  SENTINEL_DATA )
		bni_error ( "(mmdefault) free : corrupted data found before the start of memory block at 0x%.8X.", ptr ) ;

	if  ( cp [ cellcount ]  !=  SENTINEL_DATA )
		bni_error ( "(mmdefault) free : corrupted data found after the end of memory block at 0x%.8X.", ptr ) ;

	ptr = cp - 1 ;
# endif

	free ( ptr ) ;
    }


// Memory manager declaration for this manager
bni_memory_manager_t	bni_mm_default	=  
   { 
	/* init_func		*/  NULL, 
	/* terminate_func	*/  NULL, 
	/* alloc_func		*/  default_alloc_function, 
	/* realloc_func		*/  default_realloc_function, 
	/* free_func		*/  default_free_function 
    }	 ;

END_C_CALLING_CONVENTION