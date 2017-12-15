/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:05 by rle               #+#    #+#             */
/*   Updated: 2017/12/02 14:40:53 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strreplace_help(char *str, char *new, int i, int k)
{
	char	*newstr;
	char	*end;
	int		j;

	newstr = (char *)malloc(i + 1);
	end = (char *)malloc((ft_strlen(str) - k) + 1);
	j = 0;
	while (j < i)
	{
		newstr[j] = str[j];
		j++;
	}
	newstr[j] = '\0';
	newstr = ft_append_str(newstr, new, 1);
	j = 0;
	while (str[k])
	{
		end[j] = str[k];
		j++;
		k++;
	}
	end[j] = '\0';
	newstr = ft_append_str(newstr, end, 3);
	free(str);
	return (newstr);
}

char		*ft_strreplace(char *str, char *replace, char *new)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (str[i])
	{
		j = 0;
		k = i;
		while ((str[k] && replace[j]) && \
		(str[k] == replace[j]))
		{
			j++;
			k++;
		}
		if (!replace[j])
			return (ft_strreplace_help(str, new, i, k));
		i++;
	}
	return (str);
}
