/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afennoun <afennoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 01:26:54 by afennoun          #+#    #+#             */
/*   Updated: 2024/02/29 22:18:26 by afennoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (*(s + i))
	{
		if (*(s + i) != c && i > 0 && (*(s + i + 1) == c || *(s + i
					+ 1) == '\0'))
			count++;
		i++;
	}
	return (count + 1);
}

static void	*freealloc(char **splited, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(splited[i++]);
	free(splited);
	return (NULL);
}

static int	skipc(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) != c && *(s + i))
		i++;
	return (i);
}

void	*split_condition(char **ss, int *j)
{
	if (*(ss + *j) == NULL)
		return (freealloc(ss, *j));
	(*j)++;
	return (NULL);
}

char	**ft_split_pars(char *s, char c, t_par *par)
{
	char	**ss;
	int		i;
	int		j;
	int		k;

	ss = calloc(word(s, c) + 1, sizeof(char *));
	if (!s || !ss)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			k = skipc(s + i, c);
			*(ss + j) = ft_substr_pars(s, i, k);
			lst_add(par->col, lst_new(*(ss + j), par->col));
			split_condition(ss, &j);
			i += k;
		}
		else
			i++;
	}
	return (ss);
}
