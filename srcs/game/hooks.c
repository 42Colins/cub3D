/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:12:16 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/14 14:41:35 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		release_keys(int key, t_data *cube);

int	press_keys(int key, t_data *cube)
{
	if (key == W)
		cube->keys[Wk] = 1;
	else if (key == S)
		cube->keys[Sk] = 1;
	else if (key == A)
		cube->keys[Ak] = 1;
	else if (key == D)
		cube->keys[Dk] = 1;
	else if (key == ESC)
	{
		close_window(cube);
		exit (0);
	}
	if (key == LEFT_ARR)
		cube->keys[LEFT_ARRk] = 1;
	else if (key == RIGHT_ARR)
		cube->keys[RIGHT_ARRk] = 1;
	return (key);
}

int	release_keys(int key, t_data *cube)
{
	if (key == W)
		cube->keys[Wk] = 0;
	else if (key == S)
		cube->keys[Sk] = 0;
	else if (key == A)
		cube->keys[Ak] = 0;
	else if (key == D)
		cube->keys[Dk] = 0;
	else if (key == LEFT_ARR)
		cube->keys[LEFT_ARRk] = 0;
	else if (key == RIGHT_ARR)
		cube->keys[RIGHT_ARRk] = 0;
	return (key);
}

int	is_wall(t_data *cube, double posx, double posy)
{
	if (posy <= 0 || posx <= 0)
		return (1);
	posx = floor(posx + 5) / 10;
	posy = floor(posy + 5) / 10;
	if (cube->map[(int)posy][(int)posx] == '1')
		return (1);
	if (cube->map[(int)(posy + 0.1)][(int)(posx + 0.1)] == '1')
		return (1);
	if (cube->map[(int)(posy - 0.1)][(int)(posx - 0.1)] == '1')
		return (1);
	if (cube->map[(int)(posy + 0.1)][(int)(posx - 0.1)] == '1')
		return (1);
	if (cube->map[(int)(posy - 0.1)][(int)(posx + 0.1)] == '1')
		return (1);
	return (0);
}

int	close_window(t_data *cube)
{
	mlx_destroy_image(cube->window.mlx_ptr, cube->ntexture.img_ptr);
	mlx_destroy_image(cube->window.mlx_ptr, cube->stexture.img_ptr);
	mlx_destroy_image(cube->window.mlx_ptr, cube->etexture.img_ptr);
	mlx_destroy_image(cube->window.mlx_ptr, cube->wtexture.img_ptr);
	mlx_destroy_image(cube->window.mlx_ptr, cube->window.img_ptr);
	mlx_destroy_window(cube->window.mlx_ptr, cube->window.mlx_win);
	// mlx_destroy_display(cube->window.mlx_ptr);
	free_map(cube);
	free_parse(cube->p, NULL, 1);
	free(cube->keys);
	free(cube->window.mlx_ptr);
	free(cube);
	exit (0);
}
