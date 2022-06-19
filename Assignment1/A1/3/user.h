#ifndef _USER_H
#define _USER_H

#include "musicplayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User * User_p;

struct User
{
    char * name;
    Player P;
    Queue liked_songs_head;
    Queue liked_songs_tail;
    int liked_no;
};

User_p createUser(char * user_name);
int addSongToQueueUser(User_p U , Song_p S);
int removeSongFromQueueUser (User_p U , int pos);
int playSongUser(User_p U);
Song_p getCurrentSongUser(User_p U);
int addLikedSong(User_p U , Song_p S);
int removeLikedSong(User_p U, Song_p S);
int userCompatibility (User_p U1 , User_p U2);
void print (User_p U);
void print_user(User_p * U_P,int no);
//void print_player (Player P);
#endif