#ifndef _SONG_H
#define _SONG_H

typedef struct _song * Song;

struct _song
{
    char * name;
    char * artist;
    float duration;
};

Song makeSong(char * name , char * artist , float duration);

#endif