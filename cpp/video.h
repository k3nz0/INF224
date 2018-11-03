#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include "multimedia.h"

using namespace std;


class Video : public Multimedia {
protected:
    int duration;
public:
    Video(string name, string fileName, int duration) :
        Multimedia(name, fileName), duration(duration) {

    }
    virtual ~Video() {}

    void printVariables(ostream & flux) const override {
        Multimedia::printVariables(flux);
        flux << "duration : " << duration << "||";
    }

    void play() const override {
        string command = "mpv " + fileName + " &";
        system(command.c_str());
    }


    void setDuree(int duration) {
        this->duration = duration;
    }

    int getDuration() const {
        return duration;
    }

};

#endif // VIDEO_H

