#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main (int argc, char ** argv)
{
 	pid_t pid;
	printf("FORK \n");
	pid=fork();
	if(pid==0){
		time_t now = time(NULL);
		int count=0;
		while(time(NULL) != now)
			count++;
		printf("Child ID = %ld count = %ld\n",getpid(),count);
	}else if(pid > 0){
		time_t now = time(NULL);
		int count = 0;
		while(time(NULL) != now)
			count++;
		printf("Parent ID = %ld count = %ld\n",getpid(),count);
	}else printf("Error\n");
	return 0;
}

