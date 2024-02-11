#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <iostream>
#include "MultimediaObject.h"

class Photo : public MultimediaObject {
private:
    double latitude;
    double longitude;

public:
    Photo(const std::string& name, const std::string& filename, double latitude, double longitude);

    double getLatitude() const;
    double getLongitude() const;

    void setLatitude(double latitude);
    void setLongitude(double longitude);

    virtual std::string display() const override;
    virtual void play() const override;
};

#endif /* PHOTO_H */