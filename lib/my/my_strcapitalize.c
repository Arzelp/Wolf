/*
** my_strcapitalize.c for my_strcapitalize in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Oct  5 22:34:35 2015 Paskal Arzel
** Last update Thu Oct  8 15:43:48 2015 Paskal Arzel
*/

char     *my_strcapitalize(char *str)
{
  int   a;

  a = 2;
  if (str[0] >= 97 && str[0] <= 122)
    str[0] = str[0] - 32;
  while (str[a] != '\0')
    {
      if (str[a] < 97 || str[a] > 122)
        {
          if (str[a + 1] >= 97 && str[a] <= 122)
	    str[a + 1] = str[a + 1] - 32;
          a++;
        }
      a++;
    }
  return (str);
}
