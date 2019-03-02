#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGKEY 231456

struct msg_type
{
    long type;
    int content;
};

int main()
{
    int msgid = msgget(MSGKEY,IPC_CREAT | 0666);
    struct msg_type msg;

    pid_t child = fork();
    if(child == -1)
    {
        puts("error");
        return 1;
    }
    if(child == 0)
    {
        msg.type = 1;
        msg.content = getpid();
        msgsnd(msgid,&msg,sizeof(int),0);
    }
    else
    {
        child = fork();
        if(child == -1)
        {
            puts("error");
            return 2;
        }
        if(child == 0)
        {
            msg.type = 1;
            msg.content = getpid();
            msgsnd(msgid,&msg,sizeof(int),0);
        }
        else
        {
            for(int i = 0;i<2;++i)
            {
                msgrcv(msgid,&msg,sizeof(int),0,0);
                printf("PID: %d\n",msg.content);
            }
            msgctl(msgid,IPC_RMID,NULL);
        }

    }
    return 0;
}