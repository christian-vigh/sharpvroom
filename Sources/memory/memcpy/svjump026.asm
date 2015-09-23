/*==============================================================================================================

	Jump table destination for data size = 026.

  ==============================================================================================================*/

SVCopy_026 :	; Copy 6 DWORD + 1 WORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY ( EAX, 16 )
		COPY ( EAX, 20 )
		COPY (  AX, 24 )
		JUMPRETURN

SVCopy_026_1 :	; Copy 6 DWORD + 1 WORD
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		COPY ( EAX, 15 )
		COPY ( EAX, 19 )
		COPY (  AX, 23 )
		COPY (  AL, 25 )
		JUMPRETURN

SVCopy_026_2 :	; Copy 6 DWORD + 1 WORD
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY ( EAX, 14 )
		COPY ( EAX, 18 )
		COPY ( EAX, 22 )
		JUMPRETURN

SVCopy_026_3 :	; Copy 6 DWORD + 1 WORD
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )	
		COPY ( EAX,  9 )
		COPY ( EAX, 13 )
		COPY ( EAX, 17 )
		COPY ( EAX, 21 ) 
		COPY (  AL, 25 )
		JUMPRETURN