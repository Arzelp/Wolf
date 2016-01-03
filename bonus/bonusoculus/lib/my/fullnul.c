/*
** fullnul.c for fullnul in /home/arzel_p/rendu/Piscine_C_bistromathique/lib/my
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Tue Oct 27 17:15:49 2015 Paskal Arzel
** Last update Fri Oct 30 17:59:14 2015 Paskal Arzel
*/

#include <stdlib.h>

char	*fullnul(char *str, int lenstr)
{
  int	i;

  i = 0;
  while (i < lenstr)
    {
      str[i] = '0';
      i++;
    }
  str[i] = '\0';
  return (str);
}
