
@{{BLOCK(PlayerVertical)

@=======================================================================
@
@	PlayerVertical, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2019-01-11, 12:34:20
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global PlayerVerticalTiles		@ 128 unsigned chars
PlayerVerticalTiles:
	.word 0x00000000,0x00000000,0x00000000,0x60000000,0x50000000,0x89355500,0x87755444,0xA8745554
	.word 0x00000D00,0x0000DCD0,0x000CCCCD,0x00CCC888,0x09BA8777,0x00006965,0x00003218,0x0009A114
	.word 0x88855554,0x88855554,0x88875574,0x88755554,0x7B755554,0x7CE55750,0x5CC75450,0x96345500
	.word 0x000ABC54,0x008BB814,0x038AA114,0x007BA114,0x00DBA114,0xFDDAA114,0xF0D03115,0x00000000

	.section .rodata
	.align	2
	.global PlayerVerticalPal		@ 32 unsigned chars
PlayerVerticalPal:
	.hword 0x716B,0x0441,0x1041,0x18C4,0x10C6,0x14E7,0x2505,0x1D09
	.hword 0x212A,0x3168,0x296B,0x2DAD,0x35AD,0x41EB,0x4230,0x5AB2

@}}BLOCK(PlayerVertical)
