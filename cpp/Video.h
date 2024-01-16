#include "MultimediaObject.h"
#include <string>

class Video : public MultimediaObject {
private:
    int duration;
public:
    Video(const std::string& name, const std::string& filename, int duration)
        : MultimediaObject(name, filename), duration(duration) {}

    int getDuration() const { return duration; }

    void setDuration(int newDuration) { duration = newDuration; }

    void display() const override {
        MultimediaObject::display();
        std::cout << "Duration: " << duration << " seconds" << std::endl;
    }

    void play() const override {
        std::string command = "start " + getFilename();
        system(command.data());
    }
};