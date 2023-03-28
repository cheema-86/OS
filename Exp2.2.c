#include <stdio.h>
#include <unistd.h>

void main(){
    int process_id;
    int p_process_id;

    process_id = getpid();
    p_process_id = getppid();

    printf("The process id: %d\n",process_id);
    printf("The process id of parent: %d\n",p_process_id);
    
}


/*

void main(){
    printf("The process id: %d\n", getpid());
    printf("The process id of parent: %d\n", getppid());
}

*/