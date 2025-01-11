/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:18:27 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/11 13:57:31 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"




// ########################################################

// void    pipex(int f1, int f2)
// {
//     int end[2];    pipe(end);
// }

// # pipe() takes an array of two int, and links them together
// # what is done in end[0] is visible to end[1], and vice versa
// # pipe() assigns an fd to each end
// # Fds are file descriptors
// # since files can be read and written to, by getting an fd each, the two ends can communicate
// # end[1] will write to the its own fd, and end[0] will read end[1]’s fd and write to its own





// #############################################

// void    pipex(int f1, int f2)
// {
//     int   end[2];
//     int parent;


//     pipe(end);
//     parent = fork();
//     if (parent < 0)
//          return (perror("Fork: "));
//     if (!parent) // if fork() returns 0, we are in the child process
//         child_process(f1, cmd1);
//     else
//         parent_process(f2, cmd2);
// }
// # fork() splits the process in two sub-processes -> parallel, simultaneous, happen at the same time
// # it returns 0 for the child process, a non-zero for the parent process, -1 in case of error




// ##############################################


// void    pipex(int f1, int f2, char *cmd1, char *cmd 2)
// {
//     int   end[2];
//     int   status;
//     pid_t child1;
//     pid_t child2;
// 	pipe(end);

// 	child1 = fork();
// 	if (child1 < 0)
//          return (perror("Fork: "));
//     if (child1 == 0)
//         child_one(f1, cmd1);
//     child2 = fork();
//     if (child2 < 0)
//          return (perror("Fork: "));
//     if (child2 == 0)
//         child_two(f2, cmd2);
//     close(end[0]);         // this is the parent
//     close(end[1]);         // doing nothing
//     waitpid(child1, &status, 0);  // supervising the children
//     waitpid(child2, &status, 0);  // while they finish their tasks
// }




// #############################################


#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(0);
	}
}

void	child(char **av, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec(av[3], env);
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
	parent(av, pipe_fd, env);     //if the current process is not a child it calls the parent function
}
