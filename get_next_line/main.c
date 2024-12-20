#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd = open("text", O_RDWR, 667);
	printf("%s", (get_next_line(fd)));
}
