/**************************************************************************************************************

    NAME
        mem.h

    DESCRIPTION
        Memory-related macros.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/27]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# if	! defined ( __MEM_H__ )
#	  define    __MEM_H__


/* Return non-zero if xp,xsize and yp,ysize overlap.
   If xp+xsize<=yp there's no overlap, or if yp+ysize<=xp there's no
   overlap.  If both these are false, there's an overlap. */

// Return non-zero if [xp, xp+size] and [yp, yp+ysize] overlap.
// If ( xp + xsize  <=  yp ), or if  ( yp + ysize  <=  xp ), there's no overlap.
# define	MEM_OVERLAPPING_DATA( xp, xsize, yp, ysize )		( ( xp ) + ( xsize )  >  ( yp )  &&  \
									  ( yp ) + ( ysize )  >  ( xp ) )

// The same, for char pointers
# define	MEM_OVERLAPPING_BYTES( xp, xsize, yp, ysize )		( ( char * ) ( xp ) + ( xsize )  >  ( char * ) ( yp )  &&  \
									  ( char * ) ( yp ) + ( ysize )  >  ( xp ) )


// Return non-zero if [xp..xp+xsize] and [yp..yp+ysize] are either identical or not overlapping.
// Return zero if they partially overlap.
# define	MEM_SAME_OR_SEPARATE( xp, xsize, yp, ysize )		( (xp)  ==  (yp)  ||  ! MEM_OVERLAPPING_DATA ( xp, xsize, yp, ysize ) )

// Return non-zero if [xp..xp+xsize] and [yp..yp+ysize] are either identical or overlapping in a way
// suitable for incremental or decremental copy.
// Return zero if address ranges partially overlap in an unsuitable fashion.
# define	MEM_SAME_OR_INCREMENTAL( xp, xsize, yp, ysize )		( (xp)  <=  (yp)  ||  ! MEM_OVERLAPPING_DATA ( xp, xsize, yp, ysize ) )
# define	MEM_SAME_OR_DECREMENTAL( xp, xsize, yp, ysize )		( (xp)  >=  (yp)  ||  ! MEM_OVERLAPPING_DATA ( xp, xsize, yp, ysize ) )


# endif		// __MEM_H__