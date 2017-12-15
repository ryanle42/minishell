/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:05:37 by rle               #+#    #+#             */
/*   Updated: 2017/12/03 12:41:08 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_quotes(char *str)
{
	int		i;
	int		j;
	int		length;
	char	*new;

	length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '"')
			length++;
		i++;
	}
	new = (char *)malloc(length + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '"')
			new[j++] = str[i];
		i++;
	}
	new[j] = '\0';
	free(str);
	return (new);
}

void		echo_command(char *cmd)
{
	char	**params;
	char	*str;
	int		i;

	ft_strsplit(cmd, ' ', &params);
	i = 1;
	while (params[i])
	{
		str = params[i];
		if (str)
		{
			str = remove_quotes(str);
			ft_printf("%s", str);
			if (params[i + 1])
				ft_printf(" ");
		}
		i++;
	}
	ft_printf("\n");
}
