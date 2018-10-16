#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include "multimedia.h"
#include "video.h"
using namespace std;

class Group : public list<Multimedia*>
{
    string name;

public:
    Group() {}
    Group(string name) : name(name) {}


    string getName() const {
        return name;
    }

    void printGroup() {
        for(auto it = this->begin(); it != this->end(); it++) {
            (*it)->printVariables(cout);
        }
    }

    void setName(string name) {
        this->name = name;
    }
};

#endif // GROUP_H
