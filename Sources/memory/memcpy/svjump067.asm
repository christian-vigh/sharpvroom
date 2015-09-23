/*==============================================================================================================

	Jump table destination for data size = 067.

  ==============================================================================================================*/

SVCopy_067_1 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		XMMCOPY ( XMM0,  0 )
		XMMCOPY ( XMM1, 16 )
		XMMCOPY ( XMM2, 32 )
		XMMCOPY ( XMM3, 48 ) 
		COPY (  AX, 64 )
		COPY (  AL, 66 )
		JUMPRETURN

SVCopy_067_2 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		XMMCOPY ( XMM0,  1 )
		XMMCOPY ( XMM1, 17 )
		XMMCOPY ( XMM2, 33 )
		XMMCOPY ( XMM3, 49 )
		COPY (  AX, 65 )
		JUMPRETURN

SVCopy_067_3 :	; Copy 16 DWORD + 1 WORD + 1 BYTE
		COPY (  AX,  0 )
		XMMCOPY ( XMM0,  2 )
		XMMCOPY ( XMM1, 18 )
		XMMCOPY ( XMM2, 34 )
		XMMCOPY ( XMM3, 50 )
		COPY (  AL, 66 )
		JUMPRETURN

SVCopy_067_4 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		XMMCOPY ( XMM0,  3 )
		XMMCOPY ( XMM1, 19 )
		XMMCOPY ( XMM2, 35 )
		XMMCOPY ( XMM3, 51 )
		JUMPRETURN

SVCopy_067_5 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY ( EAX,  0 )
		XMMCOPY ( XMM0,  4 )
		XMMCOPY ( XMM1, 20 )
		XMMCOPY ( XMM2, 36 )
		COPY ( EAX, 52 )	
		COPY ( EAX, 56 )
		COPY ( EAX, 60 )
		COPY (  AX, 64 )
		COPY (  AL, 66 )
		JUMPRETURN

SVCopy_067_6 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		XMMCOPY ( XMM0,  5 )
		XMMCOPY ( XMM1, 21 )
		XMMCOPY ( XMM2, 37 )
		COPY ( EAX, 53 )
		COPY ( EAX, 57 )
		COPY ( EAX, 61 )
		COPY (  AX, 65 )
		JUMPRETURN

SVCopy_067_7 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		XMMCOPY ( XMM0,  6 )
		XMMCOPY ( XMM1, 22 )
		XMMCOPY ( XMM2, 38 )
		COPY ( EAX, 54 )
		COPY ( EAX, 58 )
		COPY ( EAX, 62 )
		COPY (  AL, 66 )
		JUMPRETURN

SVCopy_067_8 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		XMMCOPY ( XMM0,  7 )
		XMMCOPY ( XMM1, 23 )
		XMMCOPY ( XMM2, 39 )
		COPY ( EAX, 55 ) 
		COPY ( EAX, 59 )
		COPY ( EAX, 63 )
		JUMPRETURN

SVCopy_067_9 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		XMMCOPY ( XMM0,  8 )
		XMMCOPY ( XMM1, 24 )
		XMMCOPY ( XMM2, 40 )
		COPY ( EAX, 56 )
		COPY ( EAX, 60 )
		COPY (  AX, 64 )
		COPY (  AL, 66 )
		JUMPRETURN

SVCopy_067_10 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		XMMCOPY ( XMM0,  9 )
		XMMCOPY ( XMM1, 25 )
		XMMCOPY ( XMM2, 41 )
		COPY ( EAX, 57 )
		COPY ( EAX, 61 )
		COPY (  AX, 65 )
		JUMPRETURN

SVCopy_067_11 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AX,  0 ) 
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		XMMCOPY ( XMM0, 10 )
		XMMCOPY ( XMM1, 26 ) 
		XMMCOPY ( XMM2, 42 )
		COPY ( EAX, 58 )
		COPY ( EAX, 62 )
		COPY (  AL, 66 )
		JUMPRETURN

SVCopy_067_12 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		XMMCOPY ( XMM0, 11 )
		XMMCOPY ( XMM1, 27 )
		XMMCOPY ( XMM2, 43 )
		COPY ( EAX, 59 )
		COPY ( EAX, 63 )
		JUMPRETURN

SVCopy_067_13 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 )
		XMMCOPY ( XMM0, 12 )
		XMMCOPY ( XMM1, 28 )
		XMMCOPY ( XMM2, 44 )
		COPY ( EAX, 60 )
		COPY (  AX, 64 )
		COPY (  AL, 66 )
		JUMPRETURN

SVCopy_067_14 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		XMMCOPY ( XMM0, 13 )
		XMMCOPY ( XMM1, 29 )
		XMMCOPY ( XMM2, 45 )
		COPY ( EAX, 61 )
		COPY  ( AX, 65 )
		JUMPRETURN

SVCopy_067_15 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		XMMCOPY ( XMM0, 14 ) 
		XMMCOPY ( XMM1, 30 )
		XMMCOPY ( XMM2, 46 )
		COPY ( EAX, 62 )
		COPY (  AL, 66 )
		JUMPRETURN

SVCopy_067_16 :	; Copy 16 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		XMMCOPY ( XMM0, 15 )
		XMMCOPY ( XMM1, 31 )
		XMMCOPY ( XMM2, 47 )
		COPY ( EAX, 63 )
		JUMPRETURN