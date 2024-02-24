#include "Photo.h"
#include <iostream>
#include <string>

Photo::Photo(const std::string& name, const std::string& filename, double latitude, double longitude)
        : MultimediaObject(name, filename), latitude(latitude), longitude(longitude) {}

// Implement the display method
std::string Photo::display() const {
    // Call the base class display method and store the result.
    std::string baseInfo = MultimediaObject::display();
    // Convert latitude and longitude to strings and concatenate.
    std::string info = baseInfo + ", Latitude: " + std::to_string(latitude) + ", Longitude: " + std::to_string(longitude);
    return info;
}


// Implement the play method
void Photo::play() const {
    std::string command = "imagej \"\" \"" + getFilename() + "\"";
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
