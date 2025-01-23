/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:18:20 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/23 16:06:28 by riel-fas         ###   ########.fr       */
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

// char **com_pars(char *cmd_str)
// {
// 	int x = 0;
// 	int y = 0;
// 	int z = 0;
// 	char *tmp = malloc(256);
// 	char **result = malloc(256 * sizeof(char *));
// 	char *copy = ft_strdup(cmd_str);
// 	char quote;

// 	while (copy[x])
// 	{
// 		if (copy[x] == '"' || copy[x] == '\'')
// 		{
// 			quote = copy[x++];
// 			while (copy[x] && copy[x] != quote)
// 				tmp[y++] = copy[x++];
// 			if (copy[x] == quote)
// 				x++;
// 		}
// 		else if (copy[x] == ' ' && y > 0)
// 		{
// 			tmp[y] = '\0';
// 			result[z++] = ft_strdup(tmp);
// 			y = 0;
// 			x++;
// 		}
// 		else
// 			tmp[y++] = copy[x++];
// 	}
// 	if (y > 0)
// 	{
// 		tmp[y] = '\0';
// 		result[z++] = ft_strdup(tmp);
// 	}
// 	result[z] = NULL;
// 	free(tmp);
// 	free(copy);
// 	return result;
// }


// char **com_pars(char *cmd_str)
// {
//     int x = 0, y = 0, z = 0;
//     char *tmp = malloc(256);
//     char **result = malloc(256 * sizeof(char *));
//     char *copy = ft_strdup(cmd_str);
//     char quote;
//     int brace = 0;

//     while (copy[x])
//     {
//         if (copy[x] == '"' || copy[x] == '\'')
//         {
//             quote = copy[x++];
//             while (copy[x] && copy[x] != quote)
//                 tmp[y++] = copy[x++];
//             if (copy[x] == quote)
//                 x++;
//         }
//         else if (copy[x] == '{' || copy[x] == '}')
//             brace = !brace;
//         else if (copy[x] == ' ' && y > 0 && !brace)
//         {
//             tmp[y] = '\0';
//             result[z++] = ft_strdup(tmp);
//             y = 0;
//             x++;
//         }
//         else
//             tmp[y++] = copy[x++];
//     }
//     if (y > 0)
//     {
//         tmp[y] = '\0';
//         result[z++] = ft_strdup(tmp);
//     }
//     result[z] = NULL;
//     free(tmp);
//     free(copy);
//     return result;
// }

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **com_pars(char *cmd_str)
{
    int i = 0, j = 0, k = 0;
    char quote = 0;
    char **result = malloc(sizeof(char *) * 256); // Allocate space for up to 256 arguments
    char *arg = malloc(strlen(cmd_str) + 1);     // Temporary buffer for each argument

    if (!result || !arg)
        return NULL; // Handle allocation failure

    while (cmd_str[i])
    {
        // Skip leading spaces
        while (cmd_str[i] == ' ')
            i++;

        // Handle quoted arguments
        if (cmd_str[i] == '"' || cmd_str[i] == '\'')
        {
            quote = cmd_str[i++];
            while (cmd_str[i] && cmd_str[i] != quote)
                arg[j++] = cmd_str[i++];
            if (cmd_str[i] == quote) // Skip closing quote
                i++;
        }
        // Handle unquoted arguments
        else
        {
            while (cmd_str[i] && cmd_str[i] != ' ')
                arg[j++] = cmd_str[i++];
        }

        // End of an argument
        if (j > 0)
        {
            arg[j] = '\0';
            result[k++] = strdup(arg); // Save argument
            j = 0;                    // Reset buffer for next argument
        }
    }

    // Null-terminate the result array
    result[k] = NULL;

    // Free temporary buffer
    free(arg);
    return result;
}
