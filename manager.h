#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <memory>
#include "multimedia.h"
#include "group.h"
#include "photo.h"
#include "video.h"
#include "film.h"

using namespace std;

class Manager
{
    map <string, shared_ptr <Multimedia> > multimedia_table;
    map <string, shared_ptr <Group> > group_table;
public:
    Manager();


    shared_ptr<Multimedia> createPhoto(string name, string fileName, double latitude, double longitude) {
        multimedia_table[name] = shared_ptr<Photo>(new Photo(fileName, fileName, latitude, longitude));
        return multimedia_table[name];
    }

    shared_ptr<Multimedia> createVideo(string name, string fileName, int duration) {
        multimedia_table[name] = shared_ptr<Video>(new Video("f", "video.mp4", 100));
        return multimedia_table[name];
    }


    shared_ptr<Multimedia> createFilm(string name, string fileName, int duration, int numberChapters) {
        multimedia_table[name] = shared_ptr<Film>(new Film(fileName, fileName, duration, numberChapters));
        return multimedia_table[name];
    }


    shared_ptr<Group> createGroup(string name) {
        group_table[name] = shared_ptr<Group>(new Group(name));
        return group_table[name];
    }

    shared_ptr<Multimedia> findMultimedia(string name) {
        auto it = multimedia_table.find(name);
        if(it == multimedia_table.end())
            return nullptr;
        else
            return it->second;
    }


    shared_ptr<Group> findGroup(string name) {
        auto it = group_table.find(name);
        if(it == group_table.end())
            return nullptr;
        else
            return it->second;
    }


    void printVariables(string name) {
       auto multimedia = findMultimedia(name);
       if(multimedia == nullptr) {
           cout << "Error can't find " << name  << " in multimedia_table " << endl;
           return;
       }
        multimedia->printVariables(cout);
    }

    void play(string name) {
        auto multimedia = findMultimedia(name);
        if(multimedia == nullptr) {
            cout << "Error can't find " << name  << " in multimedia_table " << endl;
            return;
        }
        multimedia->play();
    }
};

#endif // MANAGER_H
