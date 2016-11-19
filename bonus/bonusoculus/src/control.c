/*
** control.c for control in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Tue Dec 15 22:34:28 2015 Paskal Arzel
** Last update Fri Nov 18 18:01:32 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

int	checkcreate(t_list *list, float radangle)
{
  if (list->posx >= list->height || list->posy >= list->width)
    return (1);
  if (list->posx <= 0 || list->posy <= 0)
    return (1);
  if (list->keys[BKS_RCONTROL] && list->posx > 0)
    {
      if (sin(radangle) > cos(radangle) && sin(radangle) > -cos(radangle))
	(list->map)[(int)(list->posx)][(int)(list->posy + 1)] = 1;
      else if (sin(radangle) < cos(radangle) && sin(radangle) < -cos(radangle))
	(list->map)[(int)(list->posx)][(int)(list->posy - 1)] = 1;
      else if (cos(radangle) > sin(radangle) && cos(radangle) > -sin(radangle))
	(list->map)[(int)(list->posx + 1)][(int)(list->posy)] = 1;
      else if (cos(radangle) < sin(radangle) && cos(radangle) < -sin(radangle))
	(list->map)[(int)(list->posx - 1)][(int)(list->posy)] = 1;
    }
  return (0);
}

int	checkdestruct(t_list *list, float radangle)
{
  if (list->posx >= list->height || list->posy >= list->width)
    return (1);
  if (list->posx <= 0 || list->posy <= 0)
    return (1);
  if (list->keys[BKS_SPACE] && list->posx > 0)
    {
      if (sin(radangle) > cos(radangle) && sin(radangle) > -cos(radangle))
	(list->map)[(int)(list->posx)][(int)(list->posy + 1)] = 0;
      else if (sin(radangle) < cos(radangle) && sin(radangle) < -cos(radangle))
	(list->map)[(int)(list->posx)][(int)(list->posy - 1)] = 0;
      else if (cos(radangle) > sin(radangle) && cos(radangle) > -sin(radangle))
	(list->map)[(int)(list->posx + 1)][(int)(list->posy)] = 0;
      else if (cos(radangle) < sin(radangle) && cos(radangle) < -sin(radangle))
	(list->map)[(int)(list->posx - 1)][(int)(list->posy)] = 0;
    }
  return (0);
}

int	checktp(t_list *list)
{
  if ((list->map)[(int)list->posx][(int)list->posy] == 3)
    {
      list->posx = 2.3;
      list->posy = 2.3;
    }
  if ((list->map)[(int)list->posx][(int)list->posy] == 2)
    {
      list->posx = 11.2;
      list->posy = 25.2;
    }
  if ((list->map)[(int)list->posx][(int)list->posy] == 4)
    {
      list->posx = 3.2;
      list->posy = 11.2;
    }
  return (0);
}

int	updown(t_list *list, float radangle)
{
  int	posx;
  int	posy;

  posx = 0;
  posy = 0;
  if (list->keys[BKS_UP])
    goup(list, posx, posy, radangle);
  if (list->keys[BKS_DOWN])
    godown(list, posx, posy, radangle);
  if (list->keys[BKS_RIGHT])
    goright(list, posx, posy, radangle);
  if (list->keys[BKS_LEFT])
    goleft(list, posx, posy, radangle);
  checktp(list);
  checkdestruct(list, radangle);
  checkcreate(list, radangle);
  checkview(list);
  return (0);
}

void	controls(t_list	*list)
{
  float	radangle;

  radangle = list->angle * M_PI / 180;
  if (rand() % 2 == 0)
    list->angle += (float)(((rand() % 10000) * (list->coke - 1)) / 10000.0);
  if (rand() % 2 == 1)
    list->angle -= (float)(((rand() % 10000) * (list->coke - 1)) / 10000.0);
  sprint(list);
  list->coke *= (list->sprinting == true) ? 2.0 : 1.0;
  if (list->keys[BKS_ESCAPE])
    return;
  if (list->keys[BKS_E])
    list->angle -= 2.4;
  if (list->keys[BKS_A])
    list->angle += 2.4;
  if (list->keys[BKS_N] && list->cdnight <= 0)
    {
      list->night = (list->night == true) ? false : true;
      list->cdnight = 5;
    }
  list->cdnight = (list->cdnight <= 0) ? list->cdnight : list->cdnight - 1;
  updown(list, radangle);
  list->coke /= (list->sprinting == true) ? 2.0 : 1.0;
  return;
}
