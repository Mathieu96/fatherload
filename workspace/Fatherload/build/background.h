
//{{BLOCK(background)

//======================================================================
//
//	background, 512x272@8, 
//	+ palette 256 entries, not compressed
//	+ 1563 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 64x34 
//	Total size: 512 + 100032 + 4352 = 104896
//
//	Time-stamp: 2019-01-11, 14:09:55
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACKGROUND_H
#define GRIT_BACKGROUND_H

#define backgroundTilesLen 100032
extern const unsigned int backgroundTiles[25008];

#define backgroundMapLen 4352
extern const unsigned short backgroundMap[2176];

#define backgroundPalLen 512
extern const unsigned short backgroundPal[256];

#endif // GRIT_BACKGROUND_H

//}}BLOCK(background)
