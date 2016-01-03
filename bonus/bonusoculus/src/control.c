/*
** control.c for control in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Tue Dec 15 22:34:28 2015 Paskal Arzel
** Last update Sun Jan  3 21:19:24 2016 Paskal Arzel
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <lapin.h>
#include "my.h"

int	checkcreate(t_list *list, t_bunny_keysym keysym,
		    t_bunny_event_state state, float radangle)
{
  if (list->posx >= list->height || list->posy >= list->width)
    return (1);
  if (list->posx <= 0 || list->posy <= 0)
    return (1);
  if (keysym == BKS_RCONTROL && state == GO_DOWN && list->posx > 0)
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

int	checkdestruct(t_list *list, t_bunny_keysym keysym,
		      t_bunny_event_state state, float radangle)
{
  if (list->posx >= list->height || list->posy >= list->width)
    return (1);
  if (list->posx <= 0 || list->posy <= 0)
    return (1);
  if (keysym == BKS_SPACE && state == GO_DOWN && list->posx > 0)
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

int	updown(t_list *list, t_bunny_keysym keysym, t_bunny_event_state state,
	       float radangle)
{
  int	posx;
  int	posy;

  posx = 0;
  posy = 0;
  if (keysym == BKS_UP && state == GO_DOWN)
    goup(list, posx, posy, radangle);
  else if (keysym == BKS_DOWN && state == GO_DOWN)
    godown(list, posx, posy, radangle);
  else if (keysym == BKS_RIGHT && state == GO_DOWN)
    goright(list, posx, posy, radangle);
  else if (keysym == BKS_LEFT && state == GO_DOWN)
    goleft(list, posx, posy, radangle);
  checktp(list);
  checkdestruct(list, keysym, state, radangle);
  checkcreate(list, keysym, state, radangle);
  checkview(list);
  return (0);
}

t_bunny_response	mainresp(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 void *_data)
{
  float	radangle;
  t_list	*list;

  list = _data;
  radangle = list->angle * M_PI / 180;
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  if (keysym == BKS_E && state == GO_DOWN)
    list->angle -= 2.4;
  else if (keysym == BKS_A && state == GO_DOWN)
    list->angle += 2.4;
  else
    updown(list, keysym, state, radangle);
  return (GO_ON);
}
