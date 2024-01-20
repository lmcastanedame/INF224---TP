// Author: Laura Manuela Castañeda Medina
//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MultimediaObject.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

int main() {
    // Create a chapters array
    int chapters[] = {10, 20, 30};

    // Create a Film object
    Film film("Test Film", "Video.mp4", 120, chapters, 3);

    // Display the Film object
    film.display();

    // Display the chapters
    std::cout << "Chapters: " << std::endl;
    film.displayChapters();

    // Modify the chapters array
    int newChapters[] = {20, 25, 30};
    film.setChapters(newChapters, 3);

    // Display the Film object again
    film.display();

    // Display the chapters
    std::cout << "Chapters: " << std::endl;
    film.displayChapters();

    // Get the chapters
    int* retrievedChapters = film.getChapters();
    for (int i = 0; i < film.getNumChapters(); i++) {
        std::cout << retrievedChapters[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


int Test1(int argc, const char* argv[])
{
    // Créer des instances de MultimediaObject
    MultimediaObject* obj1 = new MultimediaObject("Object 1", "file1.txt");
    MultimediaObject* obj2 = new MultimediaObject("Object 2", "file2.txt");

    // Utiliser la méthode d'affichage pour afficher les détails des objets
    obj1->display();
    obj2->display();

    // Libérer la mémoire allouée avec new
    delete obj1;
    delete obj2;

    return 0;
}

int Test2(int argc, const char* argv[])
{
    // Create a Photo object
    Photo myPhoto("MyPhoto", "Photo.png", 40.748817, -73.985428);

    // Display the photo's properties
    myPhoto.display();

    // Change the photo's latitude and longitude
    myPhoto.setLatitude(51.5074);
    myPhoto.setLongitude(-0.1278);

    // Display the photo's properties again to confirm they've been updated
    myPhoto.display();

    // "Play" the photo
    myPhoto.play();

    return 0;
}

int Test3(int argc, const char* argv[])
{
    // Create an array of pointers to MultimediaObject
    MultimediaObject* objects[4];

    // Create instances of MultimediaObject 
    objects[0] = new Photo("Photo 1", "Photo.png", 100, 200);
    objects[1] = new Video("Video 1", "Video.mp4", 10);
    objects[2] = new Photo("Photo 1", "Photo.png", 100, 200);
    objects[3] = new Video("Video 1", "Video.mp4", 10);

    // Use the display method to show the details of the objects
    for (int i = 0; i < 4; i++)
    {
        objects[i]->display();
    }

    // Use the play method to play the objects
    for (int i = 0; i < 4; i++)
    {
        objects[i]->play();
    }

    // Free the memory allocated with new
    for (int i = 0; i < 4; i++)
    {
        delete objects[i];
    }

    return 0;
}
