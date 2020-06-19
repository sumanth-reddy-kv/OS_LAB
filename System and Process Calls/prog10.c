//chown()
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
       printf("This chown() system call changes the ownership of the file. Ownership changes requires special permission.\n");

//create and  open()  
    fd=creat("owner.txt",S_IRWXU);

    int file_desc = open("owner.txt",O_CREAT | O_RDWR);

    if(file_desc<0)
            printf("Error");

    write(file_desc,"This will be output to the file named owner.txt\n", 48);
    int chow=chown("owner.txt",/*user*/,/*another user/owner*/);

    return 0;
}

