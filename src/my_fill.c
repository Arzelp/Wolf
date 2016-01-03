/*
** my_fill.c for my_fill in /home/arzel_p/liblapin
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
**
** Started on  Sun Nov  1 15:37:16 2015 Paskal Arzel
** Last update Sun Jan  3 16:20:52 2016 Paskal Arzel
*/

#include "lapin.h"
#include "my.h"

void	my_fill(t_bunny_pixelarray *pix,
		t_color *color)
{
  t_bunny_position	*pos;

  pos = bunny_malloc(sizeof(t_bunny_position));
  pos->x = 0;
  pos->y = 0;
  while (pos->x <= (pix -> clipable.buffer.width))
    {
      pos->y = 0;
      while (pos->y <= (pix -> clipable.buffer.height))
        {
          tekpixel(pix, pos, color);
          pos->y++;
        }
      pos->x++;
    }
  bunny_free(pos);
}
