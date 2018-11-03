#include "manager.h"


Manager::Manager()
{

}


shared_ptr<Photo> Manager::createPhoto(string name, string fileName, double latitude, double longitude) {
    shared_ptr<Photo> photo_tmp(new Photo(fileName, fileName, latitude, longitude));
    multimedia_table[name] = photo_tmp ;
    return photo_tmp;
}
shared_ptr<Multimedia> Manager::createVideo(string name, string fileName, int duration) {
    shared_ptr<Video> video_tmp(new Video(name, fileName, duration));
    multimedia_table[name] = video_tmp;
    return video_tmp;
}
shared_ptr<Multimedia> Manager::createFilm(string name, string fileName, int duration, int numberChapters) {
    shared_ptr<Film> film_tmp(new Film(fileName, fileName, duration, numberChapters));
    multimedia_table[name] = film_tmp;
    return film_tmp;
}
shared_ptr<Group> Manager::createGroup(string name) {
    group_table[name] = shared_ptr<Group>(new Group(name));
    return group_table[name];
}




shared_ptr<Multimedia> Manager::findMultimedia(string name) {
    auto it = multimedia_table.find(name);
    if(it == multimedia_table.end())
        return nullptr;
    else
        return it->second;
}


shared_ptr<Group> Manager::findGroup(string name) {
    auto it = group_table.find(name);
    if(it == group_table.end())
        return nullptr;
    else
        return it->second;
}


void Manager::printVariables(string name, ostream& stream_out) {
    auto multimedia = findMultimedia(name);
    if(multimedia == nullptr) {
        cerr << "Error can't find " << name  << " in multimedia_table " << endl;
        return;
    }
    multimedia->printVariables(stream_out);
}

void Manager::play(string name) {
    auto multimedia = findMultimedia(name);
    if(multimedia == nullptr) {
        cerr << "Error can't find " << name  << " in multimedia_table " << endl;
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
bool Manager::processRequest(TCPConnection& cnx, const string& request, string& response) {

    cerr << "\nRequest: '" << request << "'" << endl;

    // 1) pour découper la requête:
    // on peut par exemple utiliser stringstream et getline()
    stringstream stream, response_stream;
    stream << request;

    string operation, target;
    stream >> operation >> target;


    // 2) faire le traitement:
    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);

    // 3) retourner la reponse au client:
    // - pour retourner quelque chose de plus utile on peut appeler la methode print()
    //   des objets ou des groupes en lui passant en argument un stringstream
    // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
    //   ils servent à délimiter les messages entre le serveur et le client
    // - dans notre cas on a mis des "||" dans printVariables qu'il faudra
    //   convertir en "\n" côté client pour un meilleur affichage.


    TCPLock lock(cnx);

    if(operation == "SEARCH") {
        shared_ptr<Multimedia> result = findMultimedia(target);
        if(result == nullptr) {
            response = "No multimedia found with name : " + target;
        }
        else {
            result->printVariables(response_stream);
            response = response_stream.str();
        }
    }
    else if(operation == "PLAY") {
        shared_ptr<Multimedia> result = findMultimedia(target);
        if(result == nullptr) {
            response = "No multimedia found with name : " + target;
        }
        else {
            result->play();
            response = "Running " + target + " on server !";
        }
    }
    else if(operation == "QUIT") {
        response = "See you soon :)!";
        return false;
    }
    else {
        // opération incompréhensible
        response = "Couldn't understand your request :-( ! Please try again";
    }
//    response = "OK: " + request;
    cerr << "response: " << response << endl;

    // renvoyer false si on veut clore la connexion avec le client
    return true;
}
