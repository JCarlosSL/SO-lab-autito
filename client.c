// Ficheros de cabecera
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 
void client(int argc, char *argv[]){
 	//Definir variables,estructuras
 	struct sockaddr_in server;
 	char ip[16]="127.0.0.1";
 	int fd, numbytes,puerto=8080;
 	char buf[1024];
 	char enviar[1024];
 
	printf("ingrese la ip del servidor\n");
	scanf("%s",ip);
 
	puerto=8080;
 
 	//Socket
 	if ((fd=socket(AF_INET, SOCK_STREAM, 0))==-1){
 		printf("socket() error\n");
 		exit(-1);
 	}
 
 	//Datos del servidor
 	server.sin_family = AF_INET;
 	server.sin_port = htons(puerto);
 	server.sin_addr.s_addr=inet_addr(ip);
 	bzero(&(server.sin_zero),8);
 
	//Conectarse al servidor
	if(connect(fd, (struct sockaddr *)&server,sizeof(struct sockaddr))==-1){
 		printf("connect() error\n");
 		exit(-1);
 	}
 	//Recibir mensaje de bienvenida
 	if ((numbytes=recv(fd,buf,1024,0)) == -1){
 		printf("Error en recv() \n");
 		exit(-1);
 	}
 	printf("%s\n",buf);

	FILE* archivo;
	archivo=fopen("cliente.txt","r");
	//Ciclo para enviar y recibir informacion

	while(feof(archivo)==0){
		//enviar informacion al servidor
 		fgets(enviar,100,archivo);
		printf("infor: %s\n",enviar);
		send(fd,enviar,1024,0);
 
 		//recibe la informacion del servidor
 		recv(fd,buf,1024,0);
 		

 		printf("Servidor: %s\n",buf);
	}
	fclose(archivo);
 //close(fd);
}
