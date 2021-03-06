/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkindere <lkindere@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:19:30 by lkindere          #+#    #+#             */
/*   Updated: 2022/06/23 15:53:12 by lkindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "math_utils.h"

typedef enum e_errors
{
	VALID,
	INVALID_ARGS,
	INVALID_MAP_FORMAT,
	INVALID_PATH_FORMAT,
	INVALID_COLOR_FORMAT,
	INVALID_DOORS,
	DUPLICATE_DEFINITION,
	UNCLOSED_MAP,
	NO_MAP,
	MALLOC
}	t_errors;

typedef enum e_pos
{
	E = 0,
	S = 1,
	W = 2,
	N = 3,
	D = 4,
	NO_POS
}	t_pos;

typedef struct s_door
{
	int		x;
	int		y;
	char	open;
	char	direction;
}	t_door;

typedef struct s_map
{
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			**door_text;
	long			floor_color;
	long			ceiling_color;
	int				width;
	int				height;
	unsigned int	pos_x;
	unsigned int	pos_y;
	enum e_pos		position;
	enum e_errors	valid;
	t_door			*doors;
}	t_map;

int		parser(int argc, char **argv, t_map *map);
int		free_map(t_map *map);

#endif