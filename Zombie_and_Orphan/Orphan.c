#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        printf("Child process (Zombie): PID = %d\n", getpid());
        exit(0);
    } 
    else {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        printf("Parent sleeping... check 'ps -l' or 'ps aux' to see zombie state (<defunct>)\n");
        sleep(30);
    }

    return 0;
}
