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
#define SA struct sockaddr 

int closeConnection(char *buf, char *end)
{
	int i;
	for (i = 0; i < 16; i++) { 
        if(buf[i] != end[i])
        	return 0;
    
    return 1;
    } 
}

// function to receive file 
int recvFile(char* buf, int s) 
{ 
    int i; 
    char ch; 
    for (i = 0; i < s; i++) { 
        ch = buf[i];  
        if (ch == EOF) 
            return 1; 
        else if(ch == '?')
        	return 2;
    } 
    printf("\n");
    return 0; 
}

 void compare(FILE *file, File *file2) 
{ 
    // fetching character of two file 
    // in two variable ch1 and ch2 
    char ch1 = getc(file); 
    char ch2 = getc(file2)
    
    // error keeps track of number of errors 
    // pos keeps track of position of errors 
    // line keeps track of error line 
    int index = 0, pos = 0, line = 1; 

    int z = 0;
    // iterate loop till end of file 
    while (ch1 != EOF && ch2 != EOF) 
    { 
        // if fetched data is not equal then 
        // error is incremented 
        if (ch1 != ch2) 
        {  
        	z = 1;
            break; 
        } 
        // fetching character until end of file 
        ch1 = getc(file); 
        ch2 = getc(file2)
    } 
    printf("\n");
    if(z = 1)
    {
    	printf("Error, files not the same \n");
    }
    else	
    	printf("Files are identical \n"); 
}

 
int main() 
{ 
    int sockfd, n; 
    struct sockaddr_in servaddr; 
    char buff[80];
    char *filename = malloc(80 * sizeof(int));
    char *ack = "Packet Acknowledged \n"; 
    char *nack = "Packet Not Acknowledged \n";
    char *end = "Close Connection \n";
    char fileContents[80];
    int servlen = sizeof(servaddr);
    bzero(&servaddr, sizeof(servaddr));
    
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
    
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
    
    if ( sockfd < 0 ) { 
        printf("socket creation failed"); 
        return 0;
    } 
    else
        printf("Socket successfully created..\n"); 
     

    
  //  for (;;) 
  //  { 
    
   	//Zero out buffer
   		bzero(buff, sizeof(buff)); 
        
    	//Get file name
    	printf("Enter the string : \t"); 
    	scanf("%s", buff);
 		sprintf(filename, buff);
 		printf("filename is %s \n", buff);
 		sendto(sockfd, buff, MAX, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
 
 		//Send filename to server
 
 		printf("Sending file to server \n");
 		
 		int a = 0;
 		
 		while(1)
 		{
    		bzero(buff, sizeof(buff));
    		
    		
    		printf("Receiving packet %d... \n", a);
    		
        	n = recvfrom(sockfd, buff, MAX, 0, ( struct sockaddr *) &servaddr, &servlen);
            
        
            printf("Packet received: %s \n", buff);
            
            if(closeConnection(buff, end))
            {
            	close(sockfd);
            	break;
            }
            
            a += 1;
            
            
            if(n < 0)
            {
            	printf("Error, returned -1 \n");
            	return 0;
            }
            if(recvFile(buff, MAX) == 0)
            {
            	printf("Sending ACK \n");
        
            	sendto(sockfd, ack, MAX, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
            	strcat(fileContents, buff);
            	printf("%s \n", fileContents);
            }
            
            if(recvFile(buff, MAX) == 2)
            {
            	printf("File Corrupted, sending NACK \n ");
            	sendto(sockfd, nack, MAX, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
            	a--;
            }
            	
   		}

        	FILE *file = fopen(filename, "r");
        
        	if(file != NULL)
        	{
        		FILE *file2 = fopen("newFile.txt", "w")
        		int results = fputs(fileContents, file);
        		compare(file, file2);
        		return 0;
   			}
   			
   			else
   			{
   				printf("Error, file corrupted \n");
   				return 0;
   			}
   	 
    return 0;
} 
