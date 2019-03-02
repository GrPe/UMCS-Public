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
    char content[100];
};

#define MSGKEY 123456


int main()
{
    struct msg_type msg;
    strcpy(msg.content,"JAkis dziwny tekst");
    msg.type = 1;

    int msgid = msgget(MSGKEY,IPC_CREAT | 0600);
    if(msgid == -1)
    {
        perror("Error msgget\n");
        exit(0x1);
    }

    if(msgsnd(msgid,&msg,100,0) == -1)
    {
        perror("error msgsnd\n");
        exit(0x1);
    }

    if(msgrcv(msgid,&msg,100,0,0) == -1)
    {
        perror("error msgrcv\n");
        exit(0x2);
    }

    puts(msg.content);

    msgctl(msgid,IPC_RMID,NULL);

    return 0;
}