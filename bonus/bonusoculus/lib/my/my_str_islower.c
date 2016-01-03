/*
** my_str_islower.c for my_str_islow in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 23:17:38 2015 Paskal Arzel
** Last update Fri Oct 16 10:13:01 2015 Paskal Arzel
*/

int	my_str_islower(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] < 97 || str[a] > 122)
        return (0);
      a = a + 1;
    }
  return (1);
}
