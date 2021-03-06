/*==============================================================================================================

	Jump table destination for data size = 033.

  ==============================================================================================================*/

SVCopy_033 :	; Copy 8 DWORD + 1 BYTE
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY ( EAX, 16 )
		COPY ( EAX, 20 )
		COPY ( EAX, 24 )
		COPY ( EAX, 28 )
		COPY (  AL, 32 )
		JUMPRETURN

SVCopy_033_1 :	; Copy 8 DWORD + 1 BYTE
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		COPY ( EAX, 15 )
		COPY ( EAX, 19 )
		COPY ( EAX, 23 )
		COPY ( EAX, 27 )
		COPY (  AX, 31 )
		JUMPRETURN

SVCopy_033_2 :	; Copy 8 DWORD + 1 BYTE
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY ( EAX, 14 )
		COPY ( EAX, 18 )
		COPY ( EAX, 22 )
		COPY ( EAX, 26 )
		COPY (  AX, 30 )
		COPY (  AL, 32 )
		JUMPRETURN

SVCopy_033_3 :	; Copy 8 DWORD + 1 BYTE
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )	
		COPY ( EAX,  9 )
		COPY ( EAX, 13 )
		COPY ( EAX, 17 )
		COPY ( EAX, 21 ) 
		COPY ( EAX, 25 )
		COPY ( EAX, 29 )
		JUMPRETURN

SVCopy_033_16 :	; Copy 8 DWORD + 1 BYTE
		COPY ( AL, 0 )
		XMMCOPY ( XMM0,  1 )
		XMMCOPY ( XMM1, 17 )
		JUMPRETURN