/*==============================================================================================================

	Jump table destination for data size = 010.

  ==============================================================================================================*/

SVCopy_010 :	; Copy 1 WORD + 2 DWORD
		COPY ( EAX, 0 )
		COPY ( EAX, 4 )
		COPY (  AX, 8 )
		JUMPRETURN
		
SVCopy_010_1 :	; Copy 1 WORD + 2 DWORD (misaligned by 1)
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY (  AX,  7 )
		COPY (  AL,  9 )
		JUMPRETURN

SVCopy_010_2 :	; Copy 1 WORD + 2 DWORD (misaligned by 2)
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		JUMPRETURN

SVCopy_010_3 :	; Copy 1 WORD + 2 DWORD (misaligned by 3)
		COPY (  AL, 0 )
		COPY ( EAX, 1 ) 
		COPY ( EAX, 5 )
		COPY (  AL, 9 )
		JUMPRETURN