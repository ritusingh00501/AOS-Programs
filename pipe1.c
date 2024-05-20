#include<stdio.h>
#include<unistd.h>
int main()
{
	int pipefds[2];
	int returnstatus;
	char writemessages[3][20]={"Hello World","Hello SPPU","Linux is Funny."};
	char readmessage[20];
	returnstatus=pipe(pipefds);
	if(returnstatus==-1)
	{
		printf("Unable to create pipe\n");
		return 1;
	}
	int child=fork();
	if(child==0)
	{
		printf("child is writing to pipe - message 1 is %s\n",writemessages[0]);
		write(pipefds[1],writemessages[0],sizeof(writemessages[0]));
		printf("child is writing to pipe - message 2 is %s\n",writemessages[1]);
		write(pipefds[1],writemessages[1],sizeof(writemessages[1]));
		printf("child is writing to pipe - message 3 is %s\n", writemessages[2]);
		write(pipefds[1],writemessages[2],sizeof(writemessages[2]));
	}
	else
	{
		read(pipefds[0],readmessage,sizeof(readmessage));
		printf("parent process is reading from pipe - message 1 is %s\n",readmessage);
		read(pipefds[0],readmessage,sizeof(readmessage));
		printf("parent process is reading from pipe - message 2 is %s\n",readmessage);
		read(pipefds[0],readmessage,sizeof(readmessage));
		printf("parent pricess is reading from pipe - message 3 is %s\n",readmessage);
	}
}

