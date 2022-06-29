#include "user.h"

User_p createUser(char * name)
{
    User_p U = (User_p)malloc(sizeof(struct User));
    U->name = (char *)malloc(100);
    strcpy(U->name , name);
    U->P = createMusicPlayer();
    U->liked_songs_head = NULL;
    U->liked_no = 0;
    return U;   
}

int addSongToQueueUser(User_p U , Song_p S)
{
    return(addSongToQueue((U->P),S));
}
int removeSongFromQueueUser(User_p U , int pos)
{
    return(removeSongFromQueue((U->P),pos));
}
int playSongUser(User_p U)
{
    return(playSong(U->P));
}
Song_p getCurrentSongUser(User_p U)
{
    return(getCurrentSong(U->P));
}

int addLikedSong(User_p U , Song_p S)
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
        (U->liked_songs_tail)->next =q;    
        q->next = NULL;
        q->song = S;
        //q->sno = ((q->prev)->sno) +1;
        U->liked_songs_tail = q;
        U->liked_no = U->liked_no +1;   
    }
    return 0;
}

int removeLikedSong(User_p U , Song_p S)
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

int userCompatibility(User_p U1 , User_p U2)
{

    // printf("%p name=%s liked_head = %p player = %p \n",U1,U1->name,U1->liked_songs_head , U1->P);
    // printf("%p name=%s liked_head = %p player = %p \n",U2,U2->name,U2->liked_songs_head , U2->P);
    // printf("\n\n");

    int ct =0;
    Queue a = U1->liked_songs_head;
    Queue b = U2->liked_songs_head;
    while( (a !=NULL))
    {   b = U2->liked_songs_head;
        while (b !=NULL)
        {   
            // printf("comparing %s and %s\n",a->song->name , b->song->name);
            if(strcmp(a->song->name , b->song->name)==0)
            {
                // printf(" > > > matched %s and %s\n",a->song->name , b->song->name);
                ct++;
            }    
            b=b->next;
        }
        a=a->next;
    }
    return ct;
}
void print (User_p U)
{
    printf("-------printing user %p--------------\n",U);
    printf("name = %s liked no = %d\n",U->name,U->liked_no);
    for(Queue a = (U->liked_songs_head);a!=NULL;a=a->next)
    {
        printf("%s ",(a->song)->name);
    }
    printf("\nprinted liked_songs\n");
    for(Queue a = (U->P)->queue_head;a!=NULL;a=a->next)
    { 
        printf("%p %s %p\n",a->prev,(a->song)->name,a->next);
    }
    printf("\nprinted player songs\n");
    // printf("----------printed player songs-------------\n");
    printf("XXXXXXXXXXXXXXXXXXXXXXxx\n");
}
void print_user(User_p * U_P,int no)
{
    printf("%p\n",U_P);
    for(int i=0;i<no;i++)
    {
        printf("%p name=%s liked_head = %p player = %p \n",&U_P[i],U_P[i]->name,U_P[i]->liked_songs_head , U_P[i]->P);
    }
    printf("\n\n");
}
/*
U1 = struct user *
U_P = struct user **;
U_P[0] = struct user *
*/