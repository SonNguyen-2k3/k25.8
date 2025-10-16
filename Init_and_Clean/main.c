#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        printf("Child process:\n");
        printf("PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(10);
    } 
    else {
        printf("Parent process:\n");
        printf("PID = %d, Child PID = %d\n", getpid(), pid);

        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child exited normally with code %d\n", WEXITSTATUS(status));
        } else {
            printf("Child did not terminate normally.\n");
        }
    }

    return 0;
}
