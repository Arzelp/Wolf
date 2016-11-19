/*
** minimap.c for minimap in /home/arzel_p/rendu/gfx_wolf3d/bonus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Dec 18 19:45:34 2015 Paskal Arzel
** Last update Fri Nov 18 14:58:32 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"
#include "mini.h"

int		minisquare(t_bunny_pixelarray *pix, t_bunny_position *pos,
			   unsigned int col)
{
  t_color	*color;
  int	i;
  int	j;
  int	ancx;
  int	ancy;

  if ((color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  i = -1;
  color->full = col;
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

unsigned int	*makecolortab()
{
  unsigned int	*colors;

  if ((colors = malloc(NB_TYPES * sizeof(unsigned int))) == NULL)
    return (NULL);
  colors[0] = COLOR_GROUND;
  colors[1] = COLOR_WALL;
  colors[2] = COLOR_TP;
  colors[3] = COLOR_TP;
  colors[4] = COLOR_TP;
  colors[5] = COLOR_DRUNK;
  colors[6] = COLOR_UNDRUNK;
  colors[7] = COLOR_LIGHT;
  colors[8] = COLOR_BIGL;
  return (colors);
}

int		minimap(t_bunny_pixelarray *pix, t_list *list)
{
  int	i;
  int	j;
  unsigned int		*colors;
  t_bunny_position	*pos;

  if ((pos = bunny_malloc(sizeof(t_bunny_position))) == NULL ||
      (colors = makecolortab()) == NULL)
    return (1);
  i = -1;
  while (++i < list->height)
    {
      j = -1;
      while (++j < list->width)
	{
	  pos->x = (790 - list->width * 6) + 6 * j;
	  pos->y = 20 + 6 * i;
	  if (list->map[i][j] >= 0 && list->map[i][j] <= NB_TYPES - 2)
	    minisquare(pix, pos, colors[(int)list->map[i][j]]);
	  else
	    minisquare(pix, pos, 0x000000);
	}
    }
  return (0);
}
