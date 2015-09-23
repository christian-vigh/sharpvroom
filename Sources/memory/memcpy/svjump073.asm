/*==============================================================================================================

	Jump table destination for data size = 073.

  ==============================================================================================================*/

SVCopy_073_1 :	; Copy 18 DWORD + 1 BYTE 
		XMMCOPY ( XMM0,  0 )
		XMMCOPY ( XMM1, 16 )
		XMMCOPY ( XMM2, 32 )
		XMMCOPY ( XMM3, 48 ) 
		COPY ( EAX, 64 )
		COPY ( EAX, 68 )
		COPY (  AL, 72 )
		JUMPRETURN

SVCopy_073_2 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AL,  0 )
		XMMCOPY ( XMM0,  1 )
		XMMCOPY ( XMM1, 17 )
		XMMCOPY ( XMM2, 33 )
		XMMCOPY ( XMM3, 49 )
		COPY ( EAX, 65 )
		COPY ( EAX, 69 )
		JUMPRETURN

SVCopy_073_3 :	; Copy 18 DWORD + 1 BYTE
		COPY (  AX,  0 )
		XMMCOPY ( XMM0,  2 )
		XMMCOPY ( XMM1, 18 )
		XMMCOPY ( XMM2, 34 )
		XMMCOPY ( XMM3, 50 )
		COPY ( EAX, 66 )
		COPY (  AX, 70 )
		COPY (  AL, 72 )
		JUMPRETURN

SVCopy_073_4 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		XMMCOPY ( XMM0,  3 )
		XMMCOPY ( XMM1, 19 )
		XMMCOPY ( XMM2, 35 )
		XMMCOPY ( XMM3, 51 )
		COPY ( EAX, 67 )
		COPY (  AX, 71 )
		JUMPRETURN

SVCopy_073_5 :	; Copy 18 DWORD + 1 BYTE 
		COPY ( EAX,  0 )
		XMMCOPY ( XMM0,  4 )
		XMMCOPY ( XMM1, 20 )
		XMMCOPY ( XMM2, 36 )
		XMMCOPY ( XMM3, 52 )
		COPY ( EAX, 68 )
		COPY (  AL, 72 )
		JUMPRETURN

SVCopy_073_6 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		XMMCOPY ( XMM0,  5 )
		XMMCOPY ( XMM1, 21 )
		XMMCOPY ( XMM2, 37 )
		XMMCOPY ( XMM3, 53 )
		COPY ( EAX, 69 )
		JUMPRETURN

SVCopy_073_7 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		XMMCOPY ( XMM0,  6 )
		XMMCOPY ( XMM1, 22 )
		XMMCOPY ( XMM2, 38 )
		XMMCOPY ( XMM3, 54 )
		COPY (  AX, 70 )
		COPY (  AL, 72 )
		JUMPRETURN

SVCopy_073_8 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		XMMCOPY ( XMM0,  7 )
		XMMCOPY ( XMM1, 23 )
		XMMCOPY ( XMM2, 39 )
		XMMCOPY ( XMM3, 55 )
		COPY (  AX, 71 )
		JUMPRETURN

SVCopy_073_9 :	; Copy 18 DWORD + 1 BYTE 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		XMMCOPY ( XMM0,  8 )
		XMMCOPY ( XMM1, 24 )
		XMMCOPY ( XMM2, 40 )
		XMMCOPY ( XMM3, 56 )
		COPY (  AL, 72 )
		JUMPRETURN

SVCopy_073_10 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		XMMCOPY ( XMM0,  9 )
		XMMCOPY ( XMM1, 25 )
		XMMCOPY ( XMM2, 41 )
		XMMCOPY ( XMM3, 57 )
		JUMPRETURN

SVCopy_073_11 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AX,  0 ) 
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		XMMCOPY ( XMM0, 10 )
		XMMCOPY ( XMM1, 26 ) 
		XMMCOPY ( XMM2, 42 )
		COPY ( EAX, 58 )
		COPY ( EAX, 62 )
		COPY ( EAX, 66 )
		COPY (  AX, 70 )
		COPY (  AL, 72 )
		JUMPRETURN

SVCopy_073_12 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		XMMCOPY ( XMM0, 11 )
		XMMCOPY ( XMM1, 27 )
		XMMCOPY ( XMM2, 43 )
		COPY ( EAX, 59 )
		COPY ( EAX, 63 )
		COPY ( EAX, 67 )
		COPY (  AX, 71 )
		JUMPRETURN

SVCopy_073_13 :	; Copy 18 DWORD + 1 BYTE 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 )
		XMMCOPY ( XMM0, 12 )
		XMMCOPY ( XMM1, 28 )
		XMMCOPY ( XMM2, 44 )
		COPY ( EAX, 60 )
		COPY ( EAX, 64 )
		COPY ( EAX, 68 )
		COPY (  AL, 72 )
		JUMPRETURN

SVCopy_073_14 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		XMMCOPY ( XMM0, 13 )
		XMMCOPY ( XMM1, 29 )
		XMMCOPY ( XMM2, 45 )
		COPY ( EAX, 61 )
		COPY ( EAX, 65 )
		COPY ( EAX, 69 )
		JUMPRETURN

SVCopy_073_15 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		XMMCOPY ( XMM0, 14 ) 
		XMMCOPY ( XMM1, 30 )
		XMMCOPY ( XMM2, 46 )
		COPY ( EAX, 62 )
		COPY ( EAX, 66 )
		COPY (  AX, 70 )
		COPY (  AL, 72 )
		JUMPRETURN

SVCopy_073_16 :	; Copy 18 DWORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		XMMCOPY ( XMM0, 15 )
		XMMCOPY ( XMM1, 31 )
		XMMCOPY ( XMM2, 47 )
		COPY ( EAX, 63 )
		COPY ( EAX, 67 )
		COPY (  AX, 71 )
		JUMPRETURN