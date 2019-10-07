#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>

#include "servidor-udp.h"

#define MAX_SIZE 16000

int server_udp(int sockfd)
{
	// @@server_io_udp@start@@
	/*
	 * Assume that sockfd is an open socket
	 * which is bound to the server's address,
	 * and (kinda) listening to messages,
	 * so that it can receive messages from clients.
	 * As such, all we have to do is just recvfrom the requests.
	 */
	struct sockaddr_storage client_addr;
	socklen_t client_addrlen = sizeof(client_addr);
	size_t bufsize = MAX_SIZE * sizeof(uint32_t);
	uint32_t *buf = malloc(bufsize);
	if (buf == NULL) {
		perror("malloc");
		return -1;
	}
	ssize_t r = recvfrom(sockfd, buf, bufsize, 0, (struct sockaddr*)&client_addr, &client_addrlen);
	if (r == -1) {
		perror("recvfrom");
		free(buf);
		return -2;
	}

	char end_cliente[INET6_ADDRSTRLEN];
	int err=getnameinfo((struct sockaddr*)&client_addr,client_addrlen,end_cliente,sizeof(end_cliente),0,0,NI_NUMERICHOST);
	if (err!=0) {
	  printf("Falha ao converter endereço (código=%d)\n",err);
	} else
	  printf("Endereço do cliente: %s\n", end_cliente);
	
	size_t recv_bytes = r;
	int nint = recv_bytes/sizeof(uint32_t);
	uint32_t sum[4];
	for (int i = 0; i < nint; i++) {
		if (i == 0) {
			sum[0] = buf[i];
		} else {
			sum[i] = ntohl(ntohl(sum[i-1]) + ntohl(buf[i]));
		}
	}
	free(buf);
	//sum = htonl(sum);
	ssize_t s = sendto(sockfd, (void*)&sum, sizeof(sum), 0, (struct sockaddr*)&client_addr, client_addrlen);
	if (s != sizeof(uint32_t)) {
		perror("sendto");
		return -2;
	}
	return 0;
	// @@server_io_udp@end@@
}

int main()
{
  struct sockaddr_in servaddr, cliaddr;
  int sockfd;
      
  // Creating socket file descriptor 
  if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
    perror("socket creation failed"); 
    exit(EXIT_FAILURE); 
  } 
      
  memset(&servaddr, 0, sizeof(servaddr)); 
  memset(&cliaddr, 0, sizeof(cliaddr)); 
      
  // Filling server information 
  servaddr.sin_family    = AF_INET; // IPv4 
  servaddr.sin_addr.s_addr = INADDR_ANY; 
  servaddr.sin_port = htons(20000); 
  
  // Bind the socket with the server address 
  if ( bind(sockfd, (const struct sockaddr *)&servaddr,  
            sizeof(servaddr)) < 0 ) 
    { 
      perror("bind failed"); 
      exit(EXIT_FAILURE); 
    }
  while (1)
    server_udp(sockfd);
  
}
