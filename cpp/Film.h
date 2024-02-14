#ifndef FILM_H
#define FILM_H

#include "Video.h"

/**
 * @class Film
 * @brief A class that extends Video to manage films, including chapter information.
 * 
 * This class provides functionalities to handle film-specific attributes such as chapters, 
 * in addition to inheriting common video attributes from the Video class.
 */
class Film : public Video {
private:
    int* chapters; ///< Dynamic array to store the duration of each chapter.
    int numChapters; ///< Number of chapters in the film.

public:
    /**
     * @brief Construct a new Film object.
     * 
     * @param name The name of the film.
     * @param filepath The file path to the film's video file.
     * @param duration The total duration of the film.
     * @param chapters An array containing the duration of each chapter.
     * @param numChapters The number of chapters.
     */
    Film(const std::string& name, const std::string& filepath, int duration, int* chapters, int numChapters);

    /**
     * @brief Copy constructor for the Film class.
     * 
     * @param other The Film object to be copied.
     */
    Film(const Film& other);

    /**
     * @brief Overloaded assignment operator for the Film class.
     * 
     * @param other The Film object to be assigned from.
     * @return Film& A reference to the assigned Film object.
     */
    Film& operator=(const Film& other);

    /**
     * @brief Destructor for the Film class.
     */
    ~Film();

    /**
     * @brief Sets the chapters of the film.
     * 
     * @param chapters An array containing the duration of each chapter.
     * @param numChapters The number of chapters.
     */
    void setChapters(int* chapters, int numChapters);

    /**
     * @brief Gets the chapters of the film.
     * 
     * @return int* An array containing the duration of each chapter.
     */
    int* getChapters() const;

    /**
     * @brief Gets the number of chapters in the film.
     * 
     * @return int The number of chapters.
     */
    int getNumChapters() const;

    /**
     * @brief Displays information about the chapters of the film.
     */
    void displayChapters() const;

    /**
     * @brief Virtual method to display information about the film.
     * 
     * Overrides the display method in the base Video class to include information about chapters.
     * 
     * @return std::string A string representing the film's information.
     */
    virtual std::string display() const override;
};

#endif // FILM_H
