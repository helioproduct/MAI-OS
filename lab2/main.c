#include <stdio.h>
#include "unistd.h"

double calclulate_sum()
{
    printf("%s", "pass...\n");
}

int main()
{
    int fildes[2];
    
    if (pipe(fildes) == -1) {
        perror("pipe open error");
        return -1;
    }

    int id = fork();
    if (id == -1) {
        perror("fork error");
        return -2;
    }
    if (id == 0) {
        printf("%s\n", "child");
        printf("pid = %d\n", getpid());
        calclulate_sum();
    }
    else {
        printf("%s\n", "parent");
        printf("%d\n", getpid());
    }

    return 0;
}