/**************************************************************************************************************

    NAME
        Vroom.cpp

    DESCRIPTION
        DLL main entry point.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/03]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include		"stdafx.h"
# include		"Vroom.h"
# include		"VroomInit.h"


/*==============================================================================================================

	Global variables.

  ==============================================================================================================*/
HMODULE		CurrentModule ;
HANDLE		CurrentProcessId ;
HANDLE		CurrentThreadId ;
HANDLE		CurrentProcessHeap ;
DWORD		ReasonForCall ;



/*==========================================================================================

    NAME
	DLLMain 

    DESCRIPTION
	Initializes the helper DLL.

 ==========================================================================================*/
BOOL APIENTRY DllMain	( 
				HMODULE		hModule,
				DWORD		ul_reason_for_call,
				LPVOID		lpReserved
			  )
   {
	BOOL		Status		=  TRUE ;			// DllMain call result
	char *		Reason		=  "" ;


	// Save parameters
	CurrentModule	=  hModule ;
	ReasonForCall	=  ul_reason_for_call ;


	// Handle each call case
	switch ( ul_reason_for_call )
	   {
		// DLL_PROCESS_ATTACH :
		//	Get the current process and current process heap handles.
		case DLL_PROCESS_ATTACH	:
			CurrentProcessId	=  GetCurrentProcess ( ) ;
			CurrentProcessHeap	=  GetProcessHeap ( ) ;
			Reason			=  " [DLL_PROCESS_ATTACH]" ;
			break ;

		// DLL_THREAD_ATTACH :
		//	Get the current thread handle.
		case DLL_THREAD_ATTACH	:
			CurrentThreadId		=  GetCurrentThread ( ) ;
			Reason			=  " [DLL_THREAD_ATTACH]" ;
			break ;

		// DLL_THREAD_DETACH :
		//	Does nothing for the moment.
		case DLL_THREAD_DETACH	:
			Reason			=  " [DLL_THREAD_DETACH]" ;
			break ;

		// DLL_PROCESS_DETACH :
		//	Does nothing for the moment.
		case DLL_PROCESS_DETACH	:
			Reason			=  " [DLL_PROCESS_DETACH]" ;
			break ;
	    }

	// Process any declared entry points
	for  ( DLLMAINCALLBACKENTRY *  p  =  DllCallbacks ; p -> lpszName  !=  NULL ; p ++ )
	   {
		// Ignore the entry points not declared to handle this "reason for call"
		if  ( p -> dwReasonForCall  !=  ul_reason_for_call )
			continue ;

		// If the entry point function pointer is NULL, load it from this library
		if  ( p -> lpFunction  ==  NULL )
		   {
			p -> lpFunction		=  ( DLLMAINCALLBACK ) GetProcAddress ( hModule, p -> lpszName ) ;

			// If not found, return FALSE to signal an error
			if  ( p -> lpFunction  ==  NULL )
			   {
				MsgBox ( VROOM_DLL, MB_OK, 
						"Initialization error : Unable to find entry point \"%s\".\n"
						"(DllMain call reason = 0x%.8X%s)",
						p -> lpszName, ul_reason_for_call, Reason ) ;
				Status	=  FALSE ;
				break ;
			    }		

			// Otherwise, call the function
			Status = p -> lpFunction ( ul_reason_for_call ) ;

			if  ( Status  ==  FALSE )		// And stop if initializer function failed
			   {
				MsgBox ( VROOM_DLL, MB_OK, 
						"Initialization error : Initialization function \"%s\" failed.\n"
						"(DllMain call reason = 0x%.8X%s)",
						p -> lpszName, ul_reason_for_call, Reason ) ;
				Status	=  FALSE ;
				break ;
			    }
		     }
	    }

	// Return initialization status
	return ( Status ) ;
    }

