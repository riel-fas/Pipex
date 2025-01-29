/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 08:54:30 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/29 12:27:36 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_child1(char **av, int *pipe_fd, char **env)
{
	pid_t	child_id;

	child_id = fork();
	if (child_id == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if (child_id == 0)
	{
		close(pipe_fd[0]);
		child1(av, pipe_fd, env);
	}
}

static void	execute_child2(char **av, int *pipe_fd, char **env)
{
	pid_t	child_id;

	child_id = fork();
	if (child_id == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if (child_id == 0)
	{
		close(pipe_fd[1]);
		child2(av, pipe_fd, env);
	}
}

void	pipe_execution(char **av, char **env)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}
	execute_child1(av, pipe_fd, env);
	execute_child2(av, pipe_fd, env);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
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
