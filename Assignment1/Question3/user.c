#include "user.h"

User createUser(char * name)
{
    User U = (User)malloc(sizeof(struct _user));
    U->name = (char *)malloc(100);
    strcpy(U->name , name);
    U->P = createMusicPlayer();
    U->liked_songs_head = NULL;
    U->liked_no = 0;
    return U;   
}

int addSongToQueueUser(User U , Song S)
{
    return(addSongToQueue((U->P),S));
}
int removeSongFromQueueUser(User U , int pos)
{
    retrun(removeSongFromQueue((U->P),pos));
}
int playSongUser(User U)
{
    return(playSong(U->P));
}
Song getCurrentSongUser(User U)
{
    retrun(getCurrentSong(U->P));
}

int addLikedSong(User U , Song S)
{
     if((U->liked_songs_head) == NULL)
    {
        Queue q = (Queue)malloc(sizeof(struct _queue));
        if(q==NULL)
            return 1;
        U->liked_songs_head = q;
        q->prev = NULL;
        q->next = NULL;
        q->song = S;
        U->liked_songs_tail =q;
        U->liked_no = U->liked_no +1;
    }
    else
    {
        Queue q = (Queue)malloc(sizeof(struct _queue));
        if(q==NULL)
            return 1;
        q->prev = (U->liked_songs_tail);    
        q->next = NULL;
        q->song = S;
        //q->sno = ((q->prev)->sno) +1;
        U->liked_songs_tail = q;
        U->liked_no = U->liked_no +1;   
    }
    return 0;
}


int removeLikedSong(User U , Song S)
{   

    //if( (i >= U->liked_no) || (i<0) )
    //   return 1;
    if(U->liked_no==1)
    {
        free(U->liked_songs_head);
        U->liked_no=0;
        U->liked_songs_head =NULL;
        U->liked_songs_tail = NULL; 
        return 0;
    }
    else
    {
        for(Queue a = U->liked_songs_head;;a=a->next)
        {
            if((U->liked_songs_head)->song == S)
            {
                U->liked_songs_head =a->next;
                (U->liked_songs_head)->prev = NULL;
                U->liked_no = U->liked_no -1;
                free(a);
                return 0;
            }
            else if ((U->liked_songs_tail)->song == S)
            {   
                Queue temp = U->liked_songs_tail;
                ((U->liked_songs_tail)->prev)->next = NULL;
                U->liked_songs_tail = (U->liked_songs_tail)->prev;
                U->liked_no = U->liked_no -1;
                free(temp); 
                return 0;
            }
            else if(a->song == S)
            {   
                (a->prev)->next = a->next;
                (a->next)->prev = a->prev;
                U->liked_no = U->liked_no -1;
                free (a);
                return 0;
            }
            if(a->next == NULL)
                break;
        }
    }
    return 1;
}

int userCompatibility(User U1 , User U2)
{
    int ct =0;
    Queue a = U1->liked_songs_head;
    Queue b = U2->liked_songs_head;
    while( (a->next !=NULL) || (b->next !=NULL))
    {
        if(a->song == b->song)
            ct++;
        a=a->next;
        b=b->next;
    }
    return ct;
}