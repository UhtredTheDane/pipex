void	error_management(int status)
{
	int exit_value;

	if (WIFEXITED(status))
	{
		exit_value = WEXITSTATUS(status);
		if (exit_value == 1)
			perror("Problème avec in_file");
		else if (exit_value == 2)
			perror("Problème avec out_file");
		else if (exit_value == 3)
			perror("Problème avec dup2");
		else if (exit_value == 4)
			perror("Problème avec execve");
	}
}

void	free_cmd(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		++i;
	}
	free(cmd);
}

void	clean_exit(char **cmd, int pipe_fd, int file_fd, int exit_value)
{
	close(pipe_fd);
	close(file_fd);
	free_cmd(cmd);
	exit(exit_value);
}