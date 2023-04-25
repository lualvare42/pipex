/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:42:07 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/25 15:06:06 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub;
	size_t				n;
	unsigned int		size;

	size = (unsigned int)ft_strlen(s);
	if ((len > (ft_strlen(s) - (size_t)start)) && (size >= start))
		len = ft_strlen(s) - (size_t)start;
	else if (size < start)
		len = 0;
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	n = 0;
	while ((n < len) && (size > start))
	{
		sub[n] = s[n + (size_t)start];
		n++;
	}
	sub[n] = '\0';
	return (sub);
}
