/*==============================================================================================================

	Jump table destination for data size = 013.

  ==============================================================================================================*/

SVCopy_013 :	; Copy 3 DWORD + 1 BYTE
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 )
		COPY (  AL, 12 )
		JUMPRETURN

SVCopy_013_1 :	; Copy 3 DWORD + 1 BYTE (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY (  AX, 11 )
		JUMPRETURN

SVCopy_013_2 :	; Copy 3 DWORD + 1 BYTE (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY (  AX, 10 )
		COPY (  AL, 12 )
		JUMPRETURN

SVCopy_013_3 :	; Copy 3 DWORD + 1 BYTE (misaligned by 3)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		JUMPRETURN