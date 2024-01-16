#include "MultimediaObject.h"
#include <iostream>
#include <string>

MultimediaObject::MultimediaObject(const std::string& name, const std::string& filename)
    : name(name), filename(filename) {}

MultimediaObject::~MultimediaObject() {
    std::cout << "Destroying MultimediaObject " << name << std::endl;
}

std::string MultimediaObject::getName() const {
    return name;
}

std::string MultimediaObject::getFilename() const {
    return filename;
}

void MultimediaObject::play() const {
    // Provide a definition for the play function
    std::cout << "Playing " << name << " from file " << filename << std::endl;
}

void MultimediaObject::display() const {
    // Provide a definition for the display function
    std::cout << "Name: " << name << ", Filename: " << filename << std::endl;
}