#include<stdio.h>
#include<dirent.h>
#include<string.h>
int main(int argc,char* argv[])
{
	DIR *d;
	char *position;
	struct dirent *dir;
	int i=0;
	if(argc!=2)
	{
		printf("Provide sufficient args");
	}
	else
	{
		d=opendir(".");
		if(d)
		{
			while((dir=readdir(d))!=NULL)
			{
				position=strstr(dir->d_name,argv[1]);
				i=position-dir->d_name;
				if(i==0)
					printf("%s\n",dir->d_name);
			}
			closedir(d);
		}
		return(0);
	}
}

					
