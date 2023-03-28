#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int arc, char*ar[]){
    int pid;
    char s[100];
    pid = fork();
    
    if(pid < 0){
        printf("error");
    } else if (pid > 0){
        wait(NULL);
        printf("\nParent Procss: \n");
        printf("Parent Process id: %d\n", getpid());

        execlp("cat","cat", ar[1], (char*)0);
        perror("can't execute cat");
    } else {
        printf("\nChild process: \n");
        printf("Childprocess parent id: %d\n", getppid());
        printf("Child Process id: %d\n", getpid());

        write(1,s,strlen(s));
        
        execvp(ar[2], &ar[2]);
        perror("Can't execute write operation");
    }

    return 0;
}

