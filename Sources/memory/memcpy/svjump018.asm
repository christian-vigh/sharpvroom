/*==============================================================================================================

	Jump table destination for data size = 018.

  ==============================================================================================================*/

SVCopy_018 :	; Copy 4 DWORD + 1 WORD
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY (  AX, 16 )
		JUMPRETURN

SVCopy_018_1 :	; Copy 4 DWORD + 1 WORD (misaligned by 1)
		COPY (  AL,   0 ) 
		COPY (  AX,   1 )
		COPY ( EAX,   3 )
		COPY ( EAX,   7 )
		COPY ( EAX,  11 )
		COPY (  AX,  15 )
		COPY (  AL,  17 )
		JUMPRETURN

SVCopy_018_2 :	; Copy 4 DWORD + 1 WORD (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 ) 
		COPY ( EAX, 14 )
		JUMPRETURN

SVCopy_018_3 :	; Copy 4 DWORD + 1 WORD (misaligned by 1)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 ) 
		COPY ( EAX, 13 )
		COPY (  AL, 17 )
		JUMPRETURN