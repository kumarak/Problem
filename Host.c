/*
 * Host.c
 *
 *  Created on: 2014-11-02
 *      Author: akshayk
 */

#include "Audio.h"
#include "Host.h"

static int StreamOpen(HostDeviceInfo *hostApi,
        void** s, const StreamParameters *inputParameters,
        const StreamParameters *outputParameters, double sampleRate,
        unsigned long framesPerBuffer, StreamCallback* callback, void *userData);

static void StreamTerminate(HostDeviceInfo *hostApi);


static int Host_LoadLibrary()
{
    //TODO:: check if the corresponding modules are loaded or not
    // if not load the appropriate modules
    return 1;
}

static int StreamStart(void *stream)
{
    int result = 0;

    //TODO : start streaming the audio buffer
    return result;
}

static int StreamClose(void* stream)
{
    int result = 0;

    // TODO: close the stream; free all the resources;
    return result;
}


static int StreamRead( void* stream, void *buffer, unsigned long frames )
{
    int result = 0;

    // TODO: callback for reading the stream buffer
    return result;
}

static int StreamWrite(void *stream, const void *buffer, unsigned long frames )
{
    int result = 0;
    // TODO :: callback for wring the stream
    return result;
}



int InitializeHost(HostDeviceInfo *deviceInfo)
{
    int result = 0;

    // load the modules
    Host_LoadLibrary();

    // initialize host functions for callback
    deviceInfo->OpenStream = StreamOpen;
    deviceInfo->Terminate = StreamTerminate;

    deviceInfo->interface.Start = StreamStart;
    deviceInfo->interface.Close = StreamClose;
    deviceInfo->interface.Read = StreamRead;
    deviceInfo->interface.Write = StreamWrite;
    return result;
}

static int StreamOpen(HostDeviceInfo *hostApi,
        void** s,
        const StreamParameters *inputParameters,
        const StreamParameters *outputParameters,
        double sampleRate,
        unsigned long framesPerBuffer,
        StreamCallback* callback,
        void *userData )
{
    int result = 0;

    //TODO:: Host specific functions to open devices.
    return result;
}

static void StreamTerminate(HostDeviceInfo *hostApi)
{
}
