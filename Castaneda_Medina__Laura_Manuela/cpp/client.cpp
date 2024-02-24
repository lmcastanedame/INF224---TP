//
// Client C++ pour communiquer avec un serveur TCP
// eric lecolinet - telecom paristech - 2016/2020
//

#include <iostream>
#include <string>
#include <algorithm>
#include "ccsocket.h"

static const std::string HOST = "127.0.0.1";
static const int PORT = 3331;

// Function to display available commands to the user
void displayHelp() {
    std::cout << "Available Commands:\n"
              << "CREATE_PHOTO <name> <pathname> <latitude> <longitude> - Create a new photo object.\n"
              << "CREATE_VIDEO <name> <pathname> <duration> - Create a new video object.\n"
              << "SEARCH <name> - Search for a multimedia object by name and display its details.\n"
              << "PLAY <name> - Play a multimedia object by name.\n"
              << "CREATE_GROUP <name> - Create a new group of multimedia objects.\n"
              << "DISPLAY_GROUP <name> - Display all multimedia objects within a group.\n"
              << "quit - Exit the client.\n"
              << "help - Display this help message.\n";
}


int main() {
    Socket sock;
    SocketBuffer sockbuf(sock);

    int status = sock.connect(HOST, PORT);

    if (status < 0) {
        switch (status) {
            case Socket::Failed:
                std::cerr << "Client: Couldn't reach host " << HOST << ":" << PORT << std::endl;
                return 1;
            case Socket::UnknownHost:
                std::cerr << "Client: Couldn't find host " << HOST << ":" << PORT << std::endl;
                return 1;
            default:
                std::cerr << "Client: Couldn't connect to host " << HOST << ":" << PORT << std::endl;
                return 1;
        }
    }

    std::cout << "Client connected to " << HOST << ":" << PORT << std::endl;
    displayHelp(); // Display available commands at startup

    while (std::cin) {
        std::cout << "Request: ";
        std::string request, response;

        std::getline(std::cin, request);
        if (request.empty()) continue; // Skip empty requests
        if (request == "quit") break; // Exit the loop to end the program
        if (request == "help") {
            displayHelp(); // Display help message
            continue;
        }

        // Sending the request to the server
        if (sockbuf.writeLine(request) < 0) {
            std::cerr << "Client: Couldn't send message" << std::endl;
            break; // Exit the loop if sending fails
        }

        // Receiving the response from the server
        if (sockbuf.readLine(response) < 0) {
            std::cerr << "Client: Couldn't receive message" << std::endl;
            break; // Exit the loop if receiving fails
        }

        // Convert ';' back to '\n' in the response for display, if necessary
        std::replace(response.begin(), response.end(), ';', '\n');
        std::cout << "Response: " << response << std::endl;
    }

    return 0;
}

