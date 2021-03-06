/*==============================================================================================================

	Jump table destination for data size = 100.

  ==============================================================================================================*/

SVCopy_100_1 :	; Copy 25 DWORD 
		XMMCOPY ( XMM0,  0 )
		XMMCOPY ( XMM1, 16 )
		XMMCOPY ( XMM2, 32 )
		XMMCOPY ( XMM3, 48 ) 
		XMMCOPY ( XMM4, 64 )
		XMMCOPY ( XMM5, 80 )
		COPY ( EAX, 96 )
		JUMPRETURN

SVCopy_100_2 :	; Copy 25 DWORD 
		COPY (  AL,  0 )
		XMMCOPY ( XMM0,  1 )
		XMMCOPY ( XMM1, 17 )
		XMMCOPY ( XMM2, 33 )
		XMMCOPY ( XMM3, 49 )
		XMMCOPY ( XMM4, 65 )
		XMMCOPY ( XMM5, 81 )
		COPY (  AX, 97 )
		COPY (  AL, 99 )
		JUMPRETURN

SVCopy_100_3 :	; Copy 25 DWORD
		COPY (  AX,  0 )
		XMMCOPY ( XMM0,  2 )
		XMMCOPY ( XMM1, 18 )
		XMMCOPY ( XMM2, 34 )
		XMMCOPY ( XMM3, 50 )
		XMMCOPY ( XMM4, 66 )
		XMMCOPY ( XMM5, 82 )
		COPY (  AX, 98 )
		JUMPRETURN

SVCopy_100_4 :	; Copy 25 DWORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		XMMCOPY ( XMM0,  3 )
		XMMCOPY ( XMM1, 19 )
		XMMCOPY ( XMM2, 35 )
		XMMCOPY ( XMM3, 51 )
		XMMCOPY ( XMM4, 67 )
		XMMCOPY ( XMM5, 83 )
		COPY (  AL, 99 )
		JUMPRETURN

SVCopy_100_5 :	; Copy 25 DWORD 
		COPY ( EAX,  0 )
		XMMCOPY ( XMM0,  4 )
		XMMCOPY ( XMM1, 20 )
		XMMCOPY ( XMM2, 36 )
		XMMCOPY ( XMM3, 52 )
		XMMCOPY ( XMM4, 68 )
		XMMCOPY ( XMM5, 84 )
		JUMPRETURN

SVCopy_100_6 :	; Copy 25 DWORD 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		XMMCOPY ( XMM0,  5 )
		XMMCOPY ( XMM1, 21 )
		XMMCOPY ( XMM2, 37 )
		XMMCOPY ( XMM3, 53 )
		XMMCOPY ( XMM4, 69 )
		COPY ( EAX, 85 )
		COPY ( EAX, 89 )
		COPY ( EAX, 93 )
		COPY (  AX, 97 )
		COPY (  AL, 99 )
		JUMPRETURN

SVCopy_100_7 :	; Copy 25 DWORD 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		XMMCOPY ( XMM0,  6 )
		XMMCOPY ( XMM1, 22 )
		XMMCOPY ( XMM2, 38 )
		XMMCOPY ( XMM3, 54 )
		XMMCOPY ( XMM4, 70 )
		COPY ( EAX, 86 )
		COPY ( EAX, 90 )
		COPY ( EAX, 94 )
		COPY (  AX, 98 )
		JUMPRETURN

SVCopy_100_8 :	; Copy 25 DWORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		XMMCOPY ( XMM0,  7 )
		XMMCOPY ( XMM1, 23 )
		XMMCOPY ( XMM2, 39 )
		XMMCOPY ( XMM3, 55 )
		XMMCOPY ( XMM4, 71 )
		COPY ( EAX, 87 )
		COPY ( EAX, 91 )
		COPY ( EAX, 95 )
		COPY (  AL, 99 )
		JUMPRETURN

SVCopy_100_9 :	; Copy 25 DWORD 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		XMMCOPY ( XMM0,  8 )
		XMMCOPY ( XMM1, 24 )
		XMMCOPY ( XMM2, 40 )
		XMMCOPY ( XMM3, 56 )
		XMMCOPY ( XMM4, 72 )
		COPY ( EAX, 88 )
		COPY ( EAX, 92 )
		COPY ( EAX, 96 )
		JUMPRETURN

SVCopy_100_10 :	; Copy 25 DWORD 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		XMMCOPY ( XMM0,  9 )
		XMMCOPY ( XMM1, 25 )
		XMMCOPY ( XMM2, 41 )
		XMMCOPY ( XMM3, 57 )
		XMMCOPY ( XMM4, 73 )
		COPY ( EAX, 89 )
		COPY ( EAX, 93 )
		COPY (  AX, 97 )
		COPY (  AL, 99 )
		JUMPRETURN

SVCopy_100_11 :	; Copy 25 DWORD 
		COPY (  AX,  0 ) 
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		XMMCOPY ( XMM0, 10 )
		XMMCOPY ( XMM1, 26 ) 
		XMMCOPY ( XMM2, 42 )
		XMMCOPY ( XMM3, 58 )
		XMMCOPY ( XMM4, 74 )
		COPY ( EAX, 90 )
		COPY ( EAX, 94 )
		COPY (  AX, 98 )
		JUMPRETURN

SVCopy_100_12 :	; Copy 25 DWORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		XMMCOPY ( XMM0, 11 )
		XMMCOPY ( XMM1, 27 )
		XMMCOPY ( XMM2, 43 )
		XMMCOPY ( XMM3, 59 )
		XMMCOPY ( XMM4, 75 )
		COPY ( EAX, 91 )
		COPY ( EAX, 95 )
		COPY (  AL, 99 )
		JUMPRETURN

SVCopy_100_13 :	; Copy 25 DWORD 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 )
		XMMCOPY ( XMM0, 12 )
		XMMCOPY ( XMM1, 28 )
		XMMCOPY ( XMM2, 44 )
		XMMCOPY ( XMM3, 60 )
		XMMCOPY ( XMM4, 76 )
		COPY ( EAX, 92 )
		COPY ( EAX, 96 )
		JUMPRETURN

SVCopy_100_14 :	; Copy 25 DWORD 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		XMMCOPY ( XMM0, 13 )
		XMMCOPY ( XMM1, 29 )
		XMMCOPY ( XMM2, 45 )
		XMMCOPY ( XMM3, 61 )
		XMMCOPY ( XMM4, 77 )
		COPY ( EAX, 93 )
		COPY (  AX, 97 )
		COPY (  AL, 99 )
		JUMPRETURN

SVCopy_100_15 :	; Copy 25 DWORD 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		XMMCOPY ( XMM0, 14 ) 
		XMMCOPY ( XMM1, 30 )
		XMMCOPY ( XMM2, 46 )
		XMMCOPY ( XMM3, 62 )
		XMMCOPY ( XMM4, 78 )
		COPY ( EAX, 94 )
		COPY (  AX, 98 )
		JUMPRETURN

SVCopy_100_16 :	; Copy 25 DWORD 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		COPY ( EAX, 11 )
		XMMCOPY ( XMM0, 15 )
		XMMCOPY ( XMM1, 31 )
		XMMCOPY ( XMM2, 47 )
		XMMCOPY ( XMM3, 63 )
		XMMCOPY ( XMM4, 79 )
		COPY ( EAX, 95 )
		COPY (  AL, 99 )
		JUMPRETURN