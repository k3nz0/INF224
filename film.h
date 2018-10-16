#ifndef FILM_H
#define FILM_H
#include "video.h"


class Film : public Video
{
    int numberChapters;
    int *durationChapters;
public:
    Film(string name, string fileName, int duration, int numberChapters)
        : Video(name, fileName, duration)
    {
        durationChapters = nullptr;
    }

    ~Film() {
//        cout << "Calling destructor Film " << endl;
        delete[] durationChapters;
    }

    void printVariables(ostream & flux) const override {
        Video::printVariables(flux);
        flux << "Number of chapters : " << numberChapters << endl;
        for(int i = 0; i < numberChapters; i++) {
            flux << "Duration chapter #" << i + 1 << ": " << durationChapters[i] << endl;
        }
    }

    void setDurationChapters(const int *durationChapters, int numberChapters) {
        this->numberChapters = numberChapters;

        delete[] this->durationChapters;
        this->durationChapters = nullptr;

//        this->durationChapters = (int*) malloc(numberChapters * sizeof(int));
        if(numberChapters > 0)
            this->durationChapters = new int[numberChapters];

        for(int i = 0; i < numberChapters; i++) {
            this->durationChapters[i] = durationChapters[i];
        }

    }

    int getNumberChapters() const {
        return numberChapters;
    }

    const int* getDurationChapters() const{
        return durationChapters;
    }

    int getChapter(int index) {
        if(index >= numberChapters)
            return -1; // out of bound
        else
            return durationChapters[index];

    }



};

#endif // FILM_H
