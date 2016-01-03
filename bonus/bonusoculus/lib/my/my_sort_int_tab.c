/*
** my_sort_int_tab.c for my_sor_int_tab in /home/arzel_p/rendu/Piscine_C_J08/lib/my
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Thu Oct  8 15:40:56 2015 Paskal Arzel
** Last update Thu Oct 15 18:33:24 2015 Paskal Arzel
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	j;
  int	c;

  i = size - 1;
  while (i >= 1)
    {
      j = 0;
      while (j < i)
	{
	  if (tab[j] > tab[j + 1])
	    {
	      c = tab[j + 1];
	      tab[j + 1] = tab [j];
	      tab[j] = c;
	    }
	  j++;
	}
      i--;
    }
}
