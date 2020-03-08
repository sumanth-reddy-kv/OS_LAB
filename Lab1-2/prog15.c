#include<stdio.h> 
#include<signal.h>

  void handle_sigint(void) 
{ 
    printf("Caught signal \n"); 
} 
  
int main() 
{ 
    signal(SIGINT, handle_sigint); 
    while (1) 
    { 
        printf("hello world\n");  
    } 
    return 0; 
} 
