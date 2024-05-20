#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void child_signal_handler(int signum)
{
	switch(signum)
	{
		case SIGHUP:
			printf("child: I have received SIGHUP \n");
			break;
		case SIGINT:
			printf("child: I have received SIGINT \n");
			break;
		case SIGQUIT:
			printf("My papa has killed me !!! \n");
			exit(0);
			break;
		default:
			printf("child: Received unexpected signal \n");
	}
}
int main()
{
	pid_t pid;
	int i;
	pid=fork();

	if(pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if(pid == 0)
	{
		//child process
		signal(SIGHUP, child_signal_handler);
		signal(SIGINT, child_signal_handler);
		signal(SIGQUIT, child_signal_handler);

		while(1)
		{
			sleep(1);
		}
	}
	else
	{
		//parent process
		//send SIGHUP or SIGINT every 3 sec for 15 sec
		for(i=1;i<=5;i++)
		{
			sleep(3);
			if(i%2==0)
			{
				printf("parent: sending SIGHUP signal \n");
				kill(pid,SIGHUP);
			}
			else
			{
				printf("parent: sending SIGINT signal \n");
				kill(pid,SIGINT);
			}
		}
		//send SIGQUIT to terminate child after 15 sec.
		sleep(3);
		printf("parent: sending SIGQUIT signal to terminate child \n");
		kill(pid,SIGQUIT);
	}
	return 0;
}


