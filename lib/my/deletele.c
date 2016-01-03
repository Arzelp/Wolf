/*
** deletele.c for deletele in /home/arzel_p/rendu/PSU_2015_my_select/lib/my/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Tue Dec  1 16:14:52 2015 Paskal Arzel
** Last update Fri Dec 11 22:58:27 2015 Paskal Arzel
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

t_list	*delfirst(t_list **first, t_list **cursor, int lenght)
{
  t_list	*list;

  if ((*first)->next == NULL || (*first)->next == *first)
    {
      clear();
      refresh();
      endwin();
      exit(EXIT_FAILURE);
    }
  list = (*first)->next->next;
  *first = (*first)->next;
  (*cursor)->previous->next = (*cursor)->next;
  (*cursor)->next->previous = (*cursor)->previous;
  *cursor = (*cursor)->previous;
  (*first)->posx = (*first)->posx - 1;
  while (list != *first)
    {
      list->posx = list->posx - 1;
      if (list->posx < 0)
	{
	  list->posx = LINES - 1;
	  list->posy = list->posy - lenght - 1;
	}
      list = list->next;
    }
}

t_list	*deletele(t_list **cursor, t_list **first, int lenght)
{
  t_list	*list;

  if (*cursor == *first && (*cursor)->next != NULL)
    delfirst(first, cursor, lenght);
  else
    {
      (*cursor)->previous->next = (*cursor)->next;
      (*cursor)->next->previous = (*cursor)->previous;
      *cursor = (*cursor)->previous;
      list = (*cursor)->next;
      while (list != *first)
	{
	  list->posx = list->posx - 1;
	  if (list->posx < 0)
	    {
	      list->posx = LINES - 1;
	      list->posy = list->posy - lenght - 1;
	    }
	  list = list->next;
	}
      *cursor = ((*cursor)->next == *first) ? *cursor : (*cursor)->next;
      return (*cursor);
    }
}
