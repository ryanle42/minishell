/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:05:50 by rle               #+#    #+#             */
/*   Updated: 2017/11/30 18:48:27 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_tokens(const char *str, char delim)
{
	int		count;
	char	*p;

	p = (char *)str;
	count = 1;
	while (*p != '\0')
	{
		if (*p == delim)
			count++;
		p++;
	}
	return (count);
}

static void	malloc_arrays(const char *str, char delim, char ***arr)
{
	int		i;
	int		token_len;
	char	*p;

	p = (char *)str;
	token_len = 1;
	i = 0;
	while (*p != '\0')
	{
		if (*p == delim)
		{
			(*arr)[i] = (char *)malloc(sizeof(char) * token_len);
			ft_bzero((*arr)[i], token_len);
			token_len = 1;
			i++;
		}
		p++;
		token_len++;
	}
	(*arr)[i] = (char *)malloc(sizeof(char) * token_len);
	ft_bzero((*arr)[i], token_len);
}

static void	fill_arrays(const char *str, char delim, char ***arr)
{
	int		i;
	char	*tmp;
	char	*p;

	p = (char *)str;
	i = 0;
	tmp = ((*arr)[i]);
	while (*p != '\0')
	{
		if (*p != delim && *p != '\0')
		{
			*tmp = *p;
			tmp++;
		}
		else
		{
			i++;
			*tmp = '\0';
			tmp = ((*arr)[i]);
		}
		p++;
	}
}

int			ft_strsplit(const char *str, char delim, char ***arr)
{
	int	count;

	if (!str)
		return (0);
	count = count_tokens(str, delim);
	*arr = (char **)malloc(sizeof(char *) * (count + 1));
	malloc_arrays(str, delim, arr);
	fill_arrays(str, delim, arr);
	(*arr)[count] = NULL;
	return (count);
}
