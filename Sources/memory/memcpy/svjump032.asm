/*==============================================================================================================

	Jump table destination for data size = 032.

  ==============================================================================================================*/

SVCopy_032 :	; Copy 8 DWORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY ( EAX, 16 )
		COPY ( EAX, 20 )
		COPY ( EAX, 24 )
		COPY ( EAX, 28 )
		JUMPRETURN

SVCopy_032_1 :	; Copy 8 DWORD
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		COPY ( EAX, 15 )
		COPY ( EAX, 19 )
		COPY ( EAX, 23 )
		COPY ( EAX, 27 )
		COPY (  AL, 31 )
		JUMPRETURN

SVCopy_032_2 :	; Copy 8 DWORD
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY ( EAX, 14 )
		COPY ( EAX, 18 )
		COPY ( EAX, 22 )
		COPY ( EAX, 26 )
		COPY (  AX, 30 )
		JUMPRETURN

SVCopy_032_3 :	; Copy 8 DWORD
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )	
		COPY ( EAX,  9 )
		COPY ( EAX, 13 )
		COPY ( EAX, 17 )
		COPY ( EAX, 21 ) 
		COPY ( EAX, 25 )
		COPY (  AX, 29 )
		COPY (  AL, 31 )
		JUMPRETURN

SVCopy_032_16 :	; Copy 8 DWORD
		XMMCOPY ( XMM0,  0 )
		XMMCOPY ( XMM1, 16 )
		JUMPRETURN