#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
        int fd;
       printf("This excel() call is used to stop the current process and start another.\n");


    printf("PID of example.c = %d\n", getpid());
	char *args[]={"Hello","C","Programming",NULL};

    execv("./prog14.c",args);
    
    printf("Back to example.c");

    return 0;
}
