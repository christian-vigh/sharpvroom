/**************************************************************************************************************

    NAME
        dynarray.h

    DESCRIPTION
        Implements a dynamic array using a Windows heap.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/24]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# if	! defined ( __HEAPARRAY_H__ )
#	  define    __HEAPARRAY_H__

/*==============================================================================================================

    Constants.

  ==============================================================================================================*/

// Data alignment within a DYNARRAY
# define	DYNARRAY_DATA_ALIGNMENT			32
// DYNARRAY items must be a multiple of this value ; if not, they are rounded
# define	DYNARRAY_DATA_UNIT			4
// In the free list, specifies a null pointer for the previous or next pointers
# define	DYNARRAY_NULLPTR			0xFFFFFFFF


/*==============================================================================================================

    DYNARRAY structure -
	Implements a dynamic, growable-only array.

  ==============================================================================================================*/

typedef struct  DYNARRAY
   {
	DWORD			dwItemSize ;			// Item size in bytes (a multiplier of DYNARRAY_DATA_ALIGNMENT)
	DWORD			dwInitialItemCount ;		// Initial item count
	DWORD			dwItemCount ;			// Number of items
	DWORD			dwItemGrowth ;			// Number of items to grow by when reallocation needed
	DWORD			dwSize ;			// Total size in bytes
	DWORD			dwFreeListHead ;		// Offset to free list head in lpData
	DWORD			dwFreeListTail ;		// Offset to tail of free list
	BYTE *			lpData ;			// Pointer to heap data, aligned on a DYNARRAY_DATA_ALIGNMENT boundary.
    }  DYNARRAY ;



/*==============================================================================================================

    Exported functions.

  ==============================================================================================================*/
BEGIN_C_CALLING_CONVENTION

exported DYNARRAY * fastcall		vroom_dynarray_alloc	( unsigned int  item_size, unsigned int  item_count, unsigned int  item_growth ) ;
exported void fastcall			vroom_dynarray_free	( DYNARRAY *  da ) ;
exported DYNARRAY * fastcall		vroom_dynarray_grow	( DYNARRAY *  da, unsigned int  growth ) ;

exported DWORD fastcall			vroom_dynarray_get	( DYNARRAY *  da ) ;
exported void fastcall			vroom_dynarray_release	( DYNARRAY *  da, DWORD  handle ) ;
exported BYTE *  fastcall		vroom_dynarray_pointer  ( DYNARRAY *  da, DWORD  handle ) ;

END_C_CALLING_CONVENTION

# endif		// __HEAPARRAY_H__