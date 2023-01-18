/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:01:42 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/18 02:11:44 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**make_cmd(char *one_string_cmd, char **envp)
{
	char	**cmd;
	size_t	i;

	cmd = ft_split(one_string_cmd, ' ');
	if (!cmd)
		return (NULL);
	cmd[0] = format_string(cmd);
	if (!cmd[0])
		return (NULL);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		++i;
	cmd[0] = find_path(cmd):
	if (!cmd[0])
		return (NULL);
	return (cmd);
}

void	receiver(char **argv, char **envp, int *pipe_fd)
{
	int		fd_stdout;
	char	**cmd;

	close(pipe_fd[1]);
	fd_stdout = -1;
	cmd = make_cmd(argv[3], envp);
	if (!cmd)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 5);
	fd_stdout = open(argv[4], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_stdout == -1)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 2);
	if (dup2(pipe_fd[0], 0) == -1)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 3);
	if (dup2(fd_stdout, 1) == -1)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 3);
	if (execve(cmd[0], cmd, envp) == -1)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 4);
}

void	sender(char **argv, char **envp, int *pipe_fd)
{
	int		fd_stdin;
	char	**cmd;

	close(pipe_fd[0]);
	fd_stdin = -1;
	cmd = make_cmd(argv[2], envp);
	if (!cmd)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 5);
	fd_stdin = open(argv[1], O_RDONLY);
	if (fd_stdin == -1)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 2);
	if (dup2(fd_stdin, 0) == -1)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 3);
	if (dup2(pipe_fd[1], 1) == -1)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 3);
	if (execve(cmd[0], cmd, envp) == -1)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 4);
}

void	run_pipe(char **argv, char **envp, int *pipe_fd)
{
	size_t	i;
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
	int	pipe_fd[2];
	int	status;

	if (argc != 5)
	{
		printf("Pas le bon nombre d arguments.\n");
		return (0);
	}
	if (pipe(pipe_fd))
		return (0);
	run_pipe(argv, envp, pipe_fd);
	waitpid(-1, &status, 0);
	return (0);
}
