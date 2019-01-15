
@{{BLOCK(PlayerVertical)

@=======================================================================
@
@	PlayerVertical, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2019-01-13, 12:22:06
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global PlayerVerticalTiles		@ 128 unsigned chars
PlayerVerticalTiles:
	.word 0x00000000,0x60000000,0x10000000,0x56000000,0x11200000,0x66600000,0x11660000,0x51110000
	.word 0x00000005,0x00000001,0x00000056,0x00000111,0x00000564,0x00001111,0x00006661,0x00003166
	.word 0x6653A880,0x11777888,0x11777BBB,0x11777CCC,0x11777DD0,0x11777EE0,0x11777FF0,0x00000F00
	.word 0x08894421,0x88877711,0xBBB77711,0xCCC77711,0x0DD77711,0x0EE77711,0x0FF77711,0x00F00000

	.section .rodata
	.align	2
	.global PlayerVerticalPal		@ 32 unsigned chars
PlayerVerticalPal:
	.hword 0x0000,0x0000,0x0003,0x0005,0x0007,0x042C,0x042E,0x0850
	.hword 0x18C6,0x10D3,0x10F5,0x18DA,0x1D5D,0x21BE,0x263E,0x2ABD

@}}BLOCK(PlayerVertical)
