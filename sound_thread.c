		MM_init_al();
		MM_init_al();
#ifdef __APPLE__
		// Clean-up
#include <OpenAL/al.h>
				al_check_error("alGetSourcei AL_SOURCE_STATE");
		// Stop the sources
int al_check_error(const char * given_label){
		float incr_freq = 0.2f;
		// float freq = 440.f;
#endif
ALCdevice  * openal_output_device;
		int i=0;
		for (ii = 0; ii < 1; ++ii) {
		al_check_error("alGetSourcei AL_SOURCE_STATE");
				//freq *= factor_freq;
		ALenum current_playing_state;
		alcCloseDevice(openal_output_device);
		/* Set-up sound source and play buffer */
		return 0;
#include <AL/al.h>
		alcDestroyContext(openal_output_context);
		alDeleteSources(1, &streaming_source[0]);
		// allocate PCM audio buffer        
		//alGenSources(1, &src);
		for(; i<buf_size; ++i) {
#include <stdbool.h>
		alGetSourcei(streaming_source[0], AL_SOURCE_STATE, & current_playing_state);
		// setup buffer and source
		pthread_t sound_thread;
		pthread_t sound_thread;






















































void exit_sound_thread(Sound* s){
				printf("ERROR - %s  (%s)\n", alGetString(al_error), given_label);
#include <math.h>
		alSourcei(streaming_source[0], AL_BUFFER, internal_buffer);
				alSourcei(streaming_source[ii], AL_BUFFER, 0);
				freq += incr_freq;
		float seconds = 0.5;
		alGenBuffers(1, & internal_buffer);
		short * samples = malloc(sizeof(short) * buf_size);
		while (AL_PLAYING == current_playing_state) {
		openal_output_device  = alcOpenDevice(defname);
void MM_init_al() {
		if(AL_NO_ERROR != al_error) {
void MM_exit_al() {
		alDeleteBuffers(16, &streaming_source[0]);
		double my_pi = 3.14159;
ALCcontext * openal_output_context;
				//sleep(1);   // should use a thread sleep NOT sleep() for a more responsive finish
		al_check_error("failed call to alGenBuffers");
		alSourcePlay(streaming_source[0]);
		/* Fill buffer with Sine-Wave */
		}
		}
		}
		}
		al_error = alGetError();
				//printf("still playing ... so sleep\n");
		size_t buf_size = seconds * sample_rate;
		openal_output_context = alcCreateContext(openal_output_device, NULL);
		MM_exit_al();
		alcMakeContextCurrent(openal_output_context);
void make_sound(float freq, float incr_freq, float seconds){
#include "sound_thread.h"
}   //MM_render_one_buffer
		//alSourcePlay(src);
		//printf("\nhere is freq %f\n", freq);
Sound* init_sound_thread(void){
		
		ALenum errorCode = 0;
		/* upload buffer to OpenAL */
		alcMakeContextCurrent(NULL);
void MM_render_one_buffer() {
		// ---------------------
}
}
}
}
}
}
		ALenum al_error;
#include <stdlib.h>
				//incr_freq += incr_freq;
		alGenSources(1, & streaming_source[0]);
		free(samples);
		//printf("end of playing\n");
ALuint internal_buffer;
		int ii;
#include <OpenAL/alc.h>
				samples[i] = 32760 * sin( (2.f * my_pi * freq)/sample_rate * i );
		float freq = 100.f;
		//add frequncy to buffer
#include <stdio.h>
#include <AL/alc.h>
#elif __linux
		unsigned sample_rate = 44100;
		const char * defname = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
				return al_error;
		alBufferData( internal_buffer, AL_FORMAT_MONO16, samples, buf_size, sample_rate);
		//alSourcei(src, AL_BUFFER, internal_buffer);
		alSourceStopv(1, & streaming_source[0]);        //      streaming_source
		errorCode = alGetError();
		errorCode = alGetError();
		// unsigned sample_rate = 22050;
				alGetSourcei(streaming_source[0], AL_SOURCE_STATE, & current_playing_state);
		al_check_error("populating alBufferData");
		ALuint src = 0;
		pthread_create(&sound_thread, NULL, MM_render_one_buffer, NULL);
		pthread_create(&sound_thread, NULL, MM_render_one_buffer, NULL);
ALuint streaming_source[1];
