#ifndef FILM_H
#define FILM_H
#include "video.h"

/**
 * @brief The Film class
 */
class Film : public Video
{
    int numberChapters;
    int *durationChapters;
public:
    /**
     * @brief Film hello
     * @param name
     * @param fileName
     * @param duration
     * @param numberChapters
     */
    Film(string name, string fileName, int duration, int numberChapters)
        : Video(name, fileName, duration)
    {
        durationChapters = nullptr;
    }

    ~Film() {
//        cout << "Calling destructor Film " << endl;
        delete[] durationChapters;
    }
    /**
     * @brief printVariables
     * @param flux
     */
    void printVariables(ostream & flux) const override {
        // Afin d'éviter les \n dans les sockets, on les remplace par "||". Il faudra les parser par la suite côté client
        Video::printVariables(flux);
        flux << "Number of chapters : " << numberChapters << "||";
        for(int i = 0; i < numberChapters; i++) {
            flux << "Duration chapter #" << i + 1 << ": " << durationChapters[i] << "||";
        }
    }
    /**
     * @brief setDurationChapters
     * @param durationChapters
     * @param numberChapters
     */
    void setDurationChapters(const int *durationChapters, int numberChapters) {
        this->numberChapters = numberChapters;

        delete[] this->durationChapters;
        this->durationChapters = nullptr;

        if(numberChapters > 0)
            this->durationChapters = new int[numberChapters];

        for(int i = 0; i < numberChapters; i++) {
            this->durationChapters[i] = durationChapters[i];
        }

    }
    /**
     * @brief getNumberChapters
     * @return
     */
    int getNumberChapters() const {
        return numberChapters;
    }

    /**
     * @brief getDurationChapters
     * @return
     */

    const int* getDurationChapters() const{
        return durationChapters;
    }
    /**
     * @brief getChapter
     * @param index
     * @return
     */
    int getChapter(int index) {
        if(index >= numberChapters)
            return -1; // out of bound
        else
            return durationChapters[index];

    }



};

#endif // FILM_H
