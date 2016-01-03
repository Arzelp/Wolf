/*
** moves.c for moves in /home/arzel_p/rendu/gfx_wolf3d/bonus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Dec 18 01:06:49 2015 Paskal Arzel
** Last update Mon Dec 28 16:32:05 2015 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

int	goup(t_list *list, int posx, int posy, float radangle)
{
  list->posx += 0.12 * cos(radangle);
  if (list->posx < 0 || list->posx >= list->height)
    list->posx -= 0.12 * cos(radangle);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posx -= 0.12 * cos(radangle);
  list->posy += 0.12 * sin(radangle);
  posx = list->posx;
  posy = list->posy;
  if (list->posy < 0 || list->posy >= list->width)
    list->posy -= 0.12 * sin(radangle);
  if ((list->map)[posx][posy] == 1)
    list->posy -= 0.12 * sin(radangle);
  return (0);
}

int	godown(t_list *list, int posx, int posy, float radangle)
{
  list->posx -= 0.12 * cos(radangle);
  if (list->posx < 0 || list->posx >= list->height)
    list->posx += 0.12 * cos(radangle);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posx += 0.12 * cos(radangle);
  list->posy -= 0.12 * sin(radangle);
  if (list->posy < 0 || list->posy >= list->width)
    list->posy += 0.12 * sin(radangle);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posy += 0.12 * sin(radangle);
  return (0);
}

int	goright(t_list *list, int posx, int posy, float radangle)
{
  list->posx -= 0.12 * cos(radangle + M_PI / 2);
  if (list->posx < 0 || list->posx >= list->height)
    list->posx += 0.12 * cos(radangle + M_PI / 2);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posx += 0.12 * cos(radangle + M_PI / 2);
  list->posy -= 0.12 * sin(radangle + M_PI / 2);
  if (list->posy < 0 || list->posy >= list->width)
    list->posy += 0.12 * sin(radangle + M_PI / 2);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posy += 0.12 * sin(radangle + M_PI / 2);
  return (0);
}

int	goleft(t_list *list, int posx, int posy, float radangle)
{
  list->posx += 0.12 * cos(radangle + M_PI / 2);
  if (list->posx < 0 || list->posx >= list->height)
    list->posx -= 0.12 * cos(radangle + M_PI / 2);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posx -= 0.12 * cos(radangle + M_PI / 2);
  list->posy += 0.12 * sin(radangle + M_PI / 2);
  posx = list->posx;
  posy = list->posy;
  if (list->posy < 0 || list->posy >= list->width)
    list->posy -= 0.12 * sin(radangle + M_PI / 2);
  if ((list->map)[posx][posy] == 1)
    list->posy -= 0.12 * sin(radangle + M_PI / 2);
  return (0);
}

int	checkview(t_list *list)
{
  if ((list->map)[(int)list->posx][(int)list->posy] == 5)
    list->view = 1.5;
  else if ((list->map)[(int)list->posx][(int)list->posy] == 6)
    list->view = 0;
  else if ((list->map)[(int)list->posx][(int)list->posy] == 7)
    list->light = 255;
  return (0);
}
