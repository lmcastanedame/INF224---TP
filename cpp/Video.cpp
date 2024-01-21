#include "Video.h"
#include <iostream>
#include <string>

Video::Video(const std::string& name, const std::string& filepath, int duration)
    : MultimediaObject(name, filepath), duration(duration) {}

Video::Video(const Video& other) 
    : MultimediaObject(other), duration(other.duration) {}

// Implement the display method
void Video::display() const {
    MultimediaObject::display();
    std::cout << "Duration: " << duration << " seconds" << std::endl;
}

// Implement the play method
void Video::play() const {
    std::string command = "start " + getFilename() + "\"";
    system(command.c_str());
}

int Video::getDuration() const {
    return duration;
}

void Video::setDuration(int duration) {
    this->duration = duration;
}   