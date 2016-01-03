/*
** my_putstrhid.c for my_putstrhid in /home/arzel_p/lib/my
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Fri Nov  6 20:53:29 2015 Paskal Arzel
** Last update Mon Nov  9 18:39:28 2015 Paskal Arzel
*/

void	my_putstrhid(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putchar(92);
	  if (str[i] < 9)
	    my_putstr("00");
	  else if (str[i] < 65)
	    my_putchar('0');
	  my_put_nbr_base(str[i], 8);
	}
      else
	my_putchar(str[i]);
      i++;
    }
}
