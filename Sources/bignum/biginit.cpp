/**************************************************************************************************************

    NAME
        biginit.cpp

    DESCRIPTION
        Bignum package initialization, at the DLL level.

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
/*==============================================================================================================

    __bignum_process_initialize -
        Initialization function for the bignum package.

  ==============================================================================================================*/
exported BOOL	__bignum_process_initialize ( HANDLE  hModule, DWORD  dwCallReason )
   {
	// Set the memory manager to be used
	bn_set_memory_manager ( BN_DEFAULT_MEMORY_MANAGER ) ;

	// All done, return
	return ( TRUE ) ;
    }


/*==============================================================================================================

    __bignum_process_terminate -
        Termination function for the bignum package.

  ==============================================================================================================*/
exported BOOL	__bignum_process_terminate ( HANDLE  hModule, DWORD  dwCallReason )
   {
	// If defined, call the current memory manager termination function.
	bni_mm_terminate ( bni_mm_current ) ;

	// All done, return
	return ( TRUE ) ;
    }

END_C_CALLING_CONVENTION