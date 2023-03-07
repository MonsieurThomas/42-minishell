/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:33:03 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/06 18:22:35 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*total;
	size_t	i;

	if (size && (((size_t)-1) / size) < count)
		return (NULL);
	total = malloc(count * size);
	if (!total)
		return (0);
	i = 0;
	ft_bzero(total, count * size);
	return (total);
	return ((void *)total);
}
