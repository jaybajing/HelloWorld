/*
* @Author: jaybajing
* @Date:   2018-03-31 17:40:21
* @Create by: jaybajing
* @create time : 2018-03-31 17:40:21
* @Last Modified by:   jaybajing
* @Last Modified time: 2018-03-31 21:11:18
* @email : linlianjie105@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet.h>
#include <arpa/inet.h>
#include <sys/select.h>

static int sockfd = -1;
static struct sockaddr_in clientAddr;
static struct sockaddr_in serverAddr;

char udp_server_init(int port) {
	struct sockaddr_in addr;

    char ret = -1;
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    	perror("socket");
    	return ret;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) <0)		
    {
    	perror("bind");
    	return ret;
    }

    printf("init udp server finish\n");
}

char udp_client_int(int *clientSock, int *serverSock, int port, char *ip) {
    char ret =-1;
    
    if ((*clientSock = socket(AF_INET, SOCK_DGRAM, 0))< 0)
    {
    	perror("init client sock error");
    	return ret;
    }
  
    serverAddr->sin_family = AF_INET;
    serverAddr->sin_port = htons(port);
    serverAddr->sin_addr.s_addr = inet_addr(ip);

}

char client_cmd(int sockfd, unsigned char *buf, int bufsize) {
    char ret = -1;

	if(sockfd == -1) {
		printf("get socket failed");
		return ret;
	}

    char len = sizeof(clientAddr);
	ret = recvfrom(sockfd, buf, bufsize, 0, (struct sockaddr_in *) clientAddr, &len);
	if (ret == -1)
	{
		printf("recv client failed \n");
		bzero(clientAddr, sizeof(clientAddr));
		return ret;
	}

    return ret;

}

char server_response(int sockfd, unsigned char *buf, int bufsize) {
	char ret = -1;

	if(sockfd == -1) {
		printf("get socket failed\n");
	}

	char len = sizeof(clientAddr);

	ret = sendto(sockfd, buf, bufsize, 0, (struct sockaddr *) clientAddr, len) ;
	if (ret == -1)
	{
		printf("sendto client failed\n");
		return -1;
	}

	return -1;
}