#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
int val=0;

void handler(int sig) {
    printf("Signal handler called\n");
    printf("this process has pid: %d\n", getpid());
    val += 1;
    wait(NULL);
    printf("val: %d\n", val);
}

int main() {
    pid_t child_pid;
    child_pid = fork();
    if (child_pid > 0) {
        sleep(10);
        printf("Child process: %d\n", child_pid);
        printf("Parent process has pid: %d\n", getpid());
        printf("val: %d\n", val);
        while (1) {
            signal(SIGCHLD, handler);
        }
    } else {
        exit(0);
    }
    return 0;
}
