#include "MultimediaObject.h"
#include <string>

class Photo : public MultimediaObject {
private:
    double latitude;
    double longitude;
public:
    Photo(const std::string& name, const std::string& filename, double latitude, double longitude)
        : MultimediaObject(name, filename), latitude(latitude), longitude(longitude) {}

    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }

    void setLatitude(double newLatitude) { latitude = newLatitude; }
    void setLongitude(double newLongitude) { longitude = newLongitude; }

    void display() const override {
        MultimediaObject::display();
        std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
    }

    void play() const override {
        std::string command = "start \"\" \"" + getFilename() + "\"";
        system(command.data());
    }
};