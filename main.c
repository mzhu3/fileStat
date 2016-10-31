#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char * convertSize(unsigned long size){
  char *suffix[4] = {"B", "Kb","Mb","Gb"};
  int suffIndex = 0 ;
  int end = 0;
  char ans[256];
  if(size < 1024){
    sprintf(ans,"%d",size);
    strcat(ans,suffix[suffIndex]);
    return ans;
  }
  else{
    while(size / 1024){
      suffIndex ++;
      size = size /1024;
      end = size;
    }
  }
  sprintf(ans,"%d",end);
  strcat(ans,suffix[suffIndex]);
  return ans;
}
  int main() {
    struct stat buffer;
    int init = stat("file.txt", &buffer);
    printf("File Size: %lu\n", buffer.st_size);
    printf("File Size: %s\n", convertSize(buffer.st_size));
    printf("mode: %o\n", buffer.st_mode);
    printf("Last Access: %s\n", ctime(&buffer.st_atime));
    return 0;
}
