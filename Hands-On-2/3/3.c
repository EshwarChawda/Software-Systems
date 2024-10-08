/*
============================================================================
Name : 3.c
Author : Eshwar Chawda
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.  
Date: 14th Sep, 2024.
============================================================================
*/
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
void print(char *text, rlim_t soft, rlim_t hard, char *unit)
{
    printf("%s - \n", text);

    printf("\tSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", soft, unit);

    printf("\tHard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", hard, unit);
}

void main()
{
    int status;                   
    struct rlimit resourceLimits; 
    printf("before updatimg limits");
    
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_STACK!");
    else
        print("Maximum  size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    printf("Choosing new resource limits\n");
    struct rlimit newresourceLimits; 
    newresourceLimits.rlim_cur=10000;
    newresourceLimits.rlim_max=20000;
    status = setrlimit(RLIMIT_SIGPENDING, &newresourceLimits);

    printf("after updatimg limits");
    
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_STACK!");
    else
        print("Maximum  size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
}
/*
============================================================================
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/3$ gcc 3.c -o 3
eshwar@eshwar-Lenovo-V14-IIL:~/Desktop/handson_2/3$ ./3
before updatimg limitsMaximum  size of the process stack - 
	Soft Limit: 30676 bytes
	Hard Limit: 30676 bytes
Choosing new resource limits
after updatimg limitsMaximum  size of the process stack - 
	Soft Limit: 10000 bytes
	Hard Limit: 20000 bytes
============================================================================
*/
