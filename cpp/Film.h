#include "Video.h"

class Film : public Video {
private:
    int* chapters;
    int numChapters;

public:
    Film(const std::string& name, const std::string& filepath, int duration, int* chapters, int numChapters);
    ~Film();
    void setChapters(int* chapters, int numChapters);
    int* getChapters() const;
    int getNumChapters() const;
    virtual void display() const override;
    // No need to override play() as per your requirements
};