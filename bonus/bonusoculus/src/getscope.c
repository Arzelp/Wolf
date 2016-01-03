/*
** getscope.c for getscope in /home/arzel_p/rendu/gfx_wolf3d/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Sun Dec 13 18:55:13 2015 Paskal Arzel
** Last update Thu Dec 31 12:24:51 2015 Paskal Arzel
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <lapin.h>
#include "my.h"

int	lenscope(char *str)
{
  int	fd;
  char	buf[1];
  int	i;

  i = 0;
  if ((fd = open(str, O_RDONLY)) == -1)
    return (-1);
  while (read(fd, buf, 1) > 0)
    if (buf[0] == '[')
	{
	  while (read(fd, buf, 1) > 0 && buf[0] != ']')
	    i++;
	}
  close(fd);
  return (i);
}

char	*getscope(char *str)
{
  int	fd;
  char	buf[1];
  char	*res;
  int	i;

  if (lenscope(str) < 0)
    return (NULL);
  res = bunny_malloc(lenscope(str) * sizeof(char));
  i = 0;
  if ((fd = open(str, O_RDONLY)) == -1)
    return (NULL);
  while (read(fd, buf, 1) > 0)
    if (buf[0] == '[')
	{
	  while (read(fd, buf, 1) > 0 && buf[0] != ']')
	    {
	      res[i] = buf[0];
	      i++;
	    }
	}
  close(fd);
  return (res);
}
