/**************************************************************************************************************

    NAME
        string.cpp

    DESCRIPTION
        String conversion functions.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/27]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include		"stdafx.h"
# include		"Vroom.h"
# include		"math/bignum.h"


BEGIN_C_CALLING_CONVENTION

# pragma region bni_digit_values[] array
// Table to be indexed by character, to get its numerical value.  Assumes ASCII character set. 
// First part of table supports common usages, where 'A' and 'a' have the same value; this supports bases 2..36
// At offset 224, values for bases 37..62 start.  Here, 'A' has the value 10 (in decimal) and 'a' has the value 36.
# define	X			0xFF

const unsigned char  bni_digit_values [] =
   {
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  X,  X,  X,  X,  X,  X,
	   X, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
	  25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,  X,  X,  X,  X,  X,
	   X, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
	  25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  X,  X,  X,  X,  X,  X,
	   X, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
	  25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35,  X,  X,  X,  X,  X,
	   X, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
	  51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,
	   X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X,  X
    } ;
# pragma endregion


END_C_CALLING_CONVENTION
