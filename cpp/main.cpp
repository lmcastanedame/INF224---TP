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

int Test() {
    // Create a chapters array
    int chapters[] = {5, 10, 15};

    // Create a Film object
    Film film("Test Film", "/path/to/film", 30, chapters, 3);

    // Display the Film object
    film.display();

    // Modify the chapters array
    chapters[0] = 20;
    chapters[1] = 25;
    chapters[2] = 30;

    // Display the Film object again
    film.display();

    // The Film object's chapters should not have changed,
    // because it made a copy of the array

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

int main(int argc, const char* argv[])
{
    // Create an array of pointers to MultimediaObject
    MultimediaObject* objects[4];

    // Create instances of MultimediaObject 
    objects[0] = new MultimediaObject("Object 1", "file1.txt");
    objects[1] = new MultimediaObject("Object 2", "file2.txt");
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
