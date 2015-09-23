/*==============================================================================================================

	Jump table destination for data size = 119.

  ==============================================================================================================*/

SVCopy_119_1 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		XMMCOPY ( XMM0,  0 )
		XMMCOPY ( XMM1, 16 )
		XMMCOPY ( XMM2, 32 )
		XMMCOPY ( XMM3, 48 ) 
		XMMCOPY ( XMM4, 64 )
		XMMCOPY ( XMM5, 80 )
		XMMCOPY ( XMM6, 96 )
		COPY ( EAX, 112 )
		COPY (  AX, 116 )
		COPY (  AL, 118 )
		JUMPRETURN

SVCopy_119_2 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		XMMCOPY ( XMM0,  1 )
		XMMCOPY ( XMM1, 17 )
		XMMCOPY ( XMM2, 33 )
		XMMCOPY ( XMM3, 49 )
		XMMCOPY ( XMM4, 65 )
		XMMCOPY ( XMM5, 81 )
		XMMCOPY ( XMM6, 97 )
		COPY ( EAX, 113 )
		COPY (  AX, 117 )
		JUMPRETURN

SVCopy_119_3 :	; Copy 29 DWORD + 1 WORD + 1 BYTE
		COPY (  AX,  0 )
		XMMCOPY ( XMM0,  2 )
		XMMCOPY ( XMM1, 18 )
		XMMCOPY ( XMM2, 34 )
		XMMCOPY ( XMM3, 50 )
		XMMCOPY ( XMM4, 66 )
		XMMCOPY ( XMM5, 82 )
		XMMCOPY ( XMM6, 98 )
		COPY ( EAX, 114 )
		COPY (  AL, 118 )
		JUMPRETURN

SVCopy_119_4 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		XMMCOPY ( XMM0,  3 )
		XMMCOPY ( XMM1, 19 )
		XMMCOPY ( XMM2, 35 )
		XMMCOPY ( XMM3, 51 )
		XMMCOPY ( XMM4, 67 )
		XMMCOPY ( XMM5, 83 )
		XMMCOPY ( XMM6, 99 )
		COPY ( EAX, 115 )
		JUMPRETURN

SVCopy_119_5 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY ( EAX,  0 )
		XMMCOPY ( XMM0,  4 )
		XMMCOPY ( XMM1, 20 )
		XMMCOPY ( XMM2, 36 )
		XMMCOPY ( XMM3, 52 )
		XMMCOPY ( XMM4, 68 )
		XMMCOPY ( XMM5, 84 )
		XMMCOPY ( XMM6, 100 )
		COPY (  AX, 116 )
		COPY (  AL, 118 )
		JUMPRETURN

SVCopy_119_6 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		XMMCOPY ( XMM0,  5 )
		XMMCOPY ( XMM1, 21 )
		XMMCOPY ( XMM2, 37 )
		XMMCOPY ( XMM3, 53 )
		XMMCOPY ( XMM4, 69 )
		XMMCOPY ( XMM5, 85 )
		XMMCOPY ( XMM6, 101 )
		COPY (  AX, 117 )
		JUMPRETURN

SVCopy_119_7 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		XMMCOPY ( XMM0,  6 )
		XMMCOPY ( XMM1, 22 )
		XMMCOPY ( XMM2, 38 )
		XMMCOPY ( XMM3, 54 )
		XMMCOPY ( XMM4, 70 )
		XMMCOPY ( XMM5, 86 )
		XMMCOPY ( XMM6, 102 )
		COPY (  AL, 118 )
		JUMPRETURN

SVCopy_119_8 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		XMMCOPY ( XMM0,  7 )
		XMMCOPY ( XMM1, 23 )
		XMMCOPY ( XMM2, 39 )
		XMMCOPY ( XMM3, 55 )
		XMMCOPY ( XMM4, 71 )
		XMMCOPY ( XMM5, 87 )
		XMMCOPY ( XMM6, 103 )
		JUMPRETURN

SVCopy_119_9 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		XMMCOPY ( XMM0,  8 )
		XMMCOPY ( XMM1, 24 )
		XMMCOPY ( XMM2, 40 )
		XMMCOPY ( XMM3, 56 )
		XMMCOPY ( XMM4, 72 )
		XMMCOPY ( XMM5, 88 )
		COPY ( EAX, 104 )
		COPY ( EAX, 108 )
		COPY ( EAX, 112 )
		COPY (  AX, 116 )
		COPY (  AL, 118 )
		JUMPRETURN

SVCopy_119_10 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		XMMCOPY ( XMM0,  9 )
		XMMCOPY ( XMM1, 25 )
		XMMCOPY ( XMM2, 41 )
		XMMCOPY ( XMM3, 57 )
		XMMCOPY ( XMM4, 73 )
		XMMCOPY ( XMM5, 89 )
		COPY ( EAX, 105 )
		COPY ( EAX, 109 )
		COPY ( EAX, 113 )
		COPY (  AX, 117 )
		JUMPRETURN

SVCopy_119_11 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY (  AX,  0 ) 
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		XMMCOPY ( XMM0, 10 )
		XMMCOPY ( XMM1, 26 ) 
		XMMCOPY ( XMM2, 42 )
		XMMCOPY ( XMM3, 58 )
		XMMCOPY ( XMM4, 74 )
		XMMCOPY ( XMM5, 90 )
		COPY ( EAX, 106 )
		COPY ( EAX, 110 )
		COPY ( EAX, 114 )
		COPY (  AL, 118 )
		JUMPRETURN

SVCopy_119_12 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY (  AX,  1 )
		COPY ( EAX,  3 )
		COPY ( EAX,  7 )
		XMMCOPY ( XMM0, 11 )
		XMMCOPY ( XMM1, 27 )
		XMMCOPY ( XMM2, 43 )
		XMMCOPY ( XMM3, 59 )
		XMMCOPY ( XMM4, 75 )
		XMMCOPY ( XMM5, 91 )
		COPY ( EAX, 107 )
		COPY ( EAX, 111 )
		COPY ( EAX, 115 )
		JUMPRETURN

SVCopy_119_13 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY ( EAX,  0 )
		COPY ( EAX,  4 )
		COPY ( EAX,  8 )
		XMMCOPY ( XMM0, 12 )
		XMMCOPY ( XMM1, 28 )
		XMMCOPY ( XMM2, 44 )
		XMMCOPY ( XMM3, 60 )
		XMMCOPY ( XMM4, 76 )
		XMMCOPY ( XMM5, 92 )
		COPY ( EAX, 108 )
		COPY ( EAX, 112 )
		COPY (  AX, 116 )
		COPY (  AL, 118 )
		JUMPRETURN

SVCopy_119_14 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY (  AL,  0 )
		COPY ( EAX,  1 )
		COPY ( EAX,  5 )
		COPY ( EAX,  9 )
		XMMCOPY ( XMM0, 13 )
		XMMCOPY ( XMM1, 29 )
		XMMCOPY ( XMM2, 45 )
		XMMCOPY ( XMM3, 61 )
		XMMCOPY ( XMM4, 77 )
		XMMCOPY ( XMM5, 93 )
		COPY ( EAX, 109 )
		COPY ( EAX, 113 )
		COPY (  AX, 117 )
		JUMPRETURN

SVCopy_119_15 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
		COPY (  AX,  0 )
		COPY ( EAX,  2 )
		COPY ( EAX,  6 )
		COPY ( EAX, 10 )
		XMMCOPY ( XMM0, 14 ) 
		XMMCOPY ( XMM1, 30 )
		XMMCOPY ( XMM2, 46 )
		XMMCOPY ( XMM3, 62 )
		XMMCOPY ( XMM4, 78 )
		XMMCOPY ( XMM5, 94 )
		COPY ( EAX, 110 )
		COPY ( EAX, 114 )
		COPY (  AL, 118 )
		JUMPRETURN

SVCopy_119_16 :	; Copy 29 DWORD + 1 WORD + 1 BYTE 
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
		XMMCOPY ( XMM5, 95 )
		COPY ( EAX, 111 )
		COPY ( EAX, 115 )
		JUMPRETURN