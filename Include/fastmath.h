/**************************************************************************************************************

    NAME
        Math.h

    DESCRIPTION
        Miscellaneous math functions.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/21]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# if	! defined ( __FASTMATH_H__ )
#	  define    __FASTMATH_H__


/*==============================================================================================================

	Exported functions.

  ==============================================================================================================*/

BEGIN_C_CALLING_CONVENTION
 
extern exported unsigned int fastcall		vroom_math_ipow2ge		( unsigned int  value ) ;
extern exported unsigned int fastcall		vroom_math_ipow2gt		( unsigned int  value ) ;
extern exported unsigned int fastcall		vroom_math_ipow2ceiling		( unsigned int  data, unsigned int  alignment ) ;

END_C_CALLING_CONVENTION


# endif		// __FASTMATH_H__