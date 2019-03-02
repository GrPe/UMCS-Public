#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TYP 1

struct msg_type
{
    long mtype;
    int mvalue;
};

int main()
{
    int msgid;
    struct msg_type elem;
    
    msgid = msgget(666666,IPC_CREAT | IPC_EXCL | 0600);
    if(msgid == -1)
    {
        msgid = msgget(666666,IPC_CREAT | 0600);
        if(msgid == -1)
        {
            perror("ERROR - Tworzenie kolejki\n");
            exit(2);
        }
    }
    
    for(int i = 0; i<3;i++)
    {
        if(fork() == 0)
        {
            elem.mtype = TYP;
            elem.mvalue = getpid();
            if(msgsnd(msgid,&elem,sizeof(elem.mvalue),0) == -1)
            {
                perror("ERROR - wysylanie wiadomosci\n");
                exit(3);
            }
            exit(0);
        }
    }
    
    for(int i = 0;i<3;++i)
    {
        if(msgrcv(msgid,&elem,sizeof(elem.mvalue),TYP,0) == -1)
        {
            perror("ERROR - Odczytywanie wiadomosci\n");
            exit(4);
        }
        printf("Nr%d, PID:%d\n",i,elem.mvalue);
    }
    
    msgctl(msgid,IPC_RMID,NULL);
    
    return 0;
}
