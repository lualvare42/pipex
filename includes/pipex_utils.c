/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:28:12 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/01 13:18:51 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/** Explanation here
 * @brief
		This function helps to build a 2D array of integers.
		It will hold both pairs of fd needed for the pipex program
			- fd[0] will hold fd from file1 && file2
			- fd[1] will hold fd from pipe system call.
 * 
 * @param n 
		n is passed from calling function. Its value is 0, and used to loop
		through the double pointer.
 * @return int** 
 */
int	**ft_fd_array(int n)
{
	int	**fd;

	fd = (int **) malloc(sizeof(int *) * 2);
	if (fd == 0)
		return (0);
	while (n < 2)
	{
		fd[n] = (int *) malloc(sizeof(int) * 2);
		if (fd[n] == 0)
		{
			ft_free_doubleptr((void **)fd);
			return (0);
		}
		n = n + 1;
	}
	return (fd);
}
