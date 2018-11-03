#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <memory>
#include <sstream>
#include <ostream>
#include "multimedia.h"
#include "group.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "tcpserver.h"

using namespace std;
using namespace cppu;
/**
 * @brief The Manager class
 */
class Manager
{
private:
    map <string, shared_ptr <Multimedia> > multimedia_table;
    map <string, shared_ptr <Group> > group_table;

public:
    Manager();


    shared_ptr<Photo> createPhoto(string name, string fileName, double latitude, double longitude);
    shared_ptr<Multimedia> createVideo(string name, string fileName, int duration);
    shared_ptr<Multimedia> createFilm(string name, string fileName, int duration, int numberChapters);
    shared_ptr<Group> createGroup(string name);


    shared_ptr<Multimedia> findMultimedia(string name);
    shared_ptr<Group> findGroup(string name);


    void printVariables(string name, ostream& stream_out);
    void play(string name);
    string listAllMultimedia();


    bool processRequest(TCPConnection& cnx, const string& request, string& response);
};

#endif // MANAGER_H
