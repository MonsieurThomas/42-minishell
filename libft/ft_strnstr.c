/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:11:59 by rthomas           #+#    #+#             */
/*   Updated: 2022/05/27 14:25:53 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*j;

	i = 0;
	j = (char *)haystack;
	n_len = ft_strlen((char *)needle);
	if (n_len == 0 || haystack == needle)
		return (j);
	while (j[i] != '\0' && i < len)
	{
		c = 0;
		while (j[i + c] != '\0' && needle[c] != '\0'
			&& j[i + c] == needle[c] && i + c < len)
			c++;
		if (c == n_len)
			return (j + i);
		i++;
	}
	return (0);
}
