/*
** sprint.c for sprint in /home/arzel_p/rendu/Infographie/gfx_wolf3d/bonus/bonusoculus/jpo/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Fri Nov 18 17:58:17 2016 Paskal Arzel
** Last update Sat Nov 19 14:26:01 2016 Paskal Arzel
*/

#include "my.h"

/*
  Touches utilisées : list->keys[BKS_{nom de la touche}],
  list->sprint : Energie disponible ( / 100)
  list->sprinting : true/false (le joueur court-il ?)
*/

void	sprint(t_list	*list)
{
  if (list->keys[BKS_LSHIFT] && list->sprint > 0)
    {
      list->sprinting = true;
      list->sprint -= 2;
    }
  else
    list->sprint += (list->sprint >= 100) ? 0 : 1;
}
