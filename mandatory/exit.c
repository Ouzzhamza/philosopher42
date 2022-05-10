/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:29:44 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/10 16:57:55 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philosopher.h"

/* **************************************************** */
/*                     🅵🆃_🅴🆁🆁🅾🆁                    */
/* **************************************************** */

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit (0);
}

/* **************************************************** */
/*                     🅵🆃_🅲🅻🅴🅰🆁                    */
/* **************************************************** */

int	ft_clear(void)
{
	return (1);
}

/* **************************************************** */
/*                     🅵🆃_🅲🅻🅴🅰🆁                    */
/* **************************************************** */

void	printing(t_info *rules, int id, char *str)
{
	(void) (rules);
	printf ("%lli %d %s\n", get_time(), id, str);
}
