/*==============================================================================================================

	Jump table destination for data size = 014.

  ==============================================================================================================*/

SVCopy_014 :	; Copy 3 DWORD + 1 WORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 )
		COPY (  AX, 12 )
		JUMPRETURN

SVCopy_014_1 :	; Copy 3 DWORD + 1 WORD (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY (  AX, 11 )
		COPY (  AL, 13 )
		JUMPRETURN

SVCopy_014_2 :	; Copy 3 DWORD + 1 WORD (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		JUMPRETURN

SVCopy_014_3 :	; Copy 3 DWORD + 1 WORD (misaligned by 3)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		COPY (  AL, 13 )
		JUMPRETURN