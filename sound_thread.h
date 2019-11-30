#include <stdbool.h>
#ifndef SOUND_THREAD_H_
#define SOUND_THREAD_H_

typedef struct Sound{
	bool played;
	float freq;
	float incr_freq;
	float seconds;
} Sound;

Sound* init_sound_thread(void);
void make_sound(float freq, float incr_freq, float seconds);
void exit_sound_thread(Sound* s);

#endif
