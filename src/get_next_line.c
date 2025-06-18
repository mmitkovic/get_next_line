#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static	char	*stash;
	char		*line;
	char		*buffer;
	int		bytes_read;

	// 1. Input validation: check for bad fd or invalid BUFFER_SIZE
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// 2. Allocating temporary buffer for reading
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);

	bytes_read = 1;
	// 3. Loop: Read from the file until a '\n' is in our stash,
	// or until we reach the end of the file.
	while (find_newline(stash) == NULL && bytes_read > 0) 
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0) // Error handling
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = join_strings(stash, buffer);
	}
	free(buffer); // The temporary buffer's job is done
	

	// 4. At this point stash contains a line (and maybe more), or it's EOF.
	// Now, we extract the line and clean the stash for the next call.
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}

