#include "Funciones.h"

//Funciones


//Menú de selección.
void Menu()
{
    int opcion;

    do{
        system("clear");

        cout << "\e1[mSeleccione una opción:\e[0m" << endl;
        cout << "1.- Búsqueda por RUT." << endl;
        cout << "2.- Búsqueda por Comuna." << endl;
        cout << "3.- Búsqueda por Año." << endl;
        cout << "4.- Búsqueda de inhabilitados para sufragar por Letra (Apellido Paterno)." << endl;
        cout << "5.- Totalizador" << endl;
        cout << "0.- Salir" << endl;
        cout << ">>  " << endl;
        cin >> opcion;
        cin.ignore(5, '\n');

        switch(opcion){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                cout << "Seleccione una opción válida." << endl;
                break;
        }
    }while(opcion != 0);
}

void mostrarPila(Stack<Elector> &S)
{
    //Terminar.
}

void mostrarCola(Cola<Elector> &C)
{
    Cola<Elector> Cola_Aux;
    while(!C.vacio()){
        Elector Aux = C.extraer();
        Aux.verElector();

        Cola_Aux.agregar(Aux);    
    }

    //Volvemos a rellenar la cola.
    while(!Cola_Aux.vacio()){
        Elector Aux = Cola_Aux.extraer();

        C.agregar(Aux);    
    }
    
    cout << "Toda la cola mostrada." << endl;
}

void arregloACola(Cola<Elector> &C, Elector p[], int indice)
{
    for(int i = 0; i < indice; i++){
        C.agregar(p[i]);
    }
}

void archivoAVector(string nombreArchivo, Elector p[] , int &indice){
    ifstream archivo;
    string lineaObtenida;
    string palabra;

    archivo.open(nombreArchivo, ios::in);
    
    if(archivo.is_open() == true) {
        while( getline(archivo, lineaObtenida, '\n')){
            //ahora recorremos la línea
            vector<string> data = split(lineaObtenida, ';');

            if(indice > 0) {
                RUN Run_Aux(stol(data[0]), data[1].front());

                Fecha Fecha_Aux(stoi(data[5]), stoi(data[6]), stoi(data[7]));
                
                Direccion Dir_Aux(data[8], stoi(data[9]), data[10]);
                
                Elector Elector_Aux(data[2], data[3], data[4], Run_Aux, Fecha_Aux, Dir_Aux, stoi(data[11]), stoi(data[12]), stoi(data[13]));

                p[indice] = Elector_Aux;
            }
            indice++;
        }
    }
    archivo.close();
}

vector<string> split(string lineaASeparar, char delimitador) {
    vector<string> vector_interno;      //#include <vector>
    stringstream linea(lineaASeparar);  //#include <sstream>
    string parteDelString;

    while(getline(linea, parteDelString, delimitador))
        vector_interno.push_back(parteDelString);

    return vector_interno;
}