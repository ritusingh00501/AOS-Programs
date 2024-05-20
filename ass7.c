#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	if(argc != 2)
		return 1;
	int file=0;
	if((file=open(argv[1],O_RDONLY)) < -1)
		return 1;

	struct stat fileStat;
	if(fstat(file,&fileStat) < 0)
		return 1;
	printf("Information for %s\n",argv[1]);
	printf("----------------------------\n");
	
	printf("File size:%lld bytes \n", (long long) fileStat.st_size);
	printf("No of hard links: %ld\n",(long) fileStat.st_nlink);
	printf("File Inode :%ld\n",(long) fileStat.st_ino);
	printf("File Permissions : \t");
	printf(S_ISDIR(fileStat.st_mode) ? "d" : "-");
	printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n");
	close(file);
	return 0;
}



