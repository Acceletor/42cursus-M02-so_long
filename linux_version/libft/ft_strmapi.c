/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuebtha <ksuebtha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:08:37 by ksuebtha          #+#    #+#             */
/*   Updated: 2024/12/12 17:31:33 by ksuebtha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*des;
	int		len;
	int		i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	des = malloc((len + 1) * sizeof(char));
	if (!des)
		return (0);
	i = 0;
	while (s[i])
	{
		des[i] = (*f)(i, s[i]);
		i++;
	}
	des[i] = 0;
	return (des);
}
