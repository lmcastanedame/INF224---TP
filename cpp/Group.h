#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include "MultimediaObject.h"
#include <memory> // for std::shared_ptr
#include <sstream>

template <typename T>
using TPtr = std::shared_ptr<T>;

template <typename T>
class Group : public std::list<TPtr<T>> {
private:
    std::string name;

public:
    Group(const std::string& name) : name(name) {};
    std::string getName() const { return name; }

    std::string display() const {
        std::ostringstream oss;
        oss << "Group: " << name << std::endl;
        for (const TPtr<T>& object : *this) {
            oss << object->display() << std::endl;
        }
        return oss.str();
    }
};

#endif // GROUP_H