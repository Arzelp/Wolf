/*
** sprinter.c for sprinter in /home/arzel_p/rendu/Infographie/gfx_wolf3d/bonus/bonusoculus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Nov 18 14:36:10 2016 Paskal Arzel
** Last update Fri Nov 18 17:51:39 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <lapin.h>
#include "my.h"


static void	dess_sprintcol(t_bunny_pixelarray *pix, t_bunny_position pos)
{
  int	i;
  t_color color;

  i = 0;
  pos.y = Y_SPRINT;
  color.full = 0xFFCC33;
  while (++i < SIZE_SPRINT)
    {
      printf("pos : %d || %d\n", pos.x, pos.y);
      color.argb[2] = (i < SIZE_SPRINT / 2) ? color.argb[2] - 4 : color.argb[2] + 4;
      tekpixel(pix, &pos, &color);
      pos.y++;
    }
}

static void	dess_barre(t_bunny_pixelarray *pix, t_list *list)
{
  t_bunny_position	pos;
  int	i;
  int	max;

  i = 0;
  max = list->sprint;
  pos.x = X_SPRINT;
  while (i < max)
    {
      dess_sprintcol(pix, pos);
      i++;
      pos.x++;
    }
  return;
}

void	sprinter(t_bunny_pixelarray *pix, t_list *list)
{
  dess_barre(pix, list);
  return;
}
