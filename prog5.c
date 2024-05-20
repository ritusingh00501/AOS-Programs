#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(void)
{
	int num1,num2,sum;
	int input_fds=open("./input.txt",O_RDONLY);
	if(dup2(input_fds,STDIN_FILENO)<0)
	{
		printf("unable to duplicate the file description");
		exit(EXIT_FAILURE);
	}
	scanf("%d%d",&num1,&num2);
	sum=num1+num2;
	printf("%d+%d=%d\n",num1,num2,sum);
	return EXIT_SUCCESS;
}

