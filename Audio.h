/*
 * Audio.h
 *
 *  Created on: 2014-11-02
 *      Author: akshayk
 */

#ifndef AUDIO_H_
#define AUDIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void Stream;

#define INVALID_VALUE -1

typedef struct _StreamParameters{
    int deviceIndex;
    int channelCount;
    unsigned int sampleFormat;
    double suggestedLatency;
    void *hostApiSpecificStreamInfo;
} StreamParameters;


int InitializeDevice(void);

// get the host input device for recording
int GetInputDevice(void);

int StartStream( void *stream );

int StopStream( void *stream );


#endif /* AUDIO_H_ */
