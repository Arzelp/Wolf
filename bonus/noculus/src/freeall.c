/*
** freeall.c for freeall in /home/arzel_p/rendu/Infographie/gfx_wolf3d/bonus/noculus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Thu Dec 22 15:32:48 2016 Paskal Arzel
** Last update Thu Dec 22 15:40:54 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

void	freeall(t_list *list, t_bunny_pixelarray *pix)
{
  int	i;

  free(list->weapons_sprite);
  free(list->weaponson_sprite);
  free(list->textures);
  i = 0;
  while (list->map[i])
    {
      free(list->map[i]);
      i++;
    }
  free(list->map);
}
