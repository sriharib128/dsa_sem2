#include "user.h"

Song_p makeSong(char * name , char * artist , float duration)
{
    Song_p S = (Song_p)malloc(sizeof(struct Song));
    S->name = (char*)malloc(100);
    strcpy((S->name),name);
    S->artist = (char*)malloc(100);
    strcpy((S->artist),artist);
    S->duration = duration;
    return S;
}
