#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <memory>
#include "multimedia.h"
#include "video.h"
using namespace std;




#define debug(x) cerr << "       - " <<#x << " : " << x << endl;
#define debugs(x, y) cerr << "       - " <<#x << " : " << x << "    - " <<#y << " : " << y << endl;


class Group : public list<shared_ptr<Multimedia>>
{
    string name;

public:
    Group() {}
    Group(string name) : name(name) {}
    ~Group() {
        cout << "Group " << name << " is dead ! " << endl;
        for(auto it = this->begin(); it != this->end(); it++) {
//            debug(it->use_count());
            it->reset();
        }
    }

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
