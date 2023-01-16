/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:01:42 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/16 21:57:27 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define PROCESSUS_NB 2
char	**ft_split(char const *s, char c);

void	receiver(char **envp, char **argv, int *pipe_fd)
{
	int	fd_stdout;
	char **cmd;

	close(pipe_fd[1]);
	cmd = ft_split(argv[3], ' ');
	if (!cmd)
		printf("gros bug\n");
	fd_stdout = open(argv[4], O_WRONLY | O_CREAT);
	if (fd_stdout == -1)
	{
		close(pipe_fd[0]);
		exit(1);
	}
	if (dup2(pipe_fd[0], 0) == -1)
	{
		close(pipe_fd[0]);
		close(fd_stdout);
		exit(2);
	}
	if (dup2(fd_stdout, 1) == -1)
	{
		close(pipe_fd[0]);
		close(fd_stdout);
		exit(2);
	}
	if (execve(cmd[0], cmd, envp) == -1)
	{
		close(pipe_fd[0]);
		close(fd_stdout);
		exit(3);
	}
}

void	sender(char **envp, char **argv, int *pipe_fd)
{
	int	fd_stdin;
	char **cmd;

	close(pipe_fd[0]);
	cmd = ft_split(argv[2], ' ');
	fd_stdin = open(argv[1], O_RDONLY);
	if (fd_stdin == -1)
	{
		close(pipe_fd[1]);
		exit (1);
	}
	if (dup2(fd_stdin, 0) == -1)
	{
		close(pipe_fd[1]);
		close(fd_stdin);
		exit(2);
	}
	if (dup2(pipe_fd[1], 1) == -1)
	{
		close(pipe_fd[1]);
		close(fd_stdin);
		exit(2);
	}
	if (execve(cmd[0], cmd, envp) == -1)
	{
		close(pipe_fd[1]);
		close(fd_stdin);
		exit(3);
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	int pipe_fd[2];
	pid_t	pid;
	int status;
	size_t i;

	if (argc != 5)
	{
		printf("Pas le bon nombre d arguments.\n");
		return (0);
	}
	
	if (pipe(pipe_fd))
		return (0);

	i = 0;
	while (i < PROCESSUS_NB)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Erreur fork");
			return (1);
		}
		else if (pid == 0)
		{
			if (i == 0)
				sender(envp, argv, pipe_fd);
			else
				receiver(envp, argv, pipe_fd);
		}
		++i;
	}
	i = 0;
	waitpid(-1, &status, 0);
	return (0);
}
