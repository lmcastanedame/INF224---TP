#include "Manager.h"
#include <memory>
#include <string>
#include <map>
#include "Manager.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

std::shared_ptr<Photo> Manager::createPhoto(const std::string& name, const std::string& pathname, double latitude, double longitude) {
    auto photo = std::make_shared<Photo>(name, pathname, latitude, longitude);
    multimediaObjects[name] = photo;
    return photo;
}

std::shared_ptr<Video> Manager::createVideo(const std::string& name, const std::string& pathname, int duration) {
    auto video = std::make_shared<Video>(name, pathname, duration);
    multimediaObjects[name] = video;
    return video;
}

std::shared_ptr<Film> Manager::createFilm(const std::string& name, const std::string& pathname, int duration, const std::vector<int>& chapters) {
    // Convert the vector to a dynamic array
    int* chaptersArray = new int[chapters.size()];
    std::copy(chapters.begin(), chapters.end(), chaptersArray);

    // Create the film
    auto film = std::make_shared<Film>(name, pathname, duration, chaptersArray, chapters.size());

    // Don't forget to delete the dynamic array
    delete[] chaptersArray;

    return film;
}

std::shared_ptr<Group<MultimediaObject>> Manager::createGroup(const std::string& name) {
    auto group = std::make_shared<Group<MultimediaObject>>(name);
    groups[name] = group;
    return group;
}

void Manager::displayMultimediaObject(const std::string& name) const {
    auto it = multimediaObjects.find(name);
    if (it != multimediaObjects.end()) {
        it->second->display();
    } else {
        std::cout << "Multimedia object not found" << std::endl;
    }
}

void Manager::displayGroup(const std::string& name) const {
    auto it = groups.find(name);
    if (it != groups.end()) {
        it->second->display();
    } else {
        std::cout << "Group not found" << std::endl;
    }
}

void Manager::playMultimediaObject(const std::string& name) const {
    auto it = multimediaObjects.find(name);
    if (it != multimediaObjects.end()) {
        it->second->play();
    } else {
        std::cout << "Multimedia object not found" << std::endl;
    }
}

void Manager::deleteMultimediaObject(const std::string& name) {
    auto it = multimediaObjects.find(name);
    if (it != multimediaObjects.end()) {
        // Remove the multimedia object from all groups
        for (auto& pair : groups) {
            pair.second->remove(it->second);
        }
        // Remove the multimedia object from the map
        multimediaObjects.erase(it);
    } else {
        std::cout << "Multimedia object not found" << std::endl;
    }
}

void Manager::deleteGroup(const std::string& name) {
    auto it = groups.find(name);
    if (it != groups.end()) {
        groups.erase(it);
    } else {
        std::cout << "Group not found" << std::endl;
    }
}