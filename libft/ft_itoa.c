/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:40:57 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/05 11:50:18 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_len(int n, int neg)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (neg == -1)
		i++;
	return (i);
}

int	ft_is_neg(int n)
{
	int	neg;

	neg = 1;
	if (n < 0)
	neg = -1;
	return (neg);
}

char	*ft_2nd_part_itoa(int i, int n, int neg)
{
	char	*str;
	int		j;

	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	j = i;
	while (j > 0)
	{
		str[j - 1] = (n % 10) + '0';
		n = n / 10;
		j--;
	}
	if (neg == -1)
		str[0] = '-';
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	neg = ft_is_neg(n);
	if (neg == -1)
			n *= -1;
	i = ft_get_len(n, neg);
	str = ft_2nd_part_itoa(i, n, neg);
	return (str);
}
