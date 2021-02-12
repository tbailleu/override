#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>

int auth(char *buffer, int password)
{
	int len;
	int i;
	int value;

	buffer[strcspn(buffer, "\n")] = '\0';
	len = strnlen(buffer, 32);
	if (len < 6) return (1);
    if (ptrace(PT_TRACE_ME, 0, 1, 0) == -1)
	{
		puts("\x1b[32m.---------------------------.");
		puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
		puts("\x1b[32m\'---------------------------\'");
		return (1);
    }
	value = ((int)buffer[3] ^ 0x1337U) + 0x5eeded;
	i = -1;
	while (++i < len)
	{
		if (buffer[i] < ' ') return 1;
		value = value + ((int)buffer[i] ^ value) % 0x539;
	}
	if (password == value) return (0);
	return (1);
}


int main(void)
{
	int		password;
	char	buff[32];

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");
	fgets(buff, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &password);
	if (auth(buff, password) == 0) {
		puts("Authenticated!");
		system("/bin/sh");
		return (0);
	}
	return (1);
}
