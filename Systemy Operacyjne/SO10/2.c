#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TYP 1

struct buf_elem
{
    long mtype;
    char mvalue[20];
};


int main()
{
    int msgid;
    struct buf_elem elem;
    
    msgid = msgget(123456,IPC_CREAT | IPC_EXCL | 0600);
    if(msgid == -1)
    {
        msgid = msgget(123456, IPC_CREAT | 0600);
        if(msgid == -1)
        {
            puts("ERROR");
            exit(1);
        }
    }
    
    if(fork() == 0)
    {
        if(msgrcv(msgid,&elem,sizeof(elem.mvalue),TYP,0) == -1)
        {
            puts("ERROR - Odbieranie");
            exit(3);
        }
        puts(elem.mvalue);
        msgctl(msgid,IPC_RMID,NULL);
    }
    else
    {
        elem.mtype = TYP;
        strcpy(elem.mvalue,"Witaj!");
        if(msgsnd(msgid,&elem,sizeof(elem.mvalue),0) == -1)
        {
            puts("ERROR - Wysylanie");
            exit(2);
        }
    }
    
    return 0;
}
