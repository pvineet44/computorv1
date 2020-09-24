/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:41:04 by vparekh           #+#    #+#             */
/*   Updated: 2020/09/24 23:34:55 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "computor.h"


double	*init_coefficients(double coefficients[], int size)
{
	int i;

	i = 0;
	coefficients = malloc(sizeof(double) * size);
	if (coefficients == NULL)
		exit(1 * ft_putendl_fd("Error: Malloc failed.", 2));
	while (i < size)
		coefficients[i++] = 0;
	return coefficients;
}

int		main(int argc, const char *argv[])
{
	double	*coefficients;
	int		degree;

	coefficients = NULL;
	degree = 0;
	coefficients = init_coefficients(coefficients, EXPONENT_LIMIT);
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (1);
	}
	parse(argv[1], coefficients, &degree);
	printf("0: %f\n", coefficients[0]);
	printf("1: %f\n", coefficients[1]);
	printf("2: %f\n", coefficients[2]);
	printf("3: %f\n", coefficients[3]);
	printf("degree: %d\n", degree);
	return 0;
}
