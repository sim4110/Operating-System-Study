#include<stdio.h>
#include<signal.h>
#include<windows.h>

void (*old_fun)(int);

void sigint_handler(int signum){
    printf("Ctrl-C is click\n");
    printf("program is quit\n");
    signal(SIGINT, old_fun);
}

int main(void){
    old_fun=signal(SIGINT, sigint_handler);
    while(1){
        printf("hello world\n");
        sleep(1);  //delay
    }
    return 0;
}

