/*
** whereami.c for whereami in /home/arzel_p/rendu/gfx_wolf3d/bonus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Dec 18 22:12:53 2015 Paskal Arzel
** Last update Thu Dec 31 12:58:39 2015 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <lapin.h>
#include "my.h"

int	my_square(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color	*color;
  int	i;
  int	j;
  int	ancx;
  int	ancy;

  if ((color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  i = -1;
  color->full = 0xFF;
  ancx = pos->x;
  ancy = pos->y;
  while (++i < 6)
    {
      j = -1;
      while (++j < 6)
	{
	  pos->x = ancx + j;
	  pos->y = ancy + i;
	  tekpixel(pix, pos, color);
	}
    }
  bunny_free(color);
  return (0);
}

int	whereami(t_bunny_pixelarray *pix, t_list *list)
{
  t_bunny_position	*pos;

  if ((pos = bunny_malloc(sizeof(t_bunny_position))) == NULL)
    return (1);
  pos->x = (790 - list->width * 6) + 6 * (list->posy - 0.5);
  pos->y = 20 + 6 * (list->posx - 0.5);
  my_square(pix, pos);
  bunny_free(pos);
  return (0);
}
