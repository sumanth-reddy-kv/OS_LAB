//umask()
#include<sys/stat.h>
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
       printf("This umask() sets the file mode while creation.\n");

//create and  open()  
    fd=creat("mask.txt",S_IRWXU);

    int file_desc = open("mask.txt",O_CREAT | O_RDWR);
    write(file_desc,"hello",5);
    umask(S_IRUSR);
    
    return 0;
}

