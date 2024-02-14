#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <iostream>
#include "MultimediaObject.h"

/**
 * @class Photo
 * @brief A class for managing photo objects, extending the MultimediaObject class.
 * 
 * This class represents a photo, including its geographic location (latitude and longitude)
 * along with the basic multimedia attributes inherited from MultimediaObject.
 */
class Photo : public MultimediaObject {
private:
    double latitude; ///< Latitude where the photo was taken.
    double longitude; ///< Longitude where the photo was taken.

public:
    /**
     * @brief Construct a new Photo object.
     * 
     * @param name The name of the photo.
     * @param filename The filename (including path) where the photo is stored.
     * @param latitude The latitude where the photo was taken.
     * @param longitude The longitude where the photo was taken.
     */
    Photo(const std::string& name, const std::string& filename, double latitude, double longitude);

    /**
     * @brief Gets the latitude of the photo.
     * 
     * @return double The latitude where the photo was taken.
     */
    double getLatitude() const;

    /**
     * @brief Gets the longitude of the photo.
     * 
     * @return double The longitude where the photo was taken.
     */
    double getLongitude() const;

    /**
     * @brief Sets the latitude of the photo.
     * 
     * @param latitude The new latitude where the photo was taken.
     */
    void setLatitude(double latitude);

    /**
     * @brief Sets the longitude of the photo.
     * 
     * @param longitude The new longitude where the photo was taken.
     */
    void setLongitude(double longitude);

    /**
     * @brief Virtual method to display information about the photo.
     * 
     * Overrides the display method in the MultimediaObject class to include information about the photo's location.
     * 
     * @return std::string A string containing information about the photo.
     */
    virtual std::string display() const override;

    /**
     * @brief Virtual method to "play" the photo.
     * 
     * For a photo, "playing" typically means displaying the photo. This method overrides the play method in the MultimediaObject class.
     */
    virtual void play() const override;
};

#endif /* PHOTO_H */
