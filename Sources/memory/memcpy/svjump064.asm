/*==============================================================================================================

	Jump table destination for data size = 064.

  ==============================================================================================================*/

SVCopy_064_1 :	; Copy 16 DWORD 
		XMMCOPY ( XMM0,  0 )
		XMMCOPY ( XMM1, 16 )
		XMMCOPY ( XMM2, 32 )
		XMMCOPY ( XMM3, 48 ) 
		JUMPRETURN

SVCopy_064_2 :	; Copy 16 DWORD 
		COPY (  AL,  0 )
		XMMCOPY ( XMM0,  1 )
		XMMCOPY ( XMM1, 17 )
		XMMCOPY ( XMM2, 33 )
		COPY ( EAX, 49 )
		COPY ( EAX, 53 )
		COPY ( EAX, 57 )
		COPY (  AX, 61 )
		COPY (  AL, 63 )
		JUMPRETURN

SVCopy_064_3 :	; Copy 16 DWORD
		COPY (  AX,  0 )
		XMMCOPY ( XMM0,  2 )
		XMMCOPY ( XMM1, 18 )
		XMMCOPY ( XMM2, 34 )
		COPY ( EAX, 50 )
		COPY ( EAX, 54 )
		COPY ( EAX, 58 )
		COPY (  AX, 62 )
		JUMPRETURN

SVCopy_064_4 :	; Copy 16 DWORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		XMMCOPY ( XMM0,  3 )
		XMMCOPY ( XMM1, 19 )
		XMMCOPY ( XMM2, 35 )
		COPY ( EAX, 51 )
		COPY ( EAX, 55 )
		COPY ( EAX, 59 )
		COPY (  AL, 63 )
		JUMPRETURN

SVCopy_064_5 :	; Copy 16 DWORD 
		COPY ( EAX,  0 )
		XMMCOPY ( XMM0,  4 )
		XMMCOPY ( XMM1, 20 )
		XMMCOPY ( XMM2, 36 )
		COPY ( EAX, 52 )	
		COPY ( EAX, 56 )
		COPY ( EAX, 60 )
		JUMPRETURN

SVCopy_064_6 :	; Copy 16 DWORD 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		XMMCOPY ( XMM0,  5 )
		XMMCOPY ( XMM1, 21 )
		XMMCOPY ( XMM2, 37 )
		COPY ( EAX, 53 )
		COPY ( EAX, 57 )
		COPY (  AX, 61 )
		COPY (  AL, 63 )
		JUMPRETURN

SVCopy_064_7 :	; Copy 16 DWORD 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		XMMCOPY ( XMM0,  6 )
		XMMCOPY ( XMM1, 22 )
		XMMCOPY ( XMM2, 38 )
		COPY ( EAX, 54 )
		COPY ( EAX, 58 )
		COPY (  AX, 62 )
		JUMPRETURN

SVCopy_064_8 :	; Copy 16 DWORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		XMMCOPY ( XMM0,  7 )
		XMMCOPY ( XMM1, 23 )
		XMMCOPY ( XMM2, 39 )
		COPY ( EAX, 55 ) 
		COPY ( EAX, 59 )
		COPY (  AL, 63 )
		JUMPRETURN

SVCopy_064_9 :	; Copy 16 DWORD 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		XMMCOPY ( XMM0,  8 )
		XMMCOPY ( XMM1, 24 )
		XMMCOPY ( XMM2, 40 )
		COPY ( EAX, 56 )
		COPY ( EAX, 60 )
		JUMPRETURN

SVCopy_064_10 :	; Copy 16 DWORD 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		XMMCOPY ( XMM0,  9 )
		XMMCOPY ( XMM1, 25 )
		XMMCOPY ( XMM2, 41 )
		COPY ( EAX, 57 )
		COPY (  AX, 61 )
		COPY (  AL, 63 )
		JUMPRETURN

SVCopy_064_11 :	; Copy 16 DWORD 
		COPY (  AX,  0 ) 
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		XMMCOPY ( XMM0, 10 )
		XMMCOPY ( XMM1, 26 ) 
		XMMCOPY ( XMM2, 42 )
		COPY ( EAX, 58 )
		COPY (  AX, 62 )
		JUMPRETURN

SVCopy_064_12 :	; Copy 16 DWORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		XMMCOPY ( XMM0, 11 )
		XMMCOPY ( XMM1, 27 )
		XMMCOPY ( XMM2, 43 )
		COPY ( EAX, 59 )
		COPY (  AL, 63 )
		JUMPRETURN

SVCopy_064_13 :	; Copy 16 DWORD 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 )
		XMMCOPY ( XMM0, 12 )
		XMMCOPY ( XMM1, 28 )
		XMMCOPY ( XMM2, 44 )
		COPY ( EAX, 60 )
		JUMPRETURN

SVCopy_064_14 :	; Copy 16 DWORD 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		XMMCOPY ( XMM0, 13 )
		XMMCOPY ( XMM1, 29 )
		XMMCOPY ( XMM2, 45 )
		COPY (  AX, 61 )
		COPY (  AL, 63 )
		JUMPRETURN

SVCopy_064_15 :	; Copy 16 DWORD 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		XMMCOPY ( XMM0, 14 ) 
		XMMCOPY ( XMM1, 30 )
		XMMCOPY ( XMM2, 46 )
		COPY (  AX, 62 )
		JUMPRETURN

SVCopy_064_16 :	; Copy 16 DWORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		XMMCOPY ( XMM0, 15 )
		XMMCOPY ( XMM1, 31 )
		XMMCOPY ( XMM2, 47 )
		COPY (  AL, 63 )
		JUMPRETURN