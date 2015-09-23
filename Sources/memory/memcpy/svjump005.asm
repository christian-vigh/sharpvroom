/*==============================================================================================================

	Jump table destination for data size = 005.

  ==============================================================================================================*/

SVCopy_005 :	; Copy 1 BYTE + 1 DWORD
		COPY ( EAX, 0 )
		COPY (  AL, 4 ) 
		JUMPRETURN

SVCopy_005_1 :	; Copy 1 BYTE + 1 DWORD (misaligned by 1)
		COPY (  AL, 0 ) 
		COPY ( EAX, 1 )
		JUMPRETURN

SVCopy_005_2 :	; Copy 1 BYTE + 1 DWORD (misaligned by 2)
		COPY (  AX, 0 )
		COPY (  AX, 2 )
		COPY (  AL, 4 ) 
		JUMPRETURN