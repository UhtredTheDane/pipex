/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:15:48 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/18 00:06:47 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_path(char **all_paths, char *cmd_0)
{
	size_t	i;
	char	*good_path;

	i = 0;
	while (all_paths[i])
	{
		good_path = ft_strjoin(all_paths[i], cmd_0);
		if (!good_path)
		{
			free_2d_tab(all_paths);
			return (NULL);
		}
		if (access(good_path, F_OK) == 0)
		{
			free_2d_tab(all_paths);
			return (good_path);
		}
		++i;
		free(good_path);
	}
	free_2d_tab(all_paths);
	return (NULL);
}

char	*make_path(char *path, char *cmd_0)
{
	char	**all_paths;

	all_paths = ft_split(path, ':');
	if (!all_paths)
		return (NULL);
	return (find_path(all_paths, cmd_0));
}

char	**make_cmd(char *one_string_cmd, char **envp)
{
	char	**cmd;
	char	*temp;
	size_t	i;

	cmd = ft_split(one_string_cmd, ' ');
	if (!cmd)
		return (NULL);
	temp = cmd[0];
	cmd[0] = ft_strjoin("/", temp);
	free(temp);
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		++i;
	temp = cmd[0];
	cmd[0] = make_path(envp[i] + 5, cmd[0]);
	if (!cmd[0])
		return (NULL);
	free(temp);
	return (cmd);
}

void	free_2d_tab(char **tab_2d)
{
	size_t	i;

	i = 0;
	while (tab_2d[i])
	{
		free(tab_2d[i]);
		++i;
	}
	free(tab_2d);
}

void	clean_exit(char **tab_2d, int pipe_fd, int file_fd, int exit_value)
{
	if (pipe_fd > -1)
		close(pipe_fd);
	if (file_fd > -1)
		close(file_fd);
	if (tab_2d)
		free_2d_tab(tab_2d);
	if (exit_value == 1)
		perror("Problème avec in_file");
	else if (exit_value == 2)
		perror("Problème avec out_file");
	else if (exit_value == 3)
		perror("Problème avec dup2");
	else if (exit_value == 4)
		perror("Problème avec execve");
	else if (exit_value == 5)
		printf("Impossible de formater la commande pour execve\n");
	exit(exit_value);
}
