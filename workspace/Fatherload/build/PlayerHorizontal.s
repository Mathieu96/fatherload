
@{{BLOCK(PlayerHorizontal)

@=======================================================================
@
@	PlayerHorizontal, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2019-01-11, 11:06:53
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global PlayerHorizontalTiles		@ 128 unsigned chars
PlayerHorizontalTiles:
	.word 0x00000E00,0x0000ED00,0x03600D00,0xA88AB000,0xAAAAA900,0xA7754100,0x81111100,0x11111160
	.word 0x00000000,0x00000000,0x00BA0000,0x00CC0009,0x0CCA50AA,0xCCC87038,0xBCA7521C,0x0BA75411
	.word 0x88877760,0x87778560,0x777ACE60,0x77758C40,0x44444550,0x55555449,0x57555540,0x55554500
	.word 0x00955888,0x00066888,0x00006577,0x00006457,0x00003554,0x00006445,0x00000455,0x00000555

	.section .rodata
	.align	2
	.global PlayerHorizontalPal		@ 32 unsigned chars
PlayerHorizontalPal:
	.hword 0x0CC5,0x0441,0x1461,0x18C4,0x10C6,0x14E7,0x2505,0x1D29
	.hword 0x214A,0x3168,0x296C,0x3DCB,0x35AD,0x4E2E,0x5692,0x0000

@}}BLOCK(PlayerHorizontal)
