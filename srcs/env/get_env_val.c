/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:47 by rle               #+#    #+#             */
/*   Updated: 2017/12/06 14:35:35 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_val_help(char *line, char *key)
{
	int		i;
	int		j;
	char	*name;
	char	*value;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	if (!line[i])
		return (0);
	name = (char *)malloc(i + 1);
	value = (char *)malloc(ft_strlen(line) - i);
	i = -1;
	while (line[++i] && line[i] != '=')
		name[i] = line[i];
	name[i] = '\0';
	j = -1;
	while (line[++i])
		value[++j] = line[i];
	value[++j] = '\0';
	j = ft_strcmp(key, name);
	if (j != 0)
		free(value);
	free(name);
	return ((j != 0) ? NULL : value);
}

char		*get_env_val(char *key)
{
	extern char	**environ;
	char		*val;
	int			i;

	i = 0;
	while (environ[i])
	{
		if ((val = get_env_val_help(environ[i], key)))
			return (val);
		free(val);
		i++;
	}
	return (NULL);
}
