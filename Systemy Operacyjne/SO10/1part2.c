#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX 5
#define TYP1 1
#define TYP2 2

struct buf_elem
{
    long mtype;
    int mvalue;
};

int main()
{
    int msgid, i;
    struct buf_elem elem;
    
    msgid =msgget(45281, IPC_CREAT | IPC_EXCL | 0600);
    puts("Otwarcie kolejki komunikatow");
    if(msgid == -1)
    {
        msgid = msgget(45281, IPC_CREAT | 0600);
        puts("Utworzenie kolejki komunikatow");
        if(msgid == -1)
        {
            perror("#ERROR! Utworzenie kolejki komunikatow\n");
            exit(1);
        }
    }
    
    if(msgid != -1)
    {
        if(fork() == 0)
        {
            elem.mtype = TYP1;
            for(i = 0; i < MAX; ++i)
            {
                puts("Wysylanie komunikatu typu 1");
                if(msgsnd(msgid,&elem,sizeof(elem.mvalue),0)==-1)
                {
                    perror("#ERROR! Wysylanie komunikatu \n");
                    exit(2);
                }
            }
            elem.mtype = TYP2;
            for(i = 0; i<MAX; i++)
            {
                puts("Wysylanie komunikatu typu 2");
                if(msgsnd(msgid,&elem,sizeof(elem.mvalue),0)==-1)
                {
                    perror("#ERROR! Wysylanie komunikatu\n");
                    exit(3);
                }
            }
        }
        else
        {
            for(i = 0; i<MAX;++i)
            {
                puts("Odbieranie komunikatu o typie 1");
                if(msgrcv(msgid,&elem,sizeof(elem.mvalue),TYP1,0)==-1)
                {
                    perror("#ERROR! Odebranie pustego komunikatu\n");
                    exit(4);
                }
            }
        }
    }
    else
    {
        perror("Blad utworzenia kolejki");
        exit(5);
    }
    wait(NULL);
    
    puts("Program zakonczyl sie bez bledow");
    
    return 0;
}
