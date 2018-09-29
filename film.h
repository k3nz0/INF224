#ifndef FILM_H
#define FILM_H
#include "video.h"


class Film : public Video
{
    int numberChapters;
    int *durationChapters;
public:
    Film(string name, string fileName, int duration, int numberChapters)
        : Video(name, fileName, duration), numberChapters(numberChapters)
    {
        durationChapters = (int*) malloc(sizeof(int) * numberChapters);
    }

    ~Film() {
        cout << "Calling destructor Film " << endl;
    }

    void printVariables(ostream & flux) const override {
        Video::printVariables(flux);
        flux << "Number of chapters : " << numberChapters << endl;
        for(int i = 0; i < numberChapters; i++) {
            flux << "Duration chapter #" << i + 1 << ": " << durationChapters[i] << endl;
        }
    }

    void setDurationChapters(int *durationChapters, int numberChapters) {
        this->numberChapters = numberChapters;

        if(this->durationChapters != NULL)
            free(this->durationChapters);
        this->durationChapters = NULL;

        this->durationChapters = (int*) malloc(numberChapters * sizeof(int));


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
