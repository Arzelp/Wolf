/*
** my_str_isupper.c for my_str_isupper in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 23:22:34 2015 Paskal Arzel
** Last update Mon Oct  5 23:23:54 2015 Paskal Arzel
*/

int	my_str_isupper(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] < 65 || str[a] > 90)
        return (0);
      a = a + 1;
    }
  return (1);
}
