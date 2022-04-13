#ifndef _MUSICPLAYER_H
#define _MUSICPLAYER_H

#include "Song.h"

typedef struct _musicplayer * Player;
struct _musicplayer
{
    Queue current ;
    Queue queue_head;
    Queue queue_tail;
    int count;
};

typedef struct _queue * Queue;
struct _queue
{   
    Queue prev;
    Song song;
    // int sno;   
    Queue next;
};

Player createMusicPlayer ();
int addSongToQueue (Player P , Song S);
int removeSongFromQueue(Player P, int i);
int playSong(Player P);
Song getCurrentSong(Player P);

#endif