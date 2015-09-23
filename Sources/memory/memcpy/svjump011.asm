/*==============================================================================================================

	Jump table destination for data size = 011.

  ==============================================================================================================*/

SVCopy_011 :	; Copy 1 BYTE + 1 WORD + 2 DWORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY (  AX,  8 )
		COPY (  AL, 10 )
		JUMPRETURN

SVCopy_011_1 :	; Copy 1 BYTE + 1 WORD + 2 DWORD (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		JUMPRETURN

SVCopy_011_2 :	; Copy 1 BYTE + 1 WORD + 2 DWORD (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY (  AL, 10 )
		JUMPRETURN

SVCopy_011_3 :	; Copy 1 BYTE + 1 WORD + 2 DWORD (misaligned by 3)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY (  AX,  9 )
		JUMPRETURN