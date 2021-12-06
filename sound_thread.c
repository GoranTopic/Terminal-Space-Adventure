#include <OpenAL/al.h>
#include <stdio.h>
		while (AL_PLAYING == current_playing_state) {
		return 0;
		al_check_error("failed call to alGenBuffers");
		// allocate PCM audio buffer        
				printf("ERROR - %s  (%s)\n", alGetString(al_error), given_label);
}   //MM_render_one_buffer
ALuint streaming_source[1];
#include <math.h>
		// unsigned sample_rate = 22050;
		alGenSources(1, & streaming_source[0]);
		int i=0;
		ALenum current_playing_state;
		pthread_t sound_thread;
		pthread_t sound_thread;
#ifdef __APPLE__
		size_t buf_size = seconds * sample_rate;
		/* Set-up sound source and play buffer */
#include <AL/alc.h>
		for(; i<buf_size; ++i) {
#include <stdbool.h>
		//add frequncy to buffer
		// Clean-up
		alcMakeContextCurrent(openal_output_context);
		const char * defname = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
		ALenum al_error;
}
}
}
}
}
}
void MM_render_one_buffer() {
		alSourcei(streaming_source[0], AL_BUFFER, internal_buffer);
		}
		}
		}
		}
		// Stop the sources
		short * samples = malloc(sizeof(short) * buf_size);
				return al_error;
		alSourceStopv(1, & streaming_source[0]);        //      streaming_source
		al_error = alGetError();
		free(samples);
ALuint internal_buffer;
#include <stdlib.h>
		//alSourcePlay(src);
		float freq = 100.f;
				samples[i] = 32760 * sin( (2.f * my_pi * freq)/sample_rate * i );
		//alSourcei(src, AL_BUFFER, internal_buffer);
Sound* init_sound_thread(void){
		alBufferData( internal_buffer, AL_FORMAT_MONO16, samples, buf_size, sample_rate);
void MM_init_al() {
		alSourcePlay(streaming_source[0]);
		errorCode = alGetError();
		errorCode = alGetError();
		alDeleteBuffers(16, &streaming_source[0]);
		// ---------------------
		unsigned sample_rate = 44100;
				freq += incr_freq;
		// float freq = 440.f;
		ALenum errorCode = 0;
		alGetSourcei(streaming_source[0], AL_SOURCE_STATE, & current_playing_state);
ALCcontext * openal_output_context;
		openal_output_device  = alcOpenDevice(defname);
		MM_exit_al();
#include <AL/al.h>
		/* upload buffer to OpenAL */
				//freq *= factor_freq;
		int ii;
void MM_exit_al() {
		//printf("end of playing\n");
#endif
				alSourcei(streaming_source[ii], AL_BUFFER, 0);
		float seconds = 0.5;
				al_check_error("alGetSourcei AL_SOURCE_STATE");
				//printf("still playing ... so sleep\n");
		ALuint src = 0;
#include "sound_thread.h"
#elif __linux
		al_check_error("populating alBufferData");
		alDeleteSources(1, &streaming_source[0]);
		openal_output_context = alcCreateContext(openal_output_device, NULL);
		//alGenSources(1, &src);
		for (ii = 0; ii < 1; ++ii) {
void make_sound(float freq, float incr_freq, float seconds){
		if(AL_NO_ERROR != al_error) {
				//incr_freq += incr_freq;
				alGetSourcei(streaming_source[0], AL_SOURCE_STATE, & current_playing_state);
int al_check_error(const char * given_label){
		/* Fill buffer with Sine-Wave */
#include <OpenAL/alc.h>
ALCdevice  * openal_output_device;
		
		float incr_freq = 0.2f;
		alcDestroyContext(openal_output_context);
		al_check_error("alGetSourcei AL_SOURCE_STATE");
		double my_pi = 3.14159;
		alGenBuffers(1, & internal_buffer);






















































		//printf("\nhere is freq %f\n", freq);
void exit_sound_thread(Sound* s){
		alcMakeContextCurrent(NULL);
		MM_init_al();
		MM_init_al();
				//sleep(1);   // should use a thread sleep NOT sleep() for a more responsive finish
		pthread_create(&sound_thread, NULL, MM_render_one_buffer, NULL);
		pthread_create(&sound_thread, NULL, MM_render_one_buffer, NULL);
		alcCloseDevice(openal_output_device);
		// setup buffer and source
