//get sys calls family
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
	printf("This is get sys calls family.\n");
printf("Get a real user ID:%d\n", getuid());
printf("Get the effective user ID:%d\n", geteuid());
printf("Get the real group ID:%d\n", getgid());
printf("Get the effective group ID:%d\n", getegid());
printf("Get the process ID (PID):%d\n",getpid());
printf("Get the process ID of the parent (PID):%d\n ",getppid());
return 0;
}
