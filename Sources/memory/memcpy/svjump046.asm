/*==============================================================================================================

	Jump table destination for data size = 046.

  ==============================================================================================================*/

SVCopy_046 :	; Copy 11 DWORD + 1 WORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY ( EAX, 16 )
		COPY ( EAX, 20 )
		COPY ( EAX, 24 )
		COPY ( EAX, 28 )
		COPY ( EAX, 32 )
		COPY ( EAX, 36 )
		COPY ( EAX, 40 )
		COPY  ( AX, 44 )
		JUMPRETURN

SVCopy_046_1 :	; Copy 11 DWORD + 1 WORD
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
		COPY ( EAX, 35 )
		COPY ( EAX, 39 )
		COPY (  AX, 43 )
		COPY (  AL, 45 )
		JUMPRETURN

SVCopy_046_2 :	; Copy 11 DWORD + 1 WORD
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY ( EAX, 14 )
		COPY ( EAX, 18 )
		COPY ( EAX, 22 )
		COPY ( EAX, 26 )
		COPY ( EAX, 30 )
		COPY ( EAX, 34 )
		COPY ( EAX, 38 )
		COPY ( EAX, 42 )
		JUMPRETURN

SVCopy_046_3 :	; Copy 11 DWORD + 1 WORD
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
		COPY ( EAX, 37 )
		COPY ( EAX, 41 )
		COPY (  AL, 45 )
		JUMPRETURN

SVCopy_046_16 :	; Copy 11 DWORD + 1 WORD
		COPY (  AX, 0 )
		COPY ( EAX, 2 )
		COPY ( EAX, 6 )
		COPY ( EAX, 10 )
		XMMCOPY ( XMM0, 14 )
		XMMCOPY ( XMM1, 30 )
		JUMPRETURN