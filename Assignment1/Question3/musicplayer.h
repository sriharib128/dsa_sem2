#ifndef _MUSICPLAYER_H
#define _MUSICPLAYER_H

#include "Song.h"

typedef struct _queue * Queue;
struct _queue
{   
    Queue prev;
    Song_p song;
    // int sno;   
    Queue next;
};
typedef struct MusicPlayer * Player;
struct MusicPlayer
{
    Queue current ;
    Queue queue_head;
    Queue queue_tail;
    int count;
};

Player createMusicPlayer ();
int addSongToQueue (Player P , Song_p S);
int removeSongFromQueue(Player P, int i);
int playSong(Player P);
Song_p getCurrentSong(Player P);

#endif