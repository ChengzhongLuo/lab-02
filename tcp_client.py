"""
Server receiver buffer is char[256]
If correct, the server will send a message back to you saying "I got your message"
Write your socket client code here in python
Establish a socket connection -> send a short message -> get a message back -> ternimate
use python "input->" function, enter a line of a few letters, such as "abcd"
"""
import socket

def main():
    # TODO: Create a socket and connect it to the server at the designated IP and port

    # TODO: Get user input and send it to the server using your TCP socket

    # TODO: Receive a response from the server and close the TCP connection
    # Create a socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Get local machine name
    host = socket.gethostname()

    # Reserve a port for your service.
    port = 12345

    # Connect to the server
    client_socket.connect((host, port))

    # Send a short message
    message = input("Enter message: ")
    client_socket.sendall(message.encode('utf-8'))

    # Receive data from the server
    received_message = client_socket.recv(256).decode('utf-8')

    # Print received message
    print("Server says: " + received_message)

    # Close the client socket
    client_socket.close()
    pass


if __name__ == '__main__':
    main()




    import socket





