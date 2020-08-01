/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:16:15 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/21 13:16:15 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_power_l(long double x, long n)
{
	if (n == 0)
		return (1.0);
	if (n < 0)
		return (1.0 / (x * ft_power_l(1.0 / x, n + 1)));
	return (x * ft_power_l(x, n - 1));
}
