#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<ctype.h>

#define MAX_PID 200

void signal_handler(int signum){
        printf("signal\n");
}

int main(int arcg, void*argv[]){
        int ppid = atoi(argv[1]);
        int pids[MAX_PID];
        int mafia[MAX_PID];
        int pid_count=0;

        DIR*proc_dir;
        struct dirent * entry;

        proc_dir = opendir("/proc");
        if(proc_dir==NULL){
                printf("/proc error\n");
                return -1;
        }

        int pid;

        while((entry=readdir(proc_dir))!=NULL){
                if(isdigit((*entry->d_name))){
                        pid = atoi(entry->d_name);
                        if(ppid<pid && pid_count<MAX_PID-1){
                                pids[pid_count++]=pid;
                        }
                }
        }

        int i;
        int result;

        signal(SIGUSR1,signal_handler);
        for(i=0; i<pid_count;i++){
                if(pids[i]!=getpid())
                        result=kill(pids[i],SIGUSR1);
                sleep(2);
        }

        FILE*file=fopen("confession.txt","r");
        char line[5];
        int mafia_cnt=0;
        int line_cnt=0;

        while(1){
                fgets(line,sizeof(line),file);
                if(line_cnt==200) break;
                if(strcmp(line,"!!!\n")==0){
                        mafia[mafia_cnt]=pids[line_cnt];
                        mafia_cnt++;
                }
        //      printf("%d : %s ",line_cnt,line);
                line_cnt++;
        }
        //printf("\n");


        int j;
        pid_count++;
        printf("mafia = %d\n", mafia_cnt);
        printf("citizen = %d\n",pid_count-mafia_cnt);
        printf("=== mafia list ===\n\n");

        for(j=0; j<mafia_cnt; j++){
                printf("%d\n",mafia[j]);
        }
        return 0;
}
