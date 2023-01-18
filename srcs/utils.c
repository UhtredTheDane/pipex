/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:15:48 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/18 02:04:15 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*format_string(char **cmd)
{
	char	*temp;

	temp = ft_strjoin("/", cmd[0]);
	if (!temp)
	{
		clean_2d_tab(cmd);
		return (NULL);
	}
	free(cmd[0]);
	return(temp);
}

char	*find_path(char **cmd)
{
	char	*temp;

	temp = get_path(envp[i] + 5, cmd[0]);
	if (!temp)
	{
		clean_2d_tab(cmd);
		return (NULL);
	}
	free(cmd[0]);
	return(temp);
}

char	*test_path(char **all_paths, char *cmd_0)
{
	size_t	i;
	char	*good_path;

	i = 0;
	while (all_paths[i])
	{
		good_path = ft_strjoin(all_paths[i], cmd_0);
		if (!good_path)
			return (NULL);
		if (access(good_path, F_OK) == 0)
			return (good_path);
		++i;
		free(good_path);
	}
	return (NULL);
}

char	*get_path(char *path, char *cmd_0)
{
	char	**all_paths;
	char	*cmd_path;

	all_paths = ft_split(path, ':');
	if (!all_paths)
		return (NULL);
	cmd_path = test_path(all_paths, cmd_0);
	clean_2d_tab(all_paths);
	return (cmd_path);
}
