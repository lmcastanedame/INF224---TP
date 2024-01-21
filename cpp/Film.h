#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video {
private:
    int* chapters; 
    int numChapters; 

public:
    Film(const std::string& name, const std::string& filepath, int duration, int* chapters, int numChapters);
    Film(const Film& other); // Copy constructor
    Film& operator=(const Film& other); // Overloaded assignment operator
    ~Film(); // Add destructor declaration
    
    void setChapters(int* chapters, int numChapters) ;
    int* getChapters() const;

    int getNumChapters() const;
    void displayChapters() const ;

    virtual void display() const override;
};

#endif // FILM_H
