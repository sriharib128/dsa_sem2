#include "user.h"

int main()
{
    while(1)
    {   
        Song song_list[1000];
        User user_list[1000];
        int uno=0;
        int sno=0;
        char * s = (char *)malloc(101);
        scanf("%s", s);
        if(strcmp(s,"make_song")==0)
        {
            char * name = (char *)malloc(100);
            char * artist = (char *)malloc(100);
            float duration;
            scanf("%s",name);
            scanf("%s",artist);
            scanf("%f",&duration);
            song_list[sno++] = makeSong(name,artist,duration);
        }
        else if(strcmp(s,"make_user")==0)
        {
            char * user_name = (char*)malloc(101);
            scanf("%s",user_name);
            user_list[uno++] = createUser(user_name);
        }
        
    }
    return 1;    
}