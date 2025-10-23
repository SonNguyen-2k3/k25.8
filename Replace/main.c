#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    char *cmd;

    setenv("MY_COMMAND", "ls", 1);

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        cmd = getenv("MY_COMMAND");
        if (cmd == NULL) {
            printf("Không tìm thấy biến môi trường MY_COMMAND\n");
            exit(1);
        }

        printf("Child process: Thực thi lệnh '%s'\n", cmd);
        execlp(cmd, cmd, NULL);
        perror("exec failed");
        exit(1);
    } 
    else {
        wait(NULL);
        printf("Parent process: Child has finished.\n");
    }

    return 0;
}
