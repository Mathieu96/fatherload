
@{{BLOCK(bronze)

@=======================================================================
@
@	bronze, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2019-01-13, 15:16:49
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global bronzeTiles		@ 128 unsigned chars
bronzeTiles:
	.word 0x00000000,0xC8600000,0xEC700000,0xCC840000,0xACC70000,0x7AC83600,0x5AA82660,0x56955630
	.word 0x00000000,0x00000000,0x0000DDEC,0x00CEABBC,0x006A45AA,0x0F877878,0x7EEFC834,0x48EC8425
	.word 0x55669650,0x35665310,0x55531210,0x53231100,0x33221000,0x25210000,0x35200000,0x33000000
	.word 0x44784135,0x05322454,0x03227855,0x00443532,0x00011342,0x00001242,0x00000032,0x00000002

	.section .rodata
	.align	2
	.global bronzePal		@ 32 unsigned chars
bronzePal:
	.hword 0x0000,0x0443,0x0885,0x0CA7,0x14C8,0x10EA,0x150D,0x1D2C
	.hword 0x256E,0x1D70,0x216F,0x25D2,0x2DD2,0x2E14,0x3E55,0x4AB8

@}}BLOCK(bronze)
