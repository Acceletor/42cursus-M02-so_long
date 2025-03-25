/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:49:18 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/11 20:03:50 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*position;

	position = 0;
	while (*s)
	{
		if (*s == (char)c)
			position = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (position);
}
