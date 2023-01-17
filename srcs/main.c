/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:01:42 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/17 20:16:31 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*search_path(char *path, char *cmd_0)
{
	char	**all_paths;
	char	*good_path;
	size_t	i;

	all_paths = ft_split(path, ':');
	if (!all_paths)
		return (NULL);
	i = 0;
	while (all_paths[i])
	{
		good_path = ft_strjoin(all_paths[i], cmd_0);
		if (!good_path)
			return (NULL);
		if (access(good_path, F_OK) == 0)
			return (good_path);
		++i;
	}
	return (NULL);
}

char	**make_cmd(char *one_string_cmd, char **envp)
{
	char	**cmd;
	char	*temp;
	size_t	i;

	cmd = ft_split(one_string_cmd, ' ');
	if (!cmd)
		return (NULL)
	temp = cmd[0];
	cmd[0] = ft_strjoin("/", temp);
	free(temp);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		++i;
	temp = cmd[0];
	cmd[0] = search_path(envp[i][5], cmd[0]);
	if (!cmd[0])
		return (NULL);
	free(temp);
	return (cmd);
}

void	receiver(char **argv, char **envp, int *pipe_fd)
{
	int	fd_stdout;
	char **cmd;

	close(pipe_fd[1]);
	cmd = make_cmd(argv[3], envp);
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
	cmd = make_cmd(argv[2], envp);
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
