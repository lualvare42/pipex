/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_doubleptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:07:50 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/01 13:06:28 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_doubleptr(void **ptr)
{
	int	n;

	n = 0;
	while (ptr[n])
	{
		free(ptr[n]);
		n++;
	}
	free(ptr);
}
