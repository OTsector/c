#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int option = -1;
	char *addr, *port;

	while ((option = getopt(argc, argv, "i:p:")) != -1)
	{
	switch (option)
	{
	case 'i':
		addr = strdup(optarg);
		break;
	case 'ins':
		addr = strdup(optarg);
		break;
	case 'p':
		port = strdup(optarg);
		break;
	default:
				/* unrecognised option ... add your error condition */
				break;
	}
	}
	printf("%s\n", port);
	/* rest of program */

	return 0;
}
