/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:48:27 by rthomas           #+#    #+#             */
/*   Updated: 2022/03/31 14:40:40 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*newdest;
	char		*newsrc;
	size_t		i;

	newdest = (char *)dst;
	newsrc = (char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		newdest[i] = newsrc[i];
		i++;
	}
	return (newdest);
}
