#include "../includes/get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*find_newline(const char *s)
{
	// Handle the case where the input string is NULL
	if (!s)
		return (NULL);
	// Loop until we reach end of the string
	while (*s)
	{
		// If the character is a new line ...
		if (*s == '\n')
			return ((char *)s); // ... return a pointer to this spot
		s++;
	}
	return (NULL); // No new line if found
}

char	*join_strings(char *stash, char *buffer)
{
	char	*join_str;
	int	i;
	int	j;

	if (!stash)
	{
		// We're treating stash as an empty string for the logic below.
		stash = malloc(1);
		stash[0] = '\0';
	}
	join_str = malloc(ft_strlen(stash) + ft_strlen(buffer) + 1);
	if (!join_str)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		join_str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		join_str[i + j] = buffer[j];
		j++;
	}
	join_str[i + j] = '\0';
	free(stash); // Freeing the old stash
	return (join_str);
}

char	*clean_stash(char *stash)
{
	//find the \n
	char	*newline_pos;
	char	*leftovers;
	int	i;

	newline_pos = find_newline(stash);
	if (!newline_pos)
	{
		free(stash);
		return (NULL);
	}
	leftovers = malloc(ft_strlen(newline_pos + 1) + 1);
	if (!leftovers)
		return (NULL);
	i = 0;
	// Copying the characters from after '\n' to the end
	while (*(newline_pos + 1 + i))
	{
		leftovers[i] = *(newline_pos + 1 + i);
		i++;
	}
	leftovers[i] = '\0';
	free(stash);
	return (leftovers);
}

char	*extract_line(char *stash)
{
	char	*newline_pos;
	char	*new_line;
	int	line_length;
	int	i;
	
	if (!stash || !*stash)
		return (NULL);

	newline_pos = find_newline(stash);
	if (newline_pos == NULL)
	{
		line_length = ft_strlen(stash);
	}
	else
	{

		// line1\nline2 --- newline_pos - stash = line1
		line_length = (newline_pos - stash) + 1;
	}
	new_line = malloc(sizeof(char) * (line_length + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < line_length)
	{
		new_line[i] = stash[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}
