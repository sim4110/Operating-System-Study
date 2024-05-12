#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, void*argv[]){
        int n=atoi(argv[1]);                              //실행 시 입력받은 값을 int 형으로 저장한다.
        int i;
        pid_t pid;
        int result=0;

        pid = fork();                                     //fork()함수로 child 프로세스 생성한다. 이때 pid 값으로  child 프로세스에서는 0이 저장되고, parent 프로세스에서는 child 프로세스의 pid값이 저장된다.

        //child process
        if(pid==0){ 
                printf("launch : start sumfact %d\n", n); //sumfact를 실행한다는 내용을 출력한다.
                execl("sumfact","./sumfact",argv[1],NULL);  //execl()함수를 사용해 프로세스를 sumfact 실행파일의 내용으로 변경해 실행한다. 
        }


        //parent process
        else{
                for(i=0; i<n+1; i++){                     //0부터 입력한 숫자까지 모두 더한다.
                        result+=i;
                }
                printf("launch : sum = %d\n", result);   //모두 더한 값을 출력한다.
                wait(NULL);                              //child 프로세스가 종료되기 전까지 대기한다.
        }

        return 0;
}
