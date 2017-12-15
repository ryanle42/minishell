/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:26 by rle               #+#    #+#             */
/*   Updated: 2017/12/05 12:15:02 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_prev_dir(char **prev_dir, char *dir)
{
	if (*prev_dir)
		*prev_dir = dir;
	else
	{
		free(*prev_dir);
		*prev_dir = dir;
	}
}

void		change_directory(char *cmd, char **prev_dir)
{
	char			**argv;
	struct passwd	*pw;
	char			*homedir;
	char			*cwd;

	cwd = getcwd(NULL, 0);
	pw = getpwuid(getuid());
	homedir = pw->pw_dir;
	ft_strsplit(cmd, ' ', &argv);
	if (argv[1] == NULL)
		chdir(homedir);
	else if (argv[1][0] == '-' && argv[1][1] == '\0')
		chdir(*prev_dir);
	else if (-1 == chdir(argv[1]))
	{
		if (errno == EACCES)
			ft_printf("cd: %s: Permission denied\n", argv[1]);
		if (errno == ENOENT)
			ft_printf("cd: %s: No such file or directory\n", argv[1]);
		errno = 0;
		return ;
	}
	set_prev_dir(prev_dir, cwd);
}
