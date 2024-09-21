/*
============================================================================
Name : 26.c
Author : Eshwar Chawda
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 14th Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct mesg_buffer
{
    /* data */
    long mesg_type;
    char mesg_text[100];
} mesg_buffer;
int main()
{
    /* code */
    mesg_buffer message;
    // generate unique no
    key_t key = ftok(".", 1); // projext path is current directory and project id=1
    // create massage queue using msgget
    //  msgget creates a message queue
    //  and returns identifier
    int msgid = msgget(key, 0666 | IPC_CREAT);
    printf("enter msgtype:\n");
    scanf("%ld", &message.mesg_type);
    printf("enter data: \n");
    getchar();
    fgets(message.mesg_text, 100, stdin);
    msgsnd(msgid, &message, sizeof(message), 0);
    return 0;
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/26$ gcc 26.c -o 26
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/26$ ./26
enter msgtype:
1     
enter data: 
data
============================================================================
*/
