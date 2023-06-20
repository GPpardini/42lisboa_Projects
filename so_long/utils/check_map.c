/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpardini <gpardini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:11:35 by gpardini          #+#    #+#             */
/*   Updated: 2023/06/20 19:42:16 by gpardini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_map_ber(char *file_name)
{
	char ber[4] = ".ber";
	int i;
	i = 0;
	while (file_name[i] != '\0')
	{
		if (file_name[i] == '.')
		{	
			while (file_name[i] == ber[i])
			{
				if (file_name[i] != ber[i])
					return (0);
				i++;
			}
			return(1);
		}
		i++;
	}
	return (0);
}
