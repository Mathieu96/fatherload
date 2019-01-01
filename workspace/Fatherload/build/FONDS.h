
//{{BLOCK(FONDS)

//======================================================================
//
//	FONDS, 512x512@8, 
//	+ palette 256 entries, not compressed
//	+ 1062 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 64x64 
//	Total size: 512 + 67968 + 8192 = 76672
//
//	Time-stamp: 2018-12-12, 20:10:54
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FONDS_H
#define GRIT_FONDS_H

#define FONDSTilesLen 67968
extern const unsigned int FONDSTiles[16992];

#define FONDSMapLen 8192
extern const unsigned short FONDSMap[4096];

#define FONDSPalLen 512
extern const unsigned short FONDSPal[256];

#endif // GRIT_FONDS_H

//}}BLOCK(FONDS)
