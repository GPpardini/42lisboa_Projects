/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:17:13 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/18 20:54:27 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main (int argc, char* argv[])
{
	t_node *stack_a;
    
    stack_a = start_stack_a(argv);
    print_list(stack_a);
}

t_node*    start_stack_a(char *argv[])
{
    t_node* head;
    char**  num;
    int     i;
    int     y;
    
    head = NULL;
    i = 1;
    y = 0;
    while (argv[i] != 0)
    {
        num = ft_split(argv[i], ' ');
        if (num[y] != NULL && head == NULL)
            head = start_list(ft_atoi(num[y++]));
        while  (num[y] != NULL)
        {
            printf("debug\n");
            if(head && num[y])
                add_new(head, ft_atoi(num[y]));
            y++;
        }
        i++;
        y = 0;
    }
    return(head);
}

// TAREFA PRA AMANHA 

// FAZER OS CHECKERS:
// CARACTERES INVALIDOS 
// MAXIMO E MINIMO 
// NUMEROS REPITIDOS 



