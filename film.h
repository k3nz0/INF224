#ifndef FILM_H
#define FILM_H


class Film : public Video
{
    int numberChapters;
    int *durationChapters;
public:
    Film();
    Film(string name, string fileName, int duration, int numberChapters) : Video(name, fileName, duration), numberChapters(numberChapters)
    {
        durationChapters = (int*) malloc(numberChapters);
    }


};

#endif // FILM_H
