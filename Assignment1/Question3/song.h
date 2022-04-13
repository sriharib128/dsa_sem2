#ifndef _SONG_H
#define _SONG_H

typedef struct Song * Song_p;

struct Song
{
    char * name;
    char * artist;
    float duration;
};

Song_p makeSong(char * name , char * artist , float duration);

#endif