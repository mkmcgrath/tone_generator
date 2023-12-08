#include <stdio.h>
#include <math.h>
#include <sndfile.h>
#include <string.h>
#include "frequencies.h"

int SAMPLE_RATE = 44100;
int direction = 1;
float pitchSlider = 1;

#define FRAMES_PER_BUFFER 256
#define FILE_NAME "output.wav"

// Function to generate a sine wave and write it to a WAV file
void generateAndWriteWave() {
    SNDFILE* file;
    SF_INFO sfinfo;

    // Initializing and defining variables for the function.
    sfinfo.channels = 1;
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_FLOAT; // Format can be adjusted based on desired output.	
    char userFrequencyInput[50];

    // Open the output file
    file = sf_open(FILE_NAME, SFM_WRITE, &sfinfo);
    if (!file) {
        fprintf(stderr, "Error opening output file\n\n");
        return;
    }

    // Prompt to ask user what frequencies they would like to generate
    //printf("\n\n");
    //printf("Hello!\n\n");
    //printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    //printf("Please type the frequencies (in HZ) or the notes (with letters) you would like to generate, separated by spaces:\n");
    //printf("		Example in HZ: '261.63 329.63 392.00'\n");
    //printf("		Example with Notes: 'C E G'\n\n");
    //scanf("	:%c\n", userFrequencyInput);


    //char * typeToken = strtok(userFrequencyInput, " ");
    //printf("\n\n\n");
    
    //if ( typeToken != NULL ) {

    //printf("%c\n", typeToken);

    //}

    //if ( typeToken = NULL ) {
	//    printf("ITS ACTUALLY NULL");
    //}

    //else {
	    //printf("NOT TOKEN RETURNED... NOT NULL RETURNED EITHER... \n");
	//}


    
    // Generate and write the sine wave to the file
    for (unsigned int i = 0; i < SAMPLE_RATE * 3; ++i) {
	//pitchSlider += 0.0001 * direction;
        float sampleC = 0.5f * (float)sin(2.0 * M_PI * C * pitchSlider * i / SAMPLE_RATE);
	float sampleE = 0.5f * (float)sin(2.0 * M_PI * E * pitchSlider * i / SAMPLE_RATE);
	float sampleG = 0.5f * (float)sin(2.0 * M_PI * G * pitchSlider * i / SAMPLE_RATE);
	//float sampleB = 0.5f * (float)sin(2.0 * M_PI * B * pitchSlider * i / SAMPLE_RATE);
	
	//float combinedSample = sampleE;
	float combinedSample = sampleC + sampleE + sampleG;
	//if (combinedSample >= 1.50) {
	//	combinedSample = 1.50;
	//}
	printf("%f\n", combinedSample);

        sf_writef_float(file, &combinedSample, 1);

	//if (pitchSlider >= 1.001 || pitchSlider <= 0.995) {
	//	direction = -direction;
	//}
	//if (combinedSample >= 1.90) {
	//	combinedSample = 1.90;
	//}
	//if (combinedSample >=200) {
	//	combinedSample = 199.32;
	//}
    }


    
    for (unsigned int i = 0; i < SAMPLE_RATE * 3; ++i) {
        float sampleeC = 0.5f * (float)sin(2.0 * M_PI * G * pitchSlider * i / SAMPLE_RATE);
	float sampleeE = 0.5f * (float)sin(2.0 * M_PI * B * pitchSlider * i / SAMPLE_RATE);
	float sampleeG = 0.5f * (float)sin(2.0 * M_PI * D * pitchSlider * i / SAMPLE_RATE);
	
	float combinedSamplle = sampleeC + sampleeE + sampleeG;
	printf("%f\n", combinedSamplle);

        sf_writef_float(file, &combinedSamplle, 1);
    }

    for (unsigned int i = 0; i < SAMPLE_RATE * 3; ++i) {
        float sampleeeC = 0.5f * (float)sin(2.0 * M_PI * A * pitchSlider * i / SAMPLE_RATE);
	float sampleeeE = 0.5f * (float)sin(2.0 * M_PI * C * pitchSlider * i / SAMPLE_RATE);
	float sampleeeG = 0.5f * (float)sin(2.0 * M_PI * E * pitchSlider * i / SAMPLE_RATE);
	
	float combinedSampllle = sampleeeC + sampleeeE + sampleeeG;
	printf("%f\n", combinedSampllle);

        sf_writef_float(file, &combinedSampllle, 1);
    }


    for (unsigned int i = 0; i < SAMPLE_RATE * 3; ++i) {
        float sampleeeeC = 0.5f * (float)sin(2.0 * M_PI * F * pitchSlider * i / SAMPLE_RATE);
	float sampleeeeE = 0.5f * (float)sin(2.0 * M_PI * A * pitchSlider * i / SAMPLE_RATE);
	float sampleeeeG = 0.5f * (float)sin(2.0 * M_PI * C * pitchSlider * i / SAMPLE_RATE);
	
	float combinedSamplllle = sampleeeeC + sampleeeeE + sampleeeeG;
	printf("%f\n", combinedSamplllle);

        sf_writef_float(file, &combinedSamplllle, 1);
    }

    // Close the output file
    sf_close(file);
}

int main() {
    // Generate and write the sine wave to the WAV file
    generateAndWriteWave();

    printf("WAV file generated: %s\n", FILE_NAME);

    return 0;
}

