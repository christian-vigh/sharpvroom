/*==============================================================================================================

	Jump table destination for data size = 009.

  ==============================================================================================================*/

SVCopy_009 :	; Copy 1 BYTE + 2 DWORD
		COPY ( EAX, 0 )
		COPY ( EAX, 4 ) 
		COPY (  AL, 8 )
		JUMPRETURN

SVCopy_009_1 :	; Copy 1 BYTE + 2 DWORD (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 ) 
		COPY (  AX,  7 )
		JUMPRETURN

SVCopy_009_2 :	; Copy 1 BYTE + 2 DWORD (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY (  AX,  6 )
		COPY (  AL,  8 )
		JUMPRETURN

SVCopy_009_3 :	; Copy 1 BYTE + 2 DWORD (misaligned by 3)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		JUMPRETURN