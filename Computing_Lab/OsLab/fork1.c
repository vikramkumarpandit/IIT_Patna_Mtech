#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    pid_t p = fork();

    if (p < 0) {
        printf("Fork creation is Unsuccessful\n");
    }
    else if (p == 0) {
        printf("This is Child Process & Pid = %d\n", getpid());
    }
    else {
        printf("This is Parent Process & Pid = %d\n", getpid());
    }

    return 0;
}
