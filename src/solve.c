/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:26:17 by mashar            #+#    #+#             */
/*   Updated: 2020/09/25 02:02:15 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

double		ft_sqrt(double number)
{
	double sqrt;
	double temp;

	sqrt = number / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (number / temp + temp) / 2;
	}
	return (sqrt);
}

void		solve_two_degree(double *numbers, double **solution)
{
	double discriminant;

	discriminant = (numbers[1] * numbers[1]) - 4 * numbers[0] * \
						numbers[2];
	if (discriminant == 0)
	{
		solution[0][0] = 1;
		solution[0][1] = (-1 * numbers[1]) / (2 * numbers[2]);
		return ;
	}
	else if (discriminant < 0)
	{
		discriminant = discriminant * -1;
		solution[0][0] = -1;
		solution[0][1] = (-1 * numbers[1]) / (2 * numbers[2]);
		solution[0][2] = ft_sqrt(discriminant) / (2 * numbers[2]);
		return ;
	}
	solution[0][0] = 2;
	solution[0][1] = (-1 * numbers[1] + \
			ft_sqrt(discriminant)) / (2 * numbers[2]);
	solution[0][2] = (-1 * numbers[1] - \
			ft_sqrt(discriminant)) / (2 * numbers[2]);
}

void		ft_free(double *numbers)
{
	printf("Malloc error!!!");
	free(numbers);
}

double		*solve(double *numbers, int degree)
{
	double	*solution;

	if (degree == 1)
	{
		solution = (double*)malloc(sizeof(double) * 2);
		if (!solution)
		{
			ft_free(numbers);
			exit(0);
		}
		solution[0] = 1;
		solution[1] = -numbers[0] / numbers[1];
		return (solution);
	}
	else
	{
		solution = (double*)malloc(sizeof(double) * 3);
		if (!solution)
		{
			ft_free(numbers);
			exit(0);
		}
		solve_two_degree(numbers, &solution);
		return (solution);
	}
}
