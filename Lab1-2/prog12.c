#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

int main()
{
        int fd;
       printf("This ioctl() is contrl device function. It msnipulates the underlying device parameters and requires special permission.\n");

//create and  open() 
 
    fd=creat("ioctl.txt",S_IRWXU);

    int file_desc = open("ioctl.txt",O_CREAT | O_RDWR);

    write(file_desc,"This will be output to the file named ioctl.txt\n", 46);

//    int ioc=ioctl(file_desc,unsigned long (request),...);
    return 0;
}

