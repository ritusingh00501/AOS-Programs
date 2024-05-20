#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define buffersize 10000
int main()
{
	char source[25],destination[25];
	char buffer[buffersize];
	ssize_t read_in,write_out;
	printf("Enter source file name");
	scanf("%s",source);
	printf("%s",source);
	int sourcefiledesc=open(source,O_RDONLY);
	if(sourcefiledesc < 0)
	{
		printf("source file not exist");
	}
	else
	{
		printf("Enter destination file name");
		scanf("%s",destination);
		int destfiledesc = open(destination, O_WRONLY | O_CREAT);
		while((read_in = read(sourcefiledesc, &buffer, buffersize)) >0)
		{
			write_out = write (destfiledesc,&buffer,read_in);
		}
		if(remove(sourcefiledesc)==0)
			printf("File Deleted successfully");
		else
			printf("unable to delete the file");
		close(sourcefiledesc);
		close(destfiledesc);
	}
	return 0;
}

