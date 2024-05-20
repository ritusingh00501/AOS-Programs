#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
#include<sys/times.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(void)
{
	int i,status;
	pid_t pid;
	time_t currentTime;
	struct tms cpuTime;
	if((pid=fork())==-1) //start child process
	{
		perror("\n fork error");
		exit(EXIT_FAILURE);
	}
	else if(pid==0) //child process
	{
		time(&currentTime);
		printf("\n child process started at %s", ctime(&currentTime));
		for(i=0;i<5;i++)
		{
			printf("\n Counting = %dn",i); //count for 5 second
			sleep(1);
		}
		time(&currentTime);
		printf("\n child process ended at %s", ctime(&currentTime));
		exit(EXIT_SUCCESS);
	}
	else
	{
		//parent process
		time(&currentTime); //gives normal time
		printf("\n parent process started at %s", ctime(&currentTime));
		if(wait(&status)==-1) //wait for child process
			perror("\n wait error");
		if(WIFEXITED(status))
			printf("\n child process did not end normally");
		if(times(&cpuTime)<0) //get process time
			perror("\n Times error");
		else
		{
			//_SC_CLK_TCK:system configuration time:sec clock tick.
			printf("\n parent process user time= %fn",((double)cpuTime.tms_utime));
			printf("\n parent process system time= %fn",((double)cpuTime.tms_stime));
			printf("\n child process user time= %fn",((double)cpuTime.tms_cutime));
			printf("\n child process system time= %fn",((double)cpuTime.tms_cstime));
		}
		time(&currentTime);
		printf("\n parent process ended at %s", ctime(&currentTime));
		exit(EXIT_SUCCESS);
	}
}

