#include "Film.h"
#include <iostream>
#include <string>

Film::Film(const std::string& name, const std::string& filepath, int duration, int* chapters, int numChapters)
    : Video(name, filepath, duration), chapters(nullptr), numChapters(0) {

    setChapters(chapters, numChapters);
    
    }

Film::Film(const Film& other) : Video(other) {
    numChapters = other.numChapters;
    chapters = new int[numChapters];
    for (int i = 0; i < numChapters; i++) {
        chapters[i] = other.chapters[i];
    }
}

Film& Film::operator=(const Film& other) {
    if (this != &other) {
        Video::operator=(other);
        delete[] chapters;
        numChapters = other.numChapters;
        chapters = new int[numChapters];
        for (int i = 0; i < numChapters; i++) {
            chapters[i] = other.chapters[i];
        }
    }
    return *this;
}

Film::~Film() {
    delete[] chapters;
}

void Film::setChapters(int* chapters, int numChapters) {
    delete[] this->chapters;
    this->chapters = new int[numChapters];
    for (int i = 0; i < numChapters; i++) {
        this->chapters[i] = chapters[i];
    }
    this->numChapters = numChapters;
}

int* Film::getChapters() const {
    return chapters;
}

int Film::getNumChapters() const {
    return numChapters;
}

void Film::displayChapters() const {
    for (int i = 0; i < numChapters; i++) {
        std::cout << "Chapter " << i + 1 << ": " << chapters[i] << " seconds" << std::endl;
    }
}

std::string Film::display() const {
    // Call the base class display method and store the result.
    std::string baseInfo = Video::display();
    // Convert latitude and longitude to strings and concatenate.
    std::string info = baseInfo + ", Number of chapters: " + std::to_string(numChapters);
    return info;
}