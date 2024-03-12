/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:31:19 by cgray             #+#    #+#             */
/*   Updated: 2023/10/26 12:16:27 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*outputs char 'c' to the given file descriptor 'fd'
*/
void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return ;
}
