/**************************************************************************************************************

    NAME
        Helpers.cpp

    DESCRIPTION
        Helper functions for the Vroom library.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/26]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include		"stdafx.h"
# include		"Vroom.h"


/*==============================================================================================================
 *
 *   NAME
 *	MsgBox - A shortcut for MessageBoxA, with a variable number of parameters.
 *
 *==============================================================================================================*/
int  MsgBox ( char *  title, unsigned int  type, char *  message, ... )
   {
	va_list			ap ;
	char			buffer [ 1024 ] ;

	va_start ( ap, message ) ;
	vsprintf_s ( buffer, message, ap ) ;
	va_end ( ap ) ;

	return ( MessageBoxA ( NULL, buffer, title, type ) ) ;
    }


/*==============================================================================================================
 *
 *   NAME
 *	IsConsoleApplication - Checks if we run as a console application.
 *
 *==============================================================================================================*/
BOOL  IsConsoleApplication ( )
   {
	HANDLE		handle	=  GetStdHandle ( STD_OUTPUT_HANDLE ) ;

	
	if  ( handle  ==  INVALID_HANDLE_VALUE  ||  handle  ==  NULL )
		return ( FALSE ) ;
	else
		return ( TRUE ) ;
    }