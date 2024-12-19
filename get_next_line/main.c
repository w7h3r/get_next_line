#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	printf("%s", (get_next_line(open("text", O_RDWR, 667))));
}
