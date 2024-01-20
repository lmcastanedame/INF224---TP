#include "Film.h"
#include <iostream>
#include <string>

Film::Film(const std::string& name, const std::string& filepath, int duration, int* chapters, int numChapters)
    : Video(name, filepath, duration), chapters(nullptr), numChapters(0) {

    setChapters(chapters, numChapters);
    
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

void Film::display() const {
    Video::display();
    std::cout << "Number of chapters: " << numChapters << std::endl;
}
