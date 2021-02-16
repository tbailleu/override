#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void	log_wrapper(FILE *fd, char *msg, char *file)
{
	char buffer [264];

	strcpy(buffer, msg);
	snprintf(&buffer[strlen(buffer)], 254 - strlen(buffer), file);
	buffer[strcspn(buffer, "\n")] = '\0';
	  fprintf(fd, "LOG: %s\n", buffer);
}

int		main(int argc, char **argv)
{
	int fd;
	FILE *fd_log;
	FILE *fd_argv1;
	char c;
	char buffer [100];

	if (argc != 2)
		printf("Usage: %s filename\n", argv[0]);
	if ((fd_log = fopen("./backups/.log", "w")) == NULL)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(fd_log, "Starting back up: ", argv[1]);
	if ((fd_argv1 = fopen(argv[1], "r")) == NULL)
	{
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}
	strcpy(buffer, "./backups/");
	strncat(buffer, argv[1], 89);
	if ((fd = open(buffer, O_EXCL | O_CREAT | O_WRONLY, 0660)) < 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
		exit(1);
	}
	while ((c = fgetc(fd_argv1)) != -1)
		write(fd, &c, 1);
	log_wrapper(fd_log, "Finished back up ", argv[1]);
	fclose(fd_argv1);
	close(fd);
	return (0);
}
