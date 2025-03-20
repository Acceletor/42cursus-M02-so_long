/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:42:47 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/11 15:44:41 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*des;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	des = malloc(len_s1 + len_s2 + 1);
	if (!des)
		return (0);
	i = 0;
	while (i < len_s1)
	{
		des[i] = s1[i];
		i++;
	}
	while (i - len_s1 < len_s2)
	{
		des[i] = s2[i - len_s1];
		i++;
	}
	des[i] = 0;
	return (des);
}

//int main(void)
//{
//    char *result;
//
//    result = ft_strjoin("Hello", " World");
//    printf("Test 1: %s\n", result); // Expected: "Hello World"
//    free(result);
//
//    result = ft_strjoin("", "World");
//    printf("Test 2: %s\n", result); // Expected: "World"
//    free(result);
//
//    result = ft_strjoin("Hello", "");
//    printf("Test 3: %s\n", result); // Expected: "Hello"
//    free(result);
//
//    result = ft_strjoin("", "");
//    printf("Test 4: %s\n", result); // Expected: ""
//    free(result);
//
//    result = ft_strjoin(NULL, "World");
//    printf("Test 5: %s\n", result ? result : "NULL"); // Expected: "NULL"
//
//    return (0);
//}