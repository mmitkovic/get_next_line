#include "includes/get_next_line.h"

/*
** This is a simple main function to test your get_next_line.
**
** How to compile and run:
** 1. Make sure this file, your get_next_line files, and the Makefile
** are in the same directory.
** 2. Create a file named 'test.txt' with some text in it.
** 3. Run 'make' in your terminal. This will create an executable
** called 'gnl_tester'.
** 4. Run the tester with './gnl_tester test.txt'.
**
** It will print each line from test.txt, one by one.
*/

int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	// Check if a filename was provided as an argument
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	// Open the file provided in the argument
	// It's opened in read-only mode (O_RDONLY)
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	printf("--- Reading from file: %s (fd: %d) ---\n", argv[1], fd);

	// Loop to read all lines from the file
	while ((line = get_next_line(fd)))
	{
		// Print the line that get_next_line returned
		printf("%s", line);
		// Free the memory allocated by get_next_line
		free(line);
	}

	printf("\n--- End of file ---\n");

	// Close the file descriptor
	close(fd);

	return (0);
}

