#include "P_Audio.h"

void Audio_Init()
{
	//Init the sound library
	mmInitDefaultMem((mm_addr)soundbank_bin);
	//Load module
	mmLoad(MOD_FLATOUTLIES);
}

void Audio_PlayMusic()
{
	//Start playing music in a loop
	mmStart(MOD_FLATOUTLIES, MM_PLAY_LOOP);
	//Set module volume to 512 (range 0...1024) using the function mmSetVolume(...)
	mmSetModuleVolume(1024);
}
