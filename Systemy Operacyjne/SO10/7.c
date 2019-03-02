#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>


struct msg_type
{
    long type;
    int content;
};

#define MSGKEY 213546


int main()
{
    struct msg_type msg;
    int msgid= msgget(MSGKEY,IPC_CREAT | 0600);
    if(msgid == -1)
    {
        perror("Error msgget\n");
        exit(0x1);
    }

    pid_t child = fork();
    if(child == -1)
    {
        perror("Error fork\n");
        exit(0x2);
    }
    if(child == 0)
    {
        for(int i = 1;i<=10000;++i)
        {
            if(i%3 == 0)
            {
                msg.type = 1;
                msg.content = i;
                msgsnd(msgid,&msg,sizeof(msg.content),0);
            }
            if(i%4 == 0)
            {
                msg.type = 2;
                msg.content = i;
                msgsnd(msgid,&msg,sizeof(msg.content),0);
            }
        }
    }
    else
    {
        for(int i = 0;i<5833;++i)
        {
            msgrcv(msgid,&msg,sizeof(msg.content),0,0);
            printf("%ld %d\n",msg.type,msg.content);
        }

        msgctl(msgid,IPC_RMID,NULL);
    }


    return 0;
}