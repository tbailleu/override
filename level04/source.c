#include <string.h>
#include <unistd.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

int		main(void)
{
	int		pid;
	int		stat_loc = 0;
	char	buffer[128];

	memset(buffer, 0, 128);
	pid = fork();
	if (pid == 0)
	{
		prctl(1, 1);
		ptrace(PT_TRACE_ME, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buffer);
	}
	else
	{
		do {
			wait(&stat_loc);
			if (WIFSIGNALED(stat_loc) == 0) {
				puts("child is exiting...");
				return (0);
			}
		} while (ptrace(PT_READ_U, pid, 44, 0) != 11)
		puts("no exec() for you");
		kill(pid, SIGKILL);
	}
	return (0);
}
