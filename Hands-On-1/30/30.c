/*
============================================================================
Name : 30.c
Author : Eshwar Chawda
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 27th August, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(int argc, char *argv[])
{
    time_t curr, dead;
    struct tm *deadline;

    time(&curr); // store current time in epoch
    deadline = localtime(&curr);

    // take time from terminal
    deadline->tm_hour = atoi(argv[1]);
    deadline->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);
    deadline->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);

    dead = mktime(deadline); // convert time to epoch

    int cid = fork();
    if (cid == 0)
    {
        // as parent is executed so chile becomes orphan using sessid it will become demon process;
        setsid();
        do
        {
            time(&curr); // get curr time
        } while (difftime(dead, curr) > 0);
        // run untill current time becomes deadline
        system("echo Current user=$USER");
    }
    else
    {
        exit(0);
    }
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/30$ ./30 22 00
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/30$ Current user=eshwar


*/
