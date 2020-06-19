//fork()
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void forkexample()
{
    // child process because return value zero 
    if (fork() == 0)
        printf("Hello\n");

    // parent process because return value non-zero. 
    else
        printf("Hello\n");
}
int main()
{
    forkexample();
    forkexample();
       forkexample();
    forkexample();                  forkexample();
    forkexample();                  forkexample();
    forkexample();              
    return 0;
}                                                               
