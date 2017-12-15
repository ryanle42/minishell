/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:50 by rle               #+#    #+#             */
/*   Updated: 2017/11/30 18:22:53 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_env(void)
{
	extern char	**environ;
	char		**copy;
	int			i;

	i = 0;
	while (environ[i])
		i++;
	copy = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (environ[i])
	{
		copy[i] = ft_copystr(environ[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
