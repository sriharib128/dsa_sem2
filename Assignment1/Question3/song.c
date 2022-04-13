#include "user.h"

Song makeSong(char * name , char * artist , float duration)
{
    Song S = (Song)malloc(sizeof(struct _song));
    S->name = (char*)malloc(100);
    strcpy((S->name),name);
    S->artist = (char*)malloc(100);
    strcpy((S->artist),artist);
    S->duration = duration;
    return S;
}
