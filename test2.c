#include <stdio.h>
#include <time.h>
#include <syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/ipc.h>
#include <stdlib.h>
int main() {
	pid_t pid;
	pid = fork();
	printf("pid: %d\n", pid);
	time_t time1, time2;
	int c1, c2
	int addr = -2;

	c1 = clock();
	time1 = time(NULL);

	if(nice(addr) == -1) {
		printf("err\n");
		// return 0;
	}
	printf("prio: %d\n", getpriority(PRIO_PROCESS, 0));
	
	asaBusyWait(4);
	time2 = time(NULL);
	c2 = clock();

	if(pid != 0)
		printf("parent: %ld, %d\n", (time2 - time1), (c2 - c1));
	else
		printf("child: %ld, %d\n", (time2 - time1), (c2 - c1));
	return 0;
}


int asaBusyWait(double w)
{
  clock_t start, end;
  start=clock();
  end=clock();
  while( ( (double)(end-start)/CLOCKS_PER_SEC ) <w)
    end=clock();
}