/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:20:02 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/08 17:04:01 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_image(t_data *data, int a, int b)
{
	int		x;
	int		y;

	x = b * 48;
	y = a * 48;
	if (data->map[a][b] == '0')
		mlx_put_image_to_window(data->init, data->win, data->floor, x, y);
	if (data->map[a][b] == '1')
		mlx_put_image_to_window(data->init, data->win, data->wall, x, y);
	if (data->map[a][b] == 'P')
		mlx_put_image_to_window(data->init, data->win, data->player_d, x, y);
	if (data->map[a][b] == 'E')
		mlx_put_image_to_window(data->init, data->win, data->exit_c, x, y);
	if (data->map[a][b] == 'C')
		mlx_put_image_to_window(data->init, data->win, data->collect, x, y);
}

void	init_map(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	while (data->map[a])
	{
		b = 0;
		while (data->map[a][b] != '\0')
		{
			put_image(data, a, b);
			b++;
		}
		a++;
	}
}
