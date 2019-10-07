#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "cliente-udp.h"

#define MAX_SIZE 16000

int get_sum_of_ints_udp_sol(int sockfd, uint32_t *tab, size_t length, long *rep)
{
	// @@client_io_udp@start@@
	/*
	 * We assume that sockfd is an open socket,
	 * already set up to send packets to the server,
	 * and that we only have to send one message to the server,
	 * and receive its answer (one message too).
	 * Because it's UDP.
	 */
	if (length > MAX_SIZE) { // if para conferir se o tamanho do pacote é maior do que o UDP
		fprintf(stderr, "Packet is too large to be sent over UDP");
		return -3; //
	}
	ssize_t sent_bytes = 0, recv_bytes = 0; // definir variaveis iniciais de bytes, tanto de entrada quanto de saida
	size_t total_bytes = length * sizeof(uint32_t); // definir a variavel total de bytes
	uint32_t *newtab = malloc(total_bytes); // declarar um ponteiro e ja atribuir um vetor com o tamanho total de bytes
	if (newtab == NULL) { // if para ver se o tamanho de bytes é nulo
		perror("malloc"); // mensagem para avisar que o vetor não foi alocado 
		return -1;
	}
	for (unsigned int i = 0; i < length; i++) { // for para percorrer até o tamanho do pacote
		newtab[i] = htonl(tab[i]); // percorre o vetor alocado e atribui o htol
	}
	sent_bytes = send(sockfd, newtab, total_bytes, 0); // definir bytes de entrada
	if (sent_bytes != (ssize_t) total_bytes) { // if para ver se o bytes está dentro do tamanho total de bytes
		if (sent_bytes == -1) // se for -1, é erro
			perror("send"); // msg de error de enviar
		free(newtab); // depois que ele envia ele limpa o vetor
		return -2;
	}
	free(newtab); // limpa o vetor
	uint32_t answer; //definir uma variavel de resposta
	recv_bytes = recv(sockfd, &answer, sizeof(uint32_t), 0); //definir bytes de saida
	if (recv_bytes != sizeof(uint32_t)) { // if para ver se o bytes está dentro do tamanho total de bytes
		if (recv_bytes == -1) //  // se for -1, é erro
			perror("recv"); // msg de error de receber
		return -2;
	}
	*rep = ntohl(answer); // atribui a resposta em um ponteiro
	return 0;
	// @@client_io_udp@end@@
}


int main(int argc, char *argv[])
{
    int sockfd; 
    struct sockaddr_in   servaddr; 
    int status;  
    struct hostent *hostinfo;
  
    // Creating socket file deor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
		
	//Confere se os argumentos estão corretos
    if (argc < 2) {
      printf("Uso: ./cliente <servidor>\n");
      exit(1);
    }
    hostinfo = gethostbyname(argv[1]); // atribui o primeiro argumento como nome do host
    memset(&servaddr, 0, sizeof(servaddr)); //definir mememoria 

    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(20000);
    memcpy(&servaddr.sin_addr, hostinfo->h_addr_list[0], hostinfo->h_length);
	
	// confere se está tudo certo para conectar, caso nao de uma mensagem de erro
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) {
      perror("connect");
      close(sockfd);
      return -1;
    }
    long resultado;
    int n = 4, tablen = n*sizeof(uint32_t);
    uint32_t tab[4] = {1,2,3,4};

    status = get_sum_of_ints_udp_sol(sockfd, tab, n, &resultado); // status recebe soma udp
    

	// printar mensagem para o usuario
    if (!status) {
      printf("Resultado: %ld\n", resultado);
      return 0;
    }  else {
      printf("Erro: %d\n", status);
      return 1;
    }
}

