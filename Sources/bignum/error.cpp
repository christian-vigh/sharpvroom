/**************************************************************************************************************

    NAME
        error.cpp

    DESCRIPTION
        description.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/27]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include	"stdafx.h"
# include	"Vroom.h"
# include	"math/bignum.h"


// Last bignum error
exported int		bn_errno		=  0 ;


BEGIN_C_CALLING_CONVENTION

/*==============================================================================================================
 *
 *   NAME
 *	bni_error, bni_warning - display error messages.
 *
 *   PROTOTYPE
 *	void  bni_error		( char *  format, ... ) ;
 *	void  bni_warning	( char *  format, ... ) ;
 *
 *   DESCRIPTION
 *	bni_error() displays an error message then aborts program execution.
 *	bni_warning() displays a warning messsage without stopping program execution.
 *
 *   PARAMETERS
 *	char *  format -
 *		Format string to be used as the message.
 *
 *	... -
 *		Additional arguments that will be passed to the vsprintf() function together with the format
 *		string.
 *
 *==============================================================================================================*/
void  bni_error ( char *  format, ... )
   {
	char		buffer [ 4096 ] ;
	va_list		ap ;

	va_start ( ap, format ) ;
	vsprintf_s ( buffer, format, ap ) ;
	va_end ( ap ) ;

	if  ( IsConsoleApplication ( ) )
		MsgBox ( "Bignum error", MB_OK | MB_ICONEXCLAMATION, buffer ) ;
	else
		fprintf ( stderr, "***  Bignum error  ***  %s\n", buffer ) ;
	abort ( ) ;
    }


void  bni_warning ( char *  format, ... )
   {
	char		buffer [ 4096 ] ;
	va_list		ap ;

	va_start ( ap, format ) ;
	vsprintf_s ( buffer, format, ap ) ;
	va_end ( ap ) ;

	if  ( IsConsoleApplication ( ) )
		MsgBox ( "Bignum error", MB_OK | MB_ICONEXCLAMATION, buffer ) ;
	else
		fprintf ( stderr, "*** Bignum warning ***  %s\n", buffer ) ;
    }

END_C_CALLING_CONVENTION