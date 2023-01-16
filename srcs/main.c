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

void	receiver(char **envp, char *out_file, char **argv, int *pipe_fd)
{
	int	*ft_stdout;
	char **cmd;

	close(pipe_fd[1]);
	cmd = ft_split(argv[4], ' ');
	fd_stdout = open(argv[3], O_WRONLY);
	if (fd_stdout == -1)
	{
		close(pipe_fd[0]);
		exit (1);
	}
	if (dup2(pipe_fd[0], 0) == -1)
	{
		close(pipe_fd[0]);
		close(ft_stdout);
		exit(2);
	}
	if (dup2(fd_stdout, 1) == -1)
	{
		close(pipe_fd[0]);
		close(ft_stdout);
		exit(2);
	}
	if (execve(cmd[0], cmd, envp) == -1)
	{
		close(pipe_fd[0]);
		close(ft_stdout);
		exit(3);
	}
	
}

void	sender(char **envp, char *in_file, char **argv, int *pipe_fd)
{
	int	*ft_stdin;
	char **cmd;

	close(pipe_fd[0]);
	cmd = ft_split(argv[2], ' ');
	fd_stdin = open(argv[1], O_RDONLY);
	if (fd_stdin == -1)
	{
		close(pipe_fd[1]);
		exit (1);
	}
	if (dup2(pipe_fd[1], 1) == -1)
	{
		close(pipe_fd[1]);
		close(fd_stdin);
		exit(2);
	}
	if (cmd(argv[0], cmd, envp) == -1)
	{
		close(pipe_fd[1]);
		close(fd_stdin);
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
