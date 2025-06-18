#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int	ft_strlen(char *s);
char	*find_newline(const char *s);
char	*join_strings(char *stash, char *buffer);
char	*clean_stash(char *stash);
char	*extract_line(char *stash);

# endif
