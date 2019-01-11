
@{{BLOCK(diamond)

@=======================================================================
@
@	diamond, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2019-01-06, 20:41:59
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global diamondTiles		@ 128 unsigned chars
diamondTiles:
	.word 0x00000000,0x00000000,0x00000000,0x88D00000,0xECA70000,0xFC960000,0xE2940000,0x23440000
	.word 0x00000000,0x00000000,0x00000000,0x000000AA,0x000089CE,0x000AABDF,0x00099B2D,0x00047515
	.word 0x73660000,0x211A0000,0x58AA0000,0xCC700000,0xAF000000,0x00000000,0x00000000,0x00000000
	.word 0x0000BCB1,0x0000E8CC,0x0000FCBB,0x00000DEE,0x000000FD,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global diamondPal		@ 32 unsigned chars
diamondPal:
	.hword 0x0000,0x296A,0x35CD,0x35EE,0x3A0F,0x420F,0x4251,0x4651
	.hword 0x5293,0x4E93,0x56D5,0x5AD5,0x62F7,0x6F39,0x777B,0x7FBD

@}}BLOCK(diamond)
