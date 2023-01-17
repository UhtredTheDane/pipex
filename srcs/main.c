/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:01:42 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/17 03:34:52 by agengemb         ###   ########.fr       */
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

void	receiver(char **argv, char **envp, int *pipe_fd)
{
	int	fd_stdout;
	char **cmd;

	close(pipe_fd[1]);
	cmd = ft_split(argv[3], ' ');
	if (!cmd)
	{
		printf("Impossible de formater la commande pour execve\n");
		close(pipe_fd[0]);
		free_cmd(cmd);
		exit(5);
	}
	fd_stdout = open(argv[4], O_WRONLY | O_CREAT);
	if (fd_stdout == -1)
	{
		close(pipe_fd[0]);
		free_cmd(cmd);
		exit(2);
	}
	if (dup2(pipe_fd[0], 0) == -1)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 3);
	if (dup2(fd_stdout, 1) == -1)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 3);
	if (execve(cmd[0], cmd, envp) == -1)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 3);
}

void	sender(char **argv, char **envp, int *pipe_fd)
{
	int	fd_stdin;
	char **cmd;

	close(pipe_fd[0]);
	cmd = ft_split(argv[2], ' ');
	if (!cmd)
	{
		printf("Impossible de formater la commande pour execve\n");
		close(pipe_fd[1]);
		free_cmd(cmd);
		exit(5);
	}
	fd_stdin = open(argv[1], O_RDONLY);
	if (fd_stdin == -1)
	{
		close(pipe_fd[1]);
		free_cmd(cmd);
		exit (1);
	}
	if (dup2(fd_stdin, 0) == -1)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 3);
	if (dup2(pipe_fd[1], 1) == -1)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 3);
	if (execve(cmd[0], cmd, envp) == -1)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 4);
}

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

void run_pipe(char **argv, char **envp, int *pipe_fd)
{
	size_t i;
	pid_t	pid;

	i = 0;
	while (i < PROCESSUS_NB)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Probleme fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (i == 0)
				sender(argv, envp, pipe_fd);
			else
				receiver(argv, envp, pipe_fd);
		}
		++i;
	}
}
int	main(int argc, char **argv, char **envp)
{
	int pipe_fd[2];
	int status;
	
	if (argc != 5)
	{
		printf("Pas le bon nombre d arguments.\n");
		return (0);
	}
	if (pipe(pipe_fd))
		return (0);
	run_pipe(argv, envp, pipe_fd);
	waitpid(-1, &status, 0);
	error_management(status);
	return (0);
}
