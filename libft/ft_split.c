/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:36:03 by agengemb          #+#    #+#             */
/*   Updated: 2022/07/30 14:21:52 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Description:
 *
 * Allocates and returns an array of strings obtained by splitting s using the
 * character c as a delimiter. The array must end with a NULL pointer.
 */

static size_t	count_words(char const *s, char c)
{
	size_t	nb_words;
	size_t	i;

	nb_words = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			while (*(s + i) && *(s + i) != c)
				i++;
			nb_words++;
		}
		else
			i++;
	}
	return (nb_words);
}

static char	*word_alloc(char const *s, char c)
{
	char	*word;
	size_t	nb_letters;
	size_t	i;

	nb_letters = 0;
	while (*(s + nb_letters) != c && *(s + nb_letters))
		nb_letters++;
	word = malloc(sizeof(char) * (nb_letters + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < nb_letters)
	{
		*(word + i) = *(s + i);
		i++;
	}
	*(word + i) = '\0';
	return (word);
}

static void	deallocate_tab(char ***res, size_t j)
{
	while (j-- > 0)
		free(res[j]);
	free(res[0]);
	*res = NULL;
}

static void	tab_alloc(char const *s, char c, char **res)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(s + i))
	{
		if (*(s + i) != c)
		{
			res[j] = word_alloc(s + i, c);
			if (!res[j])
			{
				deallocate_tab(&res, j);
				return ;
			}
			j++;
			while (*(s + i) && *(s + i) != c)
				i++;
		}
		else
			i++;
	}
	res[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	nb_words;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	res = malloc(sizeof(char *) * (nb_words + 1));
	if (!res)
		return (NULL);
	tab_alloc(s, c, res);
	return (res);
}
