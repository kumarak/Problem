/*
 * main.c
 *
 *  Created on: 2014-11-02
 *      Author: akshayk
 */

#include "Audio.h"

#define RING_BUFFER_SIZE    1024
#define SAMPLE_RATE         44100
#define FRAMES_PER_BUFFER   512
#define NUM_CHANNELS        2


typedef struct {
    unsigned            frameIndex;
    unsigned char       ringBufferData[RING_BUFFER_SIZE];
    FILE               *file;
} ;

static int recordCallback( const void *inputBuffer, void *outputBuffer,
        unsigned long framesPerBuffer, void *userData )
{
    // TODO: write data into ring buffer
    return 0;
}


int main(){
    int result = 0;
    StreamParameters inputParameters;
    void* stream;

    // initialize the Host module
    result = InitializeDevice();

    if(result == INVALID_VALUE){
        goto err;
    }

    //set input parameter
    inputParameters.deviceIndex = GetDefaultInputDevice();
    inputParameters.channelCount = NUM_CHANNELS;
    inputParameters.sampleFormat = 0x1;

    // open device stream
    result = OpenStream(&stream, &inputParameters, NULL,
            SAMPLE_RATE, FRAMES_PER_BUFFER, recordCallback, &data);

    result = StartStream(stream);
    result = CloseStream(stream);

err:
    return result;
}


