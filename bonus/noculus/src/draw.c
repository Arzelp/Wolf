/*
** draw.c for draw in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Mon Dec 14 19:29:31 2015 Paskal Arzel
** Last update Tue Dec 20 18:15:30 2016 Paskal Arzel
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

int	desstexture(t_list *list, t_bunny_pixelarray *pix, int i, int height)
{
  int			j;
  float			raty;
  t_bunny_position	ppos;
  t_bunny_position	pos;
  t_color		color;
  int			starty;

  j = -1;
  pos.x = i;
  height = (height >= HEIGHT / 2 + 50) ? HEIGHT / 2 + 50 : height;
  pos.y = WIDTH / 2 - height + 1;
  ppos.x = (list->block.how == 0) ? 100 * (list->block.y - (int)list->block.y) : 100 * (list->block.x - (int)list->block.x);
  raty = HEIGHT / (2 * height);
  while (++j < 2 * height - 1)
    {
      ppos.y = 100 * ((float)j / (float)(2 * height));
      color = getpixel(list->textures[list->block.type - TEXTURE_MIN + 1], &ppos);
      tekpixel(pix, &pos, &color);
      pos.y++;
    }
  return (0);
}

int	desscol(t_list *list, t_bunny_pixelarray *pix, int i, int height)
{
  int			j;
  float			raty;
  t_bunny_position	ppos;
  t_bunny_position	pos;
  t_color		color;
  int			starty;

  j = -1;
  pos.x = i;
  height = (height >= HEIGHT / 2 + 50) ? HEIGHT / 2 + 50 : height;
  pos.y = WIDTH / 2 - height + 1;
  ppos.x = (list->block.how == 0) ? 100 * (list->block.y - (int)list->block.y) : 100 * (list->block.x - (int)list->block.x);
  raty = HEIGHT / (2 * height);
  while (++j < 2 * height - 1)
    {
      ppos.y = 100 * ((float)j / (float)(2 * height));
      color = getpixel(list->textures[0], &ppos);
      tekpixel(pix, &pos, &color);
      pos.y++;
    }
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
  /* printf("block :\n{x:%d\ny:%d\ntype:%d}\n", list->block.x, list->block.y, list->block.type); */
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
      if (list->block.type < TEXTURE_MIN)
	desscol(list, pix, i, height);
      else
	desstexture(list, pix, i, height);
    }
  minimap(pix, list);
  whereami(pix, list);
  return (0);
}
