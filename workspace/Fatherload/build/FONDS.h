
//{{BLOCK(FONDS)

//======================================================================
//
//	FONDS, 512x512@8, 
//	+ palette 256 entries, not compressed
//	+ 1072 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 64x64 
//	Total size: 512 + 68608 + 8192 = 77312
//
//	Time-stamp: 2019-01-16, 05:01:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FONDS_H
#define GRIT_FONDS_H

#define FONDSTilesLen 68608
extern const unsigned int FONDSTiles[17152];

#define FONDSMapLen 8192
extern const unsigned short FONDSMap[4096];

#define FONDSPalLen 512
extern const unsigned short FONDSPal[256];

#endif // GRIT_FONDS_H

//}}BLOCK(FONDS)
