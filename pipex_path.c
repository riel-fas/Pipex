/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:18:20 by riel-fas          #+#    #+#             */
/*   Updated: 2025/01/26 09:55:23 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	skip_spaces(char *cmd_str, t_parser *p)
{
	while (cmd_str[p->i] == ' ')
		p->i++;
}

static void	handle_quoted_arg(char *cmd_str, t_parser *p)
{
	char	quote;

	quote = cmd_str[(p->i)++];
	while (cmd_str[p->i] && cmd_str[p->i] != quote)
		p->arg[(p->j)++] = cmd_str[(p->i)++];
	if (cmd_str[p->i] == quote)
		p->i++;
}

static void	handle_unquoted_arg(char *cmd_str, t_parser *p)
{
	while (cmd_str[p->i] && cmd_str[p->i] != ' ')
		p->arg[(p->j)++] = cmd_str[(p->i)++];
}

char	**com_pars(char *cmd_str)
{
	t_parser	p;

	p.result = malloc(sizeof(char *) * 256);
	p.arg = malloc(strlen(cmd_str) + 1);
	p.i = 0;
	p.j = 0;
	p.k = 0;
	if (!p.result || !p.arg)
		return (NULL);
	while (cmd_str[p.i])
	{
		skip_spaces(cmd_str, &p);
		if (cmd_str[p.i] == '"' || cmd_str[p.i] == '\'')
			handle_quoted_arg(cmd_str, &p);
		else
			handle_unquoted_arg(cmd_str, &p);
		if (p.j > 0)
		{
			p.arg[p.j] = '\0';
			p.result[p.k++] = strdup(p.arg);
			p.j = 0;
		}
	}
	p.result[p.k] = NULL;
	return (free(p.arg), p.result);
}
