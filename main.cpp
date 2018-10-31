//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <memory>
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "manager.h"

// Macro to make it easier to print " - variable_name : value"
#define debug(x) cerr << "       - " <<#x << " : " << x << endl;
#define debugs(x, y) cerr << "       - " <<#x << " : " << x << "    - " <<#y << " : " << y << endl;

using namespace std;

int main(int argc, const char* argv[])
{
//    Multimedia *multimedia = new Multimedia(string("nameXY"), string("fileNameXYZ"));
//    multimedia->printVariables(cout);

//    Photo *photo = new Photo("tpt", "tpt.jpg", 213, 100);
//    photo->printVariables(cout);
//    photo->play();

//    int cnt = 2;
//    Multimedia *multimedia[cnt];
//    multimedia[0] = new Photo("tpt", "tpt.jpg", 213, 100);
//    multimedia[1] = new Video("video", "video.mp4", 100);

//    for(int i = 0; i < cnt; i++) {
//        multimedia[i]->play();
//    }

//    int numberChapters = 10;
//    Film *film = new Film("video", "video.mp4", 100, numberChapters);
//    int duration[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//    film->setDurationChapters(duration, numberChapters);

//    duration[0] = 0; duration[1] = 0; // on modifie duration

//    film->printVariables(cout);
//    delete film;


//    shared_ptr<Video> video(new Video("video", "video.mp4", 100));
//    shared_ptr<Photo> photo(new Photo("tpt", "tpt.jpg", 213, 100));
//    Group* group(new Group(string("Vacances")));

//    cout << group->getName() << endl;
//    group->push_back(video);
//    group->push_back(photo);
//    group->printGroup();
//    delete group;
//    photo->printVariables(cout); // Photo n'est pas détruit quand le groupe est détruit

//    debug(photo.use_count());
//    group->push_back(photo);
//    group->push_back(video);
//    group->printGroup();
//    video.reset();
//    delete group;
//    debug(photo.use_count()); // on remarque bien que c'est 1, vu qu'on n'a pas fait de photo.reset()

//    photo->printVariables(cout);

    Manager m;
//    shared_ptr<Multimedia> video = (m.createVideo("video", "video.mp4", 100));
//    shared_ptr<Multimedia> photo = (m.createPhoto("photo", "tpt.jpg", 123, 321));
    m.createVideo("video", "video.mp4", 100);
    m.createPhoto("photo", "tpt.jpg", 123, 321);
    m.play("vdideo");





    return 0;
}
