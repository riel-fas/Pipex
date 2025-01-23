/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:18:27 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/23 16:37:41 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child1(char **cmd_str, int *pipe_fd, char **env)
{
    int fd = open(cmd_str[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening infile");
        exit(EXIT_FAILURE);
    }

    dup2(fd, STDIN_FILENO);         // Redirect infile to stdin
    close(fd);                      // Close file descriptor after dup2
    dup2(pipe_fd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
    close(pipe_fd[0]);             // Close read end, not used in this child
    close(pipe_fd[1]);             // Close write end after dup2

    // Execute command
    cmds_execution(cmd_str[2], env);
}

void child2(char **cmd_str, int *pipe_fd, char **env)
{
    int fd = open(cmd_str[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening outfile");
        exit(EXIT_FAILURE);
    }

    dup2(pipe_fd[0], STDIN_FILENO); // Redirect pipe read end to stdin
    close(pipe_fd[1]);             // Close write end, not used in this child
    close(pipe_fd[0]);             // Close read end after dup2
    dup2(fd, STDOUT_FILENO);        // Redirect stdout to outfile
    close(fd);                      // Close file descriptor after dup2

    // Execute command
    cmds_execution(cmd_str[3], env);
}

void	pipe_execution(char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	child_id1;
	pid_t	child_id2;

	if (pipe(pipe_fd) == -1)
	{
    	perror("pipe failed");
    	exit(EXIT_FAILURE);
	}
	// First child process
	child_id1 = fork();
	if (child_id1 == -1)
		perror("Fork error");
	if (child_id1 == 0)
	{
		close(pipe_fd[0]); // Close unused read end
		child1(av, pipe_fd, env);
	}

	// Second child process
	child_id2 = fork();
	if (child_id2 == -1)
		perror("Fork error");
	if (child_id2 == 0)
	{
		close(pipe_fd[1]); // Close unused write end
		child2(av, pipe_fd, env);
	}

	// Parent process
	close(pipe_fd[0]);  // Close both ends of the pipe
	close(pipe_fd[1]);
	waitpid(child_id1, NULL, 0); // Wait for child 1
	waitpid(child_id2, NULL, 0); // Wait for child 2
}

void cmds_execution(char *cmd_str, char **env) {
    char **split_cmds_line;
    char *exec_path;

    split_cmds_line = com_pars(cmd_str);
    if (!split_cmds_line || !split_cmds_line[0]) {
        ft_putstr_fd("ERROR: Invalid command\n", 2);
        exit(EXIT_FAILURE);
    }

    exec_path = get_the_path(split_cmds_line[0], env);
    if (!exec_path) {
        ft_putstr_fd("pipex: command not found: ", 2);
        ft_putendl_fd(split_cmds_line[0], 2);
        ft_free_tab(split_cmds_line);
        exit(EXIT_FAILURE);
    }

    printf("Executing: %s\n", exec_path);
    for (int i = 0; split_cmds_line[i]; i++)
        printf("Arg %d: %s\n", i, split_cmds_line[i]);

    if (execve(exec_path, split_cmds_line, env) == -1) {
        perror("execve failed");
        ft_free_tab(split_cmds_line);
        exit(EXIT_FAILURE);
    }

    ft_free_tab(split_cmds_line); // Free arguments after execve
}

int	main(int ac, char **av, char **env)
{
	if (ac != 5)
	{
		ft_putstr_fd("ERROR, in arguments\n", 2);
		exit(-1);
	}
	pipe_execution(av, env);
	return (EXIT_SUCCESS);
}
