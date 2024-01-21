#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include "MultimediaObject.h"
#include <memory> // for std::shared_ptr

template <typename T>
using TPtr = std::shared_ptr<T>;

template <typename T>
class Group : public std::list<TPtr<T>> {
private:
    std::string name;

public:
    Group(const std::string& name) : name(name) {};
    std::string getName() const;

    void display() const {
        std::cout << "Group: " << name << std::endl;
        for (const TPtr<T>& object : *this) {
            object->display();
        }
    }
    
};

#endif // GROUP_H