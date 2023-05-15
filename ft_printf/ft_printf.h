/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:09:15 by gpardini          #+#    #+#             */
/*   Updated: 2023/03/06 11:04:02 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
void	printchar(char a, int *countsize);
void	printstring(char *string, int *countsize);
void	printnumber(int num, int *countsize);
void	printunsigned(unsigned int num, int *countsize);
void	printpointer(unsigned long long ptr, int *countsize);
void	p_pointer(unsigned long long num, int *countsize);
void	printhex(unsigned int num, char id, int *countsize);
void	p_hex(unsigned int num, char id, int *countsize);

#endif
