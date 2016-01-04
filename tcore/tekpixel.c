/*
** my_set_pixel.c for my_set_pixel in /home/arzel_p/liblapin
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
**
** Started on  Sun Nov  1 14:38:04 2015 Paskal Arzel
** Last update Mon Jan  4 18:09:28 2016 Paskal Arzel
*/

#include "lapin.h"

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int   position;
  int	x;
  int	y;

  x = pix->clipable.buffer.width;
  y = pix->clipable.buffer.height;
  position = pos->y * (pix -> clipable.buffer.width) + pos->x;
  if (pos->x > 0 && pos->y > 0 && pos->x < x && pos->y < y)
    ((int *)pix -> pixels)[position] = color->full;
}
