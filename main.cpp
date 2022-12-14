/**
 * @author Martín Sobarzo Huerta (MESH)
 * 5/11/2022
 * Estructura de Datos
 * Mauro Castillo
*/

#include <iostream>

#include "Funciones.h"
#include "Funciones.cpp"

//Clases
#include "Clases/Direccion.h"
#include "Clases/Direccion.cpp"
#include "Clases/Fecha.h"
#include "Clases/Fecha.cpp"
#include "Clases/Run.h"
#include "Clases/Run.cpp"
#include "Clases/Persona.h"
#include "Clases/Persona.cpp"
#include "Clases/Elector.h"
#include "Clases/Elector.cpp"

//TAD
#include "TAD/Cola.h"
#include "TAD/Stack.h"

using namespace std;

#define MAX_VECTOR 1000

int main()
{
    int indice = 0; //indice del vector  o cantidad actual de elementos en el vector
    string nombreArchivo ="servel.txt";
    
    Elector Electores[MAX_VECTOR];

    Cola<Elector> Cola_Electores;

    archivoAVector(nombreArchivo, Electores, indice);
    arregloACola(Cola_Electores, Electores, indice);
    //mostrarCola(Cola_Electores);

    Menu(Cola_Electores);

    return 0;
}