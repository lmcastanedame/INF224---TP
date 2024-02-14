#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include "MultimediaObject.h"
#include <memory> // for std::shared_ptr
#include <sstream>

/**
 * @brief Alias template for shared pointer to type T.
 */
template <typename T>
using TPtr = std::shared_ptr<T>;

/**
 * @class Group
 * @brief Template class for managing groups of multimedia objects.
 * 
 * Inherits from std::list to manage collections of multimedia objects using shared pointers.
 * Allows for the aggregation and management of any type that inherits from MultimediaObject.
 * 
 * @tparam T The type of multimedia object, must be derived from MultimediaObject or be MultimediaObject itself.
 */
template <typename T>
class Group : public std::list<TPtr<T>> {
private:
    std::string name; ///< Name of the group.

public:
    /**
     * @brief Construct a new Group object.
     * 
     * @param name The name of the group.
     */
    Group(const std::string& name) : name(name) {};

    /**
     * @brief Gets the name of the group.
     * 
     * @return std::string The name of the group.
     */
    std::string getName() const { return name; }

    /**
     * @brief Displays information about the group and its multimedia objects.
     * 
     * Iterates through the list of multimedia objects, invoking their display method
     * and concatenating the result into a single string.
     * 
     * @return std::string A string containing information about the group and its objects.
     */
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
