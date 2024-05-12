#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>

void *threadFact(void*data){                        //factorial 구하는 함수
        int num = *((int*)data);                    //parameter로 받은 값 int형으로 저장한다.
        int tmp=0,fac=1;                            //tmp는 곱하기위한 수가 저장되는 변수, fac는 결과값이 저장되는 변수

        while(tmp<num){                             //1부터 num까지 곱하기 위해, tmp값이 num보다 작을 때에만 반복문 수행
                tmp++;                              //tmp에 1을 더한다.
                fac *=tmp;                          //fac값과 tmp값을 곱한다.   
        }

        printf("sumfact : sum = %d\n", fac);        //factorial 결과값 출력한다.
}


void *threadCount(void* data){                      //1부터 n까지 더하는 함수
        int n =*((int*)data);                       //parameter로 받은 값 int형으로 저장한다.
        int result=0;                               //결과값이 저장되는 변수 
        int i;                                      //for문에 사용할 변수

        for(i=1; i<n+1; i++){                       //1부터 n까지의 값 더한다.
                result+=i;
        }
        printf("sumfact : sum = %d\n", result);     //모두 더한값 result 출력한다.
}


int main(int argc, void* argv[]){
        int n = atoi(argv[1]);                                                  //명령인수로 받은 값을 int 형으로 저장한다.
        int i;                                                                  //for문에 사용할 변수
        pthread_t *thread_id=malloc(sizeof(pthread_t)*n);                       //입력 받은 개수 만큼 thread를 생성하기 위해서 thread 정보 저장할 배열 동적 할당한다.

        pthread_create(&thread_id[0], NULL, threadFact, (void*)&n);             //첫 번째 thread 생성하고 실행한다. 이때 첫 번째 thread는 n의 factorial구하는 함수 수행한다.

        for(i=1; i<n; i++){                                                         
                pthread_create(&thread_id[i], NULL, threadCount, (void *)&n);   //첫 번째를 제외한 나머지 thread를 생성하고 실행한다. 이때 생성된 thread는 1부터 n까지의 값을 모두 더하는 함수 수행한다.
        }

        for(i=0; i<n; i++){                                                     //생성된 n개의 thread들이 모두 종료할 때까지 main thread 대기한다.
                pthread_join(thread_id[i], NULL);
        }

        return 0;
}
