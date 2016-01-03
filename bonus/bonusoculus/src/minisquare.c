/*
** minisquare.c for minisquare in /home/arzel_p/rendu/gfx_wolf3d/bonus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Sun Dec 27 09:19:41 2015 Paskal Arzel
** Last update Tue Dec 29 17:30:21 2015 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

int	minisquareundrunk(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color	*color;
  int	i;
  int	j;
  int	ancx;
  int	ancy;

  if ((color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  i = -1;
  color->full = 0xFFFF33;
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

int	minisquaredrunk(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color	*color;
  int	i;
  int	j;
  int	ancx;
  int	ancy;

  if ((color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  i = -1;
  color->full = 0x0099FF;
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

int	minisquarelight(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color	*color;
  int	i;
  int	j;
  int	ancx;
  int	ancy;

  if ((color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  i = -1;
  color->full = 0xFFFFFF;
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
