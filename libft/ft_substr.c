/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:29:04 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/05 20:26:26 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	if ((start + len) <= ft_strlen(s))
		str = (char *)malloc(sizeof(char) * len + 1);
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) - start) + 1);
	i = 0;
	j = 0;
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
