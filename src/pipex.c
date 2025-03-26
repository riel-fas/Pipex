/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:18:27 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/26 16:01:02 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child1(char **cmd_str, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(cmd_str[1], O_RDONLY);
	if (fd == -1)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	dup2(fd, 0);
	close(fd);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmds_execution(cmd_str[2], env);
}

void	child2(char **cmd_str, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(cmd_str[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	dup2(fd, 1);
	close(fd);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmds_execution(cmd_str[3], env);
}

void	cmds_execution(char *cmd_str, char **env)
{
	char	**split_cmds_line;
	char	*exec_path;

	split_cmds_line = com_pars(cmd_str);
	if (!split_cmds_line || !split_cmds_line[0])
	{
		ft_putstr_fd("PIPEX:command not found\n", 2);
		exit(EXIT_FAILURE);
	}
	exec_path = get_the_path(split_cmds_line[0], env);
	if (!exec_path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(split_cmds_line[0], 2);
		ft_free_tab(split_cmds_line);
		exit(EXIT_FAILURE);
	}
	if (execve(exec_path, split_cmds_line, env) == -1)
	{
		perror("execve failed");
		ft_free_tab(split_cmds_line);
		exit(EXIT_FAILURE);
	}
	ft_free_tab(split_cmds_line);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		ft_putstr_fd("ERROR: Invalid number of arguments\n", 2);
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	pipe_execution(av, env);
	return (EXIT_SUCCESS);
}
