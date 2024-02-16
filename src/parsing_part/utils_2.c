/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhtab <aakhtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:09:00 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/05 11:55:29 by aakhtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*s3;
// 	unsigned char	*s4;

// 	s3 = (unsigned char *)s1;
// 	s4 = (unsigned char *)s2;
// 	i = 0;
// 	while ((i < n) && (s3[i] != '\0' || s4[i] != '\0'))
// 	{
// 		if (s3[i] != s4[i])
// 			return (s3[i] - s4[i]);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strnstr(char *hay, char *ne, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	b;

// 	if (*ne == '\0')
// 		return ((char *)hay);
// 	i = 0;
// 	j = 0;
// 	b = 0;
// 	while ((i < len) && *(hay + i))
// 	{
// 		while (*(hay + i + j) == *(ne + j) && i + j < len)
// 		{
// 			if (ne[j + 1] == '\0')
// 				return ((char *)(hay + i));
// 			j++;
// 		}
// 		i++;
// 		j = 0;
// 	}
// 	return (0);
// }

char	*ft_substr_pars(char *s, unsigned int st, size_t l)
{
	char	*buff;
	size_t	i;
	size_t	d;

	i = 0;
	d = 0;
	buff = NULL;
	if (!s)
		return (NULL);
	if (st >= ft_strlen(s))
		return (buff);
	if (ft_strlen(s) - st < l)
		d = ft_strlen(s) - st;
	else
		d = (l);
	buff = (char *)malloc(d + 1);
	if (!buff)
		return (NULL);
	while (s[st] && i < l)
		*(buff + i++) = *(s + st++);
	*(buff + i) = '\0';
	return (buff);
}

char	*get_index(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i + 1] && line[i] != ' ')
		i++;
	return (line + i);
}
int	ft_strcmp(char *par, char *cmp)
{
	int	i;
	int	j;

	i = 0;
	if (!par || !cmp)
		return (1);
	while (par[i++])
	{
		j = 0;
		while (cmp[j] && cmp[j] == par[i])
		{
			j++;
			i++;
		}
		if (cmp[j] == '\0')
		{
			if (par[i] == ' ' || par[i] == '\0')
			{
				while (par[i] == ' ')
					i++;
				if (par[i] == '\0')
					return (0);
			}
		}
	}
	return (1);
}
