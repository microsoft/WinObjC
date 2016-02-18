/*
 * OpenAL Audio Stream Example
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

/* This file contains a relatively simple streaming audio player. */

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


LPALBUFFERSAMPLESSOFT palBufferSamplesSOFT = wrap_BufferSamples;
LPALISBUFFERFORMATSUPPORTEDSOFT palIsBufferFormatSupportedSOFT = NULL;


/* Define the number of buffers and buffer size (in samples) to use. 4 buffers
 * with 8192 samples each gives a nice per-chunk size, and lets the queue last
 * for almost 3/4ths of a second for a 44.1khz stream. */
#define NUM_BUFFERS 4
#define BUFFER_SIZE 8192

typedef struct StreamPlayer {
    /* These are the buffers and source to play out through OpenAL with */
    ALuint buffers[NUM_BUFFERS];
    ALuint source;

    /* Handles for the audio stream */
    FilePtr file;
    StreamPtr stream;

    /* A temporary data buffer for readAVAudioData to write to and pass to
     * OpenAL with */
    ALbyte *data;
    ALsizei datasize;

    /* The format of the output stream */
    ALenum format;
    ALenum channels;
    ALenum type;
    ALuint rate;
} StreamPlayer;

static StreamPlayer *NewPlayer(void);
static void DeletePlayer(StreamPlayer *player);
static int OpenPlayerFile(StreamPlayer *player, const char *filename);
static void ClosePlayerFile(StreamPlayer *player);
static int StartPlayer(StreamPlayer *player);
static int UpdatePlayer(StreamPlayer *player);

/* Creates a new player object, and allocates the needed OpenAL source and
 * buffer objects. Error checking is simplified for the purposes of this
 * example, and will cause an abort if needed. */
static StreamPlayer *NewPlayer(void)
{
    StreamPlayer *player;

    player = malloc(sizeof(*player));
    assert(player != NULL);

    memset(player, 0, sizeof(*player));

    /* Generate the buffers and source */
    alGenBuffers(NUM_BUFFERS, player->buffers);
    assert(alGetError() == AL_NO_ERROR && "Could not create buffers");

    alGenSources(1, &player->source);
    assert(alGetError() == AL_NO_ERROR && "Could not create source");

    /* Set parameters so mono sources play out the front-center speaker and
     * won't distance attenuate. */
    alSource3i(player->source, AL_POSITION, 0, 0, -1);
    alSourcei(player->source, AL_SOURCE_RELATIVE, AL_TRUE);
    alSourcei(player->source, AL_ROLLOFF_FACTOR, 0);
    assert(alGetError() == AL_NO_ERROR && "Could not set source parameters");

    return player;
}

/* Destroys a player object, deleting the source and buffers. No error handling
 * since these calls shouldn't fail with a properly-made player object. */
static void DeletePlayer(StreamPlayer *player)
{
    ClosePlayerFile(player);

    alDeleteSources(1, &player->source);
    alDeleteBuffers(NUM_BUFFERS, player->buffers);
    if(alGetError() != AL_NO_ERROR)
        fprintf(stderr, "Failed to delete object IDs\n");

    memset(player, 0, sizeof(*player));
    free(player);
}


/* Opens the first audio stream of the named file. If a file is already open,
 * it will be closed first. */
static int OpenPlayerFile(StreamPlayer *player, const char *filename)
{
    ClosePlayerFile(player);

    /* Open the file and get the first stream from it */
    player->file = openAVFile(filename);
    player->stream = getAVAudioStream(player->file, 0);
    if(!player->stream)
    {
        fprintf(stderr, "Could not open audio in %s\n", filename);
        goto error;
    }

    /* Get the stream format, and figure out the OpenAL format */
    if(getAVAudioInfo(player->stream, &player->rate, &player->channels,
                      &player->type) != 0)
    {
        fprintf(stderr, "Error getting audio info for %s\n", filename);
        goto error;
    }

    player->format = GetFormat(player->channels, player->type, palIsBufferFormatSupportedSOFT);
    if(player->format == 0)
    {
        fprintf(stderr, "Unsupported format (%s, %s) for %s\n",
                ChannelsName(player->channels), TypeName(player->type),
                filename);
        goto error;
    }

    /* Allocate enough space for the temp buffer, given the format */
    player->datasize = FramesToBytes(BUFFER_SIZE, player->channels,
                                     player->type);
    player->data = malloc(player->datasize);
    if(player->data == NULL)
    {
        fprintf(stderr, "Error allocating %d bytes\n", player->datasize);
        goto error;
    }

    return 1;

error:
    closeAVFile(player->file);
    player->file = NULL;
    player->stream = NULL;
    player->datasize = 0;

    return 0;
}

/* Closes the audio file stream */
static void ClosePlayerFile(StreamPlayer *player)
{
    closeAVFile(player->file);
    player->file = NULL;
    player->stream = NULL;

    free(player->data);
    player->data = NULL;
    player->datasize = 0;
}


/* Prebuffers some audio from the file, and starts playing the source */
static int StartPlayer(StreamPlayer *player)
{
    size_t i, got;

    /* Rewind the source position and clear the buffer queue */
    alSourceRewind(player->source);
    alSourcei(player->source, AL_BUFFER, 0);

    /* Fill the buffer queue */
    for(i = 0;i < NUM_BUFFERS;i++)
    {
        /* Get some data to give it to the buffer */
        got = readAVAudioData(player->stream, player->data, player->datasize);
        if(got == 0) break;

        palBufferSamplesSOFT(player->buffers[i], player->rate, player->format,
                             BytesToFrames(got, player->channels, player->type),
                             player->channels, player->type, player->data);
    }
    if(alGetError() != AL_NO_ERROR)
    {
        fprintf(stderr, "Error buffering for playback\n");
        return 0;
    }

    /* Now queue and start playback! */
    alSourceQueueBuffers(player->source, i, player->buffers);
    alSourcePlay(player->source);
    if(alGetError() != AL_NO_ERROR)
    {
        fprintf(stderr, "Error starting playback\n");
        return 0;
    }

    return 1;
}

static int UpdatePlayer(StreamPlayer *player)
{
    ALint processed, state;

    /* Get relevant source info */
    alGetSourcei(player->source, AL_SOURCE_STATE, &state);
    alGetSourcei(player->source, AL_BUFFERS_PROCESSED, &processed);
    if(alGetError() != AL_NO_ERROR)
    {
        fprintf(stderr, "Error checking source state\n");
        return 0;
    }

    /* Unqueue and handle each processed buffer */
    while(processed > 0)
    {
        ALuint bufid;
        size_t got;

        alSourceUnqueueBuffers(player->source, 1, &bufid);
        processed--;

        /* Read the next chunk of data, refill the buffer, and queue it
         * back on the source */
        got = readAVAudioData(player->stream, player->data, player->datasize);
        if(got > 0)
        {
            palBufferSamplesSOFT(bufid, player->rate, player->format,
                                 BytesToFrames(got, player->channels, player->type),
                                 player->channels, player->type, player->data);
            alSourceQueueBuffers(player->source, 1, &bufid);
        }
        if(alGetError() != AL_NO_ERROR)
        {
            fprintf(stderr, "Error buffering data\n");
            return 0;
        }
    }

    /* Make sure the source hasn't underrun */
    if(state != AL_PLAYING && state != AL_PAUSED)
    {
        ALint queued;

        /* If no buffers are queued, playback is finished */
        alGetSourcei(player->source, AL_BUFFERS_QUEUED, &queued);
        if(queued == 0)
            return 0;

        alSourcePlay(player->source);
        if(alGetError() != AL_NO_ERROR)
        {
            fprintf(stderr, "Error restarting playback\n");
            return 0;
        }
    }

    return 1;
}


int main(int argc, char **argv)
{
    StreamPlayer *player;
    int i;

    /* Print out usage if no file was specified */
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s <filenames...>\n", argv[0]);
        return 1;
    }

    if(InitAL() != 0)
        return 1;

    if(alIsExtensionPresent("AL_SOFT_buffer_samples"))
    {
        printf("AL_SOFT_buffer_samples supported!\n");
        palBufferSamplesSOFT = alGetProcAddress("alBufferSamplesSOFT");
        palIsBufferFormatSupportedSOFT = alGetProcAddress("alIsBufferFormatSupportedSOFT");
    }
    else
        printf("AL_SOFT_buffer_samples not supported\n");

    player = NewPlayer();

    /* Play each file listed on the command line */
    for(i = 1;i < argc;i++)
    {
        if(!OpenPlayerFile(player, argv[i]))
            continue;

        fprintf(stderr, "Playing %s (%s, %s, %dhz)\n", argv[i],
                TypeName(player->type), ChannelsName(player->channels),
                player->rate);

        if(!StartPlayer(player))
        {
            ClosePlayerFile(player);
            continue;
        }

        while(UpdatePlayer(player))
            Sleep(10);

        /* All done with this file. Close it and go to the next */
        ClosePlayerFile(player);
    }
    fprintf(stderr, "Done.\n");

    /* All files done. Delete the player, and close OpenAL */
    DeletePlayer(player);
    player = NULL;

    CloseAL();

    return 0;
}
