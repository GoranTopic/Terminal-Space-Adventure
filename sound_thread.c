		al_check_error("alGetSourcei AL_SOURCE_STATE");
		pthread_t sound_thread;
		pthread_t sound_thread;
				return al_error;
		//alGenSources(1, &src);
		if(AL_NO_ERROR != al_error) {
		ALenum errorCode = 0;
		}
		}
		}
		}
		const char * defname = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
		al_check_error("populating alBufferData");
#endif
		openal_output_device  = alcOpenDevice(defname);
		float seconds = 0.5;
ALCdevice  * openal_output_device;
		// float freq = 440.f;
void make_sound(float freq, float incr_freq, float seconds){
		al_check_error("failed call to alGenBuffers");
#include <stdbool.h>
				printf("ERROR - %s  (%s)\n", alGetString(al_error), given_label);
				freq += incr_freq;
		pthread_create(&sound_thread, NULL, MM_render_one_buffer, NULL);
		pthread_create(&sound_thread, NULL, MM_render_one_buffer, NULL);
}   //MM_render_one_buffer
				samples[i] = 32760 * sin( (2.f * my_pi * freq)/sample_rate * i );
		//alSourcePlay(src);
		errorCode = alGetError();
		errorCode = alGetError();
#ifdef __APPLE__
void MM_exit_al() {
		size_t buf_size = seconds * sample_rate;
		alSourceStopv(1, & streaming_source[0]);        //      streaming_source
		alcCloseDevice(openal_output_device);
#include <stdio.h>
#include <AL/alc.h>
		// Stop the sources
ALCcontext * openal_output_context;
		// setup buffer and source
#include "sound_thread.h"
		ALenum current_playing_state;
		ALenum al_error;
		//printf("end of playing\n");
				alGetSourcei(streaming_source[0], AL_SOURCE_STATE, & current_playing_state);
		alcMakeContextCurrent(NULL);
				//freq *= factor_freq;
void exit_sound_thread(Sound* s){
		alGenSources(1, & streaming_source[0]);
				alSourcei(streaming_source[ii], AL_BUFFER, 0);
void MM_render_one_buffer() {
		MM_exit_al();
void MM_init_al() {
		// unsigned sample_rate = 22050;
#include <math.h>
#elif __linux
		/* upload buffer to OpenAL */
		alcDestroyContext(openal_output_context);
		int i=0;
		al_error = alGetError();
		short * samples = malloc(sizeof(short) * buf_size);
#include <OpenAL/alc.h>
		for(; i<buf_size; ++i) {
		alDeleteBuffers(16, &streaming_source[0]);
		ALuint src = 0;
		float incr_freq = 0.2f;
ALuint streaming_source[1];
		//alSourcei(src, AL_BUFFER, internal_buffer);
		//add frequncy to buffer
		for (ii = 0; ii < 1; ++ii) {
		// ---------------------
		/* Set-up sound source and play buffer */
#include <OpenAL/al.h>
#include <stdlib.h>
		// Clean-up
		return 0;
		alSourcei(streaming_source[0], AL_BUFFER, internal_buffer);
Sound* init_sound_thread(void){
		// allocate PCM audio buffer        
		/* Fill buffer with Sine-Wave */
		MM_init_al();
		MM_init_al();
				al_check_error("alGetSourcei AL_SOURCE_STATE");
		alBufferData( internal_buffer, AL_FORMAT_MONO16, samples, buf_size, sample_rate);
		double my_pi = 3.14159;
		alGetSourcei(streaming_source[0], AL_SOURCE_STATE, & current_playing_state);
				//printf("still playing ... so sleep\n");
		float freq = 100.f;
				//incr_freq += incr_freq;
#include <AL/al.h>
		int ii;
		alcMakeContextCurrent(openal_output_context);
		unsigned sample_rate = 44100;
		alGenBuffers(1, & internal_buffer);
		






















































int al_check_error(const char * given_label){
		alSourcePlay(streaming_source[0]);
				//sleep(1);   // should use a thread sleep NOT sleep() for a more responsive finish
		//printf("\nhere is freq %f\n", freq);
}
}
}
}
}
}
ALuint internal_buffer;
		free(samples);
		alDeleteSources(1, &streaming_source[0]);
		openal_output_context = alcCreateContext(openal_output_device, NULL);
		while (AL_PLAYING == current_playing_state) {
