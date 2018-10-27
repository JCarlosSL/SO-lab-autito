// Ficheros de cabecera
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include "systemobd.cpp"

//Funcion principal
void server(int argc, char *argv[]){
	systemobd carlos;

	//Definir variables,estructuras
	struct sockaddr_in server;
	struct sockaddr_in client;
	int fd,fd2,longitud_cliente,puerto;
	char buf[1024]; //Para recibir mensaje
	char enviar2[1024]; //Para enviar mensaje
	char enviar[1024]; //Para enviar mensaje
 
	//puerto de escucha
 	puerto=8080;
	system("clear");
	printf("server connect() \n");

	server.sin_family= AF_INET;
	server.sin_port = htons(puerto);
	server.sin_addr.s_addr = INADDR_ANY;
 	bzero(&(server.sin_zero),8);
 
 	//Definicion de socket
 	if (( fd=socket(AF_INET,SOCK_STREAM,0) )<0){
 		perror("Error de apertura de socket");
 		exit(-1);
 	}
 
 	//Avisar al sistema que se creo un socket
 	if(bind(fd,(struct sockaddr*)&server, sizeof(struct sockaddr))==-1) {
 		printf("error en bind() \n");
 		exit(-1);
 	}
 
 	//Establecer el socket en modo escucha
 	if(listen(fd,5) == -1) {
 		printf("error en listen()\n");
 		exit(-1);
 	}
 
 	longitud_cliente= sizeof(struct sockaddr_in);
 	if ((fd2 = accept(fd,(struct sockaddr *)&client,(socklen_t*)&longitud_cliente))==-1) {
 		printf("error en accept()\n");
 		exit(-1);
 	}
 
 	strcpy(enviar,"SERVIDOR CONECTADO...");
 	send(fd2, enviar, 1024,0);
 

	//Ciclo para enviar y recibir informacion
	while(1){
 	//El servidor espera la informacion
 		recv(fd2,buf,1024,0);
		std::string sol;
		carlos.menu_change(sol,buf);
		strcpy(enviar2,sol.c_str());

        	send(fd2,enviar2,1024,0);

	}
	//return 0;
}
