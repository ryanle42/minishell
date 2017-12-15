/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:06:08 by rle               #+#    #+#             */
/*   Updated: 2017/11/30 18:44:20 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append_str(char *a, char *b, int opt)
{
	int		len;
	int		i;
	char	*str;
	char	*c;

	i = -1;
	c = b;
	len = 0;
	if (a)
		len = ft_strlen(a);
	if (b)
		len += ft_strlen(b);
	str = (char *)malloc(len + 1);
	while (a[++i])
		str[i] = a[i];
	while (*b)
		str[i++] = *(b++);
	str[i] = '\0';
	if (opt == 1 || opt == 3)
		free(a);
	if (opt == 2 || opt == 3)
		free(c);
	return (str);
}
