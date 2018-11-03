#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"
#include <stdlib.h>

using namespace std;

class Photo : public Multimedia {
    double latitude;
    double longitude;
public:
    Photo(string name, string fileName, double latitude, double longitude) :
        Multimedia(name, fileName), latitude(latitude), longitude(longitude) {
    }

    void printVariables(ostream & flux) const override {
        Multimedia::printVariables(flux);
        flux << "latitude : " << latitude << "||";
        flux << "longitude : " << longitude <<"||";
    }

    void play() const override {
        string command = "imagej " + fileName + " &";
        cout << "IMAGE" << endl;
        system(command.c_str());
    }

    void setLattitude(double lattitude) {
        this->latitude = latitude;
    }
    void setLongitude(double longitude) {
        this->longitude = longitude;
    }

    int getLatitude() const {
        return latitude;
    }
    int getLongitude() const {
        return longitude;
    }

};

#endif // PHOTO_H
