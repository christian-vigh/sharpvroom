/*==============================================================================================================

	Jump table destination for data size = 051.

  ==============================================================================================================*/

SVCopy_051_1 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY ( EAX,  0 )
		XMMCOPY ( XMM0,  4 )
		XMMCOPY ( XMM1, 20 )
		COPY ( EAX, 36 )
		COPY ( EAX, 40 )
		COPY ( EAX, 44 )
		COPY (  AX, 48 )
		COPY (  AL, 50 )
		JUMPRETURN

SVCopy_051_2 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		XMMCOPY ( XMM0,  5 )
		XMMCOPY ( XMM1, 21 )
		COPY ( EAX, 37 )
		COPY ( EAX, 41 )
		COPY ( EAX, 45 )
		COPY (  AX, 49 )
		JUMPRETURN

SVCopy_051_3 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		XMMCOPY ( XMM0,  6 )
		XMMCOPY ( XMM1, 22 )
		COPY ( EAX, 38 )
		COPY ( EAX, 42 )
		COPY ( EAX, 46 )
		COPY (  AL, 50 )
		JUMPRETURN

SVCopy_051_4 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		XMMCOPY ( XMM0,  7 )
		XMMCOPY ( XMM1, 23 )
		COPY ( EAX, 39 )
		COPY ( EAX, 43 )
		COPY ( EAX, 47 )
		JUMPRETURN

SVCopy_051_5 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		XMMCOPY ( XMM0,  8 )
		XMMCOPY ( XMM1, 24 )
		COPY ( EAX, 40 )	
		COPY ( EAX, 44 )
		COPY (  AX, 48 )
		COPY (  AL, 50 )
		JUMPRETURN

SVCopy_051_6 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		XMMCOPY ( XMM0,  9 )
		XMMCOPY ( XMM1, 25 )
		COPY ( EAX, 41 )
		COPY ( EAX, 45 )
		COPY (  AX, 49 )
		JUMPRETURN

SVCopy_051_7 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		XMMCOPY ( XMM0, 10 )
		XMMCOPY ( XMM1, 26 )
		COPY ( EAX, 42 )
		COPY ( EAX, 46 )
		COPY (  AL, 50 )
		JUMPRETURN

SVCopy_051_8 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		XMMCOPY ( XMM0, 11 )
		XMMCOPY ( XMM1, 27 )
		COPY ( EAX, 43 ) 
		COPY ( EAX, 47 )
		JUMPRETURN

SVCopy_051_9 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 )
		XMMCOPY ( XMM0, 12 )
		XMMCOPY ( XMM1, 28 )
		COPY ( EAX, 44 )
		COPY (  AX, 48 )
		COPY (  AL, 50 )
		JUMPRETURN

SVCopy_051_10 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		XMMCOPY ( XMM0, 13 )
		XMMCOPY ( XMM1, 29 )
		COPY ( EAX, 45 )
		COPY (  AX, 49 )
		JUMPRETURN

SVCopy_051_11 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		XMMCOPY ( XMM0, 14 )
		XMMCOPY ( XMM1, 30 )
		COPY ( EAX, 46 )
		COPY (  AL, 50 )
		JUMPRETURN

SVCopy_051_12 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		XMMCOPY ( XMM0, 15 )
		XMMCOPY ( XMM1, 31 )
		COPY ( EAX, 47 )
		JUMPRETURN

SVCopy_051_13 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		XMMCOPY ( XMM0, 0 )
		XMMCOPY ( XMM1, 16 )
		XMMCOPY ( XMM2, 32 )
		COPY (  AX, 48 )
		COPY (  AL, 50 )
		JUMPRETURN

SVCopy_051_14 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AL,  0 )
		XMMCOPY ( XMM0,  1 )
		XMMCOPY ( XMM1, 17 )
		XMMCOPY ( XMM2, 33 )
		COPY (  AX, 49 )
		JUMPRETURN

SVCopy_051_15 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AX,  0 )
		XMMCOPY ( XMM0,  2 ) 
		XMMCOPY ( XMM1, 18 )
		XMMCOPY ( XMM2, 34 )
		COPY (  AL, 50 )
		JUMPRETURN

SVCopy_051_16 :	; Copy 12 DWORD + 1 WORD + 1 BYTE
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		XMMCOPY ( XMM0,  3 )
		XMMCOPY ( XMM1, 19 )
		XMMCOPY ( XMM2, 35 )
		JUMPRETURN