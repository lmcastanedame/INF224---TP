// Author: Laura Manuela Castañeda Medina
//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MultimediaObject.h"
#include "Photo.h"
#include "Video.h"

int main(int argc, const char* argv[])
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
