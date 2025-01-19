/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:18:27 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/19 12:50:38 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(char **cmd_str, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(cmd_str[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	close(fd);
	cmds_execution(cmd_str[2], env);
}
void	child2(char **cmd_str, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(cmd_str[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening file\n");
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[0], 0);
	dup2(fd, 1);
	close(pipe_fd[0]);
	close(fd);
	cmds_execution(cmd_str[3], env);
}
void	pipe_execution(char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	child_id1;
	pid_t	child_id2;

	if (pipe(pipe_fd) == -1)
	{
		perror("Pipe error");
		exit(EXIT_FAILURE);
	}
	child_id1 = fork();
	if (child_id1 == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if (child_id1 == 0) // Child 1
	{
		close(pipe_fd[0]);  // Close unused read end
		child1(av, pipe_fd, env);
		exit(EXIT_SUCCESS);
	}
	child_id2 = fork();
	if (child_id2 == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	if (child_id2 == 0) // Child 2
	{
		close(pipe_fd[1]);  // Close unused write end
		child2(av, pipe_fd, env);
		exit(EXIT_SUCCESS);
	}
	close(pipe_fd[0]);  // Close both ends of the pipe
	close(pipe_fd[1]);
	waitpid(child_id1, NULL, 0); // Wait for child 1
	waitpid(child_id2, NULL, 0); // Wait for child 2
}



void	cmds_execution(char *cmd_str, char **env)
{
	char	**split_cmds_line;
	char	*exec_path;
	size_t	x;

	split_cmds_line = ft_split(cmd_str, ' ');
	if (!split_cmds_line || !split_cmds_line[0])
	{
		ft_putstr_fd("ERROR : Invalid cmd\n", 2);
		// return (EXIT_FAILURE);
	}
	exec_path = get_the_path(split_cmds_line[0], env);
	if (execve(exec_path, split_cmds_line, env) == -1 || !exec_path)
	{
		ft_putstr_fd("pipex: command not found: \n", 2);
		ft_putendl_fd(split_cmds_line[0], 2);
		x = 0;
		while (split_cmds_line[x])
			free(split_cmds_line[x++]);
		free(split_cmds_line);
		if (exec_path)
			free(exec_path);
		exit(EXIT_FAILURE);
	}
}

// void	pipe_execution(char **av, char **env)
// {
// 	int		pipe_fd[2];
// 	pid_t	child_id1;
// 	pid_t	child_id2;

// 	if (pipe(pipe_fd) == -1)
// 	{
// 		perror("Pipe error");
// 		exit(EXIT_FAILURE);
// 	}
// 	child_id1 = fork();
// 	if (child_id1 == -1)
// 	{
// 		perror("Fork error");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (child_id1 == 0)
// 		child1(av, pipe_fd, env);
// 	child_id2 = fork();
// 	if (child_id2 == -1)
// 	{
// 		perror("Fork error");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (child_id2 == 0)
// 		child2(av, pipe_fd, env);
// 	close(pipe_fd[0]);
// 	close(pipe_fd[1]);
// 	waitpid(child_id1, NULL, 0);
// 	waitpid(child_id2, NULL, 0);
// }

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		ft_putstr_fd("ERROR, too many arguments\n", 2);
		exit(-1);
	}
	pipe_execution(av, env);
	return (EXIT_SUCCESS);
}
