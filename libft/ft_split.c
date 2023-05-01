/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:01:36 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/01 13:09:35 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **strings, int n)
{
	while (n >= 0)
	{
		free(strings[n--]);
	}
	free(strings);
}

char	*ft_strings(char const *s, char c, int *str_end)
{
	char	*str;
	int		str_start;

	str_start = *str_end;
	while (s[str_start] && s[str_start] == c)
	{
		str_start++;
	}
	*str_end = str_start;
	while (s[*str_end] && s[*str_end] != c)
	{
		*str_end = *str_end + 1;
	}
	str = ft_substr(s, (unsigned int)str_start, (size_t)(*str_end - str_start));
	return (str);
}

int	ft_string_count(char const *s, char c)
{
	int	n;
	int	strings;

	n = 0;
	strings = 0;
	while (n < (int)ft_strlen(s))
	{
		if ((s[n] != c) && ((n == 0) || (s[n - 1] == c)))
			strings = strings + 1;
		n++;
	}
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		string_number;
	int		n;
	int		k;

	string_number = ft_string_count(s, c);
	strings = (char **) malloc(sizeof(char *) * (string_number + 1));
	if (strings == NULL)
		return (NULL);
	n = 0;
	k = 0;
	while (n < string_number)
	{
		strings[n] = ft_strings(s, c, &k);
		if (strings[n] == NULL)
		{
			ft_free_doubleptr((void **)strings);
			return (NULL);
		}
		n++;
	}
	strings[n] = NULL;
	return (strings);
}
