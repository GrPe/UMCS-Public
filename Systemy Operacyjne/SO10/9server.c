#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>


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
    int sum = 0;

    int msgid = msgget(MSGKEY,IPC_CREAT | 0600);
    if(msgid == -1)
    {
        perror("Error msgget\n");
        exit(0x1);
    }

    while(1)
    {
        if(msgrcv(msgid,&msg,sizeof(msg.content),0,0) == -1)
        {
            perror("error msgrcv\n");
            exit(0x2);
        }
        if(msg.type == M_END) break;
        else sum +=msg.content;
    }

    msg.type = M_WYNIK;
    msg.content = sum;
    if(msgsnd(msgid,&msg,sizeof(msg.content),0) == -1)
    {
        perror("error msgsnd\n");
        exit(0x3);
    }

    return 0;
}