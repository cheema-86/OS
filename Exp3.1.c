#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
char buffer[2048];

int main(int argc,char *argv[]){
    int fold,fnew;

    if(argc!=3){
        printf("Needs more argument");
        exit(0);
    }
    printf("Argumant %s",argv[0]);
    printf("File1 %s",argv[1]);
    printf("File 2 %s",argv[2]);
    fold=open(argv[1],O_RDONLY);

    if(fold==-1){
        printf("Cannot open %s",argv[1]);
        exit(0);
    }

    fnew=creat(argv[2],0666);

    if(fnew==-1){
        printf("cannot open %s",argv[2]);
        exit(0);
    }

    copy(fold,fnew);
    exit(0);
}

copy(old,new)
int new,old;{
    int count;
    while((count=read(old,buffer,sizeof(buffer)))>0)
    write(new,buffer,count);
}

