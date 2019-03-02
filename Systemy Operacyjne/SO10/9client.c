#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>


struct msg_type
{
    long type;
    int content;
};

#define MSGKEY 123456
#define M_DANE 1
#define M_END 2
#define M_WYNIK 3


int main()
{
    struct msg_type msg;

    int msgid = msgget(MSGKEY,IPC_CREAT | 0600);
    if(msgid == -1)
    {
        perror("Error msgget\n");
        exit(0x1);
    }

    for(int i = 0;i<100;++i)
    {
        msg.type = M_DANE;
        msg.content = i;
        if(msgsnd(msgid,&msg,sizeof(msg.content),0) == -1)
        {
            perror("error msgsnd\n");
            exit(0x1);
        }
    }

    msg.type = M_END;
    msg.content = 0;
    if(msgsnd(msgid,&msg,sizeof(msg.content),0) == -1)
    {
        perror("error msgsnd\n");
        exit(0x1);
    }

    if(msgrcv(msgid,&msg,sizeof(msg.content),M_WYNIK,0) == -1)
    {
        perror("error msgrcv\n");
        exit(0x2);
    }

    printf("%d\n",msg.content);

    msgctl(msgid,IPC_RMID,NULL);

    return 0;
}