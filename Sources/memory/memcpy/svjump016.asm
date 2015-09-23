/*==============================================================================================================

	Jump table destination for data size = 016.

  ==============================================================================================================*/

SVCopy_016 :	; Copy 4 DWORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 ) 
		COPY ( EAX,  8 )
		COPY ( EAX, 12 )
		JUMPRETURN

SVCopy_016_1 :	; Copy 4 DWORD (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		COPY (  AL, 15 )
		JUMPRETURN

SVCopy_016_2 :	; Copy 4 DWORD (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY (  AX, 14 )
		JUMPRETURN

SVCopy_016_3 :	; Copy 4 DWORD (misaligned by 3)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		COPY (  AX, 13 )
		COPY (  AL, 15 )
		JUMPRETURN