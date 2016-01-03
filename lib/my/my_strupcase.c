/*
** my_strupcase.c for my_strupcase in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 20:55:06 2015 Paskal Arzel
** Last update Thu Oct  8 15:02:00 2015 Paskal Arzel
*/

char	*my_strupcase(char *str)
{
  int	a;

  if (str[0] > 97 && str[0] < 121)
    str[0] = str[0] - 32;
  while (str[a] != '\0')
    {
      if (str[a] < 97 || str[a] > 122)
        {
	  if (str[a + 1] >= 97 && str[a] <= 122)
	    str[a + 1] = str[a + 1] - 32;
	}
      a++;
    }
  return (str);
}
