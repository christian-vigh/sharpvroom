/*==============================================================================================================

	Jump table destination for data size = 062.

  ==============================================================================================================*/

SVCopy_062_1 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		XMMCOPY ( XMM0, 14 )
		XMMCOPY ( XMM1, 30 )
		XMMCOPY ( XMM2, 46 ) 
		JUMPRETURN

SVCopy_062_2 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		XMMCOPY ( XMM0, 15 )
		XMMCOPY ( XMM1, 31 )
		COPY ( EAX, 47 )
		COPY ( EAX, 51 )
		COPY ( EAX, 55 )
		COPY (  AX, 59 )
		COPY (  AL, 61 )
		JUMPRETURN

SVCopy_062_3 :	; Copy 15 DWORD + 1 WORD	
		XMMCOPY ( XMM0,  0 )
		XMMCOPY ( XMM1, 16 )
		XMMCOPY ( XMM2, 32 )
		COPY ( EAX, 48 )
		COPY ( EAX, 52 )
		COPY ( EAX, 56 )
		COPY (  AX, 60 )
		JUMPRETURN

SVCopy_062_4 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AL,  0 )
		XMMCOPY ( XMM0,  1 )
		XMMCOPY ( XMM1, 17 )
		XMMCOPY ( XMM2, 33 )
		COPY ( EAX, 49 )
		COPY ( EAX, 53 )
		COPY ( EAX, 57 )
		COPY (  AL, 61 )
		JUMPRETURN

SVCopy_062_5 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AX,  0 )
		XMMCOPY ( XMM0,  2 )
		XMMCOPY ( XMM1, 18 )
		XMMCOPY ( XMM2, 34 )
		COPY ( EAX, 50 )	
		COPY ( EAX, 54 )
		COPY ( EAX, 58 )
		JUMPRETURN

SVCopy_062_6 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		XMMCOPY ( XMM0,  3 )
		XMMCOPY ( XMM1, 19 )
		XMMCOPY ( XMM2, 35 )
		COPY ( EAX, 51 )
		COPY ( EAX, 55 )
		COPY (  AX, 59 )
		COPY (  AL, 61 )
		JUMPRETURN

SVCopy_062_7 :	; Copy 15 DWORD + 1 WORD 
		COPY ( EAX,  0 )
		XMMCOPY ( XMM0,  4 )
		XMMCOPY ( XMM1, 20 )
		XMMCOPY ( XMM2, 36 )
		COPY ( EAX, 52 )
		COPY ( EAX, 56 )
		COPY (  AX, 60 )
		JUMPRETURN

SVCopy_062_8 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		XMMCOPY ( XMM0,  5 )
		XMMCOPY ( XMM1, 21 )
		XMMCOPY ( XMM2, 37 )
		COPY ( EAX, 53 ) 
		COPY ( EAX, 57 )
		COPY (  AL, 61 )
		JUMPRETURN

SVCopy_062_9 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		XMMCOPY ( XMM0,  6 )
		XMMCOPY ( XMM1, 22 )
		XMMCOPY ( XMM2, 38 )
		COPY ( EAX, 54 )
		COPY ( EAX, 58 )
		JUMPRETURN

SVCopy_062_10 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		XMMCOPY ( XMM0,  7 )
		XMMCOPY ( XMM1, 23 )
		XMMCOPY ( XMM2, 39 )
		COPY ( EAX, 55 )
		COPY (  AX, 59 )
		COPY (  AL, 61 )
		JUMPRETURN

SVCopy_062_11 :	; Copy 15 DWORD + 1 WORD 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		XMMCOPY ( XMM0,  8 )
		XMMCOPY ( XMM1, 24 ) 
		XMMCOPY ( XMM2, 40 )
		COPY ( EAX, 56 )
		COPY (  AX, 60 )
		JUMPRETURN

SVCopy_062_12 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		XMMCOPY ( XMM0,  9 )
		XMMCOPY ( XMM1, 25 )
		XMMCOPY ( XMM2, 41 )
		COPY ( EAX, 57 )
		COPY (  AL, 61 )
		JUMPRETURN

SVCopy_062_13 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		XMMCOPY ( XMM0, 10 )
		XMMCOPY ( XMM1, 26 )
		XMMCOPY ( XMM2, 42 )
		COPY ( EAX, 58 )
		JUMPRETURN

SVCopy_062_14 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		XMMCOPY ( XMM0, 11 )
		XMMCOPY ( XMM1, 27 )
		XMMCOPY ( XMM2, 43 )
		COPY (  AX, 59 )
		COPY (  AL, 61 )
		JUMPRETURN

SVCopy_062_15 :	; Copy 15 DWORD + 1 WORD 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 )
		XMMCOPY ( XMM0, 12 ) 
		XMMCOPY ( XMM1, 28 )
		XMMCOPY ( XMM2, 44 )
		COPY (  AX, 60 )
		JUMPRETURN

SVCopy_062_16 :	; Copy 15 DWORD + 1 WORD 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		XMMCOPY ( XMM0, 13 )
		XMMCOPY ( XMM1, 29 )
		XMMCOPY ( XMM2, 45 )
		COPY (  AL, 61 )
		JUMPRETURN