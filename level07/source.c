#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_stdin(void)
{
	char c;

	while ((c = getchar()) != -1)
		if (c == '\n')
			break ;
}

int get_unum(void)
{
	int number;

	number = 0;
	fflush(stdout);
	scanf("%u", &number);
	clear_stdin();
	return (number);
}

int store_number(int *database)
{
	unsigned int	number;
	unsigned int	index;
	int				error;

	printf(" Number: ");
	number = get_unum();
	printf(" Index: ");
	index = get_unum();
	if ((index % 3 == 0) || (number >> 24 == 0xb7))
	{
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		error = 1;
	}
	else
	{
		database[index] = number;
		error = 0;
	}
	return error;
}


int read_number(int *database)
{
	int index;

	printf(" Index: ");
	index = get_unum();
	printf(" Number at data[%u] is %u\n", index, database[index]);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	int		database[100];
	int		error;
	char	user_input[20];

	error = 0;
	memset(user_input, '\0', 20);
	memset(database, '\0', 400);
	while (*argv)
	{
		memset(*argv, '\0', strlen(*argv));
		argv++;
	}
	while (*envp)
	{
		memset(*envp, '\0', strlen(*envp));
		envp++;
	}
	puts("----------------------------------------------------\n  Welcome to wil\'s crappy numberstorage service!   \n----------------------------------------------------\n Commands:                                         \n    store - store a number into the data storage    \n   read  - read a number from the data storage     \n    quit  - exit the program                       \n----------------------------------------------------\n   wil has reserved somestorage :>                 \n----------------------------------------------------\n");
	while (1)
	{
		printf("Input command: ");
		error = 1;
		fgets(user_input, 20, stdin);
		user_input[strlen(user_input) - 1] = '\0';
		if (memcmp(user_input,  "store",  5) == 0)
			error = store_number(database);
		else if (memcmp(user_input,  "read",  4) == 0)
			error = read_number(database);
		else if (memcmp(user_input,  "quit",  4) == 0)
			return (0);
		if (error == 0)
			printf(" Completed %s command successfully\n", user_input);
		else
			printf(" Failed to do %s command\n", user_input);
		memset(user_input, 0, 20);
	}
}
