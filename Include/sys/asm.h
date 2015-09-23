/**************************************************************************************************************

    NAME
        asm.h

    DESCRIPTION
        Definitions for assembly language.

    AUTHOR
        Christian Vigh, 09/2012.

    HISTORY
    [Version : 1.0]    [Date : 2012/09/26]     [Author : CV]
        Initial version.

 **************************************************************************************************************/

# if	! defined ( __ASM_H__ )
#	  define    __ASM_H__

// Macros related to the inline assembler
# define	asm				__asm

// NOP instructions, since the inline assembler do not support DB, DW, etc.
# define	NOP2				asm NOP  asm  NOP		
# define	NOP3				NOP2 asm NOP
# define	NOP4				NOP2 NOP2
# define	NOP5				NOP4 asm NOP
# define	NOP6				NOP4 NOP2
# define	NOP7				NOP6 asm NOP
# define	NOP8				NOP4 NOP4
# define	NOP9				NOP8 asm NOP
# define	NOP10				NOP8 NOP2
# define	NOP11				NOP10 asm NOP
# define	NOP12				NOP10 NOP2
# define	NOP13				NOP12 asm NOP
# define	NOP14				NOP12 NOP2
# define	NOP15				NOP14 asm NOP
# define	NOP16				NOP8 NOP8
# define	NOP32				NOP16 NOP16
# define	NOP64				NOP32 NOP32
# define	NOP128				NOP64 NOP64
# define	NOP256				NOP128 NOP128
# define	NOP512				NOP256 NOP256
# define	NOP1024				NOP512 NOP512

// XMM and MMX types
# define	YMM_REGISTER_SIZE		32
# define	XMM_REGISTER_SIZE		16
# define	MMX_REGISTER_SIZE		8


typedef aligned ( YMM_REGISTER_SIZE ) struct  
   {
	BYTE		bytes [ YMM_REGISTER_SIZE ] ;
    }  ymm_register ;

typedef aligned ( XMM_REGISTER_SIZE ) struct  
   {
	BYTE		bytes [ XMM_REGISTER_SIZE ] ;
    }  xmm_register ;

typedef aligned ( MMX_REGISTER_SIZE ) struct  
   {
	BYTE		bytes [ MMX_REGISTER_SIZE ] ;
    }  mmx_register ;


# endif		// __ASM_H__