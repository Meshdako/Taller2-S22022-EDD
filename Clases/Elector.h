#ifndef ELECTOR_H
#define ELECTOR_H

#include <iostream>

using namespace std;

class Elector
{
    private:
        string Nombre;
    public:
        //Constructor
        Elector();

        //Sets
        void setNombre(string x){Nombre = x;}

        //Gets
        string getNombre(){return Nombre;}

        void verElector();
};

#endif //ELECTOR_H