#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

const char* ip = "127.0.0.1";
const int port = 65432;

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }

    // Connect to the server
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_address.sin_addr);
    if (connect(sock, (sockaddr*)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Failed to connect to server" << std::endl;
        return 1;
    }

    // write a while true loop
    while (true) {
        std::cout << "Enter a message: ";
        std::string message;
        std::getline(std::cin, message);

        // Send the message
        send(sock, message.c_str(), message.size(), 0);

        // Receive the response
        char response[1024];
        recv(sock, response, sizeof(response), 0);

        // Print the response
        std::cout << "Received: " << response << std::endl;

        //delay
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // Close the socket
    close(sock);

    return 0;
}
