#ifndef DATA_H
#define DATA_H

typedef struct s_game_data
{
	int					pl_pos[2];
	int					en_pos[2];
	int					exit_pos[2];
	int					move_count;
	int					collectible;
	int					endgame;
}						t_game_data;

#endif