/*
 * FFmpeg Decoder Helpers
 *
 * Copyright (c) 2011 by Chris Robinson <chris.kcat@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* This file contains routines for helping to decode audio using libavformat
 * and libavcodec (ffmpeg). There's very little OpenAL-specific code here. */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <assert.h>

#include "AL/al.h"
#include "AL/alc.h"
#include "AL/alext.h"

#include "alhelpers.h"
#include "alffmpeg.h"


static size_t NextPowerOf2(size_t value)
{
    size_t powerOf2 = 1;

    if(value)
    {
        value--;
        while(value)
        {
            value >>= 1;
            powerOf2 <<= 1;
        }
    }
    return powerOf2;
}


struct MemData {
    char *buffer;
    size_t length;
    size_t pos;
};

static int MemData_read(void *opaque, uint8_t *buf, int buf_size)
{
    struct MemData *membuf = (struct MemData*)opaque;
    int rem = membuf->length - membuf->pos;

    if(rem > buf_size)
        rem = buf_size;

    memcpy(buf, &membuf->buffer[membuf->pos], rem);
    membuf->pos += rem;

    return rem;
}

static int MemData_write(void *opaque, uint8_t *buf, int buf_size)
{
    struct MemData *membuf = (struct MemData*)opaque;
    int rem = membuf->length - membuf->pos;

    if(rem > buf_size)
        rem = buf_size;

    memcpy(&membuf->buffer[membuf->pos], buf, rem);
    membuf->pos += rem;

    return rem;
}

static int64_t MemData_seek(void *opaque, int64_t offset, int whence)
{
    struct MemData *membuf = (struct MemData*)opaque;

    whence &= ~AVSEEK_FORCE;
    switch(whence)
    {
        case SEEK_SET:
            if(offset < 0 || offset > membuf->length)
                return -1;
            membuf->pos = offset;
            break;

        case SEEK_CUR:
            if((offset >= 0 && offset > membuf->length-membuf->pos) ||
               (offset < 0 && offset < -membuf->pos))
                return -1;
            membuf->pos += offset;
            break;

        case SEEK_END:
            if(offset > 0 || offset < -membuf->length)
                return -1;
            membuf->pos = membuf->length + offset;
            break;

        case AVSEEK_SIZE:
            return membuf->length;

        default:
            return -1;
    }

    return membuf->pos;
}


struct PacketList {
    AVPacket pkt;
    struct PacketList *next;
};

struct MyStream {
    AVCodecContext *CodecCtx;
    int StreamIdx;

    struct PacketList *Packets;

    char *DecodedData;
    size_t DecodedDataSize;

    FilePtr parent;
};

struct MyFile {
    AVFormatContext *FmtCtx;

    StreamPtr *Streams;
    size_t StreamsSize;

    struct MemData membuf;
};


static int done_init = 0;

FilePtr openAVFile(const char *fname)
{
    FilePtr file;

    /* We need to make sure ffmpeg is initialized. Optionally silence warning
     * output from the lib */
    if(!done_init) {av_register_all();
    av_log_set_level(AV_LOG_ERROR);
    done_init = 1;}

    file = (FilePtr)calloc(1, sizeof(*file));
    if(file && avformat_open_input(&file->FmtCtx, fname, NULL, NULL) == 0)
    {
        /* After opening, we must search for the stream information because not
         * all formats will have it in stream headers */
        if(avformat_find_stream_info(file->FmtCtx, NULL) >= 0)
            return file;
        av_close_input_file(file->FmtCtx);
    }

    free(file);
    return NULL;
}

FilePtr openAVData(const char *name, char *buffer, size_t buffer_len)
{
    FilePtr file;

    if(!done_init) {av_register_all();
    av_log_set_level(AV_LOG_ERROR);
    done_init = 1;}

    if(!name)
        name = "";

    file = (FilePtr)calloc(1, sizeof(*file));
    if(file && (file->FmtCtx=avformat_alloc_context()) != NULL)
    {
        file->membuf.buffer = buffer;
        file->membuf.length = buffer_len;
        file->membuf.pos = 0;

        file->FmtCtx->pb = avio_alloc_context(NULL, 0, 0, &file->membuf,
                                              MemData_read, MemData_write,
                                              MemData_seek);
        if(file->FmtCtx->pb && avformat_open_input(&file->FmtCtx, name, NULL, NULL) == 0)
        {
            if(avformat_find_stream_info(file->FmtCtx, NULL) >= 0)
                return file;
        }
        av_close_input_file(file->FmtCtx);
    }

    free(file);
    return NULL;
}

FilePtr openAVCustom(const char *name, void *user_data,
                     int (*read_packet)(void *user_data, uint8_t *buf, int buf_size),
                     int (*write_packet)(void *user_data, uint8_t *buf, int buf_size),
                     int64_t (*seek)(void *user_data, int64_t offset, int whence))
{
    FilePtr file;

    if(!done_init) {av_register_all();
    av_log_set_level(AV_LOG_ERROR);
    done_init = 1;}

    if(!name)
        name = "";

    file = (FilePtr)calloc(1, sizeof(*file));
    if(file && (file->FmtCtx=avformat_alloc_context()) != NULL)
    {
        file->FmtCtx->pb = avio_alloc_context(NULL, 0, 0, user_data,
                                              read_packet, write_packet, seek);
        if(file->FmtCtx->pb && avformat_open_input(&file->FmtCtx, name, NULL, NULL) == 0)
        {
            if(avformat_find_stream_info(file->FmtCtx, NULL) >= 0)
                return file;
        }
        av_close_input_file(file->FmtCtx);
    }

    free(file); 
    return NULL;
}


void closeAVFile(FilePtr file)
{
    size_t i;

    if(!file) return;

    for(i = 0;i < file->StreamsSize;i++)
    {
        StreamPtr stream = file->Streams[i];

        while(stream->Packets)
        {
            struct PacketList *self;

            self = stream->Packets;
            stream->Packets = self->next;

            av_free_packet(&self->pkt);
            av_free(self);
        }

        avcodec_close(stream->CodecCtx);
        av_free(stream->DecodedData);
        free(stream);
    }
    free(file->Streams);

    av_close_input_file(file->FmtCtx);
    free(file);
}


int getAVFileInfo(FilePtr file, int *numaudiostreams)
{
    unsigned int i;
    int audiocount = 0;

    if(!file) return 1;
    for(i = 0;i < file->FmtCtx->nb_streams;i++)
    {
        if(file->FmtCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO)
            audiocount++;
    }
    *numaudiostreams = audiocount;
    return 0;
}

StreamPtr getAVAudioStream(FilePtr file, int streamnum)
{
    unsigned int i;
    if(!file) return NULL;
    for(i = 0;i < file->FmtCtx->nb_streams;i++)
    {
        if(file->FmtCtx->streams[i]->codec->codec_type != AVMEDIA_TYPE_AUDIO)
            continue;

        if(streamnum == 0)
        {
            StreamPtr stream;
            AVCodec *codec;
            void *temp;
            size_t j;

            /* Found the requested stream. Check if a handle to this stream
             * already exists and return it if it does */
            for(j = 0;j < file->StreamsSize;j++)
            {
                if(file->Streams[j]->StreamIdx == (int)i)
                    return file->Streams[j];
            }

            /* Doesn't yet exist. Now allocate a new stream object and fill in
             * its info */
            stream = (StreamPtr)calloc(1, sizeof(*stream));
            if(!stream) return NULL;

            stream->parent = file;
            stream->CodecCtx = file->FmtCtx->streams[i]->codec;
            stream->StreamIdx = i;

            /* Try to find the codec for the given codec ID, and open it */
            codec = avcodec_find_decoder(stream->CodecCtx->codec_id);
            if(!codec || avcodec_open(stream->CodecCtx, codec) < 0)
            {
                free(stream);
                return NULL;
            }

            /* Allocate space for the decoded data to be stored in before it
             * gets passed to the app */
            stream->DecodedData = (char*)av_malloc(AVCODEC_MAX_AUDIO_FRAME_SIZE);
            if(!stream->DecodedData)
            {
                avcodec_close(stream->CodecCtx);
                free(stream);
                return NULL;
            }

            /* Append the new stream object to the stream list. The original
             * pointer will remain valid if realloc fails, so we need to use
             * another pointer to watch for errors and not leak memory */
            temp = realloc(file->Streams, (file->StreamsSize+1) *
                                          sizeof(*file->Streams));
            if(!temp)
            {
                avcodec_close(stream->CodecCtx);
                av_free(stream->DecodedData);
                free(stream);
                return NULL;
            }
            file->Streams = (StreamPtr*)temp;
            file->Streams[file->StreamsSize++] = stream;
            return stream;
        }
        streamnum--;
    }
    return NULL;
}

int getAVAudioInfo(StreamPtr stream, ALuint *rate, ALenum *channels, ALenum *type)
{
    if(!stream || stream->CodecCtx->codec_type != AVMEDIA_TYPE_AUDIO)
        return 1;

    /* Get the sample type for OpenAL given the format detected by ffmpeg. */
    if(stream->CodecCtx->sample_fmt == AV_SAMPLE_FMT_U8)
        *type = AL_UNSIGNED_BYTE_SOFT;
    else if(stream->CodecCtx->sample_fmt == AV_SAMPLE_FMT_S16)
        *type = AL_SHORT_SOFT;
    else if(stream->CodecCtx->sample_fmt == AV_SAMPLE_FMT_S32)
        *type = AL_INT_SOFT;
    else if(stream->CodecCtx->sample_fmt == AV_SAMPLE_FMT_FLT)
        *type = AL_FLOAT_SOFT;
    else if(stream->CodecCtx->sample_fmt == AV_SAMPLE_FMT_DBL)
        *type = AL_DOUBLE_SOFT;
    else
        return 1;

    /* Get the OpenAL channel configuration using the channel layout detected
     * by ffmpeg. NOTE: some file types may not specify a channel layout. In
     * that case, one must be guessed based on the channel count. */
    if(stream->CodecCtx->channel_layout == AV_CH_LAYOUT_MONO)
        *channels = AL_MONO_SOFT;
    else if(stream->CodecCtx->channel_layout == AV_CH_LAYOUT_STEREO)
        *channels = AL_STEREO_SOFT;
    else if(stream->CodecCtx->channel_layout == AV_CH_LAYOUT_QUAD)
        *channels = AL_QUAD_SOFT;
    else if(stream->CodecCtx->channel_layout == AV_CH_LAYOUT_5POINT1)
        *channels = AL_5POINT1_SOFT;
    else if(stream->CodecCtx->channel_layout == AV_CH_LAYOUT_7POINT1)
        *channels = AL_7POINT1_SOFT;
    else if(stream->CodecCtx->channel_layout == 0)
    {
        /* Unknown channel layout. Try to guess. */
        if(stream->CodecCtx->channels == 1)
            *channels = AL_MONO_SOFT;
        else if(stream->CodecCtx->channels == 2)
            *channels = AL_STEREO_SOFT;
        else
            return 1;
    }
    else
        return 1;

    *rate = stream->CodecCtx->sample_rate;

    return 0;
}


/* Used by getAV*Data to search for more compressed data, and buffer it in the
 * correct stream. It won't buffer data for streams that the app doesn't have a
 * handle for. */
static int getNextPacket(FilePtr file, int streamidx)
{
    struct PacketList *packet;

    packet = (struct PacketList*)av_malloc(sizeof(*packet));
    packet->next = NULL;

next_packet:
    while(av_read_frame(file->FmtCtx, &packet->pkt) >= 0)
    {
        StreamPtr *iter = file->Streams;
        StreamPtr *iter_end = iter + file->StreamsSize;

        /* Check each stream the user has a handle for, looking for the one
         * this packet belongs to */
        while(iter != iter_end)
        {
            if((*iter)->StreamIdx == packet->pkt.stream_index)
            {
                struct PacketList **last;

                last = &(*iter)->Packets;
                while(*last != NULL)
                    last = &(*last)->next;

                *last = packet;
                if((*iter)->StreamIdx == streamidx)
                    return 1;

                packet = (struct PacketList*)av_malloc(sizeof(*packet));
                packet->next = NULL;
                goto next_packet;
            }
            iter++;
        }
        /* Free the packet and look for another */
        av_free_packet(&packet->pkt);
    }

    av_free(packet);
    return 0;
}

void *getAVAudioData(StreamPtr stream, size_t *length)
{
    int size;
    int len;

    if(length) *length = 0;

    if(!stream || stream->CodecCtx->codec_type != AVMEDIA_TYPE_AUDIO)
        return NULL;

    stream->DecodedDataSize = 0;

next_packet:
    if(!stream->Packets && !getNextPacket(stream->parent, stream->StreamIdx))
        return NULL;

    /* Decode some data, and check for errors */
    size = AVCODEC_MAX_AUDIO_FRAME_SIZE;
    while((len=avcodec_decode_audio3(stream->CodecCtx,
                                     (int16_t*)stream->DecodedData, &size,
                                     &stream->Packets->pkt)) == 0)
    {
        struct PacketList *self;

        if(size > 0)
            break;

        /* Packet went unread and no data was given? Drop it and try the next,
         * I guess... */
        self = stream->Packets;
        stream->Packets = self->next;

        av_free_packet(&self->pkt);
        av_free(self);

        if(!stream->Packets)
            goto next_packet;

        size = AVCODEC_MAX_AUDIO_FRAME_SIZE;
    }

    if(len < 0)
        return NULL;

    if(len < stream->Packets->pkt.size)
    {
        /* Move the unread data to the front and clear the end bits */
        int remaining = stream->Packets->pkt.size - len;
        memmove(stream->Packets->pkt.data, &stream->Packets->pkt.data[len],
                remaining);
        memset(&stream->Packets->pkt.data[remaining], 0,
               stream->Packets->pkt.size - remaining);
        stream->Packets->pkt.size -= len;
    }
    else
    {
        struct PacketList *self;

        self = stream->Packets;
        stream->Packets = self->next;

        av_free_packet(&self->pkt);
        av_free(self);
    }

    if(size == 0)
        goto next_packet;

    /* Set the output buffer size */
    stream->DecodedDataSize = size;
    if(length) *length = stream->DecodedDataSize;

    return stream->DecodedData;
}

size_t readAVAudioData(StreamPtr stream, void *data, size_t length)
{
    size_t dec = 0;

    if(!stream || stream->CodecCtx->codec_type != AVMEDIA_TYPE_AUDIO)
        return 0;

    while(dec < length)
    {
        /* If there's no decoded data, find some */
        if(stream->DecodedDataSize == 0)
        {
            if(getAVAudioData(stream, NULL) == NULL)
                break;
        }

        if(stream->DecodedDataSize > 0)
        {
            /* Get the amount of bytes remaining to be written, and clamp to
             * the amount of decoded data we have */
            size_t rem = length-dec;
            if(rem > stream->DecodedDataSize)
                rem = stream->DecodedDataSize;

            /* Copy the data to the app's buffer and increment */
            if(data != NULL)
            {
                memcpy(data, stream->DecodedData, rem);
                data = (char*)data + rem;
            }
            dec += rem;

            /* If there's any decoded data left, move it to the front of the
             * buffer for next time */
            if(rem < stream->DecodedDataSize)
                memmove(stream->DecodedData, &stream->DecodedData[rem],
                        stream->DecodedDataSize - rem);
            stream->DecodedDataSize -= rem;
        }
    }

    /* Return the number of bytes we were able to get */
    return dec;
}

void *decodeAVAudioStream(StreamPtr stream, size_t *length)
{
    char *outbuf = NULL;
    size_t buflen = 0;
    void *inbuf;
    size_t got;

    *length = 0;
    if(!stream || stream->CodecCtx->codec_type != AVMEDIA_TYPE_AUDIO)
        return NULL;

    while((inbuf=getAVAudioData(stream, &got)) != NULL && got > 0)
    {
        void *ptr;

        ptr = realloc(outbuf, NextPowerOf2(buflen+got));
        if(ptr == NULL)
            break;
        outbuf = (char*)ptr;

        memcpy(&outbuf[buflen], inbuf, got);
        buflen += got;
    }
    outbuf = (char*)realloc(outbuf, buflen);

    *length = buflen;
    return outbuf;
}
