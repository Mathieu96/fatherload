
//{{BLOCK(Game_Over)

//======================================================================
//
//	Game_Over, 256x192@8, 
//	+ palette 256 entries, not compressed
//	+ 125 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x24 
//	Total size: 512 + 8000 + 1536 = 10048
//
//	Time-stamp: 2019-01-06, 20:41:59
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GAME_OVER_H
#define GRIT_GAME_OVER_H

#define Game_OverTilesLen 8000
extern const unsigned int Game_OverTiles[2000];

#define Game_OverMapLen 1536
extern const unsigned short Game_OverMap[768];

#define Game_OverPalLen 512
extern const unsigned short Game_OverPal[256];

#endif // GRIT_GAME_OVER_H

//}}BLOCK(Game_Over)
