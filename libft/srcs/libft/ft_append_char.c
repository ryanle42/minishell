/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:15 by rle               #+#    #+#             */
/*   Updated: 2017/11/30 18:44:38 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_char(char *str, char ch, int opt)
{
	int		len;
	char	*tmp;

	if (str)
		len = ft_strlen(str);
	else
		len = 0;
	tmp = (char *)malloc(len + 2);
	if (str)
		ft_strcpy(tmp, str);
	tmp[len] = ch;
	tmp[len + 1] = '\0';
	if (str && opt == 1)
		free(str);
	return (tmp);
}
