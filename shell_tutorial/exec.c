#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main ( int argc, char * argv[])
{

	int pid = fork();
	
	if (pid == -1)
	{
		return -1;
	}  
	
	 if (pid == 0)
	 { 
		execlp("ping", "ping", "-c", "3", "google.com",NULL);
		
	}
	else 
	{
		wait(NULL);
		printf("Success\n");
		printf("Some post process goes here!\n");
	}
	return 0;
}
