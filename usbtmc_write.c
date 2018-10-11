#include <sys/ioctl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
  
  int instr,i,length;
  char* ret;
  char* cmd;
  ret = (char*)malloc(128);
  cmd = (char*)malloc(128);
  if(argc<2){
    printf("Usage: usbtmc_query cmd\n");
    return 1;
  }
  instr = open("/dev/usbtmc0", O_RDWR);
  sprintf(cmd, "%s\n", argv[1]);
  length=strlen(argv[1])+1;
  write(instr, cmd, length);
  return 0;
}
