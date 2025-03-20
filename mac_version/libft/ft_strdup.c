/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:41:30 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/11 15:42:21 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*des;
	int		len;
	int		i;

	len = ft_strlen(s1);
	des = malloc(len + 1);
	if (des == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		des[i] = s1[i];
		i++;
	}
	des[i] = 0;
	return (des);
}

//int main() {
//    const char *original = "Hello, World!";
//    char *duplicate = ft_strdup(original);
//
//    if (duplicate == NULL) {
//        printf("Memory allocation failed\n");
//        return 1;
//    }
//
//    printf("Original: %s\n", original);
//    printf("Duplicate: %s\n", duplicate);
//
//    free(duplicate); // Free the allocated memory
//    return 0;
//}