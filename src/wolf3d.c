/*
** wolf3d.c for wolf3d in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Sun Dec 13 15:44:22 2015 Paskal Arzel
** Last update Tue Feb  2 15:33:26 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lapin.h"
#include "my.h"

int	cielsol(t_bunny_pixelarray *pix)
{
  t_color	*color;
  t_bunny_position	*pos;
  int	i;
  int	j;

  if ((color = bunny_malloc(sizeof(t_color))) == NULL)
    return (1);
  if ((pos = bunny_malloc(sizeof(t_bunny_position))) == NULL)
    return (1);
  color->full = 0x331100;
  i = -1;
  my_fill(pix, color);
  color->full = 0x005511;
  while (++i <= 800)
    {
      j = 400;
      while (++j <= 800)
	{
	  pos->x = i;
	  pos->y = j;
	  tekpixel(pix, pos, color);
	}
    }
  return (0);
}

void	aff_map(char **map, t_list *list)
{
  int	i;
  int	j;

  i = 0;
  while (i < list->height)
    {
      j = 0;
      while (j < list->width)
	{
	  my_put_nbr(map[i][j]);
	  my_putchar(',');
	  j++;
	}
      my_putchar('\n');
      i++;
    }
}

int	getmap(char *str, t_list *list)
{
  char	**map;
  int	width;
  int	height;
  t_bunny_ini	*in;

  if ((in = bunny_load_ini(str)) == NULL)
    return (1);
  if ((width = my_getcnbr(bunny_ini_get_field
			  (in, "level1", "width", 0))) == -1)
    width = 0;
  if ((height = my_getcnbr(bunny_ini_get_field
			   (in, "level1", "height", 0))) == -1)
    height = 0;
  map = creatmap(in, width, height);
  list->width = width;
  list->height = height;
  list->map = map;
  return (0);
}

t_bunny_response	mainloop(void *_list)
{
  t_list		*list;
  t_bunny_pixelarray	*pix;
  t_bunny_position	*pos;

  list = _list;
  if ((pos = bunny_malloc(sizeof(t_bunny_position))) == NULL)
    return (1);
  pos->x = -1;
  pos->y = -1;
  if ((pix = bunny_new_pixelarray(800, 800)) == NULL)
    return (1);
  cielsol(pix);
  drawit(pix, list);
  list->light = (list->light > 0) ? list->light - 0.12 : list->light;
  list->view = (list->view > 0) ? list->view - 0.0008 : list->view;
  bunny_blit(&(list->win)->buffer, &pix->clipable, pos);
  bunny_display(list->win);
  bunny_delete_clipable(&pix->clipable);
  bunny_free(pos);
  return (GO_ON);
}

int	main(int ac, char **av)
{
  t_list		*list;
  t_bunny_window 	*win;
  t_bunny_ini		*ini;

  if ((list = bunny_malloc(sizeof(list))) == NULL || ac != 2)
    return (1);
  if ((ini = bunny_load_ini(av[1])) == NULL)
    return (1);
  if ((win = bunny_start(800, 800, false, "wolf3d")) == NULL)
    return (1);
  if (getmap(av[1], list) == 1)
    return (1);
  if (creatlist(list, win, ini) == 1)
    return (1);
  aff_map(list->map, list);
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(&mainresp);
  bunny_loop(win, 80, list);
  return (0);
}
