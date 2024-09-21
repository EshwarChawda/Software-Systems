/*
============================================================================
Name : 27.c
Author : Eshwar Chawda
Description : Write a program to receive messages from the message queue.
 a. with 0 as a flag
 b. with IPC_NOWAIT as a flag
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
    int size_s = msgrcv(msgid, &message, sizeof(message), message.mesg_type, 0); // 0 flag will wait for msg and give us warning if message of type is not in msg queue.
    if (size_s <= 0)
    {
        perror("No message in queue\n");
    }
    else
    {
        printf("Message: %s\n", message.mesg_text);
    }
    return 0;
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/27$ gcc 27b.c -o 27b
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/27$ ./27b
enter msgtype:
^C
============================================================================
*/
