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

int	main(int argc, char **argv)
{
	size_t	i;
	int pipe_fd[2];
	pid_t	pid;
	int	res_pipe;
	int fd_stdin;
	int fd_stdout;
	size_t	size_bytes;

	if (argc != 5)
	{
		printf("Pas le bon nombre d arguments.\n");
		return (0);
	}
	
	res_pipe = pipe(pipe_fd)
	if (res_pipe == -1)
		return (0);


	while (i < PROCESSUS_NB)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i == 0)
			{
				close(pipe_fd[0]);
				fd_stdin = open(argv[1], O_RDONLY);
				if (fd_stdin == -1)
				{
					close(pipe_fd[1]);
					return (0);
				}
				size_bytes = read(fd_stdin, );
				
			}
			else
			{
				close(pipe_fd[1]);
				fd_stdout = open(argv[3], O_WRONLY);
				if (fd_stdout == -1)
				{
					close(pipe_fd[0]);
					return (0);
				}
			}
		}
		else
		{}
	}
	return (0);
}
