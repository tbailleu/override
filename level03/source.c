#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	decrypt(int value) {
	char	str[17];
	size_t	str_len;
	int		i;

	strcpy(str, "Q}|u`sfg~sf{}|a3");
	str_len = strlen(str);
	i = -1;
	while (++i < str_len)
		str[i] = (char)value ^ str[i];
	if (strncmp(str, "Congratulations!", 17) == 0)
		system("/bin/sh");
	else
		puts("\nInvalid Password");
}


void	test(int passwd, int value)
{
	value = value - passwd;
	switch(value) {
		default:	decrypt(rand()); break;
		case 1:		decrypt(value); break;
		case 2:		decrypt(value); break;
		case 3:		decrypt(value); break;
		case 4:		decrypt(value); break;
		case 5:		decrypt(value); break;
		case 6:		decrypt(value); break;
		case 7:		decrypt(value); break;
		case 8:		decrypt(value); break;
		case 9:		decrypt(value); break;
		case 0x10:	decrypt(value); break;
		case 0x11:	decrypt(value); break;
		case 0x12:	decrypt(value); break;
		case 0x13:	decrypt(value); break;
		case 0x14:	decrypt(value); break;
		case 0x15:	decrypt(value);
	}
}


int		main(void)
{
	int passwd;

	srand(time(NULL));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &passwd);
	test(passwd, 322424845);
	return (0);
}
