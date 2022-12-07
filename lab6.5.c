#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define SIZE_BUFF 500

void main(int argc, char const *argv[])
{
	char str[SIZE_BUFF];
	char *arg[3];
	arg[2] = NULL;
	char *name = NULL;
	char *opt = NULL;
	int i = 0;
	pid_t pid;
	int res = 0;
	while(1){
		printf("%s$",getenv("USER"));
		gets(str);

		if(strlen(str)>SIZE_BUFF){
			printf("Error command\n");
			continue;
		}

		if(!strcmp(str,"stop"))
			exit(0);
		//нахождение имени по пробелу или концу строки
		for(i=0;(str[i]!=' ')&&(str[i]!='\0');i++);

		strncpy(name =realloc(name,sizeof(char)*(i+1)),str,i);
		*(name + i)='\0';
		arg[0]=name;
		if(i==strlen(str)){
			arg[1]=NULL;
		}
		else{
			strncpy(opt =realloc(opt,(strlen(str)-i+1)),str+i+1,strlen(str)-i);
			*(opt+strlen(str)-i)='\0';
			arg[1]=opt;
		}
		pid=fork();
		if (pid==0){
			execvp(name ,arg); 
			printf("Error not found prog\n");
			system("ps");
		} else if(pid>0){
			wait(&res);
			//printf("\n%s\n",str);
			printf("Result %i\n",res;
		}
	}
	free(name);
	return 0;
}
