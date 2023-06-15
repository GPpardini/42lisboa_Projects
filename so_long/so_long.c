/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:11:16 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/15 17:41:30 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

static t_data* get(void)
{
	static t_data* data;
	return (data);
}

int main (int argc, char* argv[])
{
	get()->fd = open(argv[1], O_RDONLY);
	
	return(0);
}