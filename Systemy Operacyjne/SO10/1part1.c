#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX 10
#define ZWYKLY 1
#define WAZNY 2

struct buf_elem
{
    long mtype;
    int mvalue;
};

int main()
{
    int msgid, i;
    struct buf_elem elem;
    
    msgid = msgget(45281,IPC_CREAT | IPC_EXCL | 0600);
    puts("Proba otwatcia/utworzenia kolejki komunikatow");
    
    if(msgid == -1)
    {
        msgid = msgget(45281, IPC_CREAT | 0600);
        puts("Utworzenie kolejki komunikatow");
        if(msgid == -1)
        {
            perror("#ERROR! utworzenia kolejki komunikatow\n");
            exit(2);
        }
    }
    
    if(msgid != -1)
    {
        elem.mtype = ZWYKLY;
        for(i = 0; i<MAX;++i)
        {
            printf("Wysylanie kolejki komunikatow\n");
            if(msgsnd(msgid,&elem,sizeof(elem.mvalue),0) == -1)
            {
                perror("#ERROR! Wyslanie zwyklego komunikatu\n");
                exit(3);
            }
        }
        
        for(i = 0; i<10;i++)
        {
            puts("Odbieranie komunikatu");
            if(msgrcv(msgid,&elem,sizeof(elem.mvalue),ZWYKLY,0)==-1)
            {
                perror("#ERROR! Odbieranie zwyklego komunikatu\n");
                exit(4);
            }
            elem.mvalue = i;
            elem.mtype = WAZNY;
            if(msgsnd(msgid,&elem,sizeof(elem.mvalue),0)==-1)
            {
                perror("#ERROR! wyslanie waznego komunikatu\n");
                exit(5);
            }
            
        }
        
    }
    
    puts("Program zakonczyl sie bez bledow");
    
    return 0;
}
