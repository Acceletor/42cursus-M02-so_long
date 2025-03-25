/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:48:13 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/11 15:49:07 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

//int main() {
//    const char	*haystack = "Hello, World!";
//	const char	*needle = "World";
//	size_t		len = 13;
//
//	char *result = ft_strnstr(haystack, needle, len);
//	if (result)
//		printf("Found '%s' at position: %ld\n", needle, result - haystack);
//	else
//		printf("Substring not found within the first %zu characters.\n", len);
//
//	result = ft_strnstr(haystack, "", len);
//	printf("Result with empty needle: %p\n", result);
//
//	return (0);
//}