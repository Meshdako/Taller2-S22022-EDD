#ifndef NOMBRE_H
#define NOMBRE_H

#include <iostream>

using namespace std;

class Nombre
{
    private:
        string nombres;
        string paterno;
        string materno;
    public:
        //Constructor
        Nombre();
        Nombre(string, string, string);

        //Sets
        void setNombres(string x){nombres = x;}
        void setPaterno(string x){paterno = x;}
        void setMaterno(string x){materno = x;}

        //Gets
        string getNombres(){return nombres;}
        string getPaterno(){return paterno;}
        string getMaterno(){return materno;}

        void verNombres();
};

#endif  //NOMBRE_h