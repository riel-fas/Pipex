static void	handle_quotes(const char *cmd_str, int *i, char *arg, int *j)
{
	char	quote;

	quote = cmd_str[*i];
	(*i)++;
	while (cmd_str[*i] && cmd_str[*i] != quote)
		arg[(*j)++] = cmd_str[(*i)++];
	if (cmd_str[*i] == quote)
		(*i)++;
}

static void	handle_word(const char *cmd_str, int *i, char *arg, int *j)
{
	while (cmd_str[*i] && cmd_str[*i] != ' ')
		arg[(*j)++] = cmd_str[(*i)++];
}

char	**com_pars(char *cmd_str)
{
	int		i = 0, j = 0, k = 0;
	char	quote = 0;
	char	**result = malloc(sizeof(char *) * 256);
	char	*arg = malloc(strlen(cmd_str) + 1);

	if (!result || !arg)
		return (NULL);
	while (cmd_str[i])
	{
		while (cmd_str[i] == ' ')
			i++;
		if (cmd_str[i] == '"' || cmd_str[i] == '\'')
			handle_quotes(cmd_str, &i, arg, &j);
		else
			handle_word(cmd_str, &i, arg, &j);
		if (j > 0)
		{
			arg[j] = '\0';
			result[k++] = strdup(arg);
			j = 0;
		}
	}
	result[k] = NULL;
	free(arg);
	return (result);
}



##################################################################################################


void	execute_command(char *exec_path, char **cmd_args, char **env)
{
	if (execve(exec_path, cmd_args, env) == -1)
	{
		perror("execve failed");
		ft_free_tab(cmd_args);
		exit(EXIT_FAILURE);
	}
}

char	*resolve_command_path(char *cmd, char **env)
{
	char	*exec_path;

	exec_path = get_the_path(cmd, env);
	if (!exec_path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		exit(EXIT_FAILURE);
	}
	return (exec_path);
}

void	cmds_execution(char *cmd_str, char **env)
{
	char	**cmd_args;
	char	*exec_path;

	cmd_args = com_pars(cmd_str);
	if (!cmd_args || !cmd_args[0])
	{
		ft_putstr_fd("ERROR: Invalid command\n", 2);
		exit(EXIT_FAILURE);
	}
	exec_path = resolve_command_path(cmd_args[0], env);
	execute_command(exec_path, cmd_args, env);
	ft_free_tab(cmd_args);
}


##############################################################################################
