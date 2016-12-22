/*
** creatlist.c for creatlist in /home/arzel_p/rendu/gfx_wolf3d/bonus/bonusoculus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Sun Jan  3 20:40:22 2016 Paskal Arzel
** Last update Thu Dec 22 15:27:59 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <lapin.h>
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

int	resize_textures(t_list	*list)
{
  int	i;

  i = 0;
  while (list->textures[i])
    {
      list->textures[i] = resize(list->textures[i], 100, 100);
      i++;
    }
  return (0);
}

int	resize_weapons(t_list	*list)
{
  int	i;

  i = 0;
  while (list->weapons_sprite[i])
    {
      list->weapons_sprite[i] = resize(list->weapons_sprite[i], WIDTH, HEIGHT);
      list->weaponson_sprite[i] = resize(list->weaponson_sprite[i], WIDTH, HEIGHT);
      i++;
    }
  return (0);
}

int	find_textures(t_list	*list)
{
  if ((list->textures = malloc((NB_TEXTURES + 1) * sizeof(t_bunny_pixelarray *))) == NULL)
    return (1);
  list->textures[0] = bunny_load_pixelarray("textures/9108.jpg");
  list->textures[1] = bunny_load_pixelarray("textures/ee481.bmp");
  list->textures[2] = bunny_load_pixelarray("textures/ee410.bmp");
  list->textures[3] = bunny_load_pixelarray("textures/ee564.bmp");
  list->textures[4] = bunny_load_pixelarray("textures/ee680.bmp");
  list->textures[5] = bunny_load_pixelarray("textures/ee3456.bmp");
  list->textures[6] = bunny_load_pixelarray("textures/eridu3434.bmp");
  list->textures[7] = bunny_load_pixelarray("textures/eridu653.bmp");
  list->textures[8] = bunny_load_pixelarray("textures/eridu4423.bmp");
  list->textures[9] = bunny_load_pixelarray("textures/eridu6678.bmp");
  list->textures[10] = NULL;
  resize_textures(list);
  return (0);
}

int	find_weapons(t_list	*list)
{
  if ((list->weapons_sprite = malloc((NB_WEAPONS + 1) * sizeof(t_bunny_pixelarray *))) == NULL ||
      (list->weaponson_sprite = malloc((NB_WEAPONS + 1) * sizeof(t_bunny_pixelarray *))) == NULL)
    return (1);
  list->weapons_sprite[0] = bunny_load_pixelarray("sprite/mitraillette.gif");
  list->weaponson_sprite[0] = bunny_load_pixelarray("sprite/mitraillette_fire.gif");
  list->weapons_sprite[1] = NULL;
  list->weaponson_sprite[1] = NULL;
  resize_weapons(list);
  return (0);
}

int	start_a_mob(t_mob *mob, float x, float y, int dmg, int cooldown)
{
  mob->pos.x = x;
  mob->pos.y = y;
  mob->dmg = dmg;
  mob->maxcd = cooldown;
  mob->alive = true;
  mob->cd = 0;
}

int	start_mobs(t_list	*list)
{
  int	i;

  if ((list->mobs = malloc((NB_MOBS + 1) * sizeof(t_mob *))) == NULL)
    return (1);
  i = -1;
  while (++i <= NB_MOBS)
    {
      if ((list->mobs[i] = malloc(sizeof(t_mob))) == NULL)
	return (1);
    }
  start_a_mob(list->mobs[0], 1.5, 1.5, 12, 10);
  list->mobs[1] = NULL;
  return (0);
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
  list->weapon.cooldown = 0;
  if (start_mobs(list) == 1)
    return (1);
  if (find_textures(list) == 1 || find_weapons(list) == 1)
    return (1);
  return (0);
}
