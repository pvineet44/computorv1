/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparekh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:41:04 by vparekh           #+#    #+#             */
/*   Updated: 2020/09/24 19:08:35 by vparekh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "computor.h"

int main(int argc, const char *argv[])
{
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		return (1);
	}
	int x = parse(argv[1]);
	x++;
	return 0;
}
