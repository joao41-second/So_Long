/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperpect <jperpect@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:58:32 by jperpect          #+#    #+#             */
/*   Updated: 2024/08/26 00:44:09 by jperpect         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	vlaid_ext(char *ext, char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == ext[3] && str[len - 1] == ext[2] && str[len - 2] == ext[1]
		&& str[len - 3] == ext[0])
	{
		return (1);
	}
	ft_printf("error\nnot .ber");
	return (0);
}
