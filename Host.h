/*
 * Host.h
 *
 *  Created on: 2014-11-02
 *      Author: akshayk
 */

#ifndef HOST_H_
#define HOST_H_


typedef int StreamCallback( const void *input, void *output,
        unsigned long frameCount, const void* timeInfo,
        int statusFlags, void *userData );

typedef struct _StreamInterface {
    int (*Close)( void *stream );
    int (*Start)( void *stream );
    int (*Stop)( void *stream );
    int (*IsStopped)( void *stream );
    int (*Read)( void* stream, void *buffer, unsigned long frames );
    int (*Write)( void* stream, const void *buffer, unsigned long frames );
    signed long (*GetReadAvailable)( void* stream );
    signed long (*GetWriteAvailable)( void* stream );
} StreamInterface;




typedef struct _HostDeviceInfo {
    void    (*Terminate)( struct _HostDeviceInfo *info );

    int     (*OpenStream)( struct _HostDeviceInfo *info,
            void** stream,
            const StreamParameters *inputParameters,
            const StreamParameters *outputParameters,
            double sampleRate,
            unsigned long framesPerCallback,
            StreamCallback *streamCallback,
            void *userData );

    StreamInterface interface;
} HostDeviceInfo;

int InitializeHost(HostDeviceInfo *deviceInfo);


#endif /* HOST_H_ */
