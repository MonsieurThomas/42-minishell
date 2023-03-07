/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:21:28 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/04 19:29:00 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	letter;
	size_t	i;

	str = (char *)s;
	letter = (char)c;
	i = 0;
	while (i < n)
	{
		if (*str == letter)
			return (str);
		str++;
		i++;
	}
	return (0);
}
