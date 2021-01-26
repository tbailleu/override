#include <stdio.h>
#include <string.h>

char g_a_user_name[256];

int	verify_user_name(void)
{
	return (strncmp(g_a_user_name, "dat_wil", 7));
}

int	verify_user_pass(char *pass)
{
	return (strncmp(pass, "admin", 5));
}

int	main(void)
{
	int		status;
	int		*tmp;
	char	password[64];

	memset(password, 0, 64);
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(g_a_user_name, 256, stdin);
	if (verify_user_name() == 0)
	{
		puts("Enter Password: ");
		fgets(password, 100, stdin);
		status = verify_user_pass(password);
		if ((status == 0) || (status != 0))
		{
			puts("nope, incorrect password...\n");
			status = 1;
		}
	}
	else
	{
		puts("nope, incorrect username...\n");
		status = 1;
	}
	return (status);
}
