#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal){
	if(signal == SIGALRM)
		printf("Sinal recebido! ID do sinal = %d\n", signal);
}

int main(){
	pid_t pid;

	signal(SIGALRM, signal_handler);

	pid = fork();

	if(pid < 0){
		perror("Error at forking process\n");
	}
	// Parent
	else if(pid > 0){
		pause();

	}
	// Child
	else{ 
		sleep(5);
		kill(getppid(), SIGALRM);
	}
}