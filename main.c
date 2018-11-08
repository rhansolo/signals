#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    printf("\nI will be leaving now due to a SIGINT. TOodles!\n");
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
