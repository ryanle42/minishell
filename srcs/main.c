/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:13 by rle               #+#    #+#             */
/*   Updated: 2017/12/02 15:05:04 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_in_cmd;

static void	sig_handler(int sig)
{
	if (sig == 2 && !g_in_cmd)
	{
		ft_printf("\n");
		display_prompt();
	}
}

int			main(void)
{
	char	**cmds;
	char	*prev_dir;

	prev_dir = NULL;
	signal(SIGINT, sig_handler);
	while (1)
	{
		g_in_cmd = 0;
		cmds = NULL;
		display_prompt();
		get_next_command(&cmds);
		g_in_cmd = 1;
		execute_commands(cmds, &prev_dir);
	}
}
