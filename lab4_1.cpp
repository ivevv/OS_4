//Иванчук Евгения, 9894, 4й вариант

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << " ";
		cout.flush();
		sleep(2);
	}
	cout << endl << "ID of lab4_1: " << getpid() << endl;
	cout << "ID of lab4_1's parent: " << getppid() << endl;
	exit(31);
}
