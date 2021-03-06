/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 00:47:44 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/23 14:57:03 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include "math_utils.h"
# include "map.h"
# include "math_utils.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>

# define WIDTH 1024
# define HEIGHT 768
# define TS 64
# define MM 0.3
# define PS 0.5
# define SPEED_MULTIPLIER 0.05
# define RAY_COLOR 0x0000FFFF

//Map: 		int representation of starting tile
//Start: 	Starting x and y
//Dir:		Starting direction
//Len:		Length in x or y
//Step:		Unit step size in x or y
//Hit:		Wall hit x and y
//Distance:	Distance to wall hit
typedef struct s_ray
{
	t_vec_int	map;
	t_vec		start;
	t_vec		dir;
	t_vec		len;
	t_vec		step;
	t_vec		hit;
	t_pos		hit_pos;
	float		distance;
	bool		is_door;
}	t_ray;

typedef enum s_error
{
	NONE,
	ERROR_GENERAL,
	ERROR_MALLOC
}	t_error;

typedef enum s_speed
{
	WALK = 2,
	SPRINT = 3,
	SNEAK = 1,
	DASH = 30
}	t_speed;

typedef struct s_textures
{
	xpm_t	*n;
	xpm_t	*s;
	xpm_t	*e;
	xpm_t	*w;
	xpm_t	**door;
}	t_textures;

/**
 *	@param map Array of strings with map content.
 *	@param ps Player size.
 *	@param mlx Main mlx handle.
 *	@param walls Walls struct to be rendered.
 */
typedef struct s_data
{
	mlx_t		*mlx;
	int			width;
	int			height;
	char		**map;
	t_textures	textures;
	mlx_image_t	*p_img;
	mlx_image_t	*walls;
	mlx_image_t	*rays;
	mlx_image_t	*draw;
	float		speed;
	float		angle;
	t_vec		dir;
	t_vec		player;
	t_vec		mouse;
	int			tsm;
	int			effects;
	t_map		*map_;
}	t_data;

/*	hook				*/
void		hook(void *param);
void		key_hook(mlx_key_data_t keydata, void *param);

/* rays					*/
t_ray		do_rays(t_data *data, t_vec start, t_vec dir, float range);
int			draw_rays(t_data *data, t_ray *r, t_vec start);
void		raycaster(t_data *data);

/*	init				*/
int			init(t_data *data, t_map *map);

/*	player				*/
float		angle_fit(float angle);
void		player_rotate(t_data *data);
void		player_move(t_data *data);
int			check_collision(t_data *data, float x, float y);
void		player_dash(t_data *data);
void		player_speed(t_data *data);
void		open_door(t_data *data);

/* draw					*/
t_vec_int	screen_bounds(int x, int y);
void		safe_pixel(mlx_image_t *image, t_vec vec, uint32_t color);
void		draw_line(mlx_image_t *image, t_vec p1, t_vec p2, uint32_t color);

/* effects				*/
void		set_effects(mlx_key_data_t keydata, t_data *data);
uint32_t	funky_stuff(unsigned int color);

#endif
