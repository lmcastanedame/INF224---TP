#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <string>
#include <memory>
#include <vector>
#include "MultimediaObject.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

class Manager {
private:
    std::map<std::string, std::shared_ptr<MultimediaObject>> multimediaObjects;
    std::map<std::string, std::shared_ptr<Group<MultimediaObject>>> groups;

public:
    std::shared_ptr<Photo> createPhoto(const std::string& name, const std::string& pathname, double latitude, double longitude);
    std::shared_ptr<Video> createVideo(const std::string& name, const std::string& pathname, int duration);
    std::shared_ptr<Film> createFilm(const std::string& name, const std::string& pathname, int duration, const std::vector<int>& chapters);
    std::shared_ptr<Group<MultimediaObject>> createGroup(const std::string& name);

    std::string displayMultimediaObject(const std::string& name) const;
    void displayGroup(const std::string& name) const;

    void playMultimediaObject(const std::string& name) const;

    void deleteMultimediaObject(const std::string& name);
    void deleteGroup(const std::string& name);
};

#endif // MANAGER_H