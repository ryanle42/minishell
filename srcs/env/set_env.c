/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:07:01 by rle               #+#    #+#             */
/*   Updated: 2017/11/30 18:13:43 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		set_env_help(char *cmd)
{
	int		i;
	int		j;
	char	*name;
	char	*value;

	i = 0;
	while (cmd[i] && cmd[i] != '=')
		i++;
	if (!cmd[i])
		return (0);
	name = (char *)malloc(i + 1);
	value = (char *)malloc(ft_strlen(cmd) - i);
	i = -1;
	while (cmd[++i] && cmd[i] != '=')
		name[i] = cmd[i];
	name[i] = '\0';
	j = -1;
	while (cmd[++i])
		value[++j] = cmd[i];
	value[++j] = '\0';
	return (setenv(name, value, 1));
}

void	set_env(char *cmd)
{
	char	**params;
	int		i;

	ft_strsplit(cmd, ' ', &params);
	i = 1;
	while (params[i])
	{
		if (-1 == (set_env_help(params[i])))
		{
			if (errno == EINVAL)
				ft_printf("%s: '%s': not a valid identifier\n", \
					params[0], params[i]);
			errno = 0;
		}
		i++;
	}
}
