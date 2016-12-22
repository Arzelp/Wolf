/*
** wolf3d.c for wolf3d in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Sun Dec 13 15:44:22 2015 Paskal Arzel
** Last update Thu Dec 22 15:44:22 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <lapin.h>
#include "my.h"

t_bunny_response	mainresp(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 void *_list)
{
  t_list	*list;

  list = (t_list *)_list;
  list->keys = bunny_get_keyboard();
  return (GO_ON);
}

int	cielsol(t_bunny_pixelarray *pix, t_list *list)
{
  t_color		color;
  t_bunny_position	pos;
  int			i;
  int			j;

  color.full = 0xFFCC33;
  if (list->night == true)
    color.full = 0x331100;
  i = -1;
  my_fill(pix, &color);
  color.full = 0x33CC00;
  if (list->night == true)
    color.full = 0x005511;
  while (++i <= 800)
    {
      j = 400;
      while (++j <= 800)
	{
	  pos.x = i;
	  pos.y = j;
	  tekpixel(pix, &pos, &color);
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
    return (1);
  if ((height = my_getcnbr(bunny_ini_get_field
			   (in, "level1", "height", 0))) == -1)
    return (1);
  map = creatmap(in, width, height);
  list->width = width;
  list->height = height;
  list->map = map;
  return (0);
}

t_bunny_response	mainloop(void *_list)
{
  t_list		*list;
  t_bunny_pixelarray	*pix1;
  t_bunny_pixelarray	*pix2;
  t_bunny_position	*pos;

  list = _list;
  list->sprinting = false;
  list->keys = bunny_get_keyboard();
  if ((pos = malloc(sizeof(t_bunny_position))) == NULL)
    return (1);
  pos->x = 0;
  pos->y = 0;
  if ((pix1 = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  controls(list);
  cielsol(pix1, list);
  drawit(pix1, list);
  sprinter(pix1, list);
  weapon(pix1, list);
  list->light = (list->light > 0) ? list->light - 0.12 : list->light;
  list->view = (list->view > 0) ? list->view - 0.0008 : list->view;
  list->coke = (list->coke > 1) ? list->coke - 0.005 : 1;
  /*if (list->keys[BKS_ESCAPE])
    {
      freeall(list, pix1);
      exit (0);
    }*/
  printf("mob 1 : {pos:\n{x:%.2f\ny:%.2f\n}dmg:%d\ncooldown:%d}\n", list->mobs[0]->pos.x, list->mobs[0]->pos.y, list->mobs[0]->dmg, list->mobs[0]->maxcd);
  bunny_blit(&(list->win)->buffer, &(pix1)->clipable, pos);
  bunny_display(list->win);
  bunny_delete_clipable(&(pix1)->clipable);
  free(pos);
  return (GO_ON);
}

int	main(int ac, char **av)
{
  t_list		*list;
  t_bunny_window 	*win;
  t_bunny_ini		*ini;

  if ((list = malloc(sizeof(t_list))) == NULL || ac != 2)
    return (1);
  if ((ini = bunny_load_ini(av[1])) == NULL)
    return (1);
  if ((win = bunny_start(WIDTH, HEIGHT, false, "wolf3d")) == NULL)
    return (1);
  if (getmap(av[1], list) == 1)
    return (1);
  if (creatlist(list, win, ini) == 1)
    return (1);
  aff_map(list->map, list);
  list->keys = bunny_get_keyboard();
  list->coke = 1;
  list->night = false;
  list->cdnight = 0;
  list->weapon.selected = 0;
  list->sprint = 100;
  bunny_set_loop_main_function(mainloop);
  bunny_set_key_response(&mainresp);
  bunny_loop(win, 80, list);
  return (0);
}
