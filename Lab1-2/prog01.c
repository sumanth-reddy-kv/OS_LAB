#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

extern int errno;
void main()
{
	int fd,sz,sz2;
	char *c=(char*)calloc(100,sizeof(char));
//create
	fd=creat("first_file.txt",S_IRWXU);
	printf("%d\n",fd);
//open
	fd=open("first_file.txt",O_RDWR|O_CREAT);
	printf("%d\n",fd);

	if (fd ==-1)
    	{
        	printf("Error Number % d\n", errno);
        	perror("Program");
	}
//write
	sz=write(fd,"Hello Bro\n",strlen("Hello Bro\n"));
	printf("%d\n",sz);

	close(fd);
	fd=open("first_file.txt",O_RDONLY);

//read
	sz2=read(fd,c,10);
	c[sz]='\0';
	printf("%s\n",c);
	printf("%d\n",sz2);
//close
	int close(fd);
	printf("%d",fd);
}
