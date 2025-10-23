#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *path = argv[1];
    struct stat fileStat;

    if (lstat(path, &fileStat) == -1) {
        perror("Error: cannot access file");
        return 1;
    }

    printf("File Path: %s\n", path);

    printf("File Type: ");
    if (S_ISREG(fileStat.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(fileStat.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(fileStat.st_mode))
        printf("Symbolic Link\n");
    else
        printf("Other\n");

    printf("Size: %ld bytes\n", fileStat.st_size);

    char timebuf[80];
    struct tm *timeinfo = localtime(&fileStat.st_mtime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("Last Modified: %s\n", timebuf);

    return 0;
}
