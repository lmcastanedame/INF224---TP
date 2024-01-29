// Author: Laura Manuela Castañeda Medina
//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <string>
#include <vector>
#include <memory> // for std::shared_ptr
#include "MultimediaObject.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "Manager.h"

#include "tcpserver.h"

int main() {
    
}

int Test6() {
    Manager manager;

    auto photo1 = manager.createPhoto("Photo1", "/path/to/photo1", 1.0, 1.0);
    auto photo2 = manager.createPhoto("Photo2", "/path/to/photo2", 2.0, 2.0);
    auto video = manager.createVideo("Video", "/path/to/video", 120);
    std::vector<int> chapters = {30, 30, 60};
    auto film = manager.createFilm("Film", "/path/to/film", 120, chapters);

    auto group1 = manager.createGroup("Group 1");
    group1->push_back(photo1);
    group1->push_back(photo2);

    auto group2 = manager.createGroup("Group 2");
    group2->push_back(video);
    group2->push_back(film);

    // Test the display methods
    photo1->display();
    video->display();
    film->display();
    group1->display();
    group2->display();

    return 0;
}

int Test5() {
    auto photo1 = std::make_shared<Photo>("Photo1", "/path/to/photo1", 1.0, 1.0);
    auto photo2 = std::make_shared<Photo>("Photo2", "/path/to/photo2", 2.0, 2.0);
    auto video = std::make_shared<Video>("Video", "/path/to/video", 120);
    int chapters[] = {30, 30, 60};
    auto film = std::make_shared<Film>("Film", "/path/to/film", 120, chapters, 3);

    auto group1 = std::make_shared<Group<MultimediaObject>>("Group 1");
    group1->push_back(photo1);
    group1->push_back(photo2);

    auto group2 = std::make_shared<Group<MultimediaObject>>("Group 2");
    group2->push_back(video);
    group2->push_back(film);

    Group<Group<MultimediaObject>> group3("Group 3");
    group3.push_back(group1);
    group3.push_back(group2);

    group1->display();
    group2->display();
    group3.display();

    return 0;
}

int Test4() {
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
