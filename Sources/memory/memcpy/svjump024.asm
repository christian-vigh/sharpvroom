/*==============================================================================================================

	Jump table destination for data size = 024.

  ==============================================================================================================*/

SVCopy_024 :	; Copy 6 DWORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY ( EAX, 16 )
		COPY ( EAX, 20 )
		JUMPRETURN

SVCopy_024_1 :	; Copy 6 DWORD
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		COPY ( EAX, 15 )
		COPY ( EAX, 19 )
		COPY (  AL, 23 )
		JUMPRETURN

SVCopy_024_2 :	; Copy 6 DWORD
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY ( EAX, 14 )
		COPY ( EAX, 18 )
		COPY (  AX, 22 )
		JUMPRETURN

SVCopy_024_3 :	; Copy 6 DWORD
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )	
		COPY ( EAX,  9 )
		COPY ( EAX, 13 )
		COPY ( EAX, 17 )
		COPY (  AX, 21 ) 
		COPY (  AL, 23 )
		JUMPRETURN