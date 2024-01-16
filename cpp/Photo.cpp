#include "Photo.h"
#include <iostream>
#include <string>

Photo::Photo(const std::string& name, const std::string& filename, double latitude, double longitude)
        : MultimediaObject(name, filename), latitude(latitude), longitude(longitude) {}

// Implement the display method
void Photo::display() const {
    MultimediaObject::display();
    std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
}

// Implement the play method
void Photo::play() const {
    std::string command = "start \"\" \"" + getFilename() + "\"";
    system(command.c_str());
}

double Photo::getLatitude() const {
    return latitude;
}

double Photo::getLongitude() const {
    return longitude;
}

void Photo::setLatitude(double latitude) {
    this->latitude = latitude;
}

void Photo::setLongitude(double longitude) {
    this->longitude = longitude;
}
