/*==============================================================================================================

	Jump table destination for data size = 003.

  ==============================================================================================================*/

SVCopy_003 :	; Copy 1 BYTE + 1 WORD
		COPY ( AX, 0 )
		COPY ( AL, 2 )
		JUMPRETURN

SVCopy_003_1 :	; Copy 1 BYTE + 1 WORD
		COPY ( AL, 0 )
		COPY ( AX, 1 )
		JUMPRETURN