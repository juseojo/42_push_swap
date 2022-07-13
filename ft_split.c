/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:30:43 by seongjch          #+#    #+#             */
/*   Updated: 2022/07/13 13:36:24 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**let_free(char **s)
{
	size_t	i;

	if (s == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
	return (NULL);
}

static char	*creat_words(char *word, char const *s, int j, int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		word[i] = s[j - len];
		i++;
		len--;
	}
	word[i] = '\0';
	return (word);
}

static char	**spl(char **result, char const *s, char c, int words)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0 ;
	len = 0;
	while (s[j] && i < words)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			j++;
			len++;
		}
		result[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!result[i])
			return (let_free(result));
		creat_words (result[i], s, j, len);
		len = 0;
		i++;
	}
	result[i] = 0;
	return (result);
}

static int	cnt_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**result;

	if (s == 0)
		return (NULL);
	words = cnt_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		exit (0);
	spl(result, s, c, words);
	return (result);
}
