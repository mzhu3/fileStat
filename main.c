#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void convertSize(unsigned long size){
  char *suffix[4] = {"B", "Kb","Mb","Gb"};
  int suffIndex = 0 ;
  unsigned long end;
  char ans[256];
  while(size > 1024.0){
    suffIndex ++;
    size = size/1024.0;
  }
  end = size;
  sprintf(ans,"%lu",end);
  strcat(ans,suffix[suffIndex]);
  printf("%s\n",ans);
}

void convertToLS(int mode){
  char ans[10]= "-";
  int Octet = mode /8;
  if(mode & S_IRUSR){
    strcat(ans,"r");
  }
  else{
    strcat(ans,"-");
  }
  if(mode & S_IWUSR){
    strcat(ans,"w");
  }
  else{
    strcat(ans,"-");
  }
  if(mode & S_IXUSR){
    strcat(ans,"X");
  }
  else{
    strcat(ans,"-");
  }
  if(mode & S_IRGRP){
    strcat(ans,"r");
  }
  else{
    strcat(ans,"-");
  }
  if(mode & S_IWGRP){
    strcat(ans,"w");
  }
  else{
    strcat(ans,"-");
  }
  if(mode & S_IXGRP){
    strcat(ans,"x");
  }
  else{
    strcat(ans,"-");
  }
  if(mode & S_IROTH){
    strcat(ans,"r");
  }
  else{
    strcat(ans,"-");
  }
  if(mode & S_IWOTH){
    strcat(ans,"w");
  }
  else{
    strcat(ans,"-");
  }
  if(mode & S_IXOTH){
    strcat(ans,"r");
  }
  else{
    strcat(ans,"-");
  }
  printf("%s\n",ans);
}
  int main() {
    struct stat buffer;
    int init = stat("file.txt", &buffer);
    printf("File Size: %lu\n", buffer.st_size);
    printf("File Size:");
    convertSize(buffer.st_size);
    printf("mode: %o\n", buffer.st_mode);
    printf("mode:");
    convertToLS(buffer.st_mode);
    printf("Last Access: %s\n", ctime(&buffer.st_atime));
    return 0;
}
