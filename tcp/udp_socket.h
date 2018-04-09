

char udp_server_init(int port);
char server_response(int sockfd, unsigned char *buf, int bufsize);

char udp_client_int(int *clientSock, int *serverSock, int port, char *ip) 
char client_cmd(int sockfd, unsigned char *buf, int bufsize);

