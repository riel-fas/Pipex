/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:18:27 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/16 18:14:42 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(char **cmd_str, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(cmd_str[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
	dup2(fd, 1);              //redirect stdout to write in to file2
	dup2(pipe_fd[1], 0);           //redirect stdin to read from the pipe
	close(pipe_fd[0]);         //close pipe wrie
	close(fd);
	execution(cmd_str[2], env);
}

void	child2(char **cmd_str, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(cmd_str[4], O_RDONLY);              //opens file1(cmds1)
	if (fd == -1)
	{
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
	dup2(fd, 0);               //redirects stdin to read from cmds1
	dup2(pipe_fd[0], 1);               //redirects stdoutto write to the pipe
	close(pipe_fd[0]);              //close pipe read
	close(fd);
	execution(cmd_str[3], env);
}

void	pipe_execution(char *av, char **env)
{
	int		pipe_fd[2];                   //array holding file d. for the pipe
	pid_t	child_id1;
	pid_t	child_id2;

		if (pipe(pipe_fd) == -1)
	{
		perror("Pipe error");
		return(EXIT_FAILURE);
	}
	child_id1 = fork();               //forking new process(child1) ;
	if (child_id1 == -1)           //if pipe function fails
	{
		perror("Fork error");
		return(EXIT_FAILURE);
	}
	if (child_id1 == 0)                 //if pipe returns an error
		child1(av, pipe_fd, env);
	child_id2 = fork();
	id (child_id2 == -1)
	{
		perror("Fork error");
		return(EXIT_FAILURE);
	}
	if (child_id2 == 0)
		child2(av, pipe_fd, env);

	close(pipe_fd[0]);
	close(pipe_fd[1]);

	waitpid(child_id1, NULL, 0);
	waitpid(child_id2, NULL, 0);
}


int	main(int ac, char **av, char **env)
{
	if (ac != 5)                       // args should be less than 5 (./pipex file1 cmd1 cmd2 file2)
	{
		ft_putstr_fd("ERROR, too many arguments\n", 2);
		exit(-1);
	}
	pipe_execution(av, env);
	return(EXIT_SUCCESS);
}
