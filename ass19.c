#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename> \n",argv[0]);
		return 1;
	}
	char *filename=argv[1];

	//Get file status
	struct stat file_stat;
	if(stat(filename,&file_stat)==-1)
	{
		perror("Error getting file status");
		return 1;
	}

	//Extract last access & Modification times
	time_t access_time = file_stat.st_atime;
	time_t modify_time = file_stat.st_mtime;

	//Convert times to human readable format
	char access_time_str[20];
	char modify_time_str[20];
	strftime(access_time_str, sizeof(access_time_str), "%Y-%M-%d %H:%M:%S",localtime(&access_time));
	strftime(modify_time_str, sizeof(modify_time_str), "%Y-%M-%d %H:%M:%S",localtime(&modify_time));

	//Display the time
	printf("Last access time: %s\n", access_time_str);
	printf("Last modification time: %s\n", modify_time_str);
	return 0;
}
