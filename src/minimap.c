/*
** minimap.c for minimap in /home/arzel_p/rendu/gfx_wolf3d/bonus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Dec 18 19:45:34 2015 Paskal Arzel
** Last update Sun Jan  3 16:18:03 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

int	minisquaretp(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color	*color;
  int	ancx;
  int	ancy;
  int	i;
  int	j;

  if ((color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  ancx = pos->x;
  ancy = pos->y;
  i = -1;
  color->full = 0x996611;
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

int	minisquareground(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color	*color;
  int	ancx;
  int	ancy;
  int	i;
  int	j;

  if ((color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  ancx = pos->x;
  color->full = 0x2AEE7A;
  ancy = pos->y;
  i = -1;
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

int	minisquarewall(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color	*color;
  int	i;
  int	j;
  int	ancx;
  int	ancy;

  if ((color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  i = -1;
  color->full = 0xCCCCCC;
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

int	checkup(char nb, t_bunny_pixelarray *pix,
		t_bunny_position *pos)
{
  if (nb == 5)
    minisquaredrunk(pix, pos);
  else if (nb == 6)
    minisquareundrunk(pix, pos);
  else if (nb == 7)
    minisquarelight(pix, pos);
  return (0);
}

int	minimap(t_bunny_pixelarray *pix, t_list *list)
{
  int	i;
  int	j;
  t_bunny_position	*pos;

  if ((pos = bunny_malloc(sizeof(t_bunny_position))) == NULL)
    return (1);
  i = -1;
  while (++i < list->height)
    {
      j = -1;
      while (++j < list->width)
	{
	  pos->x = (790 - list->width * 6) + 6 * j;
	  pos->y = 20 + 6 * i;
	  if ((list->map)[i][j] == 1)
	    minisquarewall(pix, pos);
	  else if ((list->map)[i][j] <= 4 && (list->map)[i][j] >= 2)
	    minisquaretp(pix, pos);
	  else if ((list->map)[i][j] == 0)
	    minisquareground(pix, pos);
	  else
	    checkup((list->map)[i][j], pix, pos);
	}
    }
  return (0);
}
