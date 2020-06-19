//lseek()

#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

extern int errno;
void main()
{
	printf("This lseek() heps in offsetting the pointer of the file descripter.\n");

	int fd,count=0,n=5,sz;
	char *c=(char*)calloc(100,sizeof(char));
//create
	fd=creat("first_file.txt",S_IRWXU);
	fd=creat("end.txt",S_IRWXU);
	fd=open("first_file.txt",O_RDWR|O_CREAT);

//write
        sz=write(fd,"Hello Bro.How are you?Hope you enjoy your stay.\n",strlen("Hello Bro.How are you?Hope you enjoy your stay.\\n"));
        close(fd);

//open
    int f_write = open("first_file.txt", O_RDONLY); 
  
    int f_read = open("end.txt", O_WRONLY);
    
    while (read(f_write, c, 1)) 
    {
        if (count < n) 
        {
            lseek (f_write, n, SEEK_CUR); 
            write (f_read, c, 1); 
            count = n; 
        } 
  
        // After the nth byte (now taking the alternate 
        // nth byte) 
        else
        { 
            count = (2*n); 
            lseek(f_write, count, SEEK_CUR); 
            write(f_read, c, 1); 
        } 
    } 
    	close(f_write); 
    	close(f_read); 
//read
	f_read = open("end.txt", O_WRONLY);
    	sz=read(f_read,c,47);
//    	c[sz]='\0';
    	printf("%s\n",c);
    	close(f_read);
}
