/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:28:13 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/27 11:36:19 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	word(char *s, char c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		count++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

int	s_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**trim(char const *s, char c, char **arr, size_t words_count)
{
	unsigned int	j;
	unsigned int	k;
	size_t			word_len;

	k = 0;
	while (k < words_count)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		word_len = s_len(s, c);
		arr[k] = malloc(sizeof(char) * (word_len + 1));
		if (!arr[k])
			return (NULL);
		while (*s != c && *s)
		{
			arr[k][j++] = *s;
			s++;
		}
		arr[k++][j] = '\0';
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t			words_count;
	char			**arr;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	words_count = word((char *)s, c);
	arr = (char **) malloc(sizeof(char *) * (words_count + 1));
	if (!arr)
		return (NULL);
	arr = trim(s, c, arr, words_count);
	if (!arr)
	{
		i = 0;
		while (i < words_count)
			free(arr[i]);
		free(arr);
		return (NULL);
	}
	arr[words_count] = NULL;
	return (arr);
}
