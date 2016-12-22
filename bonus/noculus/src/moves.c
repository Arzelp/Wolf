/*
** moves.c for moves in /home/arzel_p/rendu/gfx_wolf3d/bonus/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Dec 18 01:06:49 2015 Paskal Arzel
** Last update Fri Nov 18 11:20:05 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"
#include "control.h"

int	goup(t_list *list, int posx, int posy, float radangle)
{
  list->posx += (MOVESPEED * list->coke) * cos(radangle);
  if (list->posx < 0 || list->posx >= list->height)
    list->posx -= (MOVESPEED * list->coke) * cos(radangle);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posx -= (MOVESPEED * list->coke) * cos(radangle);
  list->posy += (MOVESPEED * list->coke) * sin(radangle);
  posx = list->posx;
  posy = list->posy;
  if (list->posy < 0 || list->posy >= list->width)
    list->posy -= (MOVESPEED * list->coke) * sin(radangle);
  if ((list->map)[posx][posy] == 1)
    list->posy -= (MOVESPEED * list->coke) * sin(radangle);
  return (0);
}

int	godown(t_list *list, int posx, int posy, float radangle)
{
  list->posx -= (MOVESPEED * list->coke) * cos(radangle);
  if (list->posx < 0 || list->posx >= list->height)
    list->posx += (MOVESPEED * list->coke) * cos(radangle);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posx += (MOVESPEED * list->coke) * cos(radangle);
  list->posy -= (MOVESPEED * list->coke) * sin(radangle);
  if (list->posy < 0 || list->posy >= list->width)
    list->posy += (MOVESPEED * list->coke) * sin(radangle);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posy += (MOVESPEED * list->coke) * sin(radangle);
  return (0);
}

int	goright(t_list *list, int posx, int posy, float radangle)
{
  list->posx -= (MOVESPEED * list->coke) * cos(radangle + M_PI / 2);
  if (list->posx < 0 || list->posx >= list->height)
    list->posx += (MOVESPEED * list->coke) * cos(radangle + M_PI / 2);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posx += (MOVESPEED * list->coke) * cos(radangle + M_PI / 2);
  list->posy -= (MOVESPEED * list->coke) * sin(radangle + M_PI / 2);
  if (list->posy < 0 || list->posy >= list->width)
    list->posy += (MOVESPEED * list->coke) * sin(radangle + M_PI / 2);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posy += (MOVESPEED * list->coke) * sin(radangle + M_PI / 2);
  return (0);
}

int	goleft(t_list *list, int posx, int posy, float radangle)
{
  list->posx += (MOVESPEED * list->coke) * cos(radangle + M_PI / 2);
  if (list->posx < 0 || list->posx >= list->height)
    list->posx -= (MOVESPEED * list->coke) * cos(radangle + M_PI / 2);
  posx = list->posx;
  posy = list->posy;
  if ((list->map)[posx][posy] == 1)
    list->posx -= (MOVESPEED * list->coke) * cos(radangle + M_PI / 2);
  list->posy += (MOVESPEED * list->coke) * sin(radangle + M_PI / 2);
  posx = list->posx;
  posy = list->posy;
  if (list->posy < 0 || list->posy >= list->width)
    list->posy -= (MOVESPEED * list->coke) * sin(radangle + M_PI / 2);
  if ((list->map)[posx][posy] == 1)
    list->posy -= (MOVESPEED * list->coke) * sin(radangle + M_PI / 2);
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
  if ((list->map)[(int)list->posx][(int)list->posy] == 8)
    list->coke = 5;
  return (0);
}
