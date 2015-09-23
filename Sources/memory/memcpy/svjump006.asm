/*==============================================================================================================

	Jump table destination for data size = 006.

  ==============================================================================================================*/

SVCopy_006 :	; Copy 1 WORD + 1 DWORD
		COPY ( EAX, 0 )
		COPY (  AX, 4 )
		JUMPRETURN

SVCopy_006_1 :	; Copy 1 WORD + 1 DWORD (misaligned by 1)
		COPY (  AL, 0 )
		COPY ( EAX, 1 )
		COPY (  AL, 5 )
		JUMPRETURN

SVCopy_006_2 :	; Copy 1 WORD + 1 DWORD (misaligned by 2)
		COPY (  AX, 0 )
		COPY ( EAX, 2 )
		JUMPRETURN

SVCopy_006_3 :	; Copy 1 WORD + 1 DWORD (misaligned by 3)
		COPY (  AL, 0 )
		COPY (  AX, 1 )
		COPY (  AX, 3 )
		COPY (  AL, 5 )
		JUMPRETURN