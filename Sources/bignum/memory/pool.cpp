/**************************************************************************************************************

    NAME
        memory/pool.cpp

    DESCRIPTION
        Memory manager with a predefined pool of preallocated free memory. Designed to be extremely fast for 
	small allocation sizes (typically, bignums whose data part is <= 512 bytes).

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/27]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include		"stdafx.h"
# include		"Vroom.h"
# include		"math/bignum.h"
# include		"pooldata.h"


# define		DATA_END		( ( bn_ucell_t ) 0xFFFFFFFF )


static bn_ucell_t *		pool_data ;
static bn_ucell_t *		pool_data_end ;
static bn_ucell_t **		pool_start_list ;
static bn_ucell_t *		pool_free_list ;



BEGIN_C_CALLING_CONVENTION


#pragma region pool_initialize_function()
/*==============================================================================================================

    pool_initialize_function -
        Initializes the memory pool.

  ==============================================================================================================*/
static void 	pool_initialize_function ( )
   {
	size_t			total_size ;
	bn_ucell_t *		cp ;
	bn_ucell_t *		cur_cp ;
	int			i, j ;
	int			current_count, current_size ;


	// First, compute the total number of bytes needed to allocate the pool
	total_size	=  0 ;

	for  ( i = 0 ; pool_allocation_table [i] [0] ; i ++ )
		total_size +=  pool_allocation_table [i] [0] * pool_allocation_table [i] [1] ;

	// Allocate the pool
	total_size     *=  BN_BYTES_PER_CELL ;
	pool_data	=  ( bn_ucell_t * ) malloc ( total_size ) ;

	if  ( pool_data  ==  NULL )
		bni_error ( "(mmpool) init : failed to allocate %u bytes.", total_size ) ;

	pool_data_end		=  pool_data + total_size ;

	// Free list
	total_size		=  ( MAX_POOL_ALLOCATION_SIZE + 2 ) * BN_BYTES_PER_CELL ;
	pool_free_list		=  ( bn_ucell_t * ) malloc ( total_size ) ;

	if  ( pool_free_list  ==  NULL )
		bni_error ( "(mmpool) init : failed to allocate %u bytes.", total_size ) ;

	pool_start_list		=  ( bn_ucell_t ** ) malloc ( total_size ) ;

	if  ( pool_start_list  ==  NULL )
		bni_error ( "(mmpool) init : failed to allocate %u bytes.", total_size ) ;
	
	// Build a linked list for each of the possible pool sizes.
	// pool_free_list [i] gives the offset of the first free item in the item list pointed to by pool_start_list [i].
	cp	=  pool_data ;
	cur_cp	=  pool_data ;

	pool_free_list  [0]	=  DATA_END ;			// First entry in free list is unused (corresponds to size 0)
	pool_start_list [0]	=  NULL ;

	for  ( i = 0 ; pool_allocation_table [i] [0] ; i ++ )
	   {
		pool_start_list [i+1]	=  cur_cp ;
		pool_free_list  [i+1]	=  0 ;
		current_size		=  pool_allocation_table [i] [0] ;
		current_count		=  pool_allocation_table [i] [1] ;

		for  ( j = 0 ; j < current_count - 1 ; j ++, cp += current_size )
			* cp	=  ( cp + current_size + 1 ) - cur_cp ;

		* cp	 	=  DATA_END ;
		cur_cp		=  cp + current_size ;
	    }
    }
#pragma endregion


#pragma region pool_terminate_function()
/*==============================================================================================================

    pool_terminate_function -
        Terminates the memory pool.

  ==============================================================================================================*/
static void 	pool_terminate_function ( )
   {
	free ( pool_data ) ;
	free ( pool_free_list ) ;
	free ( pool_start_list ) ;
    }
#pragma endregion



/*==============================================================================================================

    pool_alloc_function -
        Memory allocation function.

  ==============================================================================================================*/
static void *	pool_alloc_function ( size_t  size )
   {
	void *			result ;
	bn_ucell_t *		data_pointer ;
	int			index ;
	int			free_offset ;


	// If the size is such that we may use our preallocated pool...
	if  ( size  <  MAX_POOL_ALLOCATION_SIZE * BN_BYTES_PER_CELL )
	   {
		// ... then first get the nearest pool table entry. For example, if we want to allocate 28 cells and have 
		// a pool of 32 cells items, then the size_matcher_table[] array will give use the index in the pool where
		// 32 cells items are stored.
		index		=  size_matcher_table [ size / BN_BYTES_PER_CELL ] ;

		// Now, locate the first free entry
		free_offset	=  pool_free_list [ index ] ;

		// If this free entry offset is DATA_END, then this mean that the corresponding data pool is full
		// (to continue with the above example, that would mean that all the 32 cells items are occupied)
		// If not equal to DATA_END...
		if  ( free_offset  !=  DATA_END )
		   {
			// Get a pointer to the first item in the pool corresponding to the specified size
			data_pointer			=  pool_start_list [ index ] ;
			// Our next free item offset will be the one stored in the data pool ; this becomes the new
			// free list start offset for this pool.
			pool_free_list [ index ]	=  data_pointer [ free_offset ] ;

			// Return a pointer to the item, in the pool, that has been allocated for the caller
			return ( data_pointer + free_offset ) ;
		    }
	    }

	// Size is greater than MAX_POOL_ALLOCATION_SIZE * BN_BYTES_PER_CELL, or corresponding data pool is full :
	// use the normal allocation function
	result		=  malloc ( size ) ;

	// In case of error, complain
	if  ( result  ==  0 )
		bni_error ( "(mmpool) alloc : failed to allocate %u bytes.", size ) ;

	// Otherwise, return the newly allocated block
	return ( result ) ;
    }



/*==============================================================================================================

    pool_realloc_function -
        Memory reallocation function.

  ==============================================================================================================*/
static void *	pool_realloc_function ( void *  oldptr, size_t  oldsize, size_t  newsize )
   {
	return ( NULL ) ;
    }


/*==============================================================================================================

    pool_free_function -
        Memory free function.

  ==============================================================================================================*/
static void    pool_free_function ( void *  ptr, size_t  oldsize ) 
   {
    }


// Memory manager declaration for this manager
bni_memory_manager_t	bni_mm_pool	=  
   { 
	/* init_func		*/  pool_initialize_function, 
	/* terminate_func	*/  pool_terminate_function, 
	/* alloc_func		*/  pool_alloc_function, 
	/* realloc_func		*/  pool_realloc_function, 
	/* free_func		*/  pool_free_function 
    }	 ;

END_C_CALLING_CONVENTION