#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

using namespace std;

class Multimedia
{
protected:
    string name;
    string fileName;
public:
    Multimedia();
    Multimedia(string name, string fileName) : name(name), fileName(fileName) {}
    virtual ~Multimedia() {}

    virtual void printVariables(ostream & flux) const;

    virtual void play() const = 0;

    string getName() const{
        return name;
    }
    string getFileName() const {
        return fileName;
    }

    void setName(string name) {
        this->name = name;
    }
    void setFileName(string fileName) {
        this->fileName = fileName;
    }

};

#endif // MULTIMEDIA_H
