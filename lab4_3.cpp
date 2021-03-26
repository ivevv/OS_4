//Иванчук Евгения, 9894, 4й вариант

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sched.h>

#define STACKSIZE (1024*1024)

using namespace std;

static int child(void *arg)
{
	cout << "ID of lab4_3's child: " << getpid() << endl;
	char *envp = (char*) arg;
	//execlpe("lab4_1", "lab4_1", "arg1", "arg2", "arg3", NULL, envp);
	execle("lab4_1", "lab4_1", "arg1", "arg2", "arg3", NULL, envp);
	return 0;
}

int main(int argc, char *argv[], char *envp[])
{
	char *stack;
	char *stackhead;
	stack = (char*)malloc(STACKSIZE);
	stackhead = stack + STACKSIZE - 1;
	cout << "ID of lab4_3: " << getpid() << endl;
	cout << "ID of lab4_3's parent: " << getppid() << endl;
	int pid = clone(child, stackhead, SIGCHLD, envp);
	if (pid == -1)
	{
		cout << "Can't create process" << endl;
		free(stack);
		exit(1);
	}
	int stat;
	while (waitpid(pid, &stat, WNOHANG) == 0)
	{
		usleep(500000);
	}
	if (WIFEXITED(stat) != 0)
	{
		cout << "Return value of lab4_1: " << WEXITSTATUS(stat) << endl;
	}
	free(stack);
	return 0;
}
