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
    msg.type = 1;

    int msgid = msgget(MSGKEY,IPC_CREAT | 0600);
    if(msgid == -1)
    {
        perror("Error msgget\n");
        exit(0x1);
    }

    int loop = 1;
     while(loop)
    {
        puts("Podaj wiadomosc: ");
        scanf("%s",msg.content);
        if(strcmp(msg.content,"exit") == 0)
        {
            msg.type = 2;
            loop = 0;
        }
        if(msgsnd(msgid,&msg,100,0) == -1)
        {
            perror("error msgsnd\n");
            exit(0x1);
        }
    }

    return 0;
}