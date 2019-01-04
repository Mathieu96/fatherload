
@{{BLOCK(amazonite)

@=======================================================================
@
@	amazonite, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2019-01-04, 19:29:09
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global amazoniteTiles		@ 128 unsigned chars
amazoniteTiles:
	.word 0x00000000,0x00000000,0xC0000000,0x88000000,0x88C00000,0xC8880000,0xCC880000,0xEB770000
	.word 0x00000000,0x00000000,0x00000000,0x00000CCD,0x0000ADCC,0x0000ABCC,0x0000BEED,0x0000AFFD
	.word 0xEA530000,0x7A520000,0x75530000,0x53220000,0x61110000,0x44400000,0x00000000,0x00000000
	.word 0x00005AEB,0x00003AD7,0x000033AA,0x00002166,0x00000449,0x00000099,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global amazonitePal		@ 32 unsigned chars
amazonitePal:
	.hword 0x0000,0x2D65,0x3183,0x35A4,0x35A9,0x39E5,0x39C8,0x4203
	.hword 0x4A41,0x39ED,0x4227,0x4626,0x4E62,0x4A46,0x4A68,0x4A49

@}}BLOCK(amazonite)
