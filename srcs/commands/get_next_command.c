/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:05:43 by rle               #+#    #+#             */
/*   Updated: 2017/12/06 13:37:39 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*read_stdin(void)
{
	char	*input;
	char	ch;

	input = NULL;
	while (read(0, &ch, 1) > 0)
	{
		if (ch == '\n')
			return (input);
		input = ft_append_char(input, ch, 1);
	}
	return (input);
}

char		*remove_first_char(char *str)
{
	int		i;
	char	*new_str;

	if (str == NULL || str[0] == '\0')
		return (str);
	new_str = (char *)malloc(ft_strlen(str));
	i = 1;
	while (str[i])
	{
		new_str[i - 1] = str[i];
		i++;
	}
	new_str[i - 1] = '\0';
	free(str);
	return (new_str);
}

char		*grab_env(char *str)
{
	char *env;

	if (str[0] == '$' &&
	(str[1] && str[1] != ' ' && str[1] != '$'))
	{
		str = remove_first_char(str);
		env = get_env_val(str);
		return (env);
	}
	return (str);
}

static void	replace_env_var(char **str)
{
	int		i;
	int		length;
	char	**arr;
	char	*new_str;
	char	*env;

	length = ft_strsplit(*str, ' ', &arr);
	new_str = grab_env(ft_copystr(arr[0]));
	free(arr[0]);
	i = 1;
	while (i < length)
	{
		env = grab_env(ft_copystr(arr[i]));
		if (env)
		{
			new_str = ft_append_char(new_str, ' ', 1);
			new_str = ft_append_str(new_str, env, 3);
		}
		free(arr[i]);
		i++;
	}
	free(arr);
	free(*str);
	*str = new_str;
}

void		get_next_command(char ***cmds)
{
	char			*line;
	int				i;
	int				len;
	struct passwd	*pw;
	char			*homedir;

	pw = getpwuid(getuid());
	homedir = pw->pw_dir;
	line = NULL;
	if (!(line = read_stdin()))
		return ;
	len = ft_strsplit(line, ';', cmds);
	i = 0;
	while (i < len)
	{
		clear_whitespaces(&((*cmds)[i]));
		if ((*cmds)[i])
		{
			replace_env_var(&((*cmds)[i]));
			(*cmds)[i] = ft_strreplace((*cmds)[i], "~", homedir);
		}
		i++;
	}
	free(line);
}
