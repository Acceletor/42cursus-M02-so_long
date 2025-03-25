/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:25:32 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/12 15:21:24 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char const *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			in_word = 0;
		else if (in_word == 0 && s[i] != c)
		{
			in_word = 1;
			count += 1;
		}
		i++;
	}
	return (count);
}

static void	input_string(char const *s, char *ptr_position, int len, int start)
{
	int	i;

	i = 0;
	while (len--)
	{
		ptr_position[i] = s[start + i];
		i++;
	}
	ptr_position[i] = 0;
	return ;
}

static void	free_split(char **split, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	create_split(char **split, char const *s, char c)
{
	int	i;
	int	j;
	int	position;

	i = 0;
	position = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
		{
			split[position] = malloc(sizeof(char) * (j + 1));
			if (!(split[position]))
				return (free_split(split, position));
			input_string(s, split[position], j, i);
			position++;
			i += j;
		}
	}
	split[position] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (0);
	words = countword(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return (0);
	create_split(split, s, c);
	return (split);
}
