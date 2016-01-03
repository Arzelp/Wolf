/*
** draw.c for draw in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Dec 14 19:29:31 2015 Paskal Arzel
** Last update Sun Dec 27 10:23:27 2015 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

t_color *makecolor(t_list *list, int height, t_color *color)
{
  int	j;
  float	h;

  h = height / 250.0;
  j = -1;
  if (list->light * h < 0)
    {
      while (++j < 3)
	color->argb[j] = 0;
    }
  else
    {
      while (++j < 3)
	color->argb[j] = (list->light * h) / 2;
    }
  return (color);
}

int	desscol(t_list *list, t_bunny_pixelarray *pix, int i, int height)
{
  int			j;
  t_bunny_position	*pos;
  t_color		*color;

  j = -1;
  if ((pos = bunny_malloc(sizeof(t_bunny_position))) == NULL)
    return (1);
  pos->x = i;
  if ((color = bunny_malloc(sizeof(t_color *))) == NULL)
    return (1);
  height = (height >= 500) ? 500 : height;
  color = makecolor(list, height, color);
  while (++j < height)
    {
      pos->y = 400 + j;
      tekpixel(pix, pos, color);
      pos->y = 400 - j;
      tekpixel(pix, pos, color);
    }
  bunny_free(pos);
  bunny_free(color);
  return (0);
}

int	calcdistance(t_list *list, t_pos *scrpos)
{
  int	height;
  float	df;
  float	vx;
  float	vy;

  vx = scrpos->x - list->posx;
  vy = scrpos->y - list->posy;
  df = colonmakerx(list, vx, vy);
  df = colonmakery(list, vx, vy, df);
  height = 400 / (df + list->view);
  return (height);
}

int	drawit(t_bunny_pixelarray *pix, t_list *list)
{
  t_pos	*scrpos;
  float	i;
  float	x;
  float	y;
  float	radangle;
  float	height;

  i = -1;
  radangle = list->angle * M_PI / 180;
  if ((scrpos = bunny_malloc(sizeof(t_pos))) == NULL)
    return (1);
  while (++i <= 800.0)
    {
      scrpos->x = 0.5;
      scrpos->y = (400.0 - i) / 800.0;
      x = scrpos->x * cos(radangle) - scrpos->y * sin(radangle);
      y = scrpos->x * sin(radangle) + scrpos->y * cos(radangle);
      scrpos->x = list->posx + x;
      scrpos->y = list->posy + y;
      height = calcdistance(list, scrpos);
      desscol(list, pix, i, height);
    }
  minimap(pix, list);
  whereami(pix, list);
  return (0);
}
