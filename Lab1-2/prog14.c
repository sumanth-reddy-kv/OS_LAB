#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
    printf("Back to example.c\n");
    printf("PID of hello.c = %d\n", getpid());
    return 0;
}
