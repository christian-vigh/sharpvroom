/*==============================================================================================================

	Jump table destination for data size = 017.

  ==============================================================================================================*/

SVCopy_017 :	; Copy 4 DWORD + 1 BYTE
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 ) 
		COPY ( EAX, 12 )
		COPY (  AL, 16 )
		JUMPRETURN

SVCopy_017_1 :	; Copy 4 DWORD + 1 BYTE (misaligned by 1)
		COPY (  AL,   0 ) 
		COPY (  AX,   1 )
		COPY ( EAX,   3 )
		COPY ( EAX,   7 )
		COPY ( EAX,  11 )
		COPY (  AX,  15 )
		JUMPRETURN

SVCopy_017_2 :	; Copy 4 DWORD + 1 BYTE (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 ) 
		COPY (  AX, 14 )
		COPY (  AL, 16 )
		JUMPRETURN

SVCopy_017_3 :	; Copy 4 DWORD + 1 BYTE (misaligned by 1)
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 ) 
		COPY ( EAX, 13 )
		JUMPRETURN