/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:17:13 by gpardini          #+#    #+#             */
/*   Updated: 2023/05/19 20:00:45 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


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
            head = start_list(check_errors(num[y++]));
        while  (num[y] != NULL)
        {
            if(head && num[y])
                add_new(head, check_errors(num[y]));
            y++;
        }
        i++;
        y = 0;
    }
    return(head);
}

// void    check_rep(t_node *stack_a, int num)
// {
//     t_node* temp;
    
//     temp = stack_a->next;
//     while (temp->next != NULL)
//     {
//         if (num == temp->value)
//             exit(33);
//         temp = temp->next;
//     }
//     if (num == temp->value)
//         exit(4);
// }

void    is_rep(t_node *stack_a)
{
  //colocar a linked list em um array, organizar por bubblesort seila, e ver se tem algum repetido pela string inteira;  
}

int    check_errors(char* num)
{
    int i;
    char* test;
    
    i = 0;
    printf("recebido: %d\n", ft_atoi(num));
    while (num[i])
    {
        if (!ft_isdigit(num[i]) || ((num[i] == '+' || num[i] == '-') && i != 0))
           exit(11);
        i++;
    }
    test = ft_itoa(ft_atoi(num));
    if (ft_strcmp(test, num) != 0)
        exit(22);
    printf("numero do check: %d\n", ft_atoi(num));
    return (ft_atoi(num));
}

int main (int argc, char* argv[])
{
	t_node *stack_a;
    
    (void)argc;
    stack_a = start_stack_a(argv);
    printf("lista antes do is_rep:\n");
    print_list(stack_a);
    is_rep(stack_a);
    print_list(stack_a);
    return (0);
}
