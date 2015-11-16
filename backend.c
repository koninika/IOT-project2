//Backend

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

typedef struct Buffer
{
	char message[250];
	int timestamp;
	struct Buffer *nextmsg;
}Buffer;


int main()
{
	int sockfd, gatewaysockfd, c;
	struct sockaddr_in gateway, backend;
	
	//Create Socket
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		printf("\nCould not create Backend socket");
	}
	puts("\nBackend socket is created");	
	
	backend.sin_family = AF_INET;
	backend.sin_addr.s_addr = INADDR_ANY;
	backend.sin_port = htons( 8081 );
	
	//Bind the socket and server address
	if((bind(sockfd, (struct sockaddr *) &backend, sizeof(backend))) < 0)
	{
		perror("\nUnable to Bind socket and address");
		return 1;
	}	
	puts("Socket and address binded");
	puts("Waiting for registrations. . .\n");

	//Listen for connections
	listen(sockfd, 5);
	
	c = sizeof(struct sockaddr_in);
	while (gatewaysockfd = accept(sockfd,(struct sockaddr *) &gateway, (socklen_t*)&c))
	{
	
		int msglen;
		char readmsg[2000];
	/*
		Buffer head;
		//Buffer last;
		head = (Buffer *) malloc(sizeof(Buffer));
		head -> message = NULL;
		head -> next = NULL;
		Buffer temp; */
		//int timestamp;
		memset(readmsg, 0, 2000);
		while(msglen = recv(gatewaysockfd, readmsg, 2000, 0) > 0 )
		{
		/*
			strcpy(tempo, readmsg);
			
			Buffer newNode;
			newNode -> message = readmsg;
			newNode -> timestamp = atoi(strtok(tempo,";"));
			newNode -> next = NULL;
			
			if(head -> message == NULL)
				head = newNode;
			else
			{
				temp = head;
				while(temp -> timestamp > temp -> timestamp || temp -> next != NULL)
				{
					if(temp -> next = NULL)
						temp -> next = newNode;
					else
					{
						newNode -> next = temp -> next;
						temp = newNode;
					}
				}
			}
			*/
			
			puts(readmsg);
			memset(readmsg, 0, 2000);
		}
	}	
}
