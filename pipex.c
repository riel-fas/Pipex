/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:18:27 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/12 12:57:35 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(char **cmds, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(cmds[1], O_RDONLY, 0777);
	dup2(fd, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	execution(cmds[3], env);
}

void	child(char **cmds, int *pipe_fd, char **env)
{
	int	fd;

	// fd = open_file(av[1], 0);
	fd = open(cmds[1], O_RDONLY, 0777);
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	execution(cmds[2], env);
}

void	execution(char *cmd, char **env)
{
	char	**split_cmd;                   //array of commands getting piped
	char	*exec_path;                    //exec environemnt
	size_t	x;



 	split_cmd = ft_split(cmd, ' ');                   //commnad splited and stored in 2d array      //file1 cmd1 | cmd2 file2


	exec_path = get_path(split_cmd[0], env);
	if (execve(exec_path, split_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		x = 0;
		while (split_cmd[x])
		{
			free(split_cmd[x]);
			x++;
		}
		free(split_cmd);
		exit(0);
	}
}


int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];                   //array holding file d. for the pipe
	pid_t	pipe_id;                     //holds process id returned after forking

	if (ac > 5)                       // args should be less than 5 (./pipex file1 cmd1 cmd2 file2)
		exit_error(1);               //handle error then exit the program

	pipe(pipe_fd);                  //pipe creation, storing the fd in pipe_fd
	pipe_id = fork();               //forking new process ; child id stored in pipe_id

	if (pipe(pipe_fd) == -1)           //if pipe function fails
		exit(-1);

	if (pipe_id == -1)                 //if pipe returns an error
	{
		perror("ERROR PIPE");
		exit(EXIT_FAILURE);
	}

	if (!pipe_id)                 //checks if the current process in the child (child id i 0), if true it calls the function child
		child(av, pipe_fd, env);
	else
		parent(av, pipe_fd, env);     //if the current process is not a child it calls the parent function
}
