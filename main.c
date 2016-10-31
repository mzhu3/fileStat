#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    struct stat buffer;
    int init = stat("file.txt", &buffer);
    printf("File Size: %lu\n", buffer.st_size);
    printf("mode: %o\n", buffer.st_mode);
    printf("Last Access: %s\n", ctime(&buffer.st_atime));
    return 0;
}
