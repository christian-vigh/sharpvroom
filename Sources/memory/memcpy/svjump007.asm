/*==============================================================================================================

	Jump table destination for data size = 007.

  ==============================================================================================================*/

SVCopy_007 :	; Copy 1 BYTE + 1 WORD + 1 DWORD 
		COPY ( EAX, 0 )
		COPY (  AX, 4 )
		COPY (  AL, 6 ) 
		JUMPRETURN

SVCopy_007_1 :	; Copy 1 BYTE + 1 WORD + 1 DWORD (misaligned by 1)
		COPY (  AL, 0 )
		COPY (  AX, 1 )
		COPY ( EAX, 3 )
		JUMPRETURN

SVCopy_007_2 :	; Copy 1 BYTE + 1 WORD + 1 DWORD (misaligned by 2)
		COPY (  AX, 0 )
		COPY ( EAX, 2 )
		COPY (  AL, 6 )
		JUMPRETURN

SVCopy_007_3 :	; Copy 1 BYTE + 1 WORD + 1 DWORD (misaligned by 3)
		COPY (  AL, 0 )
		COPY ( EAX, 1 )
		COPY (  AX, 5 )
		JUMPRETURN