/*
** my_strlen.c for my_strlen in /home/arzel_p/sandbox
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Thu Oct  1 20:04:03 2015 Paskal Arzel
** Last update Tue Nov 10 15:00:02 2015 Paskal Arzel
*/

int my_strlen(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    a = a + 1;
  return (a);
}
