/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:47:24 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/05 14:45:13 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src,
		size_t dstsize)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *) src;
	i = 0;
	if (dstsize > 0)
	{
		while (dst[i] != '\0' && i < dstsize)
			i++;
		j = i;
		while (str[i - j] != '\0' && i < dstsize - 1)
		{
			dst[i] = str[i - j];
			i++;
		}
		if (j < dstsize)
			dst[i] = '\0';
		return (j + ft_strlen(src));
	}
	else
		return (ft_strlen(src));
}
