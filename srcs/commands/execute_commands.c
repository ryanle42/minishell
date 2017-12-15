/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:35 by rle               #+#    #+#             */
/*   Updated: 2017/12/02 15:04:55 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_commands(char **cmds, char **prev_dir)
{
	int	i;

	i = -1;
	while (cmds && cmds[++i])
	{
		if (check_command(cmds[i], "exit"))
			exit(0);
		else if (check_command(cmds[i], "pwd"))
			print_working_dir();
		else if (check_command(cmds[i], "cd"))
			change_directory(cmds[i], prev_dir);
		else if (check_command(cmds[i], "export") || \
					check_command(cmds[i], "setenv"))
			set_env(cmds[i]);
		else if (check_command(cmds[i], "unsetenv"))
			unset_env(cmds[i]);
		else if (check_command(cmds[i], "env"))
			print_env();
		else if (check_command(cmds[i], "echo"))
			echo_command(cmds[i]);
		else if (cmds[i][0])
			path_command(cmds[i]);
		free(cmds[i]);
	}
	free(cmds);
}
