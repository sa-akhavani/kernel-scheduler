#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argv, char *argc[]){
	printf("start\n");
	int forks = atoi(argc[1]);
	int i;
	int pid;

	for(i = 0; i < forks;i++){
		pid = fork();
		if(pid == 0)
			break;	
	}
	printf("i am process %d with pid %d (user: %s)\n", i, getpid(), argc[2]);
	while(wait(NULL)>0);
	return 0;
}
