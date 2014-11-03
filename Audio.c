/*
 * Audio.c
 *
 *  Created on: 2014-11-02
 *      Author: akshayk
 */

#include "Audio.h"
#include "Host.h"

HostDeviceInfo *deviceInfo = NULL;


int InitializeDevice(void){
    int result;

    // allocate host device info object and initialize it
    deviceInfo = (HostDeviceInfo*)malloc(sizeof(HostDeviceInfo));
    result = InitializeHost(deviceInfo);
    return result;
}


int GetInputDevice(void){
    /* this will the input device info and return the index*/
    // in case of Linux it will get the alsa interface to get the device info
    return 1;
}


int OpenStream( void** stream,
        const StreamParameters *inputParameters, const StreamParameters *outputParameters,
        double sampleRate, unsigned long framesPerBuffer, StreamCallback *streamCallback,
        void *userData )
{
    int result;

    // check if the device is initialized or not
    if(deviceInfo == NULL || stream == NULL){
        result = INVALID_VALUE;
        return result;
    }

    result = deviceInfo->OpenStream(deviceInfo, stream, inputParameters,
            outputParameters, sampleRate, framesPerBuffer, streamCallback, userData);

    return result;
}


int StartStream(void *stream)
{
    int result;
    return 0;
}


int StopStream(void *stream)
{
    int result = 0;
    return result;
}
