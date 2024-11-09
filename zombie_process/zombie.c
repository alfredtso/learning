#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t child_pid;
    child_pid = fork();
    if (child_pid > 0) {
        sleep(3);
        printf("Child process: %d\n", child_pid);
        printf("Parent process: %d\n", getpid());
        printf("This is when the child process is a zombie, check grep\n");
        sleep(5);
        wait(NULL);
        printf("This is when the wait syscall is done, check grep\n");
        sleep(5);
    } else {
        exit(0);
    }
    return 0;
}
