/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:01:42 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/18 04:58:48 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**make_cmd(char *one_string_cmd, char **envp)
{
	char	**cmd;
	char	*tempo_cmd;
	size_t	i;

	cmd = ft_split(one_string_cmd, ' ');
	if (!cmd)
		return (NULL);
	tempo_cmd = format_string(cmd);
	if (!tempo_cmd)
		return (NULL);
	cmd[0] = tempo_cmd;
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		++i;
	tempo_cmd = find_path(envp, cmd, i);
	if (!tempo_cmd)
		return (NULL);
	cmd[0] = tempo_cmd;
	return (cmd);
}

void	receiver(char **argv, char **envp, int *pipe_fd)
{
	char	**cmd;

	close(pipe_fd[1]);
	cmd = NULL;

	if (fd_stdout == -1)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 2);
	cmd = make_cmd(argv[3], envp);
	if (!cmd)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 5);
	if (dup2(pipe_fd[0], 0) == -1)
		clean_exit(cmd, pipe_fd[0], fd_stdout, 3);
	close(pipe_fd[0]);
	if (execve(cmd[0], cmd, envp) == -1)
		clean_exit(cmd, -1, fd_stdout, 4);
}

void	sender(char **argv, char **envp, int *pipe_fd)
{
	int		fd_stdin;
	char	**cmd;

	close(pipe_fd[0]);
	cmd = NULL;
	fd_stdin = open(argv[1], O_RDONLY);
	if (fd_stdin == -1)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 2);
	cmd = make_cmd(argv[2], envp);
	if (!cmd)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 5);
	if (dup2(fd_stdin, 0) == -1)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 3);
	if (dup2(pipe_fd[1], 1) == -1)
		clean_exit(cmd, pipe_fd[1], fd_stdin, 3);
	close(pipe_fd[1]);
	if (execve(cmd[0], cmd, envp) == -1)
		clean_exit(cmd, -1, fd_stdin, 4);
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
	int	return_value;

	if (argc != 5)
	{
		printf("Pas le bon nombre d arguments.\n");
		return (6);
	}
	if (pipe(pipe_fd))
	{
		printf("Erreur init pipe\n");
		return (7);
	}
	run_pipe(argv, envp, pipe_fd);
	waitpid(-1, &status, 0);
	return_value = 0;
	if (WIFEXITED(status))
		return_value = WEXITSTATUS(status);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (return_value);
}
