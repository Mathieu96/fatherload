#ifndef _P_AUDIO_H
#define _P_AUDIO_H

#include <nds.h>
#include <maxmod9.h>
#include "graphics_main.h"
#include "fatherload_defines.h"
#include "soundbank.h"
#include "soundbank_bin.h"

void Audio_Init();
void Audio_PlaySoundEX(int i);
void Audio_PlayMusic();

#endif
