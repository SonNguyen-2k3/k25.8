#include "strutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

void print_current_user() {
    char *user = getenv("USER");
    if (user)
        printf("Current user: %s\n", user);
    else
        printf("Cannot get username.\n");
}

void print_current_directory() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Current directory: %s\n", cwd);
    else
        perror("getcwd() error");
}

void print_system_info() {
    struct utsname sysinfo;
    if (uname(&sysinfo) == 0) {
        printf("System: %s\n", sysinfo.sysname);
        printf("Node name: %s\n", sysinfo.nodename);
        printf("Release: %s\n", sysinfo.release);
        printf("Machine: %s\n", sysinfo.machine);
    } else {
        perror("uname() error");
    }
}
