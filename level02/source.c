#include <stdio.h>
#include <stdint.h>


int main(void)
{
	char	userpass[112];
	char	passwd[48];
	char	username[96];
	size_t	len;
	FILE	*fd;

	memset(username, 0, 100);
	memset(passwd, 0, 41);
	memset(userpass, 0, 100);
	fd = fopen("/home/users/level03/.pass", "r");
	if (fd == NULL) {
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}
	len = fread(passwd, 1, 41, fd);
	passwd[strcspn(passwd, "\n")] = '\0';
	if (len != 41) {
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(1);
	}
	fclose(fd);
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(username, 100, stdin);
	username[strcspn(username, "\n")] = '\0';
	printf("--[ Password: ");
	fgets(userpass, 100, stdin);
	userpass[strcspn(userpass, "\n")] = '\0';
	puts("*****************************************");
	if (strncmp(passwd, userpass, 41) == 0) {
		printf("Greetings, %s!\n", username, username);
		system("/bin/sh");
		return 0;
	}
	printf(username);
	puts(" does not have access!");
	exit(1);
}
