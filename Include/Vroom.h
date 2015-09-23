/**************************************************************************************************************

    NAME
        Vroom.h

    DESCRIPTION
        Global include file for the Vroom library.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/03]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# if ! defined ( __VROOM_H__ )
#      define    __VROOM_H__


/*==============================================================================================================

	Miscellaneous macros.

  ==============================================================================================================*/

// Stringifies its argument AFTER expansion
# define	STRINGIFY(name)			____STRINGIFY____ ( name )
# define	____STRINGIFY____(name)		#name


/*==============================================================================================================

	System-based declarations.

  ==============================================================================================================*/

// DEBUG mode
# if	defined ( _DEBUG )
#	define		DEBUG			1 
# else
#	define		DEBUG			0
# endif


// Target systems
# define	PORTABLE			1		// Portable C implementation
# define	INTEL				2		// Intel implementation

# if	defined ( _WIN64 )
	# define	INTEL32			0		// WIN64 architecture : WIN32 is still defined...
	# define	INTEL64			1
# else
	# define	INTEL32			1		// WIN32 architecture : Only INTEL32 is true
	# define	INTEL64			0
# endif

# if  ! defined ( TARGET )
#	define	  TARGET	PORTABLE
# endif



// Function attributes
# define	exported			__declspec ( dllexport )
# define	imported			__declspec ( dllimport )
# define	fastcall			__fastcall

# if	INTEL64
#	define	naked				
# else
#	define  naked				__declspec ( naked )
# endif

// DLL variables that are to be imported from the outside world need to be declared "exported" when the DLL is compiled,
// and "imported" when the application including the file where the variable is declared as "extern" is compiled.
# if	defined ( _USRDLL )
# define	dllvar				exported
# else
# define	dllvar				imported
# endif


// Miscellaneous declarations
# define	aligned(x)			__declspec ( align ( x ) )
# define	roundedsizeof(t,s)		( ( ( sizeof ( t ) + (s) - 1 ) / (s) ) * (s) )


// C declarations
# define	BEGIN_C_CALLING_CONVENTION	extern "C" {
# define	END_C_CALLING_CONVENTION	}

// Size constants
# define	BITSPERBYTE			8
# define	BYTESPERDWORD			( sizeof ( dword ) / sizeof ( byte ) )
# define	BITSPERDWORD			( BYTESPERDWORD * BITSPERBYTE )
# define	BYTESPERWORD			( sizeof ( word  ) / sizeof ( byte ) ) 
# define	BITSPERWORD			( BYTESPERWORD * BITSPERBYTE )
# define	WORDSPERDWORD			( sizeof ( dword ) / sizeof ( word ) )


// Typedefs
typedef void *			pointer ;


/*==============================================================================================================

	DLL Macros.

  ==============================================================================================================*/
# define	VROOM_DLL			"Vroom.DLL"


/*==============================================================================================================

	DLL Variables.

  ==============================================================================================================*/

extern HMODULE		CurrentModule ;
extern HANDLE		CurrentProcessId ;
extern HANDLE		CurrentThreadId ;
extern HANDLE		CurrentProcessHeap ;


/*==============================================================================================================

	Helper functions.

  ==============================================================================================================*/

# if	defined ( _USRDLL )

extern int			MsgBox				( char *  title, unsigned int  type, char *  message, ... ) ;
extern BOOL			IsConsoleApplication		( ) ;

# endif

# endif  // __VROOM_H__