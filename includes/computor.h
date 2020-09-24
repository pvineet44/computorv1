/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:52:15 by vparekh           #+#    #+#             */
/*   Updated: 2020/09/24 19:34:01 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H
# define EXPONENT_LIMIT 4096
# define MAX_EXPONENT_ERROR "Error: Maximum exponent can be 4096."
# include "libft.h"
int						parse(const char *expression);

#endif
