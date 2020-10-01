/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:41:04 by vparekh           #+#    #+#             */
/*   Updated: 2020/10/01 20:12:08 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static double	*init_coefficients(double coefficients[], int size)
{
	int i;

	i = 0;
	coefficients = malloc(sizeof(double) * size);
	if (coefficients == NULL)
		exit(1 * ft_putendl_fd("Error: Malloc failed.", 2));
	while (i < size)
		coefficients[i++] = 0;
	return (coefficients);
}

static	void	print_complex(double *solution)
{
	double tmp;

	tmp = solution[2];
	printf("\nDiscriminant is strictly negative, the complex roots are:\
\n%g ", solution[1]);
	if (solution[2] < 0 && (solution[2] *= -1))
		printf("- ");
	else
		printf("+ ");
	printf("%gi\n%g ", solution[2], solution[1]);
	if (tmp < 0 && (tmp *= -1))
		printf("+ ");
	else
		printf("- ");
	printf("%gi\n", tmp);
}

static	void	print_solution(double *solution, int degree)
{
	if (solution[1] == 0)
		solution[1] = 0.0;
	if (solution[0] != 1 && solution[2] == 0)
		solution[2] = 0.0;
	if (degree == 1)
		printf("\nThe solution is %g\n", solution[1]);
	else
	{
		if (solution[0] == 1)
			printf("\nDiscriminant is zero, the solution is %g\n", \
					solution[1]);
		else if (solution[0] == 2)
		{
			printf("\nDiscriminant is strictly positive, the two solutions are\
\n%g\n%g\n", solution[1], solution[2]);
		}
		else
			print_complex(solution);
	}
}

static	void	print_result(double *coefficients, double *solution, int degree)
{
	int		i;

	i = 1;
	printf("Reduced form: ");
	if (coefficients[0] < 0 && (coefficients[0] *= -1))
		printf("- ");
	printf("%g * X^%d ", coefficients[0], 0);
	while (i <= degree)
	{
		if (coefficients[i] < 0 && (coefficients[i] *= -1))
			printf("- ");
		else
			printf("+ ");
		printf("%g * X^%d ", coefficients[i], i);
		i++;
	}
	printf("= 0\n");
	printf("Polynomial degree:  %d", degree);
	if (degree > 2)
	{
		printf("\nThe polynomial degree is strictly greater than 2, ");
		printf("I can't solve.\n");
	}
	else
		print_solution(solution, degree);
}

int				main(int argc, const char *argv[])
{
	double	*coefficients;
	int		degree;
	double	*solution;

	solution = NULL;
	coefficients = NULL;
	degree = 0;
	coefficients = init_coefficients(coefficients, EXPONENT_LIMIT);
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		if (coefficients)
			free(coefficients);
		return (1);
	}
	parse(argv[1], coefficients, &degree);
	solution = solve(coefficients, degree);
	print_result(coefficients, solution, degree);
	if (solution)
		free(solution);
	if (coefficients)
		free(coefficients);
	return (0);
}
