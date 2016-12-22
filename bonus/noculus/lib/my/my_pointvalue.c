/*
** my_pointvalue.c for pointvalue in /home/arzel_p/lib/my
** 
** Made by Paskal Arzel
** Login   <arzel_p@epitech.net>
** 
** Started on  Mon Nov  9 18:47:34 2015 Paskal Arzel
** Last update Tue Nov 10 14:55:35 2015 Paskal Arzel
*/

void	my_pointvalue(void *ptr)
{
  my_putstr("0x");
  my_put_longnbr_base((long long)&ptr, 16);
}
