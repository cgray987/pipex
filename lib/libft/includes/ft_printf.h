/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:16:41 by cgray             #+#    #+#             */
/*   Updated: 2023/12/05 17:32:05 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_digit(long nbr, int base);
int		ft_print_upper_digit(long nbr, int base);
int		ft_print_ptr(unsigned long long ptr);

#endif
