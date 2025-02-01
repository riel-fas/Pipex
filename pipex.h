/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:01:08 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/02 00:22:22 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <string.h>
#include <sys/wait.h>

typedef struct s_parser
{
	char	**result;
	char	*arg;
	int		i;
	int		j;
	int		k;
}	t_parser;

void	cmds_execution(char *cmd_str, char **env);
char	*get_the_path(char *cmd, char **env);
void	ft_free_tab(char **tab);
char	**com_pars(char *cmd_str);
void	pipe_execution(char **av, char **env);
void	child1(char **cmd_str, int *pipe_fd, char **env);
void	child2(char **cmd_str, int *pipe_fd, char **env);

#endif
