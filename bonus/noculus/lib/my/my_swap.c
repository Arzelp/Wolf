/*
** my_swap.c for my_swap in /home/arzel_p/rendu/Piscine_C_J04
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Thu Oct  1 12:12:35 2015 Paskal Arzel
** Last update Fri Oct  2 20:48:03 2015 Paskal Arzel
*/

int	my_swap(int *a, int *b)
{
  int c;

  c = *a;
  *a = *b;
  *b = c;
}
