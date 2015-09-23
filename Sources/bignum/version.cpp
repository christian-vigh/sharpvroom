/**************************************************************************************************************

    NAME
        version.cpp

    DESCRIPTION
        Version information for the bignum package.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/27]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# include	"stdafx.h"
# include	"Vroom.h"
# include	"math/bignum.h"


# define	BN_VERSION_MAJOR	5
# define	BN_VERSION_MINOR	0
# define	BN_VERSION_REVISION	0

# define	BN_VERSION		( ( BN_VERSION_MAJOR * 10000 ) | ( BN_VERSION_MINOR * 100 ) | BN_VERSION_REVISION )

# define	BN_VERSION_STRING	"bignum package V" \
					STRINGIFY ( BN_VERSION_MAJOR ) "." \
					STRINGIFY ( BN_VERSION_MINOR ) "." \
					STRINGIFY ( BN_VERSION_REVISION )


exported char *		bn_version		=   BN_VERSION_STRING ;