#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
        
        // create a socket
        int network_socket;
        network_socket = socket(AF_INET, SOCK_STREAM, 0);

        // specify an address for the socket
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(9002);
        server_address.sin_addr.s_addr = INADDR_ANY

        int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
        //check for error with the connection
        if (connection_status == -1){
        	    printf("There was an error ,aking a connection to the remote socket \n\n");
        }

        // receive from the server
        char server_response[256]; 
        recv(network_socket, &server_response, sizeof(server_response), 0);

        // print out the serverś response
        printf("The server sent the data: %s\n", server_response);

        // and then close the socket 
        close(sock);
        
	    return 0;
}