/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:18:20 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/17 12:31:42 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*get_the_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	while (*env && ft_strncmp(*env, "PATH=", 5) != 0)
		env++;
	if (!*env)
		return (NULL);
	paths = ft_split(*env + 5, ':');
	i = 0;
	while (paths && paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (access(full_path, F_OK | X_OK) == 0)
			return (ft_free_tab(paths), full_path);
		free(full_path);
		i++;
	}
	ft_free_tab(paths);
	return (NULL);
}
