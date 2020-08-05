#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>
#include <string.h>

#include "request.h"

#include "io_helper.h"

char default_root[] = ".";

// ./wserver [-d basedir] [-p port] [-t threads] [-b buffers] [-s schedalg]

int main(int argc, char *argv[])

{

	int c;
	char *root_dir = default_root;
	int port = 10000;
	int thrd = 1;
	int buf = 1;
	char *schalg = "FIFO";
	while ((c = getopt(argc, argv, ":d:p:t:b:s:")) != -1)
		switch (c)
		{
		case 'd':
			root_dir = optarg;
			break;
		case 'p':
			if (atoi(optarg) != 0) // if integer
			{
				port = atoi(optarg);
				break;
			}
			else
				printf("Must enter integer value for -p\n");
			return 1;
		case 't':
			if (atoi(optarg) != 0)
			{
				thrd = atoi(optarg);
				break;
			}
			else
				printf("Must enter integer value for -t\n");
			return 1;
		case 'b':
			if (atoi(optarg) != 0)
			{
				buf = atoi(optarg);
				break;
			}
			else
				printf("Must enter integer value for -b\n");
			return 1;
		case 's':
			if (strcasecmp("SFF", optarg) == 0 || strcasecmp("FIFO", optarg) == 0)
			{
				schalg = optarg;
				break;
			}
			else
				printf("Invalid -s operand. Enter FIFO or SFF.\n");
			return 1;
		case ':':
			printf("-%c requires an operand.\n", optopt);
			return 1;
		case '?':
			printf("Unknown argument: -%c\n", optopt);
			return 1;
		}

	printf("d: %s\np: %d\nt: %d\nb: %d\ns: %s\n", root_dir, port, thrd, buf, schalg);
	
	return 0;
}
