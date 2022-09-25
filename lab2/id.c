#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int id = fork();
    if (id == 0) {
        // parent process dies before child
        sleep(1);
    }
    printf("Current ID: %d , parent's ID: %d\n", getpid(), 
                                                 getppid());
    if (id != 0) {
        // wait for child process
        wait(NULL);
    }
    return 0;
}