#include "multimedia.h"

Multimedia::Multimedia()
{

}


void Multimedia::printVariables(ostream &flux) const {
    flux << "-----------------------------" << endl;
    flux << "Printing variables" << endl;
    flux << "-----------------------------" << endl;
    flux << "name : " << name << endl;
    flux << "fileName : " << fileName << endl;
}
