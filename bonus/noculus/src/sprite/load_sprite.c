/*
** load_sprite.c for list_sprite in /home/arzel_p/rendu/Infographie/gfx_wolf3d/bonus/noculus/src/sprite/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Wed Dec 21 10:29:27 2016 Paskal Arzel
** Last update Wed Dec 21 17:19:12 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

int	display_weapon(t_bunny_pixelarray *pix, t_list *list, t_bunny_pixelarray *weapon)
{
  t_bunny_position	ppos;
  t_bunny_color		color;
  t_bunny_color		ccolor;

  ppos.x = 0;
  ppos.y = 0;
  ccolor = getpixel(weapon, &ppos);
  while (ppos.x < weapon->clipable.buffer.width)
    {
      ppos.y = -1;
      while (++ppos.y < weapon->clipable.buffer.height)
	{
	  color = getpixel(weapon, &ppos);
	  if (color.full != ccolor.full)
	    tekpixel(pix, &ppos, &color);
	}
      ppos.x++;
    }
  return (0);
}

int	weapon(t_bunny_pixelarray *pix, t_list *list)
{
  if (list->weapon.firing == true)
    display_weapon(pix, list, list->weaponson_sprite[list->weapon.selected]);
  if (list->weapon.firing == false)
    display_weapon(pix, list, list->weapons_sprite[list->weapon.selected]);
  return (0);
}
