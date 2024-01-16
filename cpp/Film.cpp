#include <iostream>

#include "Film.h"

Film::Film(const std::string& name, const std::string& filepath, int duration, int* chapters, int numChapters)
    : Video(name, filepath, duration), numChapters(numChapters) {
        if (numChapters > 0) {
            this->chapters = new int[numChapters];
            for(int i = 0; i < numChapters; ++i) {
                this->chapters[i] = chapters[i];
            }
        } else {
            this->chapters = nullptr;
        }
    }

int Film::getNumChapters() const {
    return numChapters;
}

void Film::display() const {
    Video::display();
    std::cout << "Chapters: ";
    for(int i = 0; i < numChapters; ++i) {
        std::cout << chapters[i] << " ";
    }
    std::cout << std::endl;
}

Film::~Film() {
    delete[] chapters;
}
