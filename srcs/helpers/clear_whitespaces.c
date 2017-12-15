/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_whitespaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:07:09 by rle               #+#    #+#             */
/*   Updated: 2017/12/15 13:02:12 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_ends(char **str)
{
	char	*tmp;
	int		i;
	int		start;
	int		end;

	start = 0;
	while ((*str)[start] && ((*str)[start] == ' ' ||
		(*str)[start] == '\t'))
		start++;
	end = strlen(*str);
	while (end > 0 && ((*str)[end - 1] == ' ' ||
		(*str)[end - 1] == '\t'))
		end--;
	tmp = (char *)malloc(end - start + 1);
	i = 0;
	while (start < end)
		tmp[i++] = (*str)[start++];
	if (i == 0)
		tmp = NULL;
	else
		tmp[i] = '\0';
	free(*str);
	*str = tmp;
}

static int	count_length(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			while (str[i] && (str[i] == ' ' ||
				str[i] == '\t'))
				i++;
			len++;
		}
		i++;
		len++;
	}
	return (len);
}

static void	clean_between(char **str)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = count_length(*str);
	tmp = (char *)malloc(len + 1);
	while ((*str)[i])
	{
		if ((*str)[i] == ' ' || (*str)[i] == '\t')
		{
			tmp[j++] = (*str)[i++];
			while ((*str)[i] && ((*str)[i] == ' ' ||
				(*str)[i] == '\t'))
				i++;
		}
		else
			tmp[j++] = (*str)[i++];
	}
	tmp[j] = '\0';
	free(*str);
	*str = tmp;
}

void		clear_whitespaces(char **str)
{
	clean_ends(str);
	if (*str)
		clean_between(str);
}
