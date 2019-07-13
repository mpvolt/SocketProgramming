#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>  

#define MAX 80 
#define PORT 8895

int checkACK(char *buf, char *ack)
{
	int i;
	for (i = 0; i < 19; i++)
	{ 
        if(buf[i] != ack[i])
        	return 0;
    } 
    return 1;
}

int flip(int p)
{
	int i; 
    i = rand() % p + 1;
 	if (i == p)
        return 1; 
    else
        return 0;
                     
}

// funtion sending file 
int sendFile(FILE* file, char* buf, int a, int s, double p) 
{ 
    int i, len; 
    if (file == NULL) 
    { 
       	printf("Error, file is null \n");
       	return 0;
    } 
  	fseek(file, a, 0);
    char ch; 
    for (i = 0; i < s; i++) 
    { 
        ch = fgetc(file); 
       if(flip(p) == 1)
        	buf[i] = '?'; 
    	else
        	buf[i] = ch;
    } 
    if(ch == EOF)
    {
      	return 2;
    }
    else 
    	return 1; 
} 


// Driver function 
int main(int argc, char **argv) 
{
    int sockfd, clientlen, n; 
    struct sockaddr_in cliaddr; 
	char buff[MAX]; 
    char filename[MAX];
	int windowSize = atoi(argv[1]);
	int p = atoi(argv[2]);
	char *ack = "Packet Acknowledged \n"; 
    char *close = "Close Connection \n";
    
    if(p < 1)
    {
    	printf("Please use a number larger than 1");
    	return 0;
    }
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
    
    if (sockfd < 0) 
    { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    

    // assign IP, PORT 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
    
    cliaddr.sin_family = AF_INET; 
    cliaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    cliaddr.sin_port = htons(PORT); 
    
      // Binding newly created socket to given IP and verification 
    if ( bind(sockfd, (const struct sockaddr *)&cliaddr, sizeof(cliaddr)) < 0 ) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }
    else
        printf("Socket successfully binded..\n"); 
     
     clientlen = sizeof(cliaddr);
    // infinite loop for chat 
    //for (;;) 
    //{ 
        bzero(buff, MAX); 
        
        printf("Listening for filename...\n");
        // Now server is ready to listen and verification 
        n = recvfrom(sockfd, (char *)buff, sizeof(buff),  0, ( struct sockaddr *) &cliaddr, &clientlen); 
                
        // print buffer which contains the client contents 
        printf("From client: %s\t", buff); 
        
        //sprintf(filename, buff);
        
        FILE *file = fopen(buff, "r");
        
        if(file == NULL)
        {
        	printf("File not found \n");
        	return 0;
        }
        else
        	printf("File found! \n");
        
        int a = 0;
        
    	while(1)
    	{
        	bzero(buff, MAX);
        	
        	printf("Sending Packet %d \n", a);
        
        	if (sendFile(file, buff, a*windowSize, windowSize, p) == 1)
        	{
        		printf("Sending: %s \n", buff);
        	 	sendto(sockfd, buff, MAX, 0, ( struct sockaddr *) &cliaddr, sizeof(cliaddr)); 
        	 	printf("Packet %d sent!\n", a);
        	} 
        	
            else if (sendFile(file, buff, a*windowSize, windowSize, p) == 0)
            	printf("Packet %d not sent!\n", a);
            	
            else if (sendFile(file, buff, a*windowSize, windowSize, p) == 2)
            {
            	sendto(sockfd, buff, MAX, 0, ( struct sockaddr *) &cliaddr, sizeof(cliaddr)); 
            	break;
            }
            	
            bzero(buff, MAX);
            
            printf("Waiting for ACK... \n");
            n = recvfrom(sockfd, buff, MAX,  0, ( struct sockaddr *) &cliaddr, &clientlen);  
                
        	// print buffer which contains the client contents 
        	printf("From client: %s\t", buff); 
        	
        	if(checkACK(buff, ack))
        	 	a++;
        	else
        	 	printf("Resending Packet %d \n", a);
        	 	 
		}
		sendto(sockfd, close, MAX, 0, ( struct sockaddr *) &cliaddr, sizeof(cliaddr)); 
        printf("Whole File Sent! \n");

    return 0;
} 
