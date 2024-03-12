/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:58:04 by cgray             #+#    #+#             */
/*   Updated: 2024/01/05 17:25:16 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Returns max value from between for two ints, a if they are equal
*/
int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
