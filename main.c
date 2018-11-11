#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    int file = open("out.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    char tmp[] = "Program ended due to SIGINT";
    write(file,tmp,27);
    close(file);
    exit(2);
  }
  if (signo == SIGUSR1){
    printf("%d \n", getppid());
  }
}
int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while (1){
    printf("Hello Im %d\n",getpid());
    sleep(1);
  }
}
