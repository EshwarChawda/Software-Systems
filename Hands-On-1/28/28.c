/*
============================================================================
Name : 28.c
Author : Eshwar Chawda
Description : Write a program to get maximum and minimum real time priority.
SCHED_RR).
Date: 27th August, 2024.
============================================================================
*/

#include <stdio.h>
#include <sched.h>
int main()
{
    printf("Maximum priority and Minimum priority of SCHED_FIFO scheduling is %d and %d respectively\n", sched_get_priority_max(SCHED_FIFO), sched_get_priority_min(SCHED_FIFO));
    printf("Maximum priority and Minimum priority of SCHED_RR scheduling is %d and %d respectively\n", sched_get_priority_max(SCHED_RR), sched_get_priority_min(SCHED_RR));
    printf("Maximum priority and Minimum priority of SCHED_OTHER scheduling is %d and %d respectively\n", sched_get_priority_max(SCHED_OTHER), sched_get_priority_min(SCHED_OTHER));
    return 0;
}

/*
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/28$ gcc 28.c -o 28
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/SS_ass/28$ ./28
Maximum priority and Minimum priority of SCHED_FIFO scheduling is 99 and 1 respectively
Maximum priority and Minimum priority of SCHED_RR scheduling is 99 and 1 respectively
Maximum priority and Minimum priority of SCHED_OTHER scheduling is 0 and 0 respectively

*/
