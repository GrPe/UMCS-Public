#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGKEY 213546

struct msg_type
{
    long mtype;
    char content[100];
};

int main()
{
    struct msg_type msg;
    int msgid = msgget(MSGKEY,IPC_CREAT | 0600);
    if(msgid == -1)
    {
        perror("Cannot create msg queue\n");
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

        for(int i = 2;i<=10;i+=2)
        {
            msg.mtype = i;
            for(int j = 0;j<10;++j)
            {
                sprintf(msg.content,"Proces potomny 1, komunikat %d, typ %d",j,i);
                msgsnd(msgid,&msg,sizeof(msg.content),0);
            }
        }
    }
    else
    {

        child = fork();
        if(child == -1)
        {
            perror("Error fork 2\n");
            exit(0x3);
        }
        if(child == 0)
        {
            for(int i = 1;i<=10;i+=2)
            {
                msg.mtype = i;
                for(int j = 0;j<10;++j)
                {
                    sprintf(msg.content,"Proces potomny 2, komunikat %d, typ %d",j,i);
                    msgsnd(msgid,&msg,sizeof(msg.content),0);
                }
            }
        }
        else
        {
            //msg.content=0;
            // for(int i = 1;i<=10;i++)
            // {
            //     msg.mtype = i;
            //     for(int j = 0;j<10;++j)
            //     {
            //         msgsnd(msgid,&msg,sizeof(msg.content),0);
            //     }
            // }

            for(int i = 0;i<10;++i)
            {   
                //Nie mam innego pomysłu :<
                if(msgrcv(msgid,&msg,sizeof(msg.content),5,0)==-1)
                {
                    perror("Error receive msg\n");
                    exit(0x5);
                }
                puts(msg.content);
                 if(msgrcv(msgid,&msg,sizeof(msg.content),6,0)==-1)
                {
                    perror("Error receive msg\n");
                    exit(0x5);
                }
                puts(msg.content);
                 if(msgrcv(msgid,&msg,sizeof(msg.content),7,0)==-1)
                {
                    perror("Error receive msg\n");
                    exit(0x5);
                }
                puts(msg.content);
                 if(msgrcv(msgid,&msg,sizeof(msg.content),8,0)==-1)
                {
                    perror("Error receive msg\n");
                    exit(0x5);
                }
                puts(msg.content);
                 if(msgrcv(msgid,&msg,sizeof(msg.content),9,0)==-1)
                {
                    perror("Error receive msg\n");
                    exit(0x5);
                }
                puts(msg.content); 
                if(msgrcv(msgid,&msg,sizeof(msg.content),10,0)==-1)
                {
                    perror("Error receive msg\n");
                    exit(0x5);
                }
                puts(msg.content);
            }


            msgctl(msgid,IPC_RMID,NULL);
        }
    }
    return 0;
}