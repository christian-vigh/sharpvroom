/**************************************************************************************************************

    NAME
        bignum.h

    DESCRIPTION
        Header file for the Windows bignum library.

    AUTHOR
        Christian Vigh, 09/2012 (largely inspired from GNU MP).

    HISTORY
    [Version : 1.0]    [Date : 2012/09/27]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# if	! defined ( __BIGNUM_H__ )
#	  define    __BIGNUM_H__


/*==============================================================================================================

	Architecture-dependent definitions.

  ==============================================================================================================*/

# if	( TARGET  ==  INTEL )
# if		INTEL32						// Definitions for WIN32

	typedef unsigned __int32	bn_ucell_t ;		// Basic digit unit for a bignum (unsigned)
	typedef signed __int32		bn_scell_t ;		// The same, signed
	typedef unsigned __int32	bn_usize_t ;		// Size type (unsigned)
	typedef signed __int32		bn_ssize_t ;		// The same, signed
	typedef unsigned __int32	bn_exp_t ;		// Exponent type
	typedef unsigned __int64	bn_bitcnt_t ;		// Bit count

# elif		INTEL64

	typedef unsigned __int32	bn_ucell_t ;		// Basic digit unit for a bignum (unsigned)
	typedef signed __int32		bn_scell_t ;		// The same, signed
	typedef unsigned __int64	bn_usize_t ;		// Size type (unsigned)
	typedef signed __int64		bn_ssize_t ;		// The same, signed
	typedef unsigned __int32	bn_exp_t ;		// Exponent type
	typedef unsigned __int64	bn_bitcnt_t ;		// Bit count

# else
#	error Either the INTEL32 or INTEL64 constant must be defined.
# endif

# else	// TARGET  ==  PORTABLE

	typedef unsigned int		bn_ucell_t ;		// Basic digit unit for a bignum (unsigned)
	typedef int			bn_scell_t ;		// The same, signed
	typedef unsigned int		bn_usize_t ;		// Size type (unsigned)
	typedef int			bn_ssize_t ;		// The same, signed
	typedef unsigned int		bn_exp_t ;		// Exponent type
	typedef unsigned long		bn_bitcnt_t ;		// Bit count

# endif


/*==============================================================================================================

	Macros and constants.

  ==============================================================================================================*/

// General macros
# define	BN_ABS(x)			( ( (x)  >=   0 ) ? (x) : -(x) )
# define	BN_MAX(x,y)			( ( (x)  >  (y) ) ? (x) :  (y) )
# define	BN_MIN(x,y)			( ( (x)  <  (y) ) ? (x) :  (y) )

// Limits
# define	BN_UBYTE_MASK			( ~ ( BYTE ) 0 )
# define	BN_UBYTE_BITS			( BITSPERBYTE )

# define	BN_USHORT_MAX			( ( unsigned short ) ~0 )
# define	BN_USHORT_BITS			( sizeof ( unsigned short ) * BITSPERBYTE )

# define	BN_UINT_MASK			( ~ ( unsigned int ) 0 )
# define	BN_UINT_BITS			( sizeof ( unsigned int ) * BITSPERBYTE )

# define	BN_ULONG_MASK			( ~ ( unsigned long ) 0 )
# define	BN_ULONG_BITS			( sizeof ( unsigned long ) * BITSPERBYTE )


// Size correspondances
# define	BN_BYTES_PER_CELL		( sizeof ( bn_ucell_t ) )
# define	BN_CELLS_PER_ALLOCATION		1
# define	BN_BYTES_PER_ALLOCATION		( BN_BYTES_PER_CELL * BN_CELLS_PER_ALLOCATION )

// Number base-related constants. BN_EXTRA_BASE_OFFSET is the offset in the bni_digit_values[] array where bases
// 37 to 62 can be found.
# define	BN_MIN_BASE			2
# define	BN_MAX_BASE			62
# define	BN_EXTRA_BASE_OFFSET		224


/*==============================================================================================================

	Memory management.

  ==============================================================================================================*/

// Memory manager identifier constants
# define	BN_DEFAULT_MEMORY_MANAGER			0
# define	BN_POOLED_MEMORY_MANAGER			1


// Memory allocation function types
typedef	void *	( bni_memalloc_t ) 		( size_t		size ) ;
typedef void *  ( bni_memrealloc_t )		( void *		oldptr,
						  size_t		oldsize, 
						  size_t		newsize ) ;
typedef void    ( bni_memfree_t )		( void *		ptr,
						  size_t		size ) ;
typedef void	( bni_meminit_t )		( ) ;
typedef void	( bni_memterminate_t )		( ) ;

// Structure declared by a memory manager. Contains function pointers to memory initialization/termination and
// allocation functions.
typedef struct  bni_memory_manager_struct
   {
	bni_meminit_t *			init_func ;
	bni_memterminate_t *		terminate_func ;
	bni_memalloc_t *		alloc_func ;
	bni_memrealloc_t *		realloc_func ;
	bni_memfree_t *			free_func ;
    }  bni_memory_manager_t ;


// Pointers to the alloc/realloc/free functions particular to the current memory manager
extern bni_memalloc_t *			bni_memalloc ;
extern bni_memrealloc_t *		bni_memrealloc ;
extern bni_memfree_t *			bni_memfree ;
extern bni_memory_manager_t *		bni_mm_current ;		// Current memory manager
extern int				bni_mm_current_id ;		// Current memory manager ID

// Currently implemented memory managers
extern bni_memory_manager_t 		bni_mm_default ;		// Default memory manager
extern bni_memory_manager_t		bni_mm_pool ;			// Memory manager using a pool of pre-allocated data


/*==============================================================================================================

	Implementation-related stuff.

  ==============================================================================================================*/

// Number base conversion stuff
extern const unsigned char	bni_digit_values [] ;


/*==============================================================================================================

	Developper-related stuff.

  ==============================================================================================================*/

// Errno
dllvar extern int		bn_errno ;

// Version
dllvar extern char *		bn_version ;


/*==============================================================================================================

	Bignum structures.

  ==============================================================================================================*/

// Definition of a big integer
typedef struct binteger_struct
   {
	bn_usize_t			allocated ;		// Number of cells allocated for this big integer
	bn_ssize_t			size ;			// abs(size) gives the number of cells really occupied. 
								// A negative value indicates the number is negative.
	bn_ucell_t *			cells ;			// Pointer to the cells.
    }  binteger ;

typedef binteger 			binteger_t [1] ;	// Cosmetics : allow to use binteger_t values where "binteger *" are required


// Definition of a big rational (quotient)
typedef struct brational_struct
   {
	binteger_struct			numerator ;		// Rational value numerator
	binteger_struct			denominator ;		// Rational value denominator
    }  brational ;

typedef brational 			brational_t [1] ;	// Cosmetics : allow to use brational_t values where "brational *" are required


// Definition of a big float
typedef struct bfloat_struct
   {
	bn_usize_t			precision ;		// Max precision, in number of cells. Set by bfloat_init() and modified by
								// bfloat_set_precision(). The array pointed to by the [cells] field contains
								// [precision] + 1 cells.
	bn_ssize_t			size ;			// abs(size) gives the number of cells really occupied. 
								// A negative value indicates the number is negative.
	bn_exp_t			exponent ;		// Exponent, in base "bn_ucell_t".
	bn_ucell_t *			cells ;			// Pointer to the cells.
    }  bfloat ;

typedef bfloat				bfloat_t [1] ;		// Cosmetics : allow to use bfloat_t values where "bfloat *" are required


/*==============================================================================================================

	Non-exported functions.

  ==============================================================================================================*/

BEGIN_C_CALLING_CONVENTION

extern void					bni_mm_set			( bni_memory_manager_t *	manager ) ;
extern void					bni_mm_init			( bni_memory_manager_t *	manager ) ;
extern void					bni_mm_terminate		( bni_memory_manager_t *	manager ) ;

extern void					bni_error			( char *			format, ... ) ;
extern void					bni_warning			( char *			format, ... ) ;

END_C_CALLING_CONVENTION



/*==============================================================================================================

	Exported functions.

  ==============================================================================================================*/

BEGIN_C_CALLING_CONVENTION

exported extern int  fastcall			bn_set_memory_manager	( int	      mmid ) ;
exported extern int  fastcall			bn_get_memory_manager   ( ) ;

exported extern void fastcall			binteger_init		( binteger *  dst ) ;
exported extern void fastcall			binteger_init_cells	( binteger *  dst, bn_usize_t   cellcount ) ;
exported extern void fastcall			binteger_init_bytes	( binteger *  dst, bn_usize_t   bytecount ) ;
exported extern void fastcall			binteger_init_bits	( binteger *  dst, bn_bitcnt_t  bitcount ) ;
exported extern void				binteger_vinit		( binteger *  dst, ... ) ;
exported extern void fastcall			binteger_ainit		( binteger *  array, size_t  array_size ) ;
exported extern void fastcall			binteger_ainit_cells	( binteger *  array, size_t  array_size, bn_usize_t   cellcount ) ;
exported extern void fastcall			binteger_ainit_bytes	( binteger *  array, size_t  array_size, bn_usize_t   bytecount ) ;
exported extern void fastcall			binteger_ainit_bits	( binteger *  array, size_t  array_size, bn_bitcnt_t  bitcount ) ;

exported extern void fastcall			binteger_clear		( binteger *  bi ) ;
exported extern void fastcall			binteger_vclear		( binteger *  bi, ... ) ;

exported extern void fastcall			binteger_set		( binteger *  dst, const binteger *   src ) ;
exported extern void fastcall			binteger_set_uint	( binteger *  dst, unsigned int	      src ) ;
exported extern void fastcall			binteger_set_int	( binteger *  dst, signed int         src ) ;
exported extern void fastcall			binteger_set_ulong	( binteger *  dst, unsigned long int  src ) ;
exported extern void fastcall			binteger_set_long	( binteger *  dst, signed long int    src ) ;

exported extern void fastcall			binteger_abs		( binteger *  dst, const binteger *   src ) ;
exported extern void fastcall			binteger_neg		( binteger *  dst, const binteger *   src ) ;
exported extern void fastcall			binteger_swap		( binteger *  dst, binteger *	      src ) ;

END_C_CALLING_CONVENTION


/*==============================================================================================================

	Macros that need not to be implemented by a function.

  ==============================================================================================================*/

// In-place absolute value of a binteger
# define	binteger_iabs(bi)		{ bi -> size  =  BN_ABS ( bi -> size ) ; }

// In-place negation of a binteger
# define	binteger_ineg(bi)		{ bi -> size = - bi -> size ; }

# endif		// __BIGNUM_H__