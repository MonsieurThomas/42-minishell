/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:35:56 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/05 20:56:38 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int				i;
	char			*result;

	i = 0;
	if (s2 == NULL || ft_strlen(s2) == 0)
		return ((char *)s1);
	while (i < ft_strlen(s1))
	{
		if (ft_strncmp((char *)&s1[i], s2, ft_strlen(s2)) == 0)
			return ((result = (char *)&s1[i]));
		i++;
	}
	return (NULL);
}
