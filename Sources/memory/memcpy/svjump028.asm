/*==============================================================================================================

	Jump table destination for data size = 028.

  ==============================================================================================================*/

SVCopy_028 :	; Copy 7 DWORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY ( EAX, 16 )
		COPY ( EAX, 20 )
		COPY ( EAX, 24 )
		JUMPRETURN

SVCopy_028_1 :	; Copy 7 DWORD
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		COPY ( EAX, 15 )
		COPY ( EAX, 19 )
		COPY ( EAX, 23 )
		COPY (  AL, 27 )
		JUMPRETURN

SVCopy_028_2 :	; Copy 7 DWORD
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY ( EAX, 14 )
		COPY ( EAX, 18 )
		COPY ( EAX, 22 )
		COPY (  AX, 26 )
		JUMPRETURN

SVCopy_028_3 :	; Copy 7 DWORD
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )	
		COPY ( EAX,  9 )
		COPY ( EAX, 13 )
		COPY ( EAX, 17 )
		COPY ( EAX, 21 ) 
		COPY (  AX, 25 )
		COPY (  AL, 27 )
		JUMPRETURN