#include <stdio.h>
#include <unistd.h>

#define MAX_CHAR 80
#define PIPE_IN 1
#define PIPE_OUT 0

int main(int argc, char *argv[]){
	int fds[2];
	char buff[MAX_CHAR];
	char pipeBuffOut[MAX_CHAR];
	
	int ret = pipe(fds);
	char * str = fgets(buff, MAX_CHAR, stdin);
	ret = write(fds[PIPE_IN], buff, MAX_CHAR);
	ret = read(fds[PIPE_OUT], pipeBuffOut, MAX_CHAR);
	printf("%s", pipeBuffOut);
	return 0;
}
