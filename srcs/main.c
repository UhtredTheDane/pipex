/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:01:42 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/15 22:58:46 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define PROCESSUS_NB 2

void	receiver(char **envp, char *out_file, char *cmd, int *pipe_fd)
{
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], 0) == -1)
	{
		exit();
	}
	fd_stdout = open(argv[3], O_WRONLY);
	if (fd_stdout == -1)
	{
		close(pipe_fd[0]);
		return (0);
	}
	if (dup2(fd_stdout, 1) == -1)
	{
		exit();
	}
	//split
	if (execve(argv[2], argv, envp) == -1)
	{
		exit();
	}
	
}

void	sender(char **envp, char *in_file, char *cmd, int *pipe_fd)
{
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], 1) == -1)
	{
		exit();
	}
	//split
	if (execve(argv[2], argv, envp) == -1)
	{
		exit();
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	size_t	i;
	int pipe_fd[2];
	pid_t	pid;
	int status;

	if (argc != 5)
	{
		printf("Pas le bon nombre d arguments.\n");
		return (0);
	}
	
	if (pipe(pipe_fd))
		return (0);


	while (i < PROCESSUS_NB)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
				sender(envp, argv[1], argv[2], pipe);
			else
				receiver(envp, argv[3], argv[4], pipe);
		}
	}
	while (waitpid(pid, &status, 0) == -1)
		;
	return (0);
}
