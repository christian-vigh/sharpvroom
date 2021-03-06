/*==============================================================================================================

	Jump table destination for data size = 020.

  ==============================================================================================================*/

SVCopy_020 :	; Copy 5 DWORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY ( EAX, 16 )
		JUMPRETURN

SVCopy_020_1 :	; Copy 5 DWORD (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		COPY ( EAX, 15 )
		COPY (  AL, 19 )
		JUMPRETURN

SVCopy_020_2 :	; Copy 5 DWORD (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY ( EAX, 14 )
		COPY (  AX, 18 )
		JUMPRETURN

SVCopy_020_3 :	; Copy 5 DWORD (misaligned by 3)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )	
		COPY ( EAX,  9 )
		COPY ( EAX, 13 )
		COPY (  AX, 17 )
		COPY (  AL, 19 ) 
		JUMPRETURN