#include "MultimediaObject.h"
#include <iostream>
#include <string>

MultimediaObject::MultimediaObject(const std::string& name, const std::string& filename)
    : name(name), filename(filename) {}

MultimediaObject::~MultimediaObject() {
    std::cout << "Destroying MultimediaObject " << name << std::endl;
}

MultimediaObject::MultimediaObject(const MultimediaObject& other) 
    : name(other.name), filename(other.filename) {}

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

std::string MultimediaObject::display() const {
    // Construct a string that contains the name and filename
    std::string info = "Name: " + name + ", Filename: " + filename;
    return info;
}
