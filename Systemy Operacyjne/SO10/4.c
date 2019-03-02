#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TYP1 1
#define TYP2 2

struct msg_type
{
    long type;
    int value;
};

void Proces1(int msgid);
void Proces2(int msgid);

int main()
{
    int msgid;
    struct msg_type elem;
    
    msgid = msgget(123456,IPC_CREAT | IPC_EXCL | 0600);
    if(msgid == -1)
    {
        msgid = msgget(123456,IPC_CREAT | 0600);
        if(msgid == -1)
        {
            perror("ERROR - tworzenie kolejki\n");
            exit(2);
        }
    }
    
    if(fork() == 0)
    {
        Proces1(msgid); 
        if(fork() == 0)
        {
            Proces2(msgid);
            exit(0);
        }
        exit(0);
    }
   
    int i = 500/4 + 1000/5 + 2;
    while(i>0)
    {
        if(msgrcv(msgid,&elem,sizeof(elem.value),0,0) == -1)
        {
            perror("ERROR - odbieranie\n");
            exit(0xf);
        }
        printf("%d\n",elem.value);
        --i;
    }
    
    msgctl(msgid,IPC_RMID,NULL);
    
    return 0;
}

void Proces1(int msgid)
{
    struct msg_type elem;
    elem.type = TYP2;
    for(int i = 0;i<=500;i+=4)
    {
        elem.value = i;
        if(msgsnd(msgid,&elem,sizeof(elem.value),0) == -1)
        {
            perror("ERROR - send proces 1\n");
            exit(3);
        }
    }
}

void Proces2(int msgid)
{
    struct msg_type elem;
    elem.type = TYP1;
    for(int i = 0;i<=1000;i+=5)
    {
        elem.value = i;
        if(msgsnd(msgid,&elem,sizeof(elem.value),0) == -1)
        {
            perror("ERROR - send proces 2\n");
            exit(4);
        }
    }
}
