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

/**
 * @class Manager
 * @brief Manages multimedia objects and groups, offering creation, display, and deletion functionalities.
 * 
 * This class uses maps to keep track of multimedia objects and groups of objects,
 * allowing for efficient lookup, display, and management operations.
 */
class Manager {
private:
    std::map<std::string, std::shared_ptr<MultimediaObject>> multimediaObjects; ///< Map of multimedia objects indexed by name.
    std::map<std::string, std::shared_ptr<Group<MultimediaObject>>> groups; ///< Map of groups indexed by name.

public:
    /**
     * @brief Creates and stores a new Photo object.
     * 
     * @param name The name of the photo.
     * @param pathname The file path of the photo.
     * @param latitude The latitude where the photo was taken.
     * @param longitude The longitude where the photo was taken.
     * @return std::shared_ptr<Photo> A shared pointer to the created Photo object.
     */
    std::shared_ptr<Photo> createPhoto(const std::string& name, const std::string& pathname, double latitude, double longitude);

    /**
     * @brief Creates and stores a new Video object.
     * 
     * @param name The name of the video.
     * @param pathname The file path of the video.
     * @param duration The duration of the video in seconds.
     * @return std::shared_ptr<Video> A shared pointer to the created Video object.
     */
    std::shared_ptr<Video> createVideo(const std::string& name, const std::string& pathname, int duration);

    /**
     * @brief Creates and stores a new Film object.
     * 
     * @param name The name of the film.
     * @param pathname The file path of the film.
     * @param duration The total duration of the film in seconds.
     * @param chapters A vector containing the duration of each chapter in the film.
     * @return std::shared_ptr<Film> A shared pointer to the created Film object.
     */
    std::shared_ptr<Film> createFilm(const std::string& name, const std::string& pathname, int duration, const std::vector<int>& chapters);

    /**
     * @brief Creates and stores a new Group object.
     * 
     * @param name The name of the group.
     * @return std::shared_ptr<Group<MultimediaObject>> A shared pointer to the created Group object.
     */
    std::shared_ptr<Group<MultimediaObject>> createGroup(const std::string& name);

    /**
     * @brief Displays information about a multimedia object.
     * 
     * @param name The name of the multimedia object to display.
     * @return std::string A string containing the information about the multimedia object.
     */
    std::string displayMultimediaObject(const std::string& name) const;

    /**
     * @brief Displays information about a group and its multimedia objects.
     * 
     * @param name The name of the group to display.
     */
    void displayGroup(const std::string& name) const;

    /**
     * @brief Plays a multimedia object.
     * 
     * Invokes the play method of the specified multimedia object.
     * 
     * @param name The name of the multimedia object to play.
     */
    void playMultimediaObject(const std::string& name) const;

    /**
     * @brief Deletes a multimedia object.
     * 
     * @param name The name of the multimedia object to delete.
     */
    void deleteMultimediaObject(const std::string& name);

    /**
     * @brief Deletes a group.
     * 
     * @param name The name of the group to delete.
     */
    void deleteGroup(const std::string& name);
};

#endif // MANAGER_H
