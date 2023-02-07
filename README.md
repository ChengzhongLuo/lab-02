# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Aum Patel
- Chengzhong Luo

## Lab Question Answers


Question 1: How did the reliability of UDP change when you added 50% loss to your local
environment? Why did this occur?

When using the command for the 50% loss with UDP, we only recieved about half of the messages (only six of the numbers). This occurs because there is packet loss with UDP as it does not require a connection to check the transfer and it also does not go back to check if the client has recieved all of the messages. 

Question 2: How did the reliability of TCP change? Why did this occur?

The TCP would show all of the numbers, even with the 50% loss command as it transfers the packets and checks if the client has recieved them. Also, TCP has a stronger connection with the client.

Question 3: How did the speed of the TCP response change? Why might this happen?

The TCP is slower than UDP as it has larger packets that ensure that the data has been recieved and also checks for errors.



tcp_server.c Questions
     /* 1. What is argc and *argv[]?
     *  Answer: argc is the argument count, which provides the number of character that will be in the argv, which is the argument vector, which will show the vector of char arguments provided by the user.
     */
     /* 2. What is a UNIX file descriptor and file descriptor table?
     *  Answer: A file descriptor is an integer that represents an action to manipulate a file (or network or terminal). A file descriptor table is simply an array of file descriptors.
        Sources: Harvard.edu
     */
     /* 3. What is a struct? What's the structure of sockaddr_in?
     *  Answer: A struct is a group of member variables that can be used to define a single variable. 
        Structs can be represented as any groups of variables. sockaddr_in currently has no variable groups (simply represented as a struct), but is used later on to bind to a file descriptor int sockfd.
     */
     /* 4. What are the input parameters and return value of socket()
     * Answer: The inputs of socket are a domain (AF_INET) which is used to represent how a socket communicates, a type (SOCK_STREAM), which shows the type of socket to be create, and a protocol (0), which in this case, as 0, represents an unspecified default protocol
     Sources: opengroup.org
     */
     /* 5. What are the input parameters of bind() and listen()?
     * Answer: The bind function takes a socket which is an int, a socket address (sockaddr in this case), which is going to be attached to the socket, and address length, which represents the length of the socket address in bytes (which shows an error in this case if it is negative). The listen function takes a socket file descriptor parameter and a backlog parameter, which is the max length for pending connections. 
     Sources: ibm.com/docs
     */
     /* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        *   Answer: If it tried to run multiple connnections at once, they might interfere. From class, it would be like traffic, and multiple processes would try to run through one road. This could cause it to not run properly and not close properly. However, if we have threads, it would be like running on multiple roads, which allows all of the processes to run together
        */
	   /* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         *  The fork command essentially creates child processes from the parent process, which allows it to run the multiple processes together as Threads. It can be applied here so we don't have to use a while loop to do one process at a time, which makes the server program run faster. 
         Sources: geeksforgeeks.com
         */
         /* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
      	 * A system call is essentially something that asks the operating system to provide a service or carry out a task, including the requests to bind and listen in this program.
      	 Sources: google.com
      	 */
...
