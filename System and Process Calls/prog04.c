//acess()
//F_OK flag : Used to check for existence of file.
//R_OK flag : Used to check for read permission bit.
//W_OK flag : Used to check for write permission bit.
//X_OK flag : Used to check for execute permission bit.
#include<stdio.h> 
#include<unistd.h> 
#include<errno.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<fcntl.h> 
  
extern int errno; 
  
int main()
{ 
    int file_desc=creat("sample.txt",S_IRWXU);
    int fd = access("sample.txt", X_OK); 
    if(fd == -1){ 
            printf("Error Number : %d\n", errno); 
        perror("Error Description:"); 
    } 
        else
                printf("No error\n"); 
    return 0; 
} 
