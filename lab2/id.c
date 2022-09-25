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
    int res = wait(NULL);

    if (res == -1) {
        printf("No children to wait\n");
    } else {
        printf("%d finished execution\n", getpid());
    } 
    
    return 0;
}