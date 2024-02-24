#include "Video.h"
#include <iostream>
#include <string>

Video::Video(const std::string& name, const std::string& filepath, int duration)
    : MultimediaObject(name, filepath), duration(duration) {}

Video::Video(const Video& other) 
    : MultimediaObject(other), duration(other.duration) {}

// Implement the display method
std::string Video::display() const {
    // Call the base class display method and store the result.
    std::string baseInfo = MultimediaObject::display();
    // Convert latitude and longitude to strings and concatenate.
    std::string info = baseInfo + ", Duration: " + std::to_string(duration) + " seconds";
    return info;
}


// Implement the play method
void Video::play() const {
    std::string command = "mpv \"" + getFilename() + "\"";
    system(command.c_str());
}

int Video::getDuration() const {
    return duration;
}

void Video::setDuration(int duration) {
    this->duration = duration;
}   