//link() and unlink()

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
       printf("This link() and unlink() system call creates a newlink to an existing file.\n");

//create and  open()  
    fd=creat("second.txt",S_IRWXU);
    int file_desc = open("second.txt",O_CREAT | O_RDWR);

    if(file_desc < 0)
        printf("Error opening the file\n");

// link() and unlink()
    int lin=link("second.txt","new_second.txt");

    write(file_desc,"This will be output to the file named second.txt\n", 49);


//    int unlin=unlink("new_second.txt");
    return 0;
}

