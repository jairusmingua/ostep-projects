#include <stdio.h>
#include "request.h"
#include "io_helper.h"
#include <getopt.h>

char default_root[] = ".";
#define DEFAULT_THREADS 3;

//
// ./wserver [-d <basedir>] [-p <portnum>] 
// 
int main(int argc, char *argv[]) {
    int c;
	char *root_dir = default_root;
	int port = 3000;
	int thrd = 1;

	while ((c = getopt(argc, argv, ":d:p:t:")) != -1)
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
		case ':':
			printf("-%c requires an operand.\n", optopt);
			return 1;
		case '?':
			printf("Unknown argument: -%c\n", optopt);
			return 1;
		}

	printf("Running web server with parameters: wwwdirectory: %s\nport: %d\nno. of threads: %d\nVisit http://localhost:%d/hello.html\n", root_dir, port, thrd,port);
	

    // run out of this directory
    // chdir_or_die(root_dir);

    // // now, get to work
    int listen_fd = open_listen_fd_or_die(port);
    while (1) {
		struct sockaddr_in client_addr;
		int client_len = sizeof(client_addr);
		int conn_fd = accept_or_die(listen_fd, (sockaddr_t *) &client_addr, (socklen_t *) &client_len);
		request_handle_thread(conn_fd);
		close_or_die(conn_fd);		
    }
    return 0;
}


    


 
