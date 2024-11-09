#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  pid_t child_pid;
  child_pid = fork();
  if (child_pid > 0) {
    printf("Child process: %d\n", child_pid);
    printf("Parent process: %d\n", getpid());
    exit(0);
  } else {
    sleep(100);
    exit(0);
  }
}
