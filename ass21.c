#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	int status;
	pid=fork();

	if (pid < 0)
	{
		//error ocurred
		fprintf(stderr,"Fork failed\n");
		return 1;
	}
	else if(pid == 0)
	{
		//child process
		printf("child process running \n");
		//simulating some work before exit
		sleep(2);
		//simulating different exit status
		int exit_status = rand() % 100;
		printf("child process exiting with status: %d\n", exit_status);
		exit(exit_status);
	}
	else
	{
		//parent process
		printf("parent process waiting for child to terminate\n");
		waitpid(pid,&status,0);
		if(WIFEXITED(status))
		{
			printf("child process exited with status: %d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("child process exited abnormally \n");
		}
	}
}

