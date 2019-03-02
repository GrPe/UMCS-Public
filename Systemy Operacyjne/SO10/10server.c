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
    char content[100];
};

#define MSGKEY 123456

int main()
{
    struct msg_type msg;

    int msgid = msgget(MSGKEY,IPC_CREAT | 0600);
    if(msgid == -1)
    {
        perror("Error msgget\n");
        exit(0x1);
    }

    while(1)
    {
        if(msgrcv(msgid,&msg,100,0,0) == -1)
        {
            perror("error msgrcv\n");
            exit(0x2);
        }
        if(msg.type == 2) break;
        puts(msg.content);
    }

    msgctl(msgid,IPC_RMID,NULL);

    return 0;
}