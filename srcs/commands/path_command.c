/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:39 by rle               #+#    #+#             */
/*   Updated: 2017/12/15 13:01:50 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		sig_handler(int sig)
{
	int	pid;

	pid = getpid();
	if (sig == 2)
		kill(pid, SIGKILL);
}

static char		**get_paths(void)
{
	char	**paths;
	char	*tmp;

	tmp = get_env_val("PATH");
	ft_strsplit(tmp, ':', &paths);
	free(tmp);
	return (paths);
}

static int		path_cmd(char **paths, char *cmd, char **argv)
{
	int		i;
	int		success;
	int		status;
	char	*path;

	i = -1;
	while (paths[++i])
		if (fork() == 0)
		{
			signal(SIGINT, sig_handler);
			path = ft_append_str(paths[i], "/", 1);
			argv[0] = ft_append_str(path, cmd, 1);
			success = execve(argv[0], &argv[0], get_env());
			exit(success);
		}
		else
		{
			wait(&status);
			if (status == 2)
				ft_printf("\n");
			if (status != 65280)
				return (0);
		}
	return (-1);
}

static int		abs_cmd(char **paths, char *cmd, char **argv)
{
	int		i;
	int		success;
	int		status;
	char	**env;

	i = -1;
	while (paths[++i])
		if (fork() == 0)
		{
			signal(SIGINT, sig_handler);
			argv[0] = cmd;
			env = get_env();
			success = execve(argv[0], &argv[0], env);
			free_str_arr(env);
			exit(success);
		}
		else
		{
			wait(&status);
			if (status == 2)
				ft_printf("\n");
			if (status != 65280)
				return (0);
		}
	return (-1);
}

void			path_command(char *cmd)
{
	char	**argv;
	char	**paths;
	int		res;

	ft_strsplit(cmd, ' ', &argv);
	cmd = ft_copystr(argv[0]);
	paths = get_paths();
	res = abs_cmd(paths, cmd, argv);
	if (res != 0)
		res = path_cmd(paths, cmd, argv);
	if (res != 0)
		ft_printf("%s: command not found\n", cmd);
	free_str_arr(argv);
	free_str_arr(paths);
	free(cmd);
}
