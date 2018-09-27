//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "multimedia.h"
#include "photo.h"
#include "video.h"

using namespace std;

int main(int argc, const char* argv[])
{
//    Multimedia *multimedia = new Multimedia(string("nameXY"), string("fileNameXYZ"));
//    multimedia->printVariables(cout);

//    Photo *photo = new Photo("tpt", "/cal/homes/mezzeddine/inf224/tpt.jpg", 213, 100);
//    photo->printVariables(cout);
//    photo->play();
    int cnt = 2;
    Multimedia *multimedia[cnt];
    multimedia[0] = new Photo("tpt", "/cal/homes/mezzeddine/inf224/tpt.jpg", 213, 100);
    multimedia[1] = new Video("video", "/cal/homes/mezzeddine/inf224/video.mp4", 100);

    for(int i = 0; i < cnt; i++) {
        multimedia[i]->play();
    }
    return 0;
}
