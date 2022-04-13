#include "user.h"

Player createMusicPlayer()
{
    Player P = (Player)malloc(sizeof(struct MusicPlayer));
    P->current = NULL;
    P->queue_head= NULL;
    P->queue_tail = NULL;
    P->count =0;
    return P;
}

int addSongToQueue(Player P, Song_p S)
{
    if((P->queue_head) == NULL)
    {
        Queue q = (Queue)malloc(sizeof(struct _queue));
        if(q==NULL)
            return 1;
        P->queue_head = q;
        P-> queue_tail = q;
        P->count = P->count +1;
        q->prev = NULL;
        q->song = S;
        // q->sno =0;
        q->next = NULL;

    }
    else
    { 
        //   printf("entered the fuction\n");
    //     printf("head = %p and tail = %p\n",P->queue_head,P->queue_tail);
    //     printf("head = %s and tail = %s\n",(P->queue_head)->song->name,P->queue_tail->song->name);
        /*
    NodePointer a = P->last;
    a->next=temp;
    temp->prev =a; 44
    temp->next=NULL; 45
    P->last = temp; 49
    P->size = P->size+1; 48
        */
        Queue q = (Queue)malloc(sizeof(struct _queue));
        if(q==NULL)
            return 1;
        (P->queue_tail)->next = q;
        q->prev = (P->queue_tail);
        q->next = NULL;
        q->song = S;
        //q->sno = ((q->prev)->sno) +1;
        P->count = P->count +1;
        P->queue_tail = q;
        Queue a = q;
        // printf("%p %s %p\n",a->prev,(a->song)->name,a->next);
        // printf("head = %p and tail = %p\n",P->queue_head,P->queue_tail);
        // printf("head = %s and tail = %s\n",(P->queue_head)->song->name,P->queue_tail->song->name);
    }
    return 0;
}

int removeSongFromQueue(Player P , int i)
{
    if( (i >= P->count) || (i<0) )
        return 1;
    else if(P->count==1)
    {
        free(P->queue_head);
        P->count=0;
        P->queue_head =NULL;
        P->queue_tail = NULL;
        P->current = NULL;
    }
    else
    {
        int j=0;
        for(Queue a = P->queue_head; ; a=a->next)
        {
            if(i==0)
            {   
                P->queue_head =(P->queue_head)->next;
                
                (P->queue_head)->prev = NULL;
                P->count = P->count -1;
                if(P->current == a)
                    P->current = NULL;
                free(a);
                break;
            }
            else if (i==(P->count -1))
            {   
                Queue temp = P->queue_tail;
                if(P->current == temp)
                    P->current = NULL;
                ((P->queue_tail)->prev)->next = NULL;
                P->queue_tail = (P->queue_tail)->prev;
                P->count = P->count -1;
                free(temp); 
            }
            else if(i == j)
            {   
                if(P->current == a)
                    P->current = NULL;
                (a->prev)->next = a->next;
                (a->next)->prev = a->prev;
                P->count = P->count -1;
                free (a);
                break;
            }
            j++;
            if(a->next == NULL)
                break;
        }
    }
    return 0;
}

int playSong(Player P)
{
    if(P->queue_head == NULL)
        return 1;
    if(P->current == NULL)
    {
        P->current = (P->queue_head);
    }
    else
    {
        removeSongFromQueue(P,0);
        P->current = (P->queue_head);
    }
    return 0;
}

Song_p getCurrentSong(Player P)
{
    return (P->current)->song;
}