/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 06:27:36 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/17 20:17:01 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define PROCESSUS_NB 2

char	**ft_split(char const *s, char c);
void	receiver(char **argv, char **envp, int *pipe_fd);
void	sender(char **argv, char **envp, int *pipe_fd);
void run_pipe(char **argv, char **envp, int *pipe_fd);
void	error_management(int status);
void	free_cmd(char **cmd);
void	clean_exit(char **cmd, int pipe_fd, int file_fd, int exit_value);

#endif
