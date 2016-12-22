/*
** colonmaker.c for colonmaker in /home/arzel_p/rendu/gfx_wolf3d/bonus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Thu Dec 24 21:11:13 2015 Paskal Arzel
** Last update Wed Dec 21 09:57:48 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

float	colonmakerx(t_list *list, float vx, float vy)
{
  float	df;
  float	fy;
  int	x;
  int	y;
  int	x2;
  float	distance;

  x = 0;
  df = 30;
  while (x < list->height)
    {
      distance = (x - list->posx) / vx;
      fy = list->posy + distance * vy;
      y = fy;
      x2 = (vx < 0 && x >= 1) ? x - 1 : x;
      if (distance > 0 && y < list->width && y >= 0)
	{
	  if (distance < df && ((list->map)[x2][y] == 1 || (list->map)[x2][y] >= TEXTURE_MIN))
	    {
	      df = distance;
	      list->block.x = x2;
	      list->block.y = fy;
	      list->block.type = (list->map)[x2][y];
	      list->block.how = 0;
	    }
	}
      x++;
    }
  return (df);
}

float	colonmakery(t_list *list, float vx, float vy, float df)
{
  float	fx;
  int	x;
  int	y;
  float	distance;
  int	y2;

  y = 0;
  while (y < list->width)
    {
      distance = (y - list->posy) / vy;
      fx = list->posx + distance * vx;
      x = fx;
      y2 = (vy < 0 && y >= 1) ? y - 1 : y;
      if (distance > 0 && x < list->height && x >= 0)
	{
	  if (distance < df && ((list->map)[x][y2] == 1 || (list->map)[x][y2] >= TEXTURE_MIN))
	    {
	      df = distance;
              list->block.x = fx;
	      list->block.y = y2;
	      list->block.type = (list->map)[x][y2];
              list->block.how = 1;
	    }
	}
      y++;
    }
  return (df);
}
