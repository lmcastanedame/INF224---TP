#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include "MultimediaObject.h"

class Video : public MultimediaObject {
public:
    Video(const std::string& name, const std::string& filepath, int duration);

    int getDuration() const;
    void setDuration(int duration); 

    virtual void display() const override;
    virtual void play() const override;

private:
    int duration;
};

#endif /* VIDEO_H */