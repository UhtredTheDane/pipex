#include "../include/pipex.h"

void	clean_2d_tab(char **tab_2d)
{
	size_t	i;

	i = 0;
	while (tab_2d[i])
	{
		if (tab_2d[i])
			free(tab_2d[i]);
		++i;
	}
	free(tab_2d);
}

void	clean_exit(char **tab_2d, int pipe_fd, int file_fd, int exit_value)
{
	if (pipe_fd > -1)
		close(pipe_fd);
	if (file_fd > -1)
		close(file_fd);
	if (tab_2d)
		free_2d_tab(tab_2d);
	if (exit_value == 1)
		perror("Problème avec in_file");
	else if (exit_value == 2)
		perror("Problème avec out_file");
	else if (exit_value == 3)
		perror("Problème avec dup2");
	else if (exit_value == 4)
		perror("Problème avec execve");
	else if (exit_value == 5)
		printf("Impossible de formater la commande pour execve\n");
	exit(exit_value);
}