/*
** go.c for go in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Sun Dec 13 15:41:28 2015 Paskal Arzel
** Last update Sun Dec 13 19:25:18 2015 Paskal Arzel
*/

#include <stdlib.h>
#include <math.h>
#include "my.h"
#include "lapin.h"

void	go(t_bunny_position *curpos, double angle, t_bunny_position *newpos,
	   int move)
{
  newpos->x = cos(angle) * move + curpos->x;
  newpos->y = sin(angle) * move + curpos->y;
}
