/*
** createlist.c for createlist.c in /home/arzel_p/rendu/gfx_wolf3d/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Sun Jan  3 16:38:08 2016 Paskal Arzel
** Last update Mon Jan  4 18:18:58 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lapin.h"
#include "my.h"

char	**creatmap(t_bunny_ini *in, int width, int height)
{
  char	**map;
  int	i = -1;
  char	c;

  if ((map = bunny_malloc((height + 1) * sizeof(char *))) == NULL)
    height = 0;
  while (++i < height)
    {
      if ((map[i] = bunny_malloc((width + 1) * sizeof(char))) == NULL)
	height = 0;
    }
  i = -1;
  while (bunny_ini_get_field(in, "level1", "data", ++i) != NULL && \
	 i < width * height)
    {
      c = my_getcnbr(bunny_ini_get_field(in, "level1", "data", i));
      map[i / width][i % width] = c;
    }
  return (map);
}

int	creatlist(t_list *list, t_bunny_window *win, t_bunny_ini *ini)
{
  list->name = "level1";
  list->win = win;
  if ((list->posx = my_getnbr
      ((char *)bunny_ini_get_field(ini, "level1", "sx", 0))) == -1)
      return (1);
  if ((list->posy = my_getnbr
       ((char *)bunny_ini_get_field(ini, "level1", "sy", 0))) == -1)
      return (1);
  if ((list->angle = my_getnbr
       ((char *)bunny_ini_get_field(ini, "level1", "sa", 0))) == -1)
      return (1);
  list->view = 0;
  list->light = 0;
  return (0);
}
