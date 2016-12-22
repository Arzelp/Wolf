/*
** getpixel.c for getpixel in /home/arzel_p/rendu/Infographie/gfx_wolf3d/bonus/noculus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Tue Dec 20 17:02:52 2016 Paskal Arzel
** Last update Tue Dec 20 17:05:59 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

t_color	getpixel(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  int	position;
  t_color	color;

  position = pos->y * pix->clipable.buffer.width + pos->x;
  if (pos->x >= 0 && pos->y >= 0 && pos->x < pix->clipable.buffer.width &&
      pos->y < pix->clipable.buffer.width)
    color.full = ((int *)pix -> pixels)[position];
  return (color);
}
