#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

struct msg_type
{
    long mtype;
    int content;
};

#define MSGKEY 231546

int main(int argc, char* argv[])
{
    int msgid = msgget(MSGKEY,IPC_CREAT | 0600);
    struct msg_type msg;
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
        for(int i = 1;i<=10;++i)
        {
            msg.mtype = i;
            msg.content = i*2*2;
            msgsnd(msgid,&msg,sizeof(msg.content),0);
        }
    }
    else
    {
        int msgtype = atoi(argv[1]);
        msgrcv(msgid,&msg,sizeof(msg.content),msgtype,0);
        printf("%d\n",msg.content);
        msgctl(msgid,IPC_RMID,NULL);
    }

    return 0;
}
