#ifndef ALFFMPEG_H
#define ALFFMPEG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

/* Opaque handles to files and streams. Apps don't need to concern themselves
 * with the internals */
typedef struct MyFile *FilePtr;
typedef struct MyStream *StreamPtr;

/* Opens a file with ffmpeg and sets up the streams' information */
FilePtr openAVFile(const char *fname);

/* Opens a named file image with ffmpeg and sets up the streams' information */
FilePtr openAVData(const char *name, char *buffer, size_t buffer_len);

/* Opens a named data stream with ffmpeg, using the specified data pointer and
 * callbacks, and sets up the streams' information */
FilePtr openAVCustom(const char *name, void *user_data,
                     int (*read_packet)(void *user_data, uint8_t *buf, int buf_size),
                     int (*write_packet)(void *user_data, uint8_t *buf, int buf_size),
                     int64_t (*seek)(void *user_data, int64_t offset, int whence));

/* Closes/frees an opened file and any of its streams */
void closeAVFile(FilePtr file);

/* Reports certain information from the file, eg, the number of audio
 * streams. Returns 0 on success. */
int getAVFileInfo(FilePtr file, int *numaudiostreams);

/* Retrieves a handle for the given audio stream number (generally 0, but some
 * files can have multiple audio streams in one file). */
StreamPtr getAVAudioStream(FilePtr file, int streamnum);

/* Returns information about the given audio stream. Returns 0 on success. */
int getAVAudioInfo(StreamPtr stream, ALuint *rate, ALenum *channels, ALenum *type);

/* Returns a pointer to the next available packet of decoded audio. Any data
 * from a previously-decoded packet is dropped. The size (in bytes) of the
 * returned data buffer is stored in 'length', and the returned pointer is only
 * valid until the next call to getAVAudioData or readAVAudioData. */
void *getAVAudioData(StreamPtr stream, size_t *length);

/* The "meat" function. Decodes audio and writes, at most, length bytes into
 * the provided data buffer. Will only return less for end-of-stream or error
 * conditions. Returns the number of bytes written. */
size_t readAVAudioData(StreamPtr stream, void *data, size_t length);

/* Decodes all remaining data from the stream and returns a buffer containing
 * the audio data, with the size stored in 'length'. The returned pointer must
 * be freed with a call to free(). Note that since this decodes the whole
 * stream, using it on lengthy streams (eg, music) will use a lot of memory.
 * Such streams are better handled using getAVAudioData or readAVAudioData to
 * keep smaller chunks in memory at any given time. */
void *decodeAVAudioStream(StreamPtr stream, size_t *length);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ALFFMPEG_H */
