/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:28 by rle               #+#    #+#             */
/*   Updated: 2017/11/30 18:25:17 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_command(char *str, char *cmd)
{
	int	i;

	i = 0;
	while ((str[i] && cmd[i]) && \
	(str[i] == cmd[i]))
		i++;
	if (cmd[i] == '\0' && \
		(!str[i] || str[i] == ' '))
		return (1);
	else
		return (0);
}
