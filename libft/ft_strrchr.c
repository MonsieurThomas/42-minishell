/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:42:37 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/04 19:13:26 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	j;
	char	*str;

	i = 0;
	str = (char *)s;
	j = (char)c;
	while (str[i])
		i++;
	while (i > 0)
	{
		if (str[i] == j)
			return (str + i);
		i--;
	}
	if (str[i] == j)
		return (str);
	return (0);
}
