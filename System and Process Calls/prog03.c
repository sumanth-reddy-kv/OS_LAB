//dup()

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
       printf("This dup() system call creates a copy of the file descripter.\n");

//create and  open()  
    fd=creat("dup.txt",S_IRWXU);

    int file_desc = open("dup.txt",O_CREAT | O_RDWR); 

    write(fd,"This will be output to the file named dup.txt\n", 46);

      
    if(file_desc < 0) 
        printf("Error opening the file\n"); 
      
// dup()  
    int copy_desc = dup(file_desc); 
          
// write()
    write(copy_desc,"This will be output to the file named dup.txt\n", 46); 
          
    write(file_desc,"This will also be output to the file named dup.txt\n", 51); 
      
    return 0; 
} 
