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


    /* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
     * Ca doit etre une methode de la classe qui gere les données, afin qu'elle
     * puisse y accéder.
     *
     * Arguments:
     * - 'request' contient la requête
     * - 'response' sert à indiquer la réponse qui sera renvoyée au client
     * - si la fonction renvoie false la connexion est close.
     *
     * Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
     * un thread par client).
     *
     * Pour eviter les problemes de concurrence on peut créer un verrou en creant
     * une variable Lock **dans la pile** qui doit etre en mode WRITE (2e argument = true)
     * si la fonction modifie les donnees.
     */
    bool processRequest(TCPConnection& cnx, const string& request, string& response);
};

#endif // MANAGER_H
