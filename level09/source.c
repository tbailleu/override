#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_struct
{
	char	msg[140];
	char	username[40];
	int		len;
}	struct_t;

void	secret_backdoor(void)
{
	char	buff[128];

	fgets(buff, 128, stdin);
	system(buff);
}

void	set_msg(struct_t *s)
{
	char	buff[1024];

	memset(buff, '\0', 1024);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(buff, 1024, stdin);
	strncpy(s->msg, buff, s->len);
}

void	set_username(struct_t *s)
{
	char	buff[136];

	memset(buff, '\0', 128);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buff, 128, stdin);
	strncpy(s->username, buff, 41);
	printf(">: Welcome, %s", s->username);
}

void	handle_msg(void)
{
	struct_t s;

	memset(s.username, '\0', 40);
	s.len = 140;
	set_username(&s);
	set_msg(&s);
	puts(">: Msg sent!");
	return ;
}

int		main(void)
{
	puts("--------------------------------------------\n"
	"|   ~Welcome to l33t-m$n ~    v1337       |\n"
	"--------------------------------------------");
	handle_msg();
	return (0);
}
