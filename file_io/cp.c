#include "main.h"

#define BUFFER_SIZE 1024	

/**
* error_handling - handles errors and exits
* @message: error message to write to stdrr
*/

void error_handling(char *message)
{
while (*message)
	write(STDERR_FILENO, message++, 1);
	exit(1);
}

/**
* main - copies content of one file to another
* @argc: argument count
* @argv: argument vector
* Return: 0 on success, other on failure
*/

int main(int argc, char *argv[])
{
int fd_from, fd_to;
ssize_T bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

// check arguments
if (argc != 3)
	error_handling("Usage: cp file_from file_to\n");

// open source file for reading
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
	error_handling("Error: can't read from file\n");

// open/create destination file for writing
fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
	error_handling("Error: can't write to file\n");
	
// read and write loop

while ((bytes_read == read(fd_from, buffer, BUFFER_SIZE) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written != bytes_read)
	error_handling("Error: write failed\n");

// close files

if (close(fd_from) == -1 || close(fd_to) == -1)
	error_handling("Error: can't close fd\n");

return (0);

}




}

