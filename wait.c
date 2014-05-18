#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int spawn (char* program, char** arg_list)
{
	pid_t child_pid;
/* Duplicate this process. */
	child_pid = fork ();
	if (child_pid != 0)
/* This is the parent process. */
		return child_pid;
	else {
/* Now execute PROGRAM, searching for it in the path. */
		execvp (program, arg_list);
/* The execvp function returns only if an error occurs. */
	fprintf (stderr, "an error occurred in execvp\n");
	}	
}

int main ()
{
	int child_status;
	char* arg_list[] = {
		"ls",
		"-l",
		"/home",
		NULL
	};

	spawn ("ls", arg_list);

	wait (&child_status);
	if (WIFEXITED (child_status))
		printf("the child process exited normally, with exit code %d\n"				,WEXITSTATUS (child_status));
	else
		printf("the child process exited abnormally\n");
	return 0;
}
