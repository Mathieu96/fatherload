
@{{BLOCK(Game_Over)

@=======================================================================
@
@	Game_Over, 256x192@8, 
@	+ palette 256 entries, not compressed
@	+ 88 tiles (t|f reduced) not compressed
@	+ regular map (flat), not compressed, 32x24 
@	Total size: 512 + 5632 + 1536 = 7680
@
@	Time-stamp: 2019-01-09, 02:11:26
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global Game_OverTiles		@ 5632 unsigned chars
Game_OverTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x1B130404,0x04040404,0x00140204,0x04040404,0x14001413
	.word 0x04040404,0x1314001B,0x04040404,0x041E000D,0x04040404,0x040C0007,0x04040404,0x0404000E
	.word 0x04040404,0x04040404,0x070E070D,0x04090803,0x00000000,0x04000000,0x13041610,0x04150B19
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x00000404,0x04000000,0x00000404,0x04000000

	.word 0x04040404,0x04040404,0x04040404,0x07070404,0x04040404,0x00001004,0x04040404,0x00001504
	.word 0x04040404,0x15150019,0x04040404,0x100B001D,0x13040404,0x13130E07,0x10040404,0x04041100
	.word 0x04040404,0x04040404,0x04040413,0x00040404,0x04040410,0x00040404,0x04040415,0x00040404
	.word 0x04041900,0x00040404,0x04040800,0x00040404,0x04130707,0x00040404,0x040B001D,0x00040404
	.word 0x04040404,0x04040404,0x040B0000,0x12040404,0x040D0E00,0x1A040404,0x02001100,0x0E0C0404
	.word 0x1F001200,0x001B0404,0x0A0A0400,0x0A140404,0x000F0400,0x0F001C1C,0x00020400,0x02001111
	.word 0x04040404,0x04040404,0x04000000,0x00040404,0x0400000E,0x00040404,0x04000011,0x00040404
	.word 0x04000012,0x00040404,0x04000004,0x00040404,0x04000004,0x00040404,0x04000004,0x00040404

	.word 0x04040404,0x04040404,0x00000000,0x04000000,0x00000000,0x04000000,0x04040400,0x04040404
	.word 0x04040400,0x04040404,0x04040400,0x04040404,0x00000000,0x04000000,0x00000000,0x04000000
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x13040404
	.word 0x04040404,0x1B040404,0x04040404,0x0D040404,0x04040404,0x07040404,0x04040404,0x0E040404
	.word 0x04040404,0x04040404,0x031F1304,0x0F030E0E,0x00000A19,0x00000000,0x12030014,0x03121313
	.word 0x04131400,0x13040404,0x04041E00,0x04040404,0x04040C00,0x04040404,0x04040400,0x04040404
	.word 0x04040404,0x04040404,0x0404040C,0x041E0003,0x0404190A,0x0418000B,0x04131400,0x16000E13
	.word 0x041B0014,0x1F001104,0x040D001E,0x0A001C04,0x04070016,0x00140404,0x040E0004,0x001B0404

	.word 0x04040404,0x04040404,0x04040404,0x03001E04,0x04040404,0x0B001804,0x04040404,0x130E0016
	.word 0x04040404,0x0411001F,0x04040404,0x041C000A,0x1204041C,0x04041400,0x1A04041A,0x04041B00
	.word 0x04040404,0x04040404,0x00000404,0x00000000,0x00000404,0x00000000,0x00000404,0x04040404
	.word 0x00000404,0x04040404,0x00000404,0x04040404,0x00000404,0x00000000,0x00000404,0x00000000
	.word 0x04040404,0x04040404,0x04040000,0x00000004,0x04040000,0x00000004,0x04040404,0x04000004
	.word 0x04040404,0x04000004,0x04040404,0x04000004,0x04040000,0x04000004,0x04040000,0x00000004
	.word 0x04040404,0x04040404,0x10150E00,0x04040404,0x00000000,0x04040410,0x00110C04,0x04040403
	.word 0x000C0404,0x0404040E,0x000C0404,0x04040407,0x00110C04,0x04040405,0x03000000,0x04040416

	.word 0x04040404,0x040C0007,0x04040404,0x04060015,0x04040404,0x04150001,0x04040404,0x15000A13
	.word 0x04040404,0x000A1904,0x04040404,0x1F130404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04000004,0x04040404,0x04000004,0x04040404,0x04000004,0x16040C12,0x0400000B
	.word 0x00000000,0x040B0E00,0x0A000703,0x04040211,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x15040404,0x04041C00,0x00190404,0x00000000,0x00080404,0x00000000,0x00071304,0x04040416
	.word 0x18000B04,0x04040404,0x1E000304,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04150002,0x00040404,0x19000000,0x00040404,0x08000000,0x00040404,0x07001604,0x00040413
	.word 0x00180404,0x0004040B,0x001E0404,0x00040403,0x04040404,0x04040404,0x04040404,0x04040404

	.word 0x15040400,0x0415070E,0x0B040400,0x040B0000,0x13040400,0x04130E0E,0x04040400,0x04040404
	.word 0x04040400,0x04040404,0x04040400,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04000004,0x00040404,0x04000004,0x00040404,0x04000004,0x00040404,0x04000004,0x00040404
	.word 0x04000004,0x00040404,0x04000004,0x00040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040400,0x04040404,0x04040400,0x04040404,0x04040400,0x04040404,0x04040400,0x04040404
	.word 0x00000000,0x04000000,0x00000000,0x04000000,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x07040404,0x04040404,0x0D040404,0x04040404,0x1B040404,0x04040404,0x13040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404

	.word 0x04040C00,0x04040404,0x04041E00,0x04040404,0x04131400,0x13040404,0x12030014,0x03121313
	.word 0x00000A19,0x00000000,0x031F0C04,0x0F030E0E,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x0407000C,0x0E0C0404,0x040D001E,0x1A040404,0x041B0014,0x12040404,0x04131400,0x04040404
	.word 0x0404190A,0x04040404,0x0404040C,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x0E13130E,0x04040C0E,0x000B0B00,0x0404041A,0x00031500,0x04040412,0x0A000014,0x04040404
	.word 0x1F000001,0x04040404,0x16000E0C,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x00000404,0x04040404,0x00000404,0x04040404,0x00000404,0x04040404,0x00000404,0x04040404
	.word 0x00000404,0x00000000,0x00000404,0x00000000,0x04040404,0x04040404,0x04040404,0x04040404

	.word 0x04040404,0x00000004,0x04040404,0x04000004,0x04040404,0x04000004,0x04040404,0x04000004
	.word 0x04040000,0x04000004,0x04040000,0x04000004,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x060E0000,0x04040404,0x0E0E1E04,0x04040409,0x00010404,0x04040415,0x14040404,0x04040B00
	.word 0x12040404,0x04160700,0x04040404,0x04050005,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x00000404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x150E0000,0x04040410

	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x00040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040400,0x17051204
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04010A0E,0x04040404
	.word 0x04040404,0x00000404,0x04040404,0x00000404,0x04040404,0x00000404,0x04040404,0x00000404
	.word 0x04040404,0x00000404,0x04040404,0x00000404,0x04040404,0x00000404,0x04040404,0x00000404

	.word 0x00000000,0x04041000,0x110C0404,0x04040300,0x0C040404,0x04040E00,0x0C040404,0x04040700
	.word 0x110C0404,0x04040500,0x00000000,0x04041603,0x0E000000,0x04040406,0x0E1E0404,0x0404090E
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x10040404,0x0A0E070D,0x001A0404,0x00000000
	.word 0x0A000B04,0x09041306,0x09001504,0x04040404,0x00000E04,0x00000000,0x00000E04,0x00000000
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x0404131D,0x0E0A1D13,0x04131400,0x0000001A
	.word 0x040F0015,0x131B000E,0x04140016,0x1F18000A,0x040E0000,0x00000706,0x04000000,0x1D061304
	.word 0x04040404,0x00000404,0x04040404,0x00000404,0x04060D07,0x00000004,0x04000000,0x00000004
	.word 0x04050904,0x00000404,0x0404041C,0x00000404,0x04191400,0x00000404,0x0403000A,0x00000404

	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04000000,0x07181204,0x04000000,0x00000004
	.word 0x04040404,0x04090504,0x04040404,0x04040404,0x04040404,0x0E030104,0x04040404,0x0000001D
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x0412150E,0x04040404,0x090E0000,0x04040404
	.word 0x1A001A16,0x04040404,0x0A000C04,0x04040404,0x0E000000,0x04040404,0x00000000,0x04040404
	.word 0x04040404,0x00040404,0x04040404,0x00040404,0x08130000,0x00000007,0x00050000,0x00000000
	.word 0x120A0000,0x00040404,0x04060000,0x00040404,0x04130000,0x00040404,0x04040000,0x00040404
	.word 0x04040400,0x00000004,0x04040400,0x13060D04,0x00000000,0x04040404,0x00000000,0x04040404
	.word 0x04040400,0x04040404,0x04040400,0x19040404,0x04040400,0x15040404,0x04040400,0x0E040404

	.word 0x1F000000,0x04040404,0x1700080C,0x04040404,0x0E001304,0x04040404,0x1A001204,0x04040404
	.word 0x0C141702,0x04040404,0x040C1417,0x04040404,0x04040900,0x04040404,0x04040400,0x04040404
	.word 0x04040404,0x00000404,0x04040404,0x00000404,0x04040404,0x00000404,0x04040404,0x00000404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x01040404,0x04041500,0x04040404,0x040B0014,0x04040404,0x16070012,0x04040404,0x05000504
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x19000304,0x04040404,0x0A000B04,0x04041610,0x00080404,0x00000000,0x12040404,0x0E0E1705
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404

	.word 0x04040404,0x04040404,0x04150B02,0x13131218,0x04000000,0x00000000,0x04090814,0x0E07051C
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04000016,0x00000404,0x040E000B,0x00070404,0x041A0000,0x00050404,0x04130F0A,0x05160404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x131E0007,0x04040412,0x0406000E,0x04000000,0x00000005,0x04000007,0x070E050C
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x00001304,0x04040404,0x00001A02,0x04040404,0x00001800,0x04040404,0x00001311,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404

	.word 0x04040000,0x00040404,0x04040000,0x07040404,0x04040000,0x05040404,0x04040000,0x16040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040400,0x00040404,0x04041200,0x04040404,0x00000000,0x00040404,0x00000705,0x00040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040400,0x04040404,0x04040404,0x04040404,0x04040400,0x04040404,0x04040400,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x03001104,0x04040404,0x00141304,0x04040401,0x0E090404,0x0404020E

	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x00030404,0x04040411,0x14000104,0x04040413,0x090E0E02,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x07040404,0x04040404,0x00100404,0x04040404,0x00150404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04041307,0x04040404,0x04041000,0x04040404,0x04041500,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x041D0000,0x04040404,0x020E0000,0x04040404,0x18000000

	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040000,0x04040404,0x04040000,0x04040404,0x04040000
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x00000000,0x0401140E,0x00000000,0x0F000000,0x04040000,0x17000113
	.word 0x1B040404,0x04040D00,0x04040404,0x0B0B0005,0x04040404,0x07070A0C,0x04040404,0x00001C04
	.word 0x04040404,0x00000404,0x04040404,0x00000404,0x04040404,0x00000404,0x04040404,0x00000404
	.word 0x041B000D,0x070D1004,0x04040500,0x0000001A,0x0B040C0A,0x13060A00,0x1504041C,0x04040900
	.word 0x0E040404,0x00000000,0x0E040404,0x00000000,0x03040404,0x04041900,0x0B040404,0x16100A00

	.word 0x131D0A0E,0x1D130404,0x14000000,0x001A0413,0x00150904,0x000E040F,0x00160404,0x000A0414
	.word 0x00000000,0x0706040E,0x00000000,0x13040400,0x04040404,0x04040404,0x0B020404,0x12180415
	.word 0x0D070E0A,0x04040406,0x00000000,0x04040400,0x0904131B,0x04040405,0x041C1F18,0x04040404
	.word 0x14000000,0x04040419,0x000A1D06,0x04040403,0x00160404,0x04040400,0x000B1313,0x0404040E
	.word 0x04040404,0x04040404,0x04040000,0x04040404,0x04040000,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x15001904,0x04040404,0x0B001D04,0x04040404,0x130E0713,0x04040404,0x04110010
	.word 0x04040404,0x041C0015,0x19040404,0x00000000,0x08040404,0x00000000,0x07130404,0x04041600

	.word 0x04190015,0x04040404,0x04080010,0x04040404,0x13070713,0x04040404,0x0B001D04,0x04040404
	.word 0x15000204,0x04040404,0x00000000,0x04040419,0x00000000,0x04040408,0x00160404,0x04041307
	.word 0x04040404,0x00180000,0x04040404,0x0E190000,0x04040404,0x1D040000,0x04040404,0x0C040000
	.word 0x04040404,0x04040000,0x04040404,0x04040000,0x04040404,0x04040000,0x04040404,0x04040000
	.word 0x04040406,0x04040000,0x0404130A,0x04040000,0x04041F00,0x04040000,0x04160E07,0x04040000
	.word 0x0405001B,0x04040000,0x12000304,0x04040000,0x14001204,0x04040000,0x00050404,0x04040000
	.word 0x03010404,0x01030E0E,0x00000D04,0x00000000,0x1E070001,0x07101313,0x041E0003,0x10040404
	.word 0x0413000E,0x13040404,0x0413000E,0x13040404,0x041E0003,0x1E040404,0x1E070001,0x071E1313

	.word 0x04040404,0x04040404,0x0404040D,0x04040000,0x04040100,0x04040000,0x04040300,0x04040404
	.word 0x04040E00,0x04040404,0x04040E00,0x04040404,0x04040300,0x04040404,0x04040100,0x04040404
	.word 0x04040000,0x0E000404,0x04040000,0x18000113,0x00000000,0x0C110E00,0x00000000,0x1B170000
	.word 0x04040000,0x00051904,0x04040000,0x000C0404,0x04040000,0x000C0404,0x04040000,0x00050204
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x0404041B,0x04040404,0x0404040A,0x04040404,0x0404040E,0x04040404,0x04040403,0x04040404
	.word 0x04040404,0x00000404,0x04040404,0x00000404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404

	.word 0x04040404,0x00000008,0x04040404,0x17051204,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x00000000,0x00000400,0x08140E0E,0x051C0409,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x00000000,0x0404041A,0x0F0A0E07,0x04040413,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x000B0404,0x04040418,0x00030404,0x0404041E,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404

	.word 0x18040404,0x04040B00,0x1E040404,0x0C040300,0x04040404,0x1B040404,0x04040404,0x03040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040000,0x04040404,0x04041400,0x04040404,0x0404190E,0x04040404,0x0404040B,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040000,0x04040404,0x04040000,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x0E020404,0x04040000,0x1D040404,0x04040000,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404

	.word 0x00000D04,0x00000000,0x03010404,0x01030E0E,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x0404040D,0x04040000,0x04040404,0x04040000,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x00000000,0x0E000000,0x00000000,0x09051700,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040412,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404
	.word 0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404,0x04040404

	.section .rodata
	.align	2
	.global Game_OverMap		@ 1536 unsigned chars
Game_OverMap:
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008
	.hword 0x0009,0x000A,0x000B,0x000C,0x000D,0x000E,0x000F,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0010,0x0011,0x0012,0x0013,0x0014,0x0015,0x0016
	.hword 0x0017,0x0018,0x0019,0x001A,0x001B,0x001C,0x001D,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x001E,0x001F,0x0001,0x0001,0x001E
	.hword 0x0001,0x0001,0x0020,0x0021,0x0022,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0023,0x0024,0x0025,0x0026,0x0027
	.hword 0x0028,0x0029,0x002A,0x002B,0x002C,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x002D,0x002E,0x002F,0x0030,0x0031
	.hword 0x0032,0x0033,0x0034,0x0035,0x0036,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0037,0x0038,0x0001,0x0001,0x0001,0x0039,0x003A
	.hword 0x0001,0x003B,0x003C,0x0001,0x0001,0x0001,0x003D,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x003E,0x003F,0x0040,0x0041,0x0042,0x0043,0x0044
	.hword 0x0001,0x0045,0x0046,0x0047,0x0048,0x0001,0x0049,0x004A
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x004B,0x004C,0x004D,0x004E,0x044B,0x004F,0x0050
	.hword 0x0051,0x0052,0x0053,0x0054,0x0055,0x0001,0x0056,0x0057
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001
	.hword 0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001,0x0001

	.section .rodata
	.align	2
	.global Game_OverPal		@ 512 unsigned chars
Game_OverPal:
	.hword 0x001F,0x463F,0x6F7F,0x18DF,0x7FFF,0x295F,0x5ADF,0x085F
	.hword 0x35BF,0x673F,0x109F,0x4E7F,0x77BF,0x211F,0x043F,0x3DFF
	.hword 0x529F,0x319F,0x5EFF,0x7BDF,0x14BF,0x1CFF,0x739F,0x0C7F
	.hword 0x253F,0x6B5F,0x2D7F,0x4A5F,0x631F,0x39DF,0x56BF,0x421F
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(Game_Over)
