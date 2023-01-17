/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 06:27:36 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/18 00:07:46 by agengemb         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	receiver(char **argv, char **envp, int *pipe_fd);
void	sender(char **argv, char **envp, int *pipe_fd);
void	run_pipe(char **argv, char **envp, int *pipe_fd);
char	*find_path(char **all_paths, char *cmd_0);
char	*make_path(char *path, char *cmd_0);
char	**make_cmd(char *one_string_cmd, char **envp);
void	free_2d_tab(char **cmd);
void	clean_exit(char **cmd, int pipe_fd, int file_fd, int exit_value);

#endif
