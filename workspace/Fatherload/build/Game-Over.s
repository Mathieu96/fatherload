
@{{BLOCK(Game_Over)

@=======================================================================
@
@	Game_Over, 256x192@8, 
@	+ palette 256 entries, not compressed
@	+ 125 tiles (t|f reduced) not compressed
@	+ regular map (flat), not compressed, 32x24 
@	Total size: 512 + 8000 + 1536 = 10048
@
@	Time-stamp: 2019-01-06, 20:41:59
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global Game_OverTiles		@ 8000 unsigned chars
Game_OverTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x15151500,0x15151515,0x15151500,0x15151515
	.word 0x15151500,0x15151515,0x15151500,0x15151515,0x15151500,0x15151515,0x15151500,0x15151515
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151500,0x15151515,0x15151500,0x15151515,0x15151500,0x15151515,0x15151500,0x15151515
	.word 0x15151500,0x15151515,0x15151500,0x15151515,0x15151500,0x15151515,0x15151500,0x15151515

	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x483B1515,0x15151515,0x2D2A0615,0x15151515,0x2A2D2A3B
	.word 0x15151515,0x3B2A2D48,0x15151515,0x15522D42,0x15151515,0x151E2D13,0x15151515,0x15152D22
	.word 0x15151515,0x15151515,0x13221342,0x151C1639,0x2D2D2D2D,0x152D2D2D,0x3B153F32,0x15181F44
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x2D2D1515,0x152D2D2D,0x2D2D1515,0x152D2D2D
	.word 0x15151515,0x15151515,0x15151515,0x13131515,0x15151515,0x2D2D3215,0x15151515,0x2D2D1815
	.word 0x15151515,0x18182D44,0x15151515,0x321F2D50,0x3B151515,0x3B3B2213,0x32151515,0x1515342D

	.word 0x15151515,0x15151515,0x1515153B,0x2D151515,0x15151532,0x2D151515,0x15151518,0x2D151515
	.word 0x1515442D,0x2D151515,0x1515162D,0x2D151515,0x153B1313,0x2D151515,0x151F2D50,0x2D151515
	.word 0x15151515,0x15151515,0x151F2D2D,0x37151515,0x1542222D,0x47151515,0x062D342D,0x221E1515
	.word 0x582D372D,0x2D481515,0x5454152D,0x542A1515,0x2D2F152D,0x2F2D4C4C,0x2D06152D,0x062D3434
	.word 0x15151515,0x15151515,0x152D2D2D,0x2D151515,0x152D2D22,0x2D151515,0x152D2D34,0x2D151515
	.word 0x152D2D37,0x2D151515,0x152D2D15,0x2D151515,0x152D2D15,0x2D151515,0x152D2D15,0x2D151515
	.word 0x15151515,0x15151515,0x2D2D2D2D,0x152D2D2D,0x2D2D2D2D,0x152D2D2D,0x1515152D,0x15151515
	.word 0x1515152D,0x15151515,0x1515152D,0x15151515,0x2D2D2D2D,0x152D2D2D,0x2D2D2D2D,0x152D2D2D

	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x3B151515
	.word 0x15151515,0x48151515,0x15151515,0x42151515,0x15151515,0x13151515,0x15151515,0x22151515
	.word 0x15151515,0x15151515,0x39583B15,0x2F392222,0x2D2D5444,0x2D2D2D2D,0x37392D2A,0x39373B3B
	.word 0x153B2A2D,0x3B151515,0x1515522D,0x15151515,0x15151E2D,0x15151515,0x1515152D,0x15151515
	.word 0x15151515,0x15151515,0x1515151E,0x15522D39,0x15154454,0x15302D1F,0x153B2A2D,0x3F2D223B
	.word 0x15482D2A,0x582D3415,0x15422D52,0x542D4C15,0x15132D3F,0x2D2A1515,0x15222D15,0x2D481515
	.word 0x15151515,0x15151515,0x15151515,0x392D5215,0x15151515,0x1F2D3015,0x15151515,0x3B222D3F
	.word 0x15151515,0x15342D58,0x15151515,0x154C2D54,0x3715154C,0x15152A2D,0x47151547,0x1515482D

	.word 0x15151515,0x15151515,0x2D2D1515,0x2D2D2D2D,0x2D2D1515,0x2D2D2D2D,0x2D2D1515,0x15151515
	.word 0x2D2D1515,0x15151515,0x2D2D1515,0x15151515,0x2D2D1515,0x2D2D2D2D,0x2D2D1515,0x2D2D2D2D
	.word 0x15151515,0x15151515,0x15152D2D,0x2D2D2D15,0x15152D2D,0x2D2D2D15,0x15151515,0x152D2D15
	.word 0x15151515,0x152D2D15,0x15151515,0x152D2D15,0x15152D2D,0x152D2D15,0x15152D2D,0x2D2D2D15
	.word 0x15151515,0x15151515,0x3218222D,0x15151515,0x2D2D2D2D,0x15151532,0x2D341E15,0x15151539
	.word 0x2D1E1515,0x15151522,0x2D1E1515,0x15151513,0x2D341E15,0x1515150B,0x392D2D2D,0x1515153F
	.word 0x15151515,0x151E2D13,0x15151515,0x150E2D18,0x15151515,0x15182D03,0x15151515,0x182D543B
	.word 0x3C151515,0x436A174B,0x24101515,0x5C6B3636,0x36243C15,0x15403324,0x24364B15,0x1515153C

	.word 0x15151515,0x152D2D15,0x15151515,0x152D2D15,0x15151515,0x152D2D15,0x3F151E37,0x152D2D1F
	.word 0x65190963,0x151F222D,0x6201663D,0x15150634,0x3121453C,0x15151515,0x15151515,0x15151515
	.word 0x18151515,0x15154C2D,0x2D441515,0x2D2D2D2D,0x2D161515,0x2D2D2D2D,0x2D133B15,0x1515153F
	.word 0x112D1F15,0x15153C12,0x68293915,0x15153336,0x36311515,0x15153136,0x31364515,0x15453631
	.word 0x15182D06,0x2D151515,0x442D2D2D,0x2D151515,0x162D2D2D,0x2D151515,0x132D3F15,0x2D15153B
	.word 0x2D301515,0x56363660,0x2D521515,0x5F23363D,0x15151515,0x36353636,0x15151515,0x36383636
	.word 0x1815152D,0x15181322,0x1F15152D,0x151F2D2D,0x3B15152D,0x153B2222,0x1515152D,0x15151515
	.word 0x1515152D,0x36363638,0x1515152D,0x3636234A,0x20151510,0x36363523,0x4B15155B,0x36363836

	.word 0x152D2D15,0x2D151515,0x152D2D15,0x2D151515,0x152D2D15,0x2D151515,0x152D2D15,0x2D151515
	.word 0x152D2D15,0x01363636,0x152D2D15,0x01363636,0x15151515,0x15153636,0x15151515,0x15153636
	.word 0x1515152D,0x15151515,0x1515152D,0x15151515,0x1515152D,0x15151515,0x1515152D,0x15151515
	.word 0x01010101,0x152D2D2D,0x01010101,0x152D2D2D,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x13151515,0x15151515,0x42151515,0x15151515,0x48151515,0x15151515,0x3B151515
	.word 0x15151515,0x5B3C1515,0x15151515,0x364F4515,0x15151515,0x3A36243C,0x15151515,0x3C24364B
	.word 0x15151E2D,0x15151515,0x1515522D,0x15151515,0x153B2A2D,0x3B151515,0x37392D2A,0x39373B3B
	.word 0x09435508,0x2D2D6453,0x3D5C5736,0x2F076159,0x383C3C38,0x3C24363A,0x15151515,0x4B36243C

	.word 0x15132D1E,0x221E1515,0x15422D52,0x47151515,0x15482D2A,0x37151515,0x153B2A2D,0x15151515
	.word 0x51360854,0x15151515,0x2636211E,0x15151515,0x36233C15,0x15151540,0x36351515,0x1515155B
	.word 0x223B3B22,0x15151E22,0x2D1F1F2D,0x15151547,0x2D39182D,0x15151537,0x542D2D2A,0x15151515
	.word 0x5C692D03,0x3615153A,0x672E221E,0x36151521,0x23364015,0x3615153C,0x35365B15,0x36151515
	.word 0x2D2D1515,0x15151515,0x2D2D1515,0x15151515,0x2D2D1515,0x15151515,0x2D2D1515,0x15151515
	.word 0x01013636,0x2D010101,0x01013636,0x2D010101,0x15151536,0x15151515,0x15151536,0x15151515
	.word 0x15151515,0x2D2D2D15,0x15151515,0x152D2D15,0x15151515,0x152D2D15,0x15151515,0x152D2D15
	.word 0x36362D2D,0x31430136,0x36362D2D,0x36010136,0x36361515,0x35201515,0x36361515,0x20151515

	.word 0x0E222D2D,0x15151515,0x22225215,0x1515151C,0x2D031515,0x15151518,0x2A151515,0x15151F2D
	.word 0x37151533,0x153F132D,0x15153336,0x150B2D0B,0x15153A36,0x15151515,0x15152336,0x15151515
	.word 0x51364115,0x15151515,0x20361215,0x36151515,0x15362315,0x36151515,0x20361215,0x15151515
	.word 0x0F363115,0x15151515,0x31360515,0x15151515,0x364F3C15,0x15203831,0x4F451515,0x36363636
	.word 0x15151515,0x15151515,0x36363636,0x15151515,0x36363636,0x15151515,0x36361515,0x15151515
	.word 0x36361515,0x45151515,0x36361515,0x1D151515,0x36362140,0x123C1515,0x21233636,0x36211515
	.word 0x21364E15,0x151D3633,0x3C23123C,0x3C12123C,0x15353633,0x21364E15,0x154D3631,0x31361015
	.word 0x36363636,0x36363636,0x36363636,0x36363636,0x15154036,0x36401515,0x15151526,0x2E2D1515

	.word 0x15151515,0x4F153636,0x15151515,0x2B153636,0x15151515,0x10153636,0x15151515,0x15153636
	.word 0x15151545,0x15153636,0x1515151D,0x15153636,0x15153C12,0x15153636,0x18225601,0x15153646
	.word 0x2415154F,0x3636154F,0x364D4D36,0x3636152B,0x36353536,0x36361510,0x31122331,0x36361515
	.word 0x21363621,0x36361515,0x3C23233C,0x36361515,0x15151515,0x36361515,0x15151515,0x36361515
	.word 0x15151515,0x15153636,0x15151515,0x36363636,0x15151515,0x36363636,0x15151515,0x15153636
	.word 0x15151515,0x15153636,0x15151515,0x15153636,0x15151515,0x15153636,0x15151515,0x36363636
	.word 0x15151515,0x15151515,0x36363636,0x15151515,0x36363636,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x36363636,0x2D2D1515

	.word 0x15151515,0x15513641,0x15151515,0x15203612,0x15151515,0x15153623,0x15151515,0x15203612
	.word 0x15151515,0x15513641,0x15151515,0x3C24364B,0x15151515,0x3A36243C,0x15151515,0x364F4515
	.word 0x15151515,0x41365115,0x15151515,0x12364015,0x15151515,0x23361515,0x15151515,0x12362015
	.word 0x15151515,0x41365115,0x15151515,0x4B36243C,0x383C3C38,0x3C24363A,0x36363636,0x15454F36
	.word 0x364D1515,0x1515154F,0x24151515,0x15154D36,0x4B151515,0x15154A36,0x20151515,0x3C3C2323
	.word 0x15151515,0x2121364A,0x15151515,0x3A313638,0x15151515,0x36362415,0x15151515,0x01360515
	.word 0x4D364F15,0x36151515,0x15243638,0x36151515,0x154B364A,0x36151515,0x15202323,0x36151515
	.word 0x15154A36,0x36151515,0x15153836,0x36151515,0x1515154F,0x36151515,0x1515155E,0x1A0B3715

	.word 0x15151536,0x15151515,0x36363636,0x15363636,0x36363636,0x15363636,0x15151536,0x15151515
	.word 0x15151536,0x15151515,0x15151536,0x15151515,0x15151536,0x15151515,0x36026259,0x15363636
	.word 0x36361515,0x20151515,0x36361515,0x35201515,0x36361515,0x36363636,0x36361515,0x23363636
	.word 0x36361515,0x23511515,0x36361515,0x05151515,0x36361515,0x15151515,0x36361515,0x15151515
	.word 0x15151236,0x15151515,0x15150A36,0x15151515,0x1515403A,0x15151515,0x1515150F,0x15151515
	.word 0x15151B23,0x15151515,0x15153136,0x15151515,0x15213624,0x15151515,0x40123638,0x15151515
	.word 0x3C151515,0x36123A5B,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515

	.word 0x1510354F,0x363A1515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151551,0x692D1515,0x15151515,0x2D2D1515,0x15151515,0x2D2D1515,0x15151515,0x2D2D1515
	.word 0x15151515,0x2D2D1515,0x15151515,0x2D2D1515,0x15151515,0x2D2D1515,0x15151515,0x2D2D1515
	.word 0x2D2D0901,0x15154601,0x341E1515,0x1515392D,0x1E151515,0x1515222D,0x1E151515,0x1515132D
	.word 0x341E1515,0x15150B2D,0x2D2D2D2D,0x15153F39,0x222D2D2D,0x1515150E,0x22521515,0x15151C22
	.word 0x15151515,0x36361515,0x15151515,0x15151515,0x32151515,0x54221342,0x2D471515,0x2D2D2D2D
	.word 0x542D1F15,0x1C153B0E,0x1C2D1815,0x15151515,0x2D2D2215,0x2D2D2D2D,0x2D2D2215,0x2D2D2D2D

	.word 0x15151515,0x36363636,0x15151515,0x15151515,0x15153B50,0x2254503B,0x153B2A2D,0x2D2D2D47
	.word 0x152F2D18,0x3B482D22,0x152A2D3F,0x58302D54,0x15222D2D,0x2D2D130E,0x152D2D2D,0x500E3B15
	.word 0x36363636,0x2D2D1515,0x15151515,0x2D2D1515,0x150E4213,0x2D2D2D15,0x152D2D2D,0x2D2D2D15
	.word 0x150B1C15,0x2D2D1515,0x1515154C,0x2D2D1515,0x15442A2D,0x2D2D1515,0x15392D54,0x2D2D1515
	.word 0x15151515,0x5B201515,0x15151515,0x15151515,0x152D2D2D,0x13303715,0x152D2D2D,0x2D2D2D15
	.word 0x15151515,0x151C0B15,0x15151515,0x15151515,0x15151515,0x22390315,0x15151515,0x2D2D2D50
	.word 0x3A23233A,0x1515202B,0x15151515,0x15151515,0x15371822,0x15151515,0x1C222D2D,0x15151515
	.word 0x472D473F,0x15151515,0x542D1E15,0x15151515,0x222D2D2D,0x15151515,0x2D2D2D2D,0x15151515

	.word 0x15151515,0x01232015,0x15151515,0x2D151515,0x163B2D2D,0x2D2D2D13,0x2D0B2D2D,0x2D2D2D2D
	.word 0x37542D2D,0x2D151515,0x150E2D2D,0x2D151515,0x153B2D2D,0x2D151515,0x15152D2D,0x2D151515
	.word 0x1515155A,0x012D2D15,0x1515152D,0x3B0E4215,0x2D2D2D2D,0x15151515,0x2D2D2D2D,0x15151515
	.word 0x1515152D,0x15151515,0x1515152D,0x44151515,0x1515152D,0x18151515,0x1515152D,0x22151515
	.word 0x5C010101,0x15363636,0x282D161E,0x15151515,0x222D3B15,0x15151515,0x472D3715,0x15151515
	.word 0x1E2A2806,0x15151515,0x151E2A28,0x15151515,0x15151C2D,0x15151515,0x1515152D,0x15151515
	.word 0x36361515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515

	.word 0x0A360A15,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x2D2D1515,0x15151515,0x2D2D1515,0x36151515,0x43013636,0x36151515,0x01013636
	.word 0x36151515,0x20151536,0x36151515,0x15151536,0x36151515,0x15151536,0x36151515,0x20151536
	.word 0x03151515,0x1515182D,0x15151515,0x151F2D2A,0x15153331,0x3F132D37,0x15333636,0x0B2D0B15
	.word 0x153A3635,0x15151515,0x15233620,0x15151515,0x15123620,0x4A151515,0x150A3635,0x36211515
	.word 0x442D3915,0x15151515,0x542D1F15,0x15153F32,0x2D161515,0x2D2D2D2D,0x37151515,0x2222280B
	.word 0x15151515,0x15151515,0x23124133,0x153C4E4F,0x36363636,0x3C243636,0x153C0F4F,0x2B36311B

	.word 0x15151515,0x15151515,0x15181F06,0x3B3B3730,0x152D2D2D,0x2D2D2D2D,0x151C162A,0x22130B4C
	.word 0x15151515,0x15151515,0x4F4E3C15,0x0F411223,0x36364A15,0x36363636,0x4B362315,0x0A1B153C
	.word 0x152D2D3F,0x2D2D1515,0x15222D1F,0x2D131515,0x36472D2D,0x2D0B1536,0x363B2F54,0x0B3F1536
	.word 0x36151515,0x15151536,0x36361515,0x36363636,0x36361515,0x36363636,0x36151515,0x15151536
	.word 0x15151515,0x3B522D13,0x15151537,0x150E2D22,0x152D2D2D,0x2D2D2D0B,0x152D2D13,0x13220B1E
	.word 0x15151515,0x15151515,0x26381515,0x38312312,0x36361515,0x23363636,0x1B0A1515,0x364A4015
	.word 0x2D2D3B15,0x15151515,0x2D2D4706,0x15151515,0x2D2D302D,0x15151515,0x2D2D3B34,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x3C363615,0x1515151B,0x0A363615,0x1515154A,0x4F363615

	.word 0x15152D2D,0x2D151515,0x15152D2D,0x13151515,0x15152D2D,0x0B153636,0x15152D2D,0x3F153636
	.word 0x15151515,0x15153636,0x3636121D,0x36363636,0x36363636,0x36363636,0x15151538,0x15153636
	.word 0x1515152D,0x2D151515,0x1515372D,0x15151515,0x5D3E2D2D,0x044F2327,0x0101130B,0x01363636
	.word 0x0F411515,0x361D203C,0x15151536,0x363C1515,0x15151536,0x36381515,0x15151515,0x24271015
	.word 0x1515152D,0x15151515,0x15151515,0x15151515,0x1515152D,0x15151515,0x1515155E,0x15151515
	.word 0x15151527,0x15151515,0x15151523,0x15151515,0x1515154A,0x15151515,0x15151520,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x392D3415,0x15151515,0x2D2A3B15,0x15151503,0x221C1515,0x15150622

	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x2D391515,0x15151534,0x2A2D0315,0x1515153B,0x1C222206,0x15151515
	.word 0x36151515,0x36363636,0x36151515,0x36363636,0x36151515,0x51151536,0x36151515,0x15151536
	.word 0x36151515,0x15151536,0x36151515,0x15151536,0x36151515,0x15151536,0x15151515,0x15151515
	.word 0x15403A36,0x36311515,0x15150F23,0x36231515,0x151B2323,0x36231515,0x15313605,0x363A1515
	.word 0x21362415,0x36211515,0x12363815,0x1D151540,0x360A1515,0x1515150A,0x15151515,0x15151515
	.word 0x1515151B,0x24364015,0x36363636,0x23363636,0x36363636,0x36363636,0x15151545,0x15151515
	.word 0x1540334F,0x31211015,0x36363636,0x36363636,0x23270A38,0x1B1D2423,0x15151515,0x15151515

	.word 0x26364F15,0x15154D5B,0x36120F15,0x45243636,0x0F3C1515,0x3A364F4E,0x15151515,0x36364015
	.word 0x3C382615,0x2336213C,0x36363615,0x49363636,0x120A4D15,0x2D144F23,0x15151515,0x2D181515
	.word 0x36151515,0x15151536,0x36151515,0x15151536,0x36151515,0x15151536,0x36151515,0x15151536
	.word 0x12151515,0x15153836,0x0A153B13,0x36363636,0x4015322D,0x3636120A,0x1515182D,0x15151515
	.word 0x15151515,0x36201515,0x3A051515,0x36363623,0x36364E15,0x36363636,0x51361215,0x363C153C
	.word 0x0F362315,0x364A1015,0x36360A15,0x36263636,0x230A2015,0x363C3512,0x15151515,0x15151515
	.word 0x1515154F,0x0F363615,0x15151523,0x3C363615,0x15151536,0x15363615,0x15151536,0x15363615
	.word 0x15151536,0x15363615,0x15151536,0x1525012D,0x15151536,0x0659012D,0x15151515,0x302D2D2D

	.word 0x15151515,0x15153636,0x15151515,0x15153636,0x15151515,0x15153636,0x15151515,0x15153636
	.word 0x15151515,0x15383612,0x15151515,0x3636015D,0x15151515,0x36125D5A,0x15151515,0x15152D2D
	.word 0x15151515,0x20242745,0x15151515,0x151B3631,0x15151515,0x15153623,0x15151515,0x15153636
	.word 0x15151515,0x15151515,0x15151536,0x15153636,0x15151536,0x15153636,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x2D2D2D2D,0x15032A22,0x2D2D2D2D,0x2F2D2D2D,0x15152D2D,0x282D033B
	.word 0x48151515,0x1515422D,0x15151515,0x1F1F2D0B,0x15151515,0x1313541E,0x15151515,0x2D2D4C15
	.word 0x15151515,0x2D2D1515,0x15151515,0x2D2D1515,0x15151515,0x2D2D1515,0x15151515,0x2D2D1515

	.word 0x15482D42,0x13423215,0x15150B2D,0x2D2D2D47,0x1F151E54,0x3B0E542D,0x1815154C,0x15151C2D
	.word 0x22151515,0x2D2D2D2D,0x22151515,0x2D2D2D2D,0x39151515,0x1515442D,0x1F151515,0x3F32542D
	.word 0x3B505422,0x503B1515,0x2A2D2D2D,0x2D47153B,0x2D181C15,0x2D22152F,0x2D3F1515,0x2D54152A
	.word 0x2D2D2D2D,0x130E1522,0x2D2D2D2D,0x3B15152D,0x15151515,0x15151515,0x1F061515,0x37301518
	.word 0x42132254,0x1515150E,0x2D2D2D2D,0x1515152D,0x1C153B48,0x1515150B,0x154C5830,0x15151515
	.word 0x2A2D2D2D,0x15151544,0x2D54500E,0x15151539,0x2D3F1515,0x1515152D,0x2D1F3B3B,0x15151522
	.word 0x15151515,0x15151515,0x15152D2D,0x15151515,0x15152D2D,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515

	.word 0x15151515,0x182D4415,0x15151515,0x1F2D5015,0x15151515,0x3B22133B,0x15151515,0x15342D32
	.word 0x15151515,0x154C2D18,0x44151515,0x2D2D2D2D,0x16151515,0x2D2D2D2D,0x133B1515,0x15153F2D
	.word 0x15442D18,0x15151515,0x15162D32,0x15151515,0x3B13133B,0x15151515,0x1F2D5015,0x15151515
	.word 0x182D0615,0x15151515,0x2D2D2D2D,0x15151544,0x2D2D2D2D,0x15151516,0x2D3F1515,0x15153B13
	.word 0x15151515,0x2D302D2D,0x15151515,0x22442D2D,0x15151515,0x50152D2D,0x15151515,0x1E152D2D
	.word 0x15151515,0x15152D2D,0x15151515,0x15152D2D,0x15151515,0x15152D2D,0x15151515,0x15152D2D
	.word 0x1515150E,0x15152D2D,0x15153B54,0x15152D2D,0x1515582D,0x15152D2D,0x153F2213,0x15152D2D
	.word 0x150B2D48,0x15152D2D,0x372D3915,0x15152D2D,0x2A2D3715,0x15152D2D,0x2D0B1515,0x15152D2D

	.word 0x39031515,0x03392222,0x2D2D4215,0x2D2D2D2D,0x52132D03,0x13323B3B,0x15522D39,0x32151515
	.word 0x153B2D22,0x3B151515,0x153B2D22,0x3B151515,0x15522D39,0x52151515,0x52132D03,0x13523B3B
	.word 0x15151515,0x15151515,0x15151542,0x15152D2D,0x1515032D,0x15152D2D,0x1515392D,0x15151515
	.word 0x1515222D,0x15151515,0x1515222D,0x15151515,0x1515392D,0x15151515,0x1515032D,0x15151515
	.word 0x15152D2D,0x222D1515,0x15152D2D,0x302D033B,0x2D2D2D2D,0x1E34222D,0x2D2D2D2D,0x48282D2D
	.word 0x15152D2D,0x2D0B4415,0x15152D2D,0x2D1E1515,0x15152D2D,0x2D1E1515,0x15152D2D,0x2D0B0615
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151548,0x15151515,0x15151554,0x15151515,0x15151522,0x15151515,0x15151539,0x15151515

	.word 0x15151515,0x36351515,0x15151515,0x243C1515,0x15151515,0x1B151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x1515153A,0x092D1515,0x15150536,0x01041515,0x15102323,0x23231015,0x1541364B,0x4B364115
	.word 0x21360A15,0x150A3621,0x124F2015,0x15204F12,0x364D1515,0x15154D36,0x36151515,0x15151536
	.word 0x15153536,0x2D2D2D16,0x15153C24,0x280B3715,0x1515151B,0x15151515,0x41331515,0x4E4F2312
	.word 0x36364A15,0x36363636,0x0F4F3621,0x311B153C,0x151B3631,0x40151515,0x36363623,0x36363636
	.word 0x2D2D2D2D,0x2D2D152D,0x162A2222,0x0B4C151C,0x15151515,0x15151515,0x3C15153C,0x12234F4E
	.word 0x4A153C24,0x36363636,0x23152B36,0x153C4B36,0x4F152436,0x4D5B2636,0x0F152336,0x36363612

	.word 0x2D2D2D2D,0x15151547,0x2F542213,0x1515153B,0x15151515,0x15151515,0x15150F41,0x15151515
	.word 0x15153636,0x15363615,0x15150A1B,0x15363615,0x15151515,0x15151515,0x15154524,0x15151515
	.word 0x15152D2D,0x15151515,0x15152D2D,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x2D1F1515,0x153C1211,0x29391515,0x15333668,0x31151515,0x15313636,0x36451515,0x45363131
	.word 0x364E1515,0x1D363321,0x23123C15,0x12123C3C,0x35363315,0x364E1515,0x4D363115,0x36101515
	.word 0x30151515,0x15151F2D,0x52151515,0x1E15392D,0x15151515,0x48151515,0x15151515,0x39151515
	.word 0x15151515,0x15151515,0x1515153C,0x15151515,0x15151521,0x15151515,0x15151531,0x15151515

	.word 0x15152D2D,0x15151515,0x15152A2D,0x15151515,0x15154422,0x15151515,0x1515151F,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x4E363615,0x15152D2D,0x23363615,0x15152D0C,0x36363615,0x15151526,0x26363615,0x15150F36
	.word 0x45363615,0x153C4F23,0x15363615,0x155B364E,0x15363615,0x40231220,0x15363615,0x0A364B15
	.word 0x220D3615,0x15152D2D,0x50363615,0x15152D2D,0x15363615,0x15151515,0x15363615,0x05151515
	.word 0x15363615,0x36411515,0x15363615,0x12360515,0x15363615,0x51363A15,0x15363615,0x3C362315
	.word 0x2D2D4215,0x2D2D2D2D,0x39031515,0x03392222,0x15151515,0x15151515,0x3A23233A,0x15151505
	.word 0x36363636,0x15154136,0x333C3C51,0x15053612,0x15151515,0x153A3633,0x15151515,0x1523363C

	.word 0x15151542,0x15152D2D,0x15151515,0x15152D2D,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15363615,0x15151515,0x15363615,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x36363615,0x15151515,0x36363615,0x15151515,0x15363615,0x15151515,0x15363615
	.word 0x15151515,0x15363615,0x15151515,0x36363615,0x15151515,0x36363615,0x15151515,0x15363615
	.word 0x042C4301,0x222D2D2D,0x01010101,0x1C0B2853,0x36053C15,0x15151527,0x36151515,0x15151523
	.word 0x36053C15,0x15151526,0x35233636,0x15151520,0x27363636,0x1515154B,0x0A451515,0x15154B36
	.word 0x15151537,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515

	.word 0x36151515,0x15151536,0x36151515,0x15151536,0x36151515,0x15151536,0x36151515,0x15151536
	.word 0x36151515,0x15151536,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x36363623,0x36363636,0x1545363A,0x15151515,0x334F3621,0x10151540,0x36361D15,0x36363636
	.word 0x0A381515,0x24232327,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15153636,0x4F4E0F3C,0x15151515,0x40151515,0x26153121,0x213C3C38,0x36153636,0x36363636
	.word 0x4D151B1D,0x4F23120A,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15153A36,0x15151515,0x15153636,0x15151515,0x15152336,0x15151515,0x15154A36,0x15363615
	.word 0x15153C2B,0x15363615,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515

	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x3C151515,0x15151515,0x21151515
	.word 0x15151515,0x3A151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x36363645,0x36363636,0x3636361D,0x36363636,0x15403612,0x40151515,0x15152636,0x15151515
	.word 0x15155136,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15154536,0x15151515,0x15151D36,0x15151515,0x153C1236,0x15151515,0x15213626,0x15363615
	.word 0x153A3651,0x15243620,0x15151515,0x1545234B,0x15151515,0x1515213A,0x15151515,0x15151515
	.word 0x15363615,0x363A1515,0x15363615,0x36381515,0x15363615,0x0A151515,0x15363615,0x10151515
	.word 0x15363615,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515

	.word 0x15363638,0x3C362315,0x15363624,0x51363A15,0x15363636,0x12360515,0x15363623,0x36411515
	.word 0x1536364E,0x05151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x1523363C,0x15151515,0x153A3651,0x513C3C51,0x15053612,0x36363636,0x15154136
	.word 0x3A23233A,0x15151505,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15363615,0x15151515
	.word 0x15363615,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515
	.word 0x15151515,0x15363615,0x15151515,0x15363615,0x15151515,0x15363615,0x15151515,0x36363615
	.word 0x15151515,0x36363615,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515

	.word 0x20151515,0x15154F36,0x20151515,0x15152336,0x0A101515,0x15153A36,0x36363636,0x15153823
	.word 0x0A273636,0x1515151B,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515,0x15151515

	.section .rodata
	.align	2
	.global Game_OverMap		@ 1536 unsigned chars
Game_OverMap:
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

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001
	.hword 0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002
	.hword 0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002
	.hword 0x0401,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003
	.hword 0x0004,0x0005,0x0006,0x0007,0x0008,0x0009,0x000A,0x000B
	.hword 0x000C,0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,0x0004
	.hword 0x0403,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003
	.hword 0x0004,0x0013,0x0014,0x0015,0x0016,0x0017,0x0018,0x0019
	.hword 0x001A,0x001B,0x001C,0x001D,0x001E,0x001F,0x0020,0x0004
	.hword 0x0403,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003
	.hword 0x0004,0x0021,0x0022,0x0023,0x0024,0x0025,0x0026,0x0027
	.hword 0x0028,0x0029,0x002A,0x002B,0x002C,0x002D,0x002E,0x0004
	.hword 0x0403,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003
	.hword 0x0004,0x002F,0x0030,0x0031,0x0032,0x0033,0x0034,0x0035
	.hword 0x0036,0x0037,0x0038,0x0039,0x003A,0x003B,0x003C,0x0004
	.hword 0x0403,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003
	.hword 0x0004,0x0004,0x0004,0x003D,0x003E,0x003F,0x0040,0x0041
	.hword 0x0042,0x0043,0x0044,0x0045,0x0046,0x0004,0x0004,0x0004
	.hword 0x0403,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003
	.hword 0x0004,0x0047,0x0048,0x0049,0x004A,0x004B,0x004C,0x004D
	.hword 0x004E,0x004F,0x0050,0x0051,0x0004,0x0004,0x0052,0x0004
	.hword 0x0403,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003
	.hword 0x0004,0x0053,0x0054,0x0055,0x0056,0x0057,0x0058,0x0059
	.hword 0x0004,0x005A,0x005B,0x005C,0x005D,0x0004,0x005E,0x005F
	.hword 0x0403,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003
	.hword 0x0060,0x0061,0x0062,0x0063,0x0064,0x0065,0x0066,0x0067
	.hword 0x0068,0x0069,0x006A,0x006B,0x006C,0x006D,0x006E,0x006F
	.hword 0x0403,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003
	.hword 0x0004,0x0070,0x0071,0x0072,0x0073,0x0074,0x0075,0x0076
	.hword 0x0004,0x0077,0x0078,0x0079,0x007A,0x007B,0x007C,0x0004
	.hword 0x0403,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0003
	.hword 0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004
	.hword 0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004
	.hword 0x0403,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0801
	.hword 0x0802,0x0802,0x0802,0x0802,0x0802,0x0802,0x0802,0x0802
	.hword 0x0802,0x0802,0x0802,0x0802,0x0802,0x0802,0x0802,0x0802
	.hword 0x0C01,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

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

	.section .rodata
	.align	2
	.global Game_OverPal		@ 512 unsigned chars
Game_OverPal:
	.hword 0x0000,0x001F,0x023F,0x7E3F,0x441F,0x47FF,0x7F7F,0x68DF
	.hword 0x1B5F,0x181F,0x2BFF,0x7D5F,0x6C1F,0x037F,0x7EDF,0x5BFF
	.hword 0x6FFF,0x093F,0x0BFF,0x7C5F,0x3E9F,0x7FFF,0x7DBF,0x235F
	.hword 0x7CFF,0x341F,0x007F,0x67FF,0x7F3F,0x37FF,0x7FBF,0x7E7F
	.hword 0x77FF,0x4FFF,0x7C3F,0x07FF,0x17FF,0x01DF,0x27FF,0x0FFF
	.hword 0x7C7F,0x501F,0x7CBF,0x3FFF,0x141F,0x7C1F,0x241F,0x7DFF
	.hword 0x7D3F,0x1FFF,0x7E9F,0x53FF,0x7D9F,0x33FF,0x03FF,0x7EFF
	.hword 0x5FFF,0x7CDF,0x1BFF,0x7FDF,0x7BFF,0x00DF,0x5C1F,0x7F9F

	.hword 0x73FF,0x23FF,0x7D1F,0x041F,0x7F5F,0x6BFF,0x029F,0x7D7F
	.hword 0x7E5F,0x2C5F,0x2FFF,0x4BFF,0x7F1F,0x63FF,0x3BFF,0x13FF
	.hword 0x7DDF,0x57FF,0x7EBF,0x3C1F,0x7C9F,0x049F,0x4C1F,0x03BF
	.hword 0x7E1F,0x003F,0x701F,0x43FF,0x021F,0x281F,0x401F,0x201F
	.hword 0x027F,0x103F,0x009F,0x081F,0x741F,0x641F,0x005F,0x039F
	.hword 0x02BF,0x541F,0x089F,0x03DF,0x0000,0x0000,0x0000,0x0000
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
