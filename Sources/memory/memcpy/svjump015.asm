/*==============================================================================================================

	Jump table destination for data size = 015.

  ==============================================================================================================*/

SVCopy_015 :	; Copy 3 DWORD + 1 WORD + 1 BYTE
		COPY ( EAX,  0 )
		COPY ( EAX,  4 ) 
		COPY ( EAX,  8 )
		COPY (  AX, 12 )
		COPY (  AL, 14 )
		JUMPRETURN

SVCopy_015_1 :	; Copy 3 DWORD + 1 WORD + 1 BYTE (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		JUMPRETURN

SVCopy_015_2 :	; Copy 3 DWORD + 1 WORD + 1 BYTE (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		COPY (  AL, 14 )
		JUMPRETURN

SVCopy_015_3 :	; Copy 3 DWORD + 1 WORD + 1 BYTE (misaligned by 3)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		COPY (  AX, 13 )
		JUMPRETURN