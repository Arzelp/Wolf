/*
** resize.c for resize in /home/arzel_p/rendu/Infographie/gfx_wolf3d/bonus/noculus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Tue Dec 20 16:54:44 2016 Paskal Arzel
** Last update Tue Dec 20 17:16:26 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

t_bunny_pixelarray	*resize(t_bunny_pixelarray *pix, int width, int height)
{
  t_bunny_pixelarray	*res;
  t_bunny_position	pos;
  t_bunny_position	ppos;
  float			ratx;
  float			raty;
  t_color		color;

  if ((res = bunny_new_pixelarray(width, height)) == NULL)
    return (1);
  ratx = (float)pix->clipable.buffer.width / (float)width;
  raty = (float)pix->clipable.buffer.height / (float)height;
  pos.x = -1;
  while (++pos.x < width)
    {
      pos.y = -1;
      while (++pos.y < height)
	{
	  ppos.x = ratx * pos.x;
	  ppos.y = raty * pos.y;
	  color = getpixel(pix, &ppos);
	  /*printf("ppos:{x:%d,y:%d}\n", ppos.x, ppos.y);*/
	  tekpixel(res, &pos, &color);
	}
    }
  return (res);
}
