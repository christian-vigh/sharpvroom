/*==============================================================================================================

	Jump table destination for data size = 023.

  ==============================================================================================================*/

SVCopy_023 :	; Copy 4 DWORD + 1 WORD + 1 BYTE
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY ( EAX, 16 )
		COPY (  AX, 20 )
		COPY (  AL, 22 )
		JUMPRETURN

SVCopy_023_1 :	; Copy 4 DWORD + 1 WORD + 1 BYTE (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		COPY ( EAX, 15 )
		COPY ( EAX, 19 )
		JUMPRETURN

SVCopy_023_2 :	; Copy 4 DWORD + 1 WORD + 1 BYTE (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY ( EAX, 14 )
		COPY ( EAX, 18 )
		COPY  ( AL, 22 )
		JUMPRETURN

SVCopy_023_3 :	; Copy 4 DWORD + 1 WORD + 1 BYTE (misaligned by 3)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )	
		COPY ( EAX,  9 )
		COPY ( EAX, 13 )
		COPY ( EAX, 17 )
		COPY (  AX, 21 ) 
		JUMPRETURN