/*==============================================================================================================

	Jump table destination for data size = 056.

  ==============================================================================================================*/

SVCopy_056_1 :	; Copy 14 DWORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		XMMCOPY ( XMM0,  8 )
		XMMCOPY ( XMM1, 24 )
		XMMCOPY ( XMM2, 40 )	
		JUMPRETURN

SVCopy_056_2 :	; Copy 14 DWORD
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		XMMCOPY ( XMM0,  9 )
		XMMCOPY ( XMM1, 25 )
		COPY ( EAX, 41 )
		COPY ( EAX, 45 )
		COPY ( EAX, 49 )
		COPY (  AX, 53 )
		COPY (  AL, 55 )
		JUMPRETURN

SVCopy_056_3 :	; Copy 14 DWORD
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		XMMCOPY ( XMM0, 10 )
		XMMCOPY ( XMM1, 26 )
		COPY ( EAX, 42 )
		COPY ( EAX, 46 )
		COPY ( EAX, 50 )
		COPY (  AX, 54 )
		JUMPRETURN

SVCopy_056_4 :	; Copy 14 DWORD
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		XMMCOPY ( XMM0, 11 )
		XMMCOPY ( XMM1, 27 )
		COPY ( EAX, 43 )
		COPY ( EAX, 47 )
		COPY ( EAX, 51 )
		COPY (  AL, 55 )
		JUMPRETURN

SVCopy_056_5 :	; Copy 14 DWORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 )
		XMMCOPY ( XMM0, 12 )
		XMMCOPY ( XMM1, 28 )
		COPY ( EAX, 44 )	
		COPY ( EAX, 48 )
		COPY ( EAX, 52 )
		JUMPRETURN

SVCopy_056_6 :	; Copy 14 DWORD
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		XMMCOPY ( XMM0, 13 )
		XMMCOPY ( XMM1, 29 )
		COPY ( EAX, 45 )
		COPY ( EAX, 49 )
		COPY (  AX, 53 )
		COPY (  AL, 55 )
		JUMPRETURN

SVCopy_056_7 :	; Copy 14 DWORD
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		XMMCOPY ( XMM0, 14 )
		XMMCOPY ( XMM1, 30 )
		COPY ( EAX, 46 )
		COPY ( EAX, 50 )
		COPY (  AX, 54 )
		JUMPRETURN

SVCopy_056_8 :	; Copy 14 DWORD
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		XMMCOPY ( XMM0, 15)
		XMMCOPY ( XMM1, 31 )
		COPY ( EAX, 47 ) 
		COPY ( EAX, 51 )
		COPY (  AL, 55 )
		JUMPRETURN

SVCopy_056_9 :	; Copy 14 DWORD
		XMMCOPY ( XMM0,  0 )
		XMMCOPY ( XMM1, 16 )
		XMMCOPY ( XMM2, 32 )
		COPY ( EAX, 48 )
		COPY ( EAX, 52 )
		JUMPRETURN

SVCopy_056_10 :	; Copy 14 DWORD
		COPY (  AL,  0 )
		XMMCOPY ( XMM0,  1 )
		XMMCOPY ( XMM1, 17 )
		XMMCOPY ( XMM2, 33 )
		COPY ( EAX, 49 )
		COPY (  AX, 53 )
		COPY (  AL, 55 )
		JUMPRETURN

SVCopy_056_11 :	; Copy 14 DWORD
		COPY (  AX,  0 )
		XMMCOPY ( XMM0,  2 )
		XMMCOPY ( XMM1, 18 ) 
		XMMCOPY ( XMM2, 34 )
		COPY ( EAX, 50 )
		COPY (  AX, 54 )
		JUMPRETURN

SVCopy_056_12 :	; Copy 14 DWORD
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		XMMCOPY ( XMM0,  3 )
		XMMCOPY ( XMM1, 19 )
		XMMCOPY ( XMM2, 35 )
		COPY ( EAX, 51 )
		COPY (  AL, 55 )
		JUMPRETURN

SVCopy_056_13 :	; Copy 14 DWORD
		COPY ( EAX,  0 )
		XMMCOPY ( XMM0,  4 )
		XMMCOPY ( XMM1, 20 )
		XMMCOPY ( XMM2, 36 )
		COPY ( EAX, 52 )
		JUMPRETURN

SVCopy_056_14 :	; Copy 14 DWORD
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		XMMCOPY ( XMM0,  5 )
		XMMCOPY ( XMM1, 21 )
		XMMCOPY ( XMM2, 37 )
		COPY (  AX, 53 )
		COPY (  AL, 55 )
		JUMPRETURN

SVCopy_056_15 :	; Copy 14 DWORD
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		XMMCOPY ( XMM0,  6 ) 
		XMMCOPY ( XMM1, 22 )
		XMMCOPY ( XMM2, 38 )
		COPY (  AX, 54 )
		JUMPRETURN

SVCopy_056_16 :	; Copy 14 DWORD
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		XMMCOPY ( XMM0,  7 )
		XMMCOPY ( XMM1, 23 )
		XMMCOPY ( XMM2, 39 )
		COPY (  AL, 55 )
		JUMPRETURN