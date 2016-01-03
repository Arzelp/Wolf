/*
** my_showstr.c for my_showstr in /home/arzel_p/rendu/Piscine_C_J08/lib/my
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Thu Oct  8 15:44:10 2015 Paskal Arzel
** Last update Fri Oct 16 11:47:53 2015 Paskal Arzel
*/

int	my_showstr(char *str)
{
  char	base[] = "0123456789abcdef";
  int	i;
  int	a;

  i = 0;
  while (str[i])
    {
      if (str[i] == 92)
	{
	  i++;
	  a = str[i];
	  my_put_nbr_base(a, base);
	}
      else
	my_putchar(str[i]);
      i++;
    }
}
