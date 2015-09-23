/*==============================================================================================================

	Jump table destination for data size = 004.

  ==============================================================================================================*/

SVCopy_004 :	; Copy 1 DWORD
		COPY ( EAX, 0 )
		JUMPRETURN

SVCopy_004_1 :	; Copy 1 DWORD (misaligned by 1 or 3)
		COPY (  AL, 0 )
		COPY (  AX, 1 )
		COPY (  AL, 3 )
		JUMPRETURN

SVCopy_004_2 :	; Copy 1 DWORD (misaligned by 2)
		COPY (  AX, 0 )
		COPY (  AX, 2 ) ;
		JUMPRETURN