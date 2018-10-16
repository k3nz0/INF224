#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <memory>
#include "multimedia.h"
#include "group.h"
#include "photo.h"
#include "video.h"

using namespace std;

class Manager
{
    map <string, shared_ptr <Multimedia> > multimedia_table;
    map <string, shared_ptr <Group> > group_table;
public:
    Manager();

    shared_ptr<Multimedia> createVideo(string name, string fileName, int duration) {
        multimedia_table[name] = shared_ptr<Video>(new Video("f", "video.mp4", 100));
        return multimedia_table[name];
    }

    shared_ptr<Multimedia> createPhoto(string name, string fileName, double latitude, double longitude) {
        multimedia_table[name] = shared_ptr<Photo>(new Photo(fileName, fileName, latitude, longitude));
        return multimedia_table[name];
    }

};

#endif // MANAGER_H
