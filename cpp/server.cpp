//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include "Manager.h" // Ensure Manager.h includes all necessary multimedia and group definitions
#include "tcpserver.h"
#include <memory>
#include <sstream>
#include <iostream>
#include <map>

const int PORT = 3331;

int main(int argc, char* argv[]) {
    Manager manager;

    auto* server = new TCPServer([&](std::string const& request, std::string& response) {
        std::istringstream requestStream(request);
        std::string command;
        requestStream >> command;

        if (command == "CREATE_PHOTO") {
            std::string name, pathname;
            double latitude, longitude;
            requestStream >> name >> pathname >> latitude >> longitude;
            auto photo = manager.createPhoto(name, pathname, latitude, longitude);
            response = "Photo created: " + name;
        }
        else if (command == "CREATE_VIDEO") {
            std::string name, pathname;
            int duration;
            requestStream >> name >> pathname >> duration;
            auto video = manager.createVideo(name, pathname, duration);
            response = "Video created: " + name;
        }
        else if (command == "SEARCH" || command == "DISPLAY") {
            std::string name;
            requestStream >> name;
            response = manager.displayMultimediaObject(name);
            // response = "Displayed: " + name;
        }
        else if (command == "PLAY") {
            std::string name;
            requestStream >> name;
            manager.playMultimediaObject(name);
            response = "Playing: " + name;
        }
        else if (command == "CREATE_GROUP") {
            std::string name;
            requestStream >> name;
            manager.createGroup(name);
            response = "Group created: " + name;
        }
        else if (command == "DISPLAY_GROUP") {
            std::string name;
            requestStream >> name;
            manager.displayGroup(name);
            response = "Group displayed: " + name;
        }
        else {
            response = "Unknown command";
        }

        return true; // Keep connection alive
    });

    std::cout << "Starting Server on port " << PORT << std::endl;
    int status = server->run(PORT);

    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
