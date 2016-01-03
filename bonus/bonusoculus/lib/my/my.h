/*
** my.h for my.h in /home/arzel_p/rendu/PSU_2015_my_select/src/
**
** Made by Paskal Arzel
** Login   <arzel_p@epitech.eu>
**
** Started on  Tue Dec  1 15:04:31 2015 Paskal Arzel
** Last update Mon Dec 14 17:09:44 2015 Paskal Arzel
*/

typedef struct s_list
{
  int	posx;
  int	posy;
  int	select;
  char	*name;
  struct s_list *next;
  struct s_list *previous;
}t_list;

t_list	*in(char *str);
t_list	*addend(t_list **cursor, char *str, int posx, int posy);
t_list	*deletele(t_list **cursor, t_list **first, int lenght);
int	testlenght(int ac, char **av);
t_list	*delfirst(t_list **first, t_list **cursor, int lenght);
int	my_getnbr(char *str);
