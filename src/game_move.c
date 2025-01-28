/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:53:31 by jwhitley          #+#    #+#             */
/*   Updated: 2024/08/08 15:48:12 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static	bool	check_rules(t_data *data, int row, int col)
{
	char	next;

	next = data->map[row][col];
	if (next == '1')
		return (false);
	if (next == 'E' && data->m_data->c != 0)
		return (false);
	if (next == 'C')
		data->m_data->c--;
	data->m_data->moves++;
	ft_printf("Moves: %d\n", data->m_data->moves);
	return (true);
}

void	left_right(t_data *data, int row, int col, int keysym)
{
	if (keysym == A || keysym == LT)
	{
		if (!check_rules(data, row, col - 1))
			return ;
		data->map[row][col] = '0';
		data->map[row][col - 1] = 'P';
		put_image(data, row, col);
		put_image(data, row, col - 1);
		data->m_data->p_col--;
	}
	if (keysym == D || keysym == RT)
	{
		if (!check_rules(data, row, col + 1))
			return ;
		data->map[row][col] = '0';
		data->map[row][col + 1] = 'P';
		put_image(data, row, col);
		put_image(data, row, col + 1);
		data->m_data->p_col++;
	}
}

void	up_down(t_data *data, int row, int col, int keysym)
{
	if (keysym == W || keysym == UP)
	{
		if (!check_rules(data, row - 1, col))
			return ;
		data->map[row][col] = '0';
		data->map[row - 1][col] = 'P';
		put_image(data, row, col);
		put_image(data, row - 1, col);
		data->m_data->p_row--;
	}
	if (keysym == S || keysym == DN)
	{
		if (!check_rules(data, row + 1, col))
			return ;
		data->map[row][col] = '0';
		data->map[row + 1][col] = 'P';
		put_image(data, row, col);
		put_image(data, row + 1, col);
		data->m_data->p_row++;
	}
}
