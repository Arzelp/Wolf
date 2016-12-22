/*
** my_putstr.c for my_putstr in /home/arzel_p/rendu/Piscine_C_J04
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Thu Oct  1 17:22:50 2015 Paskal Arzel
** Last update Thu Oct  8 20:34:04 2015 Paskal Arzel
*/

int my_putstr(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}
