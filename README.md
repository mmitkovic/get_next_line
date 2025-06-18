`get_next_line` - Read Line by Line

This project involves writing a function, `get_next_line`, which reads a line from a file descriptor, ending with a newline character (`\n`) or End Of File (EOF). This is a fundamental utility that handles reading from various sources efficiently, managing internal buffers to optimize read operations, and maintaining state across multiple calls. It's a core project in the 42 Core Curriculum, designed to deepen understanding of static variables, file I/O, and dynamic memory allocation in C.

## Technologies Used
* __C Language__: The entire project is implemented in C.
* `Makefile`: Used for compiling the source code and creating the necessary object files and executable.

## How to Build
To compile `get_next_line` and its related files, navigate to the project root directory in your terminal and use the provided `Makefile`:

* __Compile `get_next_line` (creates `get_next_line.o`)__
```
make
```
This will compile `get_next_line.c` into an object file:

* __Clean object files:__
```
make clean
```
Removes all `.o` (object) files.

* __Full clean (remove object files and executables):__
```
make fclean
```
Removes all `.o` files and any executables compiled with this `Makefile`.

* __Recompile from scratch__
```
make re
```
Performs a `fclean` then make, recompiling everything.

## How to Use
The `get_next_line` function reads from a specified file descriptor `fd` until a newline character (`\n`) is encountered or the end of the file is reached. It returns the read line as a dynamically allocated string.

__Function Sugnature__
```
char *get_next_line(int fd);
```
* `fd`: The file descriptor to read from (e.g., `0` for standard input, or a file opened with `open()`).

* __Returns:__
    
    * A `char *` containing the line read, including the newline character if present.
    * `NULL` if an error occurs or if the End Of File (EOF) is reached and no bytes were read.

__Examle Usage:__
Here's a simple main.c file demonstrating how to use get_next_line to read lines from a text file:
```
// main.c
#include "get_next_line.h" // Include your GNL header
#include <fcntl.h>        // For open()
#include <stdio.h>        // For printf()

int main(void)
{
    int     fd;
    char    *line;
    int     count = 1;

    // Open a test file (create 'test.txt' with some lines for testing)
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    printf("Reading from file descriptor %d:\n", fd);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", count, line); // Line already includes '\n'
        free(line); // IMPORTANT: Free the allocated memory after use
        count++;
    }

    // After loop, line will be NULL (EOF or error occurred)
    if (line == NULL && count == 1) // If no lines were read at all
        printf("No lines read or an error occurred.\n");
    else if (line == NULL) // If lines were read, but now it's EOF
        printf("End of file reached.\n");

    close(fd); // Close the file descriptor
    return (0);
}
```

## Implementation Details & Features
The `get_next_line` function is designed with the following key aspects:

* __Static Buffer__: Utilizes a static variable to store any leftover characters from the previous read operation. This allows for efficient reading across function calls without losing data between line boundaries.
* __Buffering__: Reads data in chunks defined by BUFFER_SIZE to minimize system calls (read()), thus improving performance.

## Learning Outcomes
Completing the `get_next_line` project significantly enhanced my understanding of:

* __File Descriptors__: Working directly with low-level file I/O operations (read, open, close).
* __Static Variables__: The concept and practical application of static variables in C, especially for preserving state across function calls.
* Dynamic Memory Management: Proficiently using `malloc`, `free`, and understanding memory leaks.
* __String Manipulation__: Implementing custom string functions (often built upon libft functions) for searching, joining, and duplicating strings.
* __Buffering Strategies__: Optimizing read operations by handling data in chunks.
* 




