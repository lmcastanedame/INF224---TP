#ifndef MULTIMEDIAOBJECT_H
#define MULTIMEDIAOBJECT_H

#include <string>

/**
 * @class MultimediaObject
 * @brief Abstract base class for multimedia objects.
 * 
 * This class serves as a base for different types of multimedia objects, providing common attributes like name and filename, and the interface for actions such as play and display.
 */
class MultimediaObject {
public:
    /**
     * @brief Default constructor for MultimediaObject.
     */
    MultimediaObject();

    /**
     * @brief Constructs a MultimediaObject with a name and filename.
     * 
     * @param name The name of the multimedia object.
     * @param filename The filename (including path) where the multimedia object is stored.
     */
    MultimediaObject(const std::string& name, const std::string& filename);

    /**
     * @brief Copy constructor for the MultimediaObject.
     * 
     * @param other The MultimediaObject instance to copy from.
     */
    MultimediaObject(const MultimediaObject& other);

    /**
     * @brief Virtual destructor for the MultimediaObject.
     */
    virtual ~MultimediaObject();

    /**
     * @brief Gets the name of the multimedia object.
     * 
     * @return std::string The name of the object.
     */
    std::string getName() const;

    /**
     * @brief Gets the filename of the multimedia object.
     * 
     * @return std::string The filename where the object is stored.
     */
    std::string getFilename() const;

    /**
     * @brief Sets the name of the multimedia object.
     * 
     * @param name The new name of the object.
     */
    void setName(const std::string& name);

    /**
     * @brief Sets the filename of the multimedia object.
     * 
     * @param filename The new filename (including path) of the object.
     */
    void setFilename(const std::string& filename);

    /**
     * @brief Virtual method to play the multimedia object.
     * 
     * This method should be overridden by derived classes to perform the action of playing the multimedia content.
     */
    virtual void play() const;

    /**
     * @brief Virtual method to display information about the multimedia object.
     * 
     * This method should be overridden by derived classes to return a string containing information about the object.
     * 
     * @return std::string A string representing the multimedia object's information.
     */
    virtual std::string display() const;

private:
    std::string name; ///< Name of the multimedia object.
    std::string filename; ///< Filename (including path) of the multimedia object.
};

#endif // MULTIMEDIAOBJECT_H
