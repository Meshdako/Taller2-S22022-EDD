#include "Funciones.h"

#define MAX_VECTOR 1000

int indice = 0; //indice del vector  o cantidad actual de elementos en el vector
Direccion direcciones[MAX_VECTOR]; 
string nombreArchivo ="servel_pruebas.txt";

/**
 * @fn leerArchivoYPasarAlVector()
 * @brief Permite leer un archivo y pasarlos hacia un vector
 * @param Asistente[] vector con datos de algún tipo 
 * @param int valor por referencia que se incrementa en base a los datos leídos del vector
 * @return nada
 */
void archivoAVector(string nombreArchivo, Direccion p[] , int &indice){
    ifstream archivo;
    string lineaObtenida;
    string palabra;

    archivo.open(nombreArchivo, ios::in);
    
    if(archivo.is_open() == true) {
        while( getline(archivo, lineaObtenida, '\n')){
            //ahora recorremos la línea
            vector<string> data = split(lineaObtenida, ';');
            cout <<data[0]<<" "<<data[1]<<" "<<data[2]<<" "<<data[3]<<" "<<data[4]<<" ";
            cout <<data[5]<<" "<<data[6]<<" "<<data[7]<<" "<<data[8]<<" "<<data[9]<<" ";
            cout <<data[10]<<" "<<data[11]<<" "<<data[12]<<" "<<data[13]<<" "<<data[14]<<" "<<endl;
            if(indice > 0) {
                p[indice].setCalle( data[10] );
            }
            indice++;
        }
    }
    archivo.close();
}

/**
 * @fn split()
 * @brief Realiza la separación de un string en base a un caracter indicado 
 * @param string una frase cualquiera que deseamos separar en partes
 * @param char es el caracter que utilizaremos para separar el string en partes
 * @return retorna un vector dinámico con las partes del string ingresado
 */
vector<string> split(string lineaASeparar, char delimitador) {
    vector<string> vector_interno;      //#include <vector>
    stringstream linea(lineaASeparar);  //#include <sstream>
    string parteDelString;

    while(getline(linea, parteDelString, delimitador))
        vector_interno.push_back(parteDelString);

    return vector_interno;
}