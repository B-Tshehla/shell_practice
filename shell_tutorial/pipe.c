#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
	int fd[2];
	// 0 read , 1 write
	if (pipe(fd) == -1)
	{
		printf("An error ocurred with opening the pipe\n");
		return 1;
	}
	int id = fork();
	
	if (id == 0)
	{
		int x;
		
		close (fd[0]);
		
		printf("Input a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else 
	{
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("Got from child process %d\n",y);
	}
	
	
	
	return 0;
	
}
