#include <iostream>     //utilizada para la entrada y salida de datos
#include <fstream>      //relacionada al manejo de archivos
#include <sstream>      //relacionada a string stream https://www.cplusplus.com/reference/sstream/
#include <vector>       //relacionada al manejo de vectores dinámicos
#include <limits>       //relacionada a los límites de valores

//Clases
#include "Clases/Direccion.h"
#include "Clases/Fecha.h"
#include "Clases/Run.h"
#include "Clases/Persona.h"
#include "Clases/Elector.h"

//TAD
#include "TAD/Cola.h"
#include "TAD/Stack.h"

using namespace std;

//Implementa correctamente una función que recibe una Cola y un run, y muestra en pantalla todos los datos del elector.
void ConsultaXRun(Cola<Elector> &C, int in_Run);

//Implementa correctamente una función que recibe una Cola y un string y retorna un Stack con la lista de electores de dicha comuna.
Stack<Elector> ElectoresXComuna(Cola<Elector> &C, string in_Comuna);

//Muestra en pantalla el número de electores que hayan nacido en el año que indique el usuario.
void RunXAnhio(Cola<Elector> &C, int in_Anhio);

//implementa correctamente una función que recibe una cola y un carácter, y retorna un Stack con los electores que se encuentran inhabilitados para sufragar cuyo apellido paterno comience con el carácter indicado.
Stack<Elector> InhabilitadosXLetra(Cola<Elector> &C, char in_Letra);

/**
 * Implementa correctamente las funciones necesarias para mostrar los siguientes datos en pantalla:
 * total de electores
 * total de electores cuyo año de nacimiento es mayor a 2002
 * total de electores habilitados para votar mayores de 35 años
 * total de vocales de mesa de la comuna de Macul.
*/
void Totalizador(Cola<Elector> &C);

//Menú que despliega todas las funciones de forma ordenada.
void Menu();

//Función que muestra una pila.
void mostrarPila(Stack<Elector> &S);

//Función que muestra la Cola, sin modificarla.
void mostrarCola(Cola<Elector> &C);

//Función que pasa un arreglo a una Cola.
void arregloACola(Cola<Elector> &C, Elector p[], int indice);

//Función que lee el archivo "servel" y guarda la información en un arreglo.
void archivoAVector(string nombreArchivo, Elector p[] , int &indice);

//Función que guarda la información de una línea en un vector, mediante un caracter delimitador.
vector<string> split(string lineaASeparar, char delimitador);