/**************************************************************************************************************

    NAME
        dynarray.cpp

    DESCRIPTION
        Implementation of a dynamic array.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/24]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include	"stdafx.h"
# include	"Vroom.h"
# include	"sys/asm.h"
# include	"fastmath.h"
# include	"dynarray.h"


BEGIN_C_CALLING_CONVENTION


#pragma region vroom_dynarray_alloc()
/*==============================================================================================================
 *
 *   NAME
 *	vroom_dynarray_alloc - Allocates a dynamic array.
 *
 *   PROTOTYPE
 *	DYNARRAY *	vroom_dynarray_alloc ( unsigned int  item_size, 
					       unsigned int  item_count,
					       unsigned int  item_growth ) ;
 *
 *   DESCRIPTION
 *	Allocates a dynamic array.
 *
 *   PARAMETERS
 *	unsigned int  item_size -
 *		Item size. If not a multiple of DYNARRAY_DATA_UNIT, it will be rounded up to be a multiple of this
 *		value.
 *
 *	unsigned int  item_count -
 *		Initial number of items in the dynamic array.
 *
 *	unsigned int  item_growth -
 *		Growth, in number of items, for future reallocations. If zero, will default to item_count.
 *
 *   RETURN VALUE
 *	A pointer to a DYNARRAY structure, or NULL if item_count is zero or a memory allocation failed.
 *
 *==============================================================================================================*/
exported DYNARRAY * fastcall	vroom_dynarray_alloc ( unsigned int  item_size, unsigned int  item_count, unsigned int  item_growth )
   {
	// If no item count specified, return nothing
	if (  ! item_count )
		return ( NULL ) ;

	// If item size is not a multiple of DYNARRAY_DATA_UNIT, adjust it
	if  ( ( item_size % DYNARRAY_DATA_UNIT )  !=  0 )
		item_size	=  ( ( item_size + DYNARRAY_DATA_UNIT - 1 ) / DYNARRAY_DATA_UNIT ) * DYNARRAY_DATA_UNIT ;

	// If item_growth is zero, default it to item_count
	if  ( ! item_growth )
		item_growth	=  item_count ;

	DWORD		size		=  item_count * item_size ;

	// Allocate the DYNARRAY structure
	DYNARRAY *		da	=  ( DYNARRAY * ) malloc ( sizeof ( DYNARRAY ) ) ;

	if  ( da  ==  NULL )
		return ( NULL ) ;

	// Then the data itself
	da -> lpData		=  ( BYTE * ) _aligned_malloc ( size, DYNARRAY_DATA_ALIGNMENT ) ;

	if (  da -> lpData  ==  NULL )
	   {
		free ( da ) ;
		return ( NULL ) ;
	    }

	// Set other fields of the structure
	da -> dwItemSize			=  item_size ;
	da -> dwInitialItemCount		=  item_count ;
	da -> dwItemCount		=  item_count ;
	da -> dwItemGrowth		=  item_growth ;
	da -> dwSize			=  size ;

	// Build the free list
	BYTE *		list			=  da -> lpData ;
	DWORD		offset			=  0 ;
	da -> dwFreeListHead			=  0 ;
	da -> dwFreeListTail			=  size - item_size ;

	for  ( unsigned int  i = 0 ; i  <  item_count - 1 ; i ++ )
	   {
		offset			+=  item_size ;
		* ( ( DWORD * ) list )	 =  offset ;
		list			+=  item_size ;
	    }

	* ( ( DWORD * ) list )		=  DYNARRAY_NULLPTR ;

	// All done, return
	return ( da ) ;
    }
#pragma endregion


#pragma region vroom_dynarray_free()
/*==============================================================================================================
 *
 *   NAME
 *	vroom_dynarray_free - Frees a dynamic array.
 *
 *   PROTOTYPE
 *	void  vroom_dynarray_free ( DYNARRAY *  da )
 *
 *   DESCRIPTION
 *	Frees a dynamic array structure and all the data allocated for it.
 *
 *   PARAMETERS
 *	DYNARRAY *  da -
 *		Pointer to the dynamic array to be freed.
 *
 *==============================================================================================================*/
exported void fastcall		vroom_dynarray_free ( DYNARRAY *  da )
   {
	_aligned_free ( da -> lpData ) ;
	free ( da ) ;
    }
#pragma endregion


#pragma region vroom_dynarray_grow()
/*==============================================================================================================
 *
 *   NAME
 *	vroom_dynarray_grow - Reallocates a dynamic array.
 *
 *   PROTOTYPE
 *	DYNARRAY *	vroom_dynarray_grow ( DYNARRAY *  da, unsigned int  growth ) ;
 *
 *   DESCRIPTION
 *	Reallocates a dynamic array with a bigger size.
 *
 *   PARAMETERS
 *	DYNARRAY *  da -
 *		Dynamic array to be reallocated.
 *
 *	unsigned int  growth -
 *		Number of items to add to the dynamic array. If set to zero, the dwItemGrowth field of the 
 *		DYNARRAY structure will be used instead.
 *
 *   RETURN VALUE
 *	The reallocated dynamic array.
 *
 *   NOTES
 *	. When reallocated, the pointer to the DYNARRAY structure never changes ; only the underlying data
 *	  pointer (lpData) could be subject to change.
 *	. A DYNARRAY can only grow, it can never be shrinked.
 *
 *==============================================================================================================*/
exported DYNARRAY * fastcall	vroom_dynarray_grow ( DYNARRAY *  da, unsigned int  growth )
   {
	// If growth is zero, use the default one in the dynamic array
	if  ( growth  ==  0 )
		growth = da -> dwItemGrowth ;

	// Compute new size
	DWORD		new_size	=  da -> dwSize + ( growth * da -> dwItemSize ) ;

	// Allocate the data
	DWORD		old_size	=  da -> dwSize ;
	DWORD		old_count	=  da -> dwItemCount ;
	DWORD		item_size	=  da -> dwItemSize ;

	da -> lpData		=  ( BYTE * ) _aligned_realloc ( da -> lpData, new_size, DYNARRAY_DATA_ALIGNMENT ) ;
	
	if  ( da -> lpData  ==  NULL )
		return ( NULL ) ;

	// Update size fields
	da -> dwItemCount	+=  growth ;
	da -> dwSize		 =  new_size ;

	// Build free list
	BYTE *		list		=  da -> lpData + old_size ;
	DWORD		old_free_list	=  da -> dwFreeListTail ;
	DWORD		offset		=  old_size ;

	* ( ( DWORD * ) ( da -> lpData + old_free_list ) )	=  old_size ;

	for  ( unsigned int  i = 0 ; i  <  growth - 1 ; i ++ )
	   {
		offset			+=  item_size ;
		* ( ( DWORD * ) list )	 =  offset ;
		list			+=  item_size ;
	    }

	* ( ( DWORD * ) list )		=  DYNARRAY_NULLPTR ;

	da -> dwFreeListTail		=  new_size - item_size ;

	// All done, return
	return ( da ) ;
    }
#pragma endregion


#pragma region vroom_dynarray_get()
/*==============================================================================================================
 *
 *   NAME
 *	vroom_dynarray_get - Allocates a dynamic array item.
 *
 *   PROTOTYPE
 *	unsigned int  vroom_dynarray_get ( DYNARRAY *  da ) ;
 *
 *   DESCRIPTION
 *	Allocates an item in a dynamic array.
 *	If the free list contains only one free item, then the array size is augmented.
 *
 *   PARAMETERS
 *	DYNARRAY *  da -
 *		A pointer to a DYNARRAY structure describing the array.
 *
 *   RETURN VALUE
 *	A handle to the item data. Use the vroom_dynarray_pointer function to get the real data address.
 *
 *==============================================================================================================*/
exported DWORD fastcall		vroom_dynarray_get ( DYNARRAY *  da )
   {
	BYTE *		data		=  da -> lpData ;
	DWORD		head		=  * ( ( DWORD * ) ( data + da -> dwFreeListHead ) ) ;
	DWORD		result ;

	if  ( head  ==  DYNARRAY_NULLPTR )
	   {
		vroom_dynarray_grow ( da, 0 ) ;
		data		=  da -> lpData ;
		head		=  * ( ( DWORD * ) ( data + da -> dwFreeListHead ) ) ;
	    }

	result				=  da -> dwFreeListHead ;
	da -> dwFreeListHead		=  head ;

	return ( result ) ;
    }
#pragma endregion


/*==============================================================================================================
 *
 *   NAME
 *	vroom_dynarray_release - Release a previously allocated item.
 *
 *   PROTOTYPE
 *	void  vroom_dynarray_release ( DYNARRAY *  da, DWORD  handle )
 *
 *   DESCRIPTION
 *	Frees an allocated item and puts it back to the free list.
 *
 *   PARAMETERS
 *	DYNARRAY *  da -
 *		A pointer to a DYNARRAY structure describing the array.
 *
 *	DWORD  handle -
 *		Handle to the dynamic array item.
 *
 *==============================================================================================================*/
#pragma region  vroom_dynarray_release()
exported void fastcall			vroom_dynarray_release ( DYNARRAY *  da, DWORD  handle )
   {
	BYTE *		data		=  da -> lpData ;
	DWORD		old_head	=  da -> dwFreeListHead ;

	da -> dwFreeListHead			=  handle ;
	* ( ( DWORD * ) ( data + handle ) )	=  old_head ;
    }
#pragma endregion


/*==============================================================================================================
 *
 *   NAME
 *	vroom_dynarray_pointer - Returns an item address from its handle.
 *
 *   PROTOTYPE
 *	BYTE *  	vroom_dynarray_pointer ( DYNARRAY *  da, DWORD  handle ) ;
 *
 *   DESCRIPTION
 *	Returns a pointer to the data of a dynamic array item, based on its handle.
 *
 *   PARAMETERS
 *	DYNARRAY *  da -
 *		A pointer to a DYNARRAY structure describing the array.
 *
 *	DWORD  handle -
 *		Handle to the dynamic array item.
 *
 *   RETURN VALUE
 *	This function returns a pointer to the item data that can be safely used as long as no reallocation
 *	occurs.
 *
 *==============================================================================================================*/
#pragma region vroom_dynarray_pointer()
exported naked BYTE *  fastcall		vroom_dynarray_pointer ( DYNARRAY *  da, DWORD  handle )
   {
	asm
	   {
		MOV		EAX, DWORD PTR [ECX + 0x1C ]		; Get da -> lpData
		ADD		EAX, EDX				; Add the specified offset
		RET							; All done, pointer is in EAX
	    }
    }
#pragma endregion


END_C_CALLING_CONVENTION