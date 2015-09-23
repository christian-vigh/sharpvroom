/**************************************************************************************************************

    NAME
        VroomInit.h

    DESCRIPTION
        Callback initialization structure.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/26]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# if	! defined ( __VROOMINIT_H__ )
#	  define    __VROOMINIT_H__



/*==============================================================================================================

	Macros.

  ==============================================================================================================*/
# define	DLLCALLBACK_TABLE		DLLMAINCALLBACKENTRY	DllCallbacks [] = {
# define	DLLCALLBACK_TABLE_END		{ 0, NULL, NULL } } ;
# define	DLLCALLBACK(reason,function)	{ reason, function, NULL },


/*==============================================================================================================

	DLL initialization/termination related types.

  ==============================================================================================================*/

// Defines a callback function to be called upon DLL initialization or termination ; this allows for Vroom packages
// to initialize correctly.
// Note : only Kernel32.DLL functions may be called by callback functions.
typedef BOOL		( * DLLMAINCALLBACK )		( DWORD  dwReasonForCall ) ;


// Structure defining which callback function should be called by DllMain, and for which reason.
typedef struct  DLLMAINCALLBACKENTRY
   {
	DWORD				dwReasonForCall ;		// Reason for call, as passed to the DllMain function
	char *				lpszName ;			// Callback function name (must be marked as "export")
	DLLMAINCALLBACK			lpFunction ;			// Callback function
    }  DLLMAINCALLBACKENTRY ;



/*==============================================================================================================

	DLL initialization/termination functions.

  ==============================================================================================================*/

DLLCALLBACK_TABLE
	DLLCALLBACK ( DLL_PROCESS_ATTACH, "__bignum_process_initialize" )
	DLLCALLBACK ( DLL_PROCESS_DETACH, "__bignum_process_terminate"  )
DLLCALLBACK_TABLE_END ;

# endif		/// __VROOMINIT_H__