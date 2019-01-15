
@{{BLOCK(PlayerHorizontal)

@=======================================================================
@
@	PlayerHorizontal, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2019-01-15, 21:36:28
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global PlayerHorizontalTiles		@ 128 unsigned chars
PlayerHorizontalTiles:
	.word 0x08BC0000,0x88BCDEF0,0x88BCDEFF,0xA7777770,0x37777770,0x57777770,0x61111110,0x61111110
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000061,0x00002661,0x00061611,0x06151615
	.word 0x11111110,0x21111110,0x47777770,0x47777770,0x97777770,0x88BCDEFF,0x88BCDEF0,0x08BC0000
	.word 0x51614116,0x00516166,0x00015161,0x00000163,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global PlayerHorizontalPal		@ 32 unsigned chars
PlayerHorizontalPal:
	.hword 0x716B,0x0000,0x0003,0x0005,0x0007,0x042C,0x042E,0x0850
	.hword 0x18C6,0x10D3,0x10F5,0x18DA,0x1D5D,0x21BE,0x263E,0x2ABD

@}}BLOCK(PlayerHorizontal)
