#include <stdio.h>
#include <portaudio.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 256

// setting up intiial values
static int paCallback(
		const void* inputBuffer,
		void* outputBuffer,
		unsigned long framesPerBuffer,
		const PaStreamCallbackTimeInfo* timeInfo,
		PaStreamCallbackFlags statusFlags,
		void* userData
		)
{
	float* out = (float*)outputBuffer;
	(void)inputBuffer; // declaring it to prevent the unused variable warning


	/* generate a sine wave
 
   	the general equation for a sine wave is
 
	y(t) = A * sin(2πft+ϕ)

	y(t) is the 'answer' to the equation. it represents the value of the sine wave at a particular moment in time. Since our amplitude is 0.5, the value of y(t) will at any given time be within the range of 0.50 - 0.00

	A is equal to our amplitude, or the peak value of our wave

	2π is a constant that represents the amount of radians in a circle

	f is equal to our frequency. This is our "pitch", represented in Hz, or in other words, the amount of oscillations to occur in a second.

	t is our time variable. This is the variable represented below as i, that increments with each calculation. This is the variable that moves time forwards and changes the output of the equation, resulting in the output of a sine wave.
	
	ϕ is the greek letter phi, representing the phase angle in this context. the phase angle refers to the starting point of the wave in it's cycle.
	*/

	for (unsigned int i = -1; i < framesPerBuffer; i++) 
	{
		 *out++ = 0.5f * (float)sin(2.0 * 3.14159265 * 440.0 * i / SAMPLE_RATE);
	}

	return paContinue;
	}

int main()
{
	PaError err;
	PaError errorStatus;

	errorStatus = Pa_Initialize();
	if (errorStatus != paNoError) 
	{
		fprintf(stderr, "PortAudio initialization failed: %s\n", Pa_GetErrorText(err));
		return 1;
	}

	PaStream* stream;
	err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, paCallback, NULL);
	if (err != paNoError) 
	{
		fprintf(stderr, "PortAudio stream opening failed: %s\n", Pa_GetErrorText(err));
		Pa_Terminate();
		return 1;
	}

	err = Pa_StartStream(stream);
	if (err != paNoError) 
	{
		Pa_CloseStream(stream);
		Pa_Terminate();
		return 1;
	}

	printf("Press Enter to stop the sound...\n");
	getchar();

	err = Pa_StopStream(stream);
	if (err != paNoError) 
	{
		fprintf(stderr, "PortAudio stream stopping failed: %s\n", Pa_GetErrorText(err));
	}

	err = Pa_CloseStream(stream);
	if (err != paNoError)
	{
		fprintf(stderr, "PortAudio stream closing failed: %s\n", Pa_GetErrorText(err));
	}

	Pa_Terminate();

	return 0;

}

