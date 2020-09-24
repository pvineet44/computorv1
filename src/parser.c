/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:06:55 by vparekh           #+#    #+#             */
/*   Updated: 2020/09/24 20:51:59 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <stdio.h>

static int				is_skip_char(int c)
{
	if (ft_isspace(c) || c == '*' || c == 'X' || c == '^')
		return (1);
	return (0);
}

static	int			is_sig(int c)
{
	if ((c == '-') || ( c == '+'))
		return (1);
	return (0);
}

int					parse(const char *expression)
{
	int			i;
	double		tmp[10];
	int		c;
	int			p;
	double			flag;

	i = 0;
	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	flag = 1;
	printf("len: %d\n", ft_strlen(expression));
	printf("str: %s\n", expression);
	while (expression[i] && ft_isspace(expression[i]))
			i++;
	while (expression[i] != '\0')
	{
		c = flag * atoi(&expression[i]);
		while (expression[i] && (ft_isspace(expression[i]) || ft_isdigit(expression[i]) || is_sig(expression[i])))
			i++;
		while (expression[i] && is_skip_char(expression[i]))
			i++;
		if (expression[i])
		{
			p = atoi(&expression[i]);
			printf("p: %d i: %d \n", p, i);
			if (p > EXPONENT_LIMIT)
				exit (1 * ft_putendl_fd(MAX_EXPONENT_ERROR, 2));
			tmp[p] += c;
			while (expression[i] && (ft_isdigit(expression[i]) || is_sig(expression[i])))
				i++;
		}
		while (expression[i] && ft_isspace(expression[i]))
			i++;
		if (expression[i] == '-' || expression[i] == '=')
			flag = -1;
		i++;
		if (i > 37)
			printf("c: %s\n", &expression[i]);
	}
	printf("0: %f\n", tmp[0]);
	printf("1: %f\n", tmp[1]);
	printf("2: %f\n", tmp[2]);
	return (1);
}
