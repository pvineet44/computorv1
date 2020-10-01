/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:06:55 by vparekh           #+#    #+#             */
/*   Updated: 2020/10/01 20:08:42 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <stdio.h>

static	int					is_skip_char(int c)
{
	if (ft_isspace(c) || c == '*' || c == 'X' || c == '^')
		return (1);
	return (0);
}

static	int					is_sig(int c)
{
	if ((c == '-') || (c == '+'))
		return (1);
	return (0);
}

static	int					skip(const char *expression, int i)
{
	while (expression[i] && (ft_isspace(expression[i]) ||\
				ft_isdigit(expression[i]) ||\
				is_sig(expression[i]) || expression[i] == '.'))
		i++;
	while (expression[i] && is_skip_char(expression[i]))
		i++;
	return (i);
}

static	int					get_exponent(const char *expression,\
		double tmp[], double c, int *index)
{
	int p;
	int i;

	i = *index;
	p = atoi(&expression[i]);
	if (p > EXPONENT_LIMIT)
		exit(1 * ft_putendl_fd(MAX_EXPONENT_ERROR, 2));
	tmp[p] += c;
	while (expression[i] && (ft_isdigit(expression[i]) ||\
				is_sig(expression[i])))
		i++;
	*index = i;
	return (p);
}

void						parse(const char *expression, double tmp[],\
		int *degree)
{
	int				i;
	double			c;
	int				p;
	double			flag;
	int				len;

	i = -1;
	flag = 1;
	len = ft_strlen(expression);
	while (++i < len)
	{
		c = flag * atof(&expression[i]);
		i = skip(expression, i);
		if (expression[i])
			p = get_exponent(expression, tmp, c, &i);
		while (expression[i] && ft_isspace(expression[i]))
			i++;
		if (expression[i] == '-' || expression[i] == '=')
			flag = -1;
		if (c != 0 && p > *degree)
			*degree = p;
	}
}
