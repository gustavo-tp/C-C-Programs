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

int server_udp(int sockfd) // sockfd é o descritor de arquivo do socket
{
	// @@server_io_udp@start@@
	/*
	 * Assume that sockfd is an open socket
	 * which is bound to the server's address,
	 * and (kinda) listening to messages,
	 * so that it can receive messages from clients.
	 * As such, all we have to do is just recvfrom the requests.
	 */
	struct sockaddr_storage client_addr; // cria estrutura de dados para armazenar o endereço do cliente
	socklen_t client_addrlen = sizeof(client_addr); // armazema comprimento do endereço do cliente
	size_t bufsize = MAX_SIZE * sizeof(uint32_t); // define o tamanho do buffer
	uint32_t *buf = malloc(bufsize); // define um ponteiro com alocando memória para o tamanho do buffer
	if (buf == NULL) { // se o ponteiro é nulo exibe um erro de alocação de memória
		perror("malloc");
		return -1;
	}
	ssize_t r = recvfrom(sockfd, buf, bufsize, 0, (struct sockaddr*)&client_addr, &client_addrlen); // recebe a requisição do cliente
	if (r == -1) { // caso a requisição der erro imprime o erro e libera a memória do buffer
		perror("recvfrom");
		free(buf);
		return -2;
	}

	char end_cliente[INET6_ADDRSTRLEN]; // declara uma string para armazenar o endereço do cliente
	int err=getnameinfo((struct sockaddr*)&client_addr,client_addrlen,end_cliente,sizeof(end_cliente),0,0,NI_NUMERICHOST); // pega o loopback pelo nome do cliente (localhost)
	if (err!=0) { // se não deu certo a conversão exibe um erro, do contrário imprime o ip
	  printf("Falha ao converter endereço (código=%d)\n",err);
	} else
	  printf("Endereço do cliente: %s\n", end_cliente);
	
	size_t recv_bytes = r; // armazena os bytes da requisição do cliente
	int nint = recv_bytes/sizeof(uint32_t); // define a quantidade de númerais recebidos
	uint32_t sum = 0;
	for (int i = 0; i < nint; i++) { // percorre todos os numerais e soma estes
		sum += ntohl(buf[i]);
	}
	free(buf); // libera o buffer
	sum = htonl(sum); // converte a soma em bytes para serem enviados ao cliente
	ssize_t s = sendto(sockfd, (void*)&sum, sizeof(uint32_t), 0, (struct sockaddr*)&client_addr, client_addrlen); // envia a soma de volta ao cliente
	if (s != sizeof(uint32_t)) { // caso ocorra, imprime um erro na tela
		perror("sendto");
		return -2;
	}
	return 0;
	// @@server_io_udp@end@@
}

int main()
{
  struct sockaddr_in servaddr, cliaddr; // define as duas entruturas de endereço para cliente e servidor
  int sockfd;
      
  // Creating socket file deor 
  if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {  // define o socket e se der falha exibe o erro na criação deste
    perror("socket creation failed"); 
    exit(EXIT_FAILURE); 
  } 
      
  memset(&servaddr, 0, sizeof(servaddr));  // aloca a memória necessária para armazenar os endereços
  memset(&cliaddr, 0, sizeof(cliaddr)); 
      
  // Filling server information // configura o servidor
  servaddr.sin_family    = AF_INET; // IPv4 
  servaddr.sin_addr.s_addr = INADDR_ANY; 
  servaddr.sin_port = htons(20000); 
  
  // Bind the socket with the server address 
  if ( bind(sockfd, (const struct sockaddr *)&servaddr,  // une o socket e o endereço do servidor, se der falha exibe erro
            sizeof(servaddr)) < 0 ) 
    { 
      perror("bind failed"); 
      exit(EXIT_FAILURE); 
    }
  while (1) // mantem o servidor em constante execução
    server_udp(sockfd);
  
}

