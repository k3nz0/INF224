#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <memory>
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
    bool processRequest(TCPConnection& cnx, const string& request, string& response)
    {
      cerr << "\nRequest: '" << request << "'" << endl;

      // 1) pour decouper la requête:
      // on peut par exemple utiliser stringstream et getline()


      // 2) faire le traitement:
      // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
      // - sinon juste: TCPLock lock(cnx);


      // 3) retourner la reponse au client:
      // - pour l'instant ca retourne juste OK suivi de la requête
      // - pour retourner quelque chose de plus utile on peut appeler la methode print()
      //   des objets ou des groupes en lui passant en argument un stringstream
      // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
      //   ils servent à délimiter les messages entre le serveur et le client

      response = "OK: " + request;
      cerr << "response: " << response << endl;

      // renvoyer false si on veut clore la connexion avec le client
      return true;
    }
};

#endif // MANAGER_H
