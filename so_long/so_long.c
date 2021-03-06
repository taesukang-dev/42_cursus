/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:01:08 by tkang             #+#    #+#             */
/*   Updated: 2022/05/26 11:01:09 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_info(int fd, t_game_info *game)
{
	char	*buf;
	int		height;

	height = 1;
	buf = get_next_line(fd);
	save_info(buf, height, game);
	while (buf)
	{
		height++;
		buf = get_next_line(fd);
		if (!buf)
			break ;
		save_info(buf, height, game);
	}
	close(fd);
	wall_check(game);
	if (game->c_count < 1 || game->p_count != 1 || game->e_count < 1)
		print_errors("map error\n");
}

void	init_game(t_game_info *game)
{
	game->mlx = mlx_init();
	game->img = init_img(game->mlx);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64, \
					game->height * 64, "so_long");
	render(game);
}

int	main(int ac, char *av[])
{
	int			fd;
	t_game_info	*game;

	game = calloc(1, sizeof(t_game_info));
	if (ac != 2)
		print_errors("not one map");
	check_map_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_errors("dosent exist a file\n");
	init_game_info(fd, game);
	init_game(game);
	mlx_hook(game->mlx_win, KEY_PRESS, 0, &keypress_event, game);
	mlx_hook(game->mlx_win, KEY_EXIT, 0, &click_redcross, game);
	mlx_loop(game->mlx);
	return (0);
}
