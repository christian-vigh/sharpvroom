/*==============================================================================================================

	Jump table destination for data size = 008.

  ==============================================================================================================*/

SVCopy_008 :	; Copy 2 DWORD
		COPY ( EAX, 0 )
		COPY ( EAX, 4 )
		JUMPRETURN

SVCopy_008_1 :	; Copy 2 DWORD (misaligned by 1)
		COPY (  AL, 0 )
		COPY (  AX, 1 )
		COPY ( EAX, 3 )
		COPY (  AL, 7 )
		JUMPRETURN

SVCopy_008_2 :	; Copy 2 DWORD (misaligned by 2)
		COPY (  AX, 0 )
		COPY ( EAX, 2 )
		COPY (  AX, 6 )
		JUMPRETURN

SVCopy_008_3 :	; Copy 2 DWORD (misaligned by 3)
		COPY (  AL, 0 )
		COPY ( EAX, 1 )
		COPY (  AX, 5 )
		COPY (  AL, 7 ) 
		JUMPRETURN