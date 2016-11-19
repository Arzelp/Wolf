/*
** sprint.c for sprint in /home/arzel_p/rendu/Infographie/gfx_wolf3d/bonus/bonusoculus/jpo/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Nov 18 17:58:17 2016 Paskal Arzel
** Last update Fri Nov 18 17:59:38 2016 Paskal Arzel
*/

#include "my.h"

void	sprint(t_list	*list)
{
  if (list->keys[BKS_LSHIFT])
    {
      list->sprint -= 2;
      list->sprinting = true;
    }
  else
    list->sprint += 1;
  return;
}
