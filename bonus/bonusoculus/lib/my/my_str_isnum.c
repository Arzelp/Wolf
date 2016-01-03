/*
** my_str_isnum.c for my_str_isnum in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 23:13:21 2015 Paskal Arzel
** Last update Mon Oct  5 23:14:53 2015 Paskal Arzel
*/

int	my_str_isnum(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if ((str[a] < 48 || str[a] > 57))
        return (0);
      a = a + 1;
    }
  return (1);
}
