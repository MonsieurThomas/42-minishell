/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:45:21 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/03 13:39:11 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{	
	int		i;
	int		lens1;
	int		lens2;
	char	*result;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!result)
		return (0);
	i = -1;
	while (++i < lens1)
		result[i] = s1[i];
	i = 0;
	while (i < lens2)
	{
		result[lens1] = s2[i];
		i++;
		lens1++;
	}
	result[lens1] = '\0';
	return (result);
}
