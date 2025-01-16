/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:18:20 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/16 13:05:03 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



// int	open_file(char *file, int in_or_out)
// {
// 	int	ret;

// 	if (in_or_out == 0)
// 		ret = open(file, O_RDONLY, 0777);
// 	if (in_or_out == 1)
// 		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if (ret == -1)
// 		exit(0);
// 	return (ret);
// }

char	*get_env(char *name, char **env)
{
	int		x;
	int		y;
	char	*sub;

	if (!name || !env)
		return (NULL);
	x = 0;
	while (env[x])
	{
		y = 0;
		while (env[x][y] && env[x][y] != '=')
			y++;
		sub = ft_substr(env[x], 0, y);
		if (!sub)
			return (NULL);
		if (!ft_strcmp(sub, name))
		{
			free(sub);
			return (env[x] + y + 1);
		}
		free(sub);
		x++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;

	i = -1;
	allpath = ft_split(getenv("PATH", env), ':');
	// s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(s_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_tab(allpath);
	// ft_free_tab(s_cmd);
	return (NULL);
}

