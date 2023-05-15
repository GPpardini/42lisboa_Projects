/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:22:18 by gpardini          #+#    #+#             */
/*   Updated: 2023/03/10 21:19:42 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	printchar(char a, int *countsize)
{
	write(1, &a, 1);
	(*countsize)++;
}

void	printunsigned(unsigned int num, int *countsize)
{
	if (num >= 10)
		printunsigned(num / 10, countsize);
	printchar(num % 10 + '0', countsize);
}

void	printstring(char *string, int *countsize)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		write(1, &(string[i]), 1);
		i++;
	}
	(*countsize) += i;
}

void	p_pointer(unsigned long long num, int *countsize)
{
	if (num >= 16)
	{
		p_pointer(num / 16, countsize);
		p_pointer(num % 16, countsize);
	}
	else
	{
		if (num <= 9)
			printchar((num + '0'), countsize);
		else
			printchar((num - 10 + 'a'), countsize);
	}
}

void	printpointer(unsigned long long ptr, int *countsize)
{
	if (ptr == 0)
		printchar(0, countsize);
	else
		p_pointer(ptr, countsize);
}

void	printnumber(int num, int *countsize)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*countsize) += 11;
		return ;
	}
	if (num < 0)
	{
		printchar('-', countsize);
		printnumber(num * -1, countsize);
	}
	else
	{
		if (num > 9)
			printnumber(num / 10, countsize);
		printchar(num % 10 + '0', countsize);
	}
}

void	p_hex(unsigned int num, char id, int *countsize)
{
	if (num >= 16)
	{
		p_hex(num / 16, id, countsize);
		p_hex(num % 16, id, countsize);
	}
	else
	{
		if (num <= 9)
			printchar((num + '0'), countsize);
		else
		{
			if (id == 'x')
				printchar((num - 10 + 'a'), countsize);
			if (id == 'X')
				printchar((num - 10 + 'A'), countsize);
		}
	}
}

void	printhex(unsigned int num, char id, int *countsize)
{
	if (num == 0)
		printchar(0, countsize);
	else
		p_hex(num, id, countsize);
}

void	param_check(char id, va_list args, int *countsize)
{
	if (id == 'c')
		printchar(va_arg(args, int), countsize);
	else if (id == 's')
		printstring(va_arg(args, char *), countsize);
	else if (id == 'p')
		printpointer(va_arg(args, unsigned long long), countsize);
	else if (id == 'd' || id == 'i')
		printnumber(va_arg(args, int), countsize);
	else if (id == 'u')
		printunsigned(va_arg(args, unsigned int), countsize);
	else if (id == 'x' || id == 'X')
		printhex(va_arg(args, unsigned int), id, countsize);
	else if (id == '%')
		printchar('%', countsize);
}

int	ft_printf(const char *fmt, ...)
{
	int		countsize;
	int		i;
	va_list	args;

	countsize = 0;
	i = 0;
	va_start(args, *fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			param_check(fmt[i + 1], args, &countsize);
			i++;
		}
		else
			printchar(fmt[i], &countsize);
		i++;
	}
	va_end(args);
	return (countsize);
}


/*

int	main(void)
{
	int		p;
	int		ft;
    char *str = "hello world";
    int num = 42;
    float fnum = 3.14159;
    double dnum = 2.71828;
    char c = 'a';
	char *str1 = "hello";
    char *str2 = "world";
    int num1 = 42;
    int num2 = 69;
    float fnum1 = 3.14159;
    float fnum2 = 2.71828;
    double dnum1 = 1.234567890123456789;
    double dnum2 = 9.876543210987654321;
    char c1 = 'a';
    char c2 = 'b';

    // Exemplo 1
    printf("input tested: '%s'\n", str);
    p = printf("%s", str);
	printf("\n");
    ft = ft_printf("%s", str);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 2
    printf("input tested: '%d'\n", num);
    p = printf("%d", num);
	printf("\n");

    ft = ft_printf("%d", num);
	printf("\n");

    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 3
    printf("input tested: '%f'\n", fnum);
    p = printf("%f", fnum);
	printf("\n");
    ft = ft_printf("%f", fnum);
	printf("\n");
	if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 4
    printf("input tested: '%lf'\n", dnum);
    p = printf("%lf", dnum);
	printf("\n");
    ft = ft_printf("%lf", dnum);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 5
    printf("input tested: '%c'\n", c);
    p = printf("%c", c);
	printf("\n");
    ft = ft_printf("%c", c);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 6
    printf("input tested: '%s %d %c'\n", str, num, c);
    p = printf("%s %d %c", str, num, c);
	printf("\n");
    ft = ft_printf("%s %d %c", str, num, c);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 7
    printf("input tested: '%s %f'\n", str, fnum);
    p = printf("%s %f", str, fnum);
	printf("\n");
    ft = ft_printf("%s %f", str, fnum);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 8
    printf("input tested: '%d %f %c'\n", num, fnum, c);
    p = printf("%d %f %c", num, fnum, c);
	printf("\n");
    ft = ft_printf("%d %f %c", num, fnum, c);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 9
    printf("input tested: '%.2f'\n", fnum);
    p = printf("%.2f", fnum);
	printf("\n");
    ft = ft_printf("%.2f", fnum);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

	// Extra tests
	printf("Extra tests\n\n");

    // Exemplo 1
    printf("input tested: '%s %d %f %lf %c %s %d %f %lf %c'\n", str1, num1, fnum1, dnum1, c1, str2, num2, fnum2, dnum2, c2);
    p = printf("%s %d %f %lf %c %s %d %f %lf %c", str1, num1, fnum1, dnum1, c1, str2, num2, fnum2, dnum2, c2);
	printf("\n");
    ft = ft_printf("%s %d %f %lf %c %s %d %f %lf %c", str1, num1, fnum1, dnum1, c1, str2, num2, fnum2, dnum2, c2);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 2
    printf("input tested: '%10s %-10d %5.2f'\n", str1, num1, fnum1);
    p = printf("%10s %-10d %5.2f", str1, num1, fnum1);
	printf("\n");
    ft = ft_printf("%10s %-10d %5.2f", str1, num1, fnum1);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 3
    printf("input tested: '%+d % 5d %010d'\n", num1, num2, num1);
    p = printf("%+d % 5d %010d", num1, num2, num1);
	printf("\n");
    ft = ft_printf("%+d % 5d %010d", num1, num2, num1);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

    // Exemplo 4
    printf("input tested: '%.10lf %.3f'\n", dnum1, fnum2);
    p = printf("%.10lf %.3f", dnum1, fnum2);
	printf("\n");
    ft = ft_printf("%.10lf %.3f", dnum1, fnum2);
	printf("\n");
    if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");
	return (0);
}
*/

int main(void)
{
	int		p;
	int		ft;
    char *str = "hello world";
    int num = 42;
    float fnum = 3.14159;
    double dnum = 2.71828;
    char c = 'a';
	char *str1 = "hello";
    char *str2 = "world";
    int num1 = 42;
    int num2 = 69;
    float fnum1 = 3.14159;
    float fnum2 = 2.71828;
    double dnum1 = 1.234567890123456789;
    double dnum2 = 9.876543210987654321;
    char c1 = 'a';
    char c2 = 'b';

	printf("input tested: '%f'\n", fnum);
    p = printf("%f", fnum);
	printf("\n");
    ft = ft_printf("%f", fnum);
	printf("\n");
	if (p == ft)
        printf("OK\n\n");
    else
        printf("x\n\n");

	return (0);
}
