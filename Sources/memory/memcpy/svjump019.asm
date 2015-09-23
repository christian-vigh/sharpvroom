/*==============================================================================================================

	Jump table destination for data size = 019.

  ==============================================================================================================*/

SVCopy_019 :	; Copy 4 DWORD + 1 WORD + 1 BYTE
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY (  AX, 16 )
		COPY (  AL, 18 )
		JUMPRETURN

SVCopy_019_1 :	; Copy 4 DWORD + 1 WORD + 1 BYTE (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		COPY ( EAX, 15 )
		JUMPRETURN

SVCopy_019_2 :	; Copy 4 DWORD + 1 WORD + 1 BYTE (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY ( EAX, 14 )
		COPY (  AL, 18 )
		JUMPRETURN

SVCopy_019_3 :	; Copy 4 DWORD + 1 WORD + 1 BYTE (misaligned by 3)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		COPY ( EAX, 13 )
		COPY (  AX, 17 )
		JUMPRETURN