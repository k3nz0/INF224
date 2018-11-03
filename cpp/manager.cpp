#include "manager.h"


Manager::Manager()
{

}

/**
 * @brief Manager::createPhoto
 * @param name
 * @param fileName
 * @param latitude
 * @param longitude
 * @return
 */
shared_ptr<Photo> Manager::createPhoto(string name, string fileName, double latitude, double longitude) {
    shared_ptr<Photo> photo_tmp(new Photo(fileName, fileName, latitude, longitude));
    multimedia_table[name] = photo_tmp ;
    return photo_tmp;
}

/**
 * @brief Manager::createVideo
 * @param name
 * @param fileName
 * @param duration
 * @return
 */

shared_ptr<Multimedia> Manager::createVideo(string name, string fileName, int duration) {
    shared_ptr<Video> video_tmp(new Video(name, fileName, duration));
    multimedia_table[name] = video_tmp;
    return video_tmp;
}

/**
 * @brief Manager::createFilm
 * @param name
 * @param fileName
 * @param duration
 * @param numberChapters
 * @return
 */
shared_ptr<Multimedia> Manager::createFilm(string name, string fileName, int duration, int numberChapters) {
    shared_ptr<Film> film_tmp(new Film(fileName, fileName, duration, numberChapters));
    multimedia_table[name] = film_tmp;
    return film_tmp;
}
/**
 * @brief Manager::createGroup
 * @param name
 * @return
 */
shared_ptr<Group> Manager::createGroup(string name) {
    group_table[name] = shared_ptr<Group>(new Group(name));
    return group_table[name];
}


/**
 * @brief Manager::findMultimedia
 * @param name
 * @return
 */

shared_ptr<Multimedia> Manager::findMultimedia(string name) {
    auto it = multimedia_table.find(name);
    if(it == multimedia_table.end())
        return nullptr;
    else
        return it->second;
}

/**
 * @brief Manager::findGroup
 * @param name
 * @return
 */

shared_ptr<Group> Manager::findGroup(string name) {
    auto it = group_table.find(name);
    if(it == group_table.end())
        return nullptr;
    else
        return it->second;
}

/**
 * @brief Manager::printVariables
 * @param name
 * @param stream_out
 */

void Manager::printVariables(string name, ostream& stream_out) {
    auto multimedia = findMultimedia(name);
    if(multimedia == nullptr) {
        cerr << "Error can't find " << name  << " in multimedia_table " << endl;
        return;
    }
    multimedia->printVariables(stream_out);
}


/**
 * @brief Manager::play given the name of the multimedia, it runs the play
 * @param name
 */

void Manager::play(string name) {
    auto multimedia = findMultimedia(name);
    if(multimedia == nullptr) {
        cerr << "Error can't find " << name  << " in multimedia_table " << endl;
        return;
    }
    multimedia->play();
}

/**
 * @brief Manager::listAllMultimedia
 * @return
 */

string Manager::listAllMultimedia() {
    string result = "";
    for(auto &e: multimedia_table) {
        result += "-------------------------------------||";
        result += "Name : '" + e.first + "'" + "|| Type : " +  e.second->getType() + "||";
    }
    return result;
}

/**
 * @brief Manager::processRequest Process sockets requets
 * @param cnx
 * @param request
 * @param response
 * @return
 */

bool Manager::processRequest(TCPConnection& cnx, const string& request, string& response) {

    cerr << "\nRequest: '" << request << "'" << endl;

    stringstream stream, response_stream;
    stream << request;

    string operation, target;
    stream >> operation >> target;

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
    else if(operation == "LIST") {
        response = listAllMultimedia();
    }
    else if(operation == "QUIT") {
        response = "See you soon :)!";
        return false;
    }
    else {
        response = "Couldn't understand your request :-( ! Please try again";
    }
    cerr << "response: " << response << endl;

    // renvoyer false si on veut clore la connexion avec le client
    return true;
}
