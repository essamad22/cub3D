/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:53:26 by aakhtab           #+#    #+#             */
/*   Updated: 2024/01/15 12:12:12 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(long nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static void	putnbr(long nb, char *str, int len)
{
	while (len > 0)
	{
		str[len - 1] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*result;
	long	nbr;

	i = 0;
	nbr = (long)n;
	len = nbr_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		result[0] = '-';
		i++;
		result++;
	}
	putnbr(nbr, result, len - i);
	result[len - i] = '\0';
	return (result - i);
}
