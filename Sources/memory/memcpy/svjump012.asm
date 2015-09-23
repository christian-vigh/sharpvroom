/*==============================================================================================================

	Jump table destination for data size = 012.

  ==============================================================================================================*/

SVCopy_012 :	; Copy 3 DWORD
		COPY ( EAX, 0 )
		COPY ( EAX, 4 )
		COPY ( EAX, 8 )
		JUMPRETURN

SVCopy_012_1 :	; Copy 3 DWORD (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY (  AL, 11 )
		JUMPRETURN

SVCopy_012_2 :	; Copy 3 DWORD (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		JUMPRETURN

SVCopy_012_3 :	; Copy 3 DWORD (misaligned by 3)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY (  AX,  9 )
		COPY (  AL, 11 )
		JUMPRETURN