/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:28:12 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/02 11:12:42 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

pid_t	*pid_array(int argc)
{
	int		number_of_cmd;
	pid_t	*pid_array;

	number_of_cmd = argc - 3;
	pid_array = (pid_t *) malloc(sizeof(pid_t) * number_of_cmd);
	if (pid_array == 0)
		return (0);
	while (number_of_cmd > 0)
	{
		pid_array[number_of_cmd - 1] = number_of_cmd + 1;
		number_of_cmd--;
	}
	return (pid_array);
}

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

int	ft_file_closer(int **fd)
{
	if (close(fd[1][0]) == -1)
	{
		ft_free_doubleptr((void **)fd);
		return (-1);
	}
	if (close(fd[1][1]) == -1)
	{
		ft_free_doubleptr((void **)fd);
		return (-1);
	}
	if (close(fd[0][0]) == -1)
	{
		ft_free_doubleptr((void **)fd);
		return (-1);
	}
	if (close(fd[0][1]) == -1)
	{
		ft_free_doubleptr((void **)fd);
		return (-1);
	}
	return (0);
}

int	ft_file_opener(int argc, char **argv, int **fd)
{
	fd[0][0] = open(argv[1], O_RDONLY);
	if (fd[0][0] == -1)
	{
		ft_free_doubleptr((void **)fd);
		return (-1);
	}
	fd[0][1] = open(argv[argc - 1], (O_TRUNC) | O_RDWR | O_CREAT, 0777);
	if (fd[0][1] == -1)
	{
		ft_free_doubleptr((void **)fd);
		return (-1);
	}
	return (0);
}
