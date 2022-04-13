#ifndef _USER_H
#define _USER_H

#include "musicplayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _user * User;

struct _user
{
    char * name;
    Player P;
    Queue liked_songs_head;
    Queue liked_songs_tail;
    int liked_no;
};

User createUser(char * user_name);
int addSongToQueueUser(User U , Song S);
int removeSongFromQueueUser (User U , int pos);
int playSongUser(User U);
Song getCurrentSongUser(User U);
int addLikedSong(User U , Song S);
int removeLikedSong(User U, Song S);
int userCompatibility (User U1 , User U2);

#endif