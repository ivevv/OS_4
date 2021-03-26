//Иванчук Евгения, 9894, 4й вариант

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	int pid = fork();
	if (pid == 0)
	{
		cout << "ID of lab4_2's child: " << getpid() << endl;
		//execlpe("lab4_1", "lab4_1", "arg1", "arg2", "arg3", NULL, envp);
		execle("lab4_1", "lab4_1", "arg1", "arg2", "arg3", NULL, envp);
	}
	else
	{
		cout << "ID of lab4_2: " << getpid() << endl;
		cout << "ID of lab4_2's parent: " << getppid() << endl;
		int stat;
		while (waitpid(pid, &stat, WNOHANG) == 0)
		{
			usleep(500000);
		}
		if (WIFEXITED(stat) != 0)
		{
			cout << "Return value of lab4_1: " << WEXITSTATUS(stat) << endl;
		}
	}
	return 0;
}
