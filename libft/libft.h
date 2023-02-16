/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:07:09 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/02/13 20:37:31 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_isalpha 	- Test for an alphabetic character;
ft_isdigit 	- Test for a decimal digit character;
ft_isalnum 	- Test for an alphanumeric character;
ft_isascii 	- Test for an ASCII character;
ft_isprint 	- Test for any printing character, including space;
ft_strlen 	- Calculate the length of a string;
ft_memset 	- Fills the first *n* bytes of the memory area pointed to by *s*
ft_bzero	- Write zeroes to a byte string;
ft_memcpy 	- Copy memory area up to *n* bytes, does not handle overlaps;
ft_memmove 	- Copy memory area up to *n* bytes, handles overlaps;
ft_strlcpy 	- Copy string up to *n* bytes;
ft_strlcat 	- Concatenate string up to *n* bytes;
ft_toupper 	- Convert lowercase letter to uppercase;
ft_tolower 	- Convert uppercase letter to lowercase;
ft_strchr 	- Locate character in a string;
ft_strrchr 	- Locate last occurrence of character in a string;
ft_strncmp 	- Compare strings up to *n* bytes;
ft_memchr 	- Locate a byte in a byte string;
ft_memcmp	- Compare bytes in memory;
ft_strnstr	- Locate a substring in a string up to *n* bytes;
ft_atoi 	- Convert ASCII string to integer;
ft_calloc	- Allocate memory for an array;
ft_strdup	- Duplicate a string;
ft_substr	- Allocate and return a substring from the string *s*, starting
	at index *start* and of maximum size *len*;
ft_strjoin 	- Concatenate *s1* and *s2*;
ft_strtrim 	- Trim characters in the string *set* from the beginning and the end 
	of the string *s1*;
ft_split 	- Split *s* using the character *c* as a delimiter;
ft_itoa 	- Convert an integer to a string;
ft_strmapi 	- Apply the function *f* to each character of the string *s* to 
create a new string (with malloc) resulting from successive applications of *f*;
ft_striteri - Apply the function *f* to each character of the string *s* 
	to modify *s* resulting from successive applications of *f*;
ft_putchar_fd	- Output the character *c* to the given file descriptor;
ft_putstr_fd	- Output the string *s* to the given file descriptor;
ft_putendl_fd	- Output the string *s* to the given file descriptor, 
	followed by a newline;
ft_putnbr_fd	- Output the integer *n* to the given file descriptor;
ft_lstnew		- Allocates a new node, next value is *NULL*;
ft_lstadd_front	- Add the node *new* at the beginning of the list;
ft_lstsize		- Counts the number of nodes in a list;
ft_lstlast		- Returns the last node of the list;
ft_lstadd_back	- Add the node *new* at the end of the list;
ft_lstdelone	- Free the memory of the node *lst*;
ft_lstclear		- Free the memory of the list *lst*;
ft_lstiter		- Iterates the list *lst* and applies the function *f* to the 
	content of each node;
ft_lstmap		- Iterates the list *lst* and applies the function *f* to the
	content of each node. Creates a new list resulting of the successive 
	applications of the function *f*.
get_next_line	- Read a line from a file descriptor;
*/	

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef MAX_FILES
#  define MAX_FILES 512
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;		

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd);
int		ft_printf(const char *str, ...);
int		ft_integer(long nb);
int		ft_char(char x);
int		ft_hex(unsigned long nb, char c);
int		ft_string(char *str);
int		ft_unsigned(unsigned int nb);
int		ft_address(unsigned long address);
size_t	ft_strlenwithoutn(const char *s);

#endif
