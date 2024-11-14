#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_handler - handles errors and exits
 * @message: error message to write to stderr
 */
void error_handler(char *message)
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
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	/* Check arguments */
	if (argc != 3)
		error_handler("Usage: cp file_from file_to\n");

	/* Open source file for reading */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_handler("Error: Can't read from file\n");

	/* Open/create destination file for writing */
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		error_handler("Error: Can't write to file\n");

	/* Read and write loop */
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
			error_handler("Error: Write failed\n");
	}

	/* Check for read error */
	if (bytes_read == -1)
		error_handler("Error: Read failed\n");

	/* Close files */
	if (close(fd_from) == -1 || close(fd_to) == -1)
		error_handler("Error: Can't close fd\n");

	return (0);
}
