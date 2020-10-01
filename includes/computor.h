/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:52:15 by vparekh           #+#    #+#             */
/*   Updated: 2020/09/25 00:27:25 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H
# define EXPONENT_LIMIT 4096
# define MAX_EXPONENT_ERROR "Error: Maximum exponent can be 4096."
# include "libft.h"
# include <stdio.h>

void						parse(const char *expression, double *tmp,\
		int *degree);
double						*solve(double *numbers, int degree);

#endif
