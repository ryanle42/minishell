/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:01 by rle               #+#    #+#             */
/*   Updated: 2017/11/30 18:37:18 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void	display_prompt(void)
{
	char			*cwd;
	struct passwd	*pw;
	char			*homedir;
	char			hostname[1024];

	pw = getpwuid(getuid());
	homedir = pw->pw_dir;
	cwd = getcwd(NULL, 0);
	cwd = ft_strreplace(cwd, homedir, "~");
	gethostname(hostname, 1024);
	ft_printf("%s%s@%s%s:", ANSI_COLOR_MAGENTA, \
		pw->pw_name, hostname, ANSI_COLOR_RESET);
	ft_printf("%s%s%s$> ", ANSI_COLOR_CYAN, cwd, ANSI_COLOR_RESET);
	free(cwd);
}
