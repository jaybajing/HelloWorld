

int tcp_init(int port, int ip);

int tcp_connect(int port);

char server_response(int sockfd, unsigned char *buf, int bufsize) ;