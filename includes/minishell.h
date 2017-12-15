/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:18 by rle               #+#    #+#             */
/*   Updated: 2017/12/06 14:02:38 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>

enum	e_cmds
{
	CMD_pwd = 1
};

/*
** ENV
*/
char	**get_env(void);
void	set_env(char *cmd);
void	unset_env(char *cmd);
void	print_env(void);
char	*get_env_val(char *key);

/*
** COMMANDS
*/
void	get_next_command(char ***cmds);
int		check_command(char *str, char *cmd);
void	execute_commands(char **cmds, char **prev_dir);
void	print_working_dir(void);
void	path_command(char *cmd);
void	change_directory(char *cmd, char **prev_dir);
void	echo_command(char *cmd);

/*
** HELPERS
*/
void	display_prompt(void);
void	clear_whitespaces(char **str);
void    free_str_arr(char **str);

#endif
