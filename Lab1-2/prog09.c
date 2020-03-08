//chmod()

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
        int fd;
       printf("This chmod() system call changes the permission of the file.\n");

//create and  open()  
    fd=creat("home.txt",S_IRWXU);
    fd=open("home.txt",O_RDWR|O_CREAT);
    write(fd,"This will be output to the file named chmod.txt\n", 48);
//chmod()
    int chmd=chmod("home.txt",S_IRUSR);

    return 0; 
}
