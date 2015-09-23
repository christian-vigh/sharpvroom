/**************************************************************************************************************

    NAME
        memcpy.h

    DESCRIPTION
        Memory-copy functions.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/21]     [Author : CV]
        Initial version.

 **************************************************************************************************************/


# if	! defined ( __MEMCPY_H__ )
#	  define    __MEMCPY_H__


/*==============================================================================================================

	Exported functions.

  ==============================================================================================================*/

BEGIN_C_CALLING_CONVENTION
 
extern exported void *	fastcall		vroom_stdmemcpy	( void *  dst, const void *  src, size_t  size ) ;
extern exported void *	fastcall		vroom_memcpy    ( void *  dst, const void *  src, size_t  size ) ;

extern exported void *  fastcall		vroom_xmmcpy	( void *  dst, void *  src, size_t  count ) ;
  	
END_C_CALLING_CONVENTION


# endif		// __MEMCPY_H__