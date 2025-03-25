/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:56:09 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/11 16:15:39 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cal_len(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (0);
	if (start + len > str_len)
		return (str_len - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (s == NULL)
		return (NULL);
	len = cal_len(s, start, len);
	if (len == 0)
	{
		sub = malloc(1 * sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	sub = malloc(len + 1 * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < (int)len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

// int	main(void)
// {
// 	char *s = "Hello, World!";
// 	char *sub;

// 	// Case: Normal substring
// 	sub = ft_substr(s, 7, 5);
// 	if (sub)
// 	{
// 		printf("Substring: '%s'\n", sub); // Output: "World"
// 		free(sub);
// 	}

// 	// Case: Start beyond string length
// 	sub = ft_substr(s, 14, 5);
// 	if (sub)
// 	{
// 		printf("Substring: '%s'\n", sub); // Output: ""
// 		free(sub);
// 	}

// 	// Case: len greater than remaining string
// 	sub = ft_substr(s, 7, 50);
// 	if (sub)
// 	{
// 		printf("Substring: '%s'\n", sub); // Output: "World!"
// 		free(sub);
// 	}

// 	return (0);
// }