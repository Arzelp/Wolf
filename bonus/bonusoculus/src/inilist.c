/*
** inilist.c for inilist in /home/arzel_p/rendu/gfx_wolf3d/bonus/bonusoculus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Thu Dec 31 12:28:44 2015 Paskal Arzel
** Last update Fri Nov 18 14:51:31 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

int	doit(t_bunny_pixelarray *pix1, t_bunny_pixelarray *pix2, t_list *list)
{
  cielsol(pix1, list);
  cielsol(pix2, list);
  drawit(pix1, list);
  drawit2(pix2, list);
  return (0);
}

int	inilist(t_list *list, t_bunny_window *win, t_bunny_ini *ini)
{
  list->name = "level1";
  list->win = win;
  if ((list->posx = my_getcnbr(bunny_ini_get_field
			       (ini, "level1", "sx", 0))) == -1)
    return (1);
  if ((list->posy = my_getcnbr(bunny_ini_get_field
			       (ini, "level1", "sy", 0))) == -1)
    return (1);
  if ((list->angle = my_getcnbr(bunny_ini_get_field
				(ini, "level1", "sa", 0))) == -1)
    return (1);
  list->view = 0;
  list->light = 0;
  return (0);
}
