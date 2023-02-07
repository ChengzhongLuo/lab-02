/* A simple server in the internet domain using TCP
 * Answer the questions below in your writeup
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    /* 1. What is argc and *argv[]?
     *  Answer: argc is the argument count, which provides the number of character that will be in the argv, which is the argument vector, 
        which will show the vector of char arguments provided by the user.
     */
    int sockfd, newsockfd, portno;
    /* 2. What is a UNIX file descriptor and file descriptor table?
     *  Answer: A file descriptor is an integer that represents an action to manipulate a file (or network or terminal). 
        A file descriptor table is simply an array of file descriptors.
        Sources: Harvard.edu
     */
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;
    /* 3. What is a struct? What's the structure of sockaddr_in?
     *  Answer: A struct is a group of member variables that can be used to define a single variable. 
        Structs can be represented as any groups of variables. sockaddr_in currently has no variable groups (simply represented as a struct),
        but is used later on to bind to a file descriptor int sockfd.
     */
    
    int n;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    /* 4. What are the input parameters and return value of socket()
     * Answer: The inputs of socket are a domain (AF_INET) which is used to represent how a socket communicates, 
     a type (SOCK_STREAM), which shows the type of socket to be create, and a protocol (0), which in this case, as 0,
     represents an unspecified default protocol
     Sources: opengroup.org
     */
    
    if (sockfd < 0) 
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");
    /* 5. What are the input parameters of bind() and listen()?
     * Answer: The bind function takes a socket which is an int, a socket address (sockaddr in this case), which is going to be attached to the socket, and address length, 
     which represents the length of the socket address in bytes (which shows an error in this case if it is negative). The listen function takes a socket file descriptor parameter 
     and a backlog parameter, which is the max length for pending connections. 
     Sources: ibm.com/docs
     */
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    while(1) {
        /* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        *   Answer: If it tried to run multiple connnections at once, they might interfere. From class, it would be like traffic, and multiple processes would try to run through one road.
            This could cause it to not run properly and not close properly. However, if we have threads, it would be like running on multiple roads, which allows all of the processes to run together
        */
        
	char buffer[256];
        newsockfd = accept(sockfd, 
                    (struct sockaddr *) &cli_addr, 
                    &clilen);
	/* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         *  The fork command essentially creates child processes from the parent process, which allows it to run the multiple processes together as Threads. 
         It can be applied here so we don't have to use a while loop to do one process at a time, which makes the server program run faster. 
         Sources: geeksforgeeks.com
         */
        
	if (newsockfd < 0) 
             error("ERROR on accept");
	bzero(buffer,256);
        
	n = read(newsockfd,buffer,255);
        if (n < 0) 
            error("ERROR reading from socket");
        //printf("Here is the message: %s\n",buffer);
        n = write(newsockfd,"I got your message",18);
        if (n < 0) 
            error("ERROR writing to socket");
        close(newsockfd);
    }
    close(sockfd);
    return 0; 
}
  
/* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
 * A system call is essentially something that asks the operating system to provide a service or carry out a task, including the requests to bind and listen in this program.
 Sources: google.com
 */