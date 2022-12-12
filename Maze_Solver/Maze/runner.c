#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "mazelib.h"
#include "runner.h"

static int facing_x;
static int facing_y;
static int position_x;
static int position_y;

void runner_solve()
{
	int counter = 0;
	while (maze_get_char(position_x, position_y) != 'E')
	{
			if (maze_get_char(position_x + facing_x, position_y + facing_y) == '#' || maze_is_coord_in_bounds(position_x + facing_x, position_y + facing_y) == false)
			{
				counter = counter + 1;
				if (facing_x == 0)
				{
					if (facing_y == 1)
					{
						facing_x = 1;
						facing_y = 0;
						
					}else if (facing_y == -1)
					{
						facing_x = -1;
						facing_y = 0;
					}
				}else if (facing_y == 0)
				{
					if (facing_x == 1)
					{
						facing_x = 0;				
						facing_y = -1;
					}else if (facing_x == -1)
					{
						facing_x = 0;
						facing_y = 1;
					}
				
				}
				
			if (counter == 2)
			{
				if (facing_x == 0)
				{
					if (facing_y == 1)
					{
						facing_x = 1;
						facing_y = 0;
						
					}else if (facing_y == -1)
					{
						facing_x = -1;
						facing_y = 0;
					}
				}else if (facing_y == 0)
				{
					if (facing_x == 1)
					{
						facing_x = 0;				
						facing_y = -1;
					}else if (facing_x == -1)
					{
						facing_x = 0;
						facing_y = 1;
					}
				
				}
			}
			}else{
				position_x = position_x + facing_x;
				position_y = position_y + facing_y;
				if (maze_get_char(position_x - facing_x, position_y - facing_y) == ' '){
					maze_set_char(position_x - facing_x, position_y - facing_y, '.');
				}else if (maze_get_char(position_x - facing_x, position_y - facing_y) == '.'){
					maze_set_char(position_x - facing_x, position_y - facing_y, 'o');
				}else if (maze_get_char(position_x - facing_x, position_y - facing_y) == 'o'){
					maze_set_char(position_x - facing_x, position_y - facing_y, 'O');
				}else if (maze_get_char(position_x - facing_x, position_y - facing_y) == 'O'){
					maze_set_char(position_x - facing_x, position_y - facing_y, '@');
				}
				counter = 0;
			}


	}
	
}

void runner_init(){
	facing_x = 1;
	facing_y = 0;
	position_x = 1;
	position_y = 1;

}
