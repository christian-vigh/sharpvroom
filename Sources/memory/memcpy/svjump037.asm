/*==============================================================================================================

	Jump table destination for data size = 037.

  ==============================================================================================================*/

SVCopy_037 :	; Copy 9 DWORD + 1 BYTE
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY ( EAX, 16 )
		COPY ( EAX, 20 )
		COPY ( EAX, 24 )
		COPY ( EAX, 28 )
		COPY ( EAX, 32 )
		COPY (  AL, 36 )
		JUMPRETURN

SVCopy_037_1 :	; Copy 9 DWORD + 1 BYTE
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		COPY ( EAX, 15 )
		COPY ( EAX, 19 )
		COPY ( EAX, 23 )
		COPY ( EAX, 27 )
		COPY ( EAX, 31 )
		COPY (  AX, 35 )
		JUMPRETURN

SVCopy_037_2 :	; Copy 9 DWORD + 1 BYTE
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY ( EAX, 14 )
		COPY ( EAX, 18 )
		COPY ( EAX, 22 )
		COPY ( EAX, 26 )
		COPY ( EAX, 30 )
		COPY (  AX, 34 )
		COPY (  AL, 36 )
		JUMPRETURN

SVCopy_037_3 :	; Copy 9 DWORD + 1 BYTE
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )	
		COPY ( EAX,  9 )
		COPY ( EAX, 13 )
		COPY ( EAX, 17 )
		COPY ( EAX, 21 ) 
		COPY ( EAX, 25 )
		COPY ( EAX, 29 )
		COPY ( EAX, 33 )
		JUMPRETURN

SVCopy_037_16 :	; Copy 9 DWORD + 1 BYTE
		COPY (  AL, 0 )
		COPY ( EAX, 1 )
		XMMCOPY ( XMM0,  5 )
		XMMCOPY ( XMM1, 21 )
		JUMPRETURN