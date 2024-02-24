#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include "MultimediaObject.h"

/**
 * @class Video
 * @brief A class for managing video objects, extending the MultimediaObject class.
 * 
 * This class represents a video, including its duration along with the basic multimedia attributes inherited from MultimediaObject.
 */
class Video : public MultimediaObject {
public:
    /**
     * @brief Construct a new Video object.
     * 
     * @param name The name of the video.
     * @param filepath The file path where the video is stored.
     * @param duration The duration of the video in seconds.
     */
    Video(const std::string& name, const std::string& filepath, int duration);

    /**
     * @brief Copy constructor for the Video class.
     * 
     * @param other The Video object to copy from.
     */
    Video(const Video& other);

    /**
     * @brief Gets the duration of the video.
     * 
     * @return int The duration of the video in seconds.
     */
    int getDuration() const;

    /**
     * @brief Sets the duration of the video.
     * 
     * @param duration The new duration of the video in seconds.
     */
    void setDuration(int duration);

    /**
     * @brief Virtual method to display information about the video.
     * 
     * Overrides the display method in the MultimediaObject class to include information about the video's duration.
     * 
     * @return std::string A string containing information about the video.
     */
    virtual std::string display() const override;

    /**
     * @brief Virtual method to "play" the video.
     * 
     * This method overrides the play method in the MultimediaObject class, typically to perform actions such as opening a video player.
     */
    virtual void play() const override;

private:
    int duration; ///< Duration of the video in seconds.
};

#endif /* VIDEO_H */
