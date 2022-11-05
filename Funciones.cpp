#include "Funciones.h"

//Funciones
void PressEnterToContinue()
{
    cout << "Presiona Enter para continuar... " << flush;
    cin.ignore(numeric_limits <std::streamsize> ::max(), '\n' ); 
}

void ConsultaXRun(Cola<Elector> &C, int in_Run)
{
    system("clear");  

    cout << "Buscando RUT solicitado..." << endl; 

    Cola<Elector> C_Aux;

    //Vacíamos la Cola Original en la Cola Auxiliar
    while(!C.vacio()){
        Elector El_Aux = C.extraer();
        C_Aux.agregar(El_Aux);
        
        if(in_Run == El_Aux.getRUN().getRun())
            El_Aux.verElector();
    }

    //Regresamos los datos a la Cola Original.
    while(!C_Aux.vacio()){
        C.agregar(C_Aux.extraer());
    }
    PressEnterToContinue();
}

Stack<Elector> ElectoresXComuna(Cola<Elector> &C, string in_Comuna)
{
    system("clear");  

    cout << "Buscando electores por comuna ingresada..." << endl; 
    
    
    Cola<Elector> C_Aux;
    Stack<Elector> S_Aux;

    for(int i = 0; !C.vacio(); i++){
        Elector El_Aux = C.extraer();
        C_Aux.agregar(El_Aux);

        if(in_Comuna == El_Aux.getDireccion().getComuna())
            S_Aux.push(El_Aux);
    }

    //Regresamos los datos a la Cola Original.
    while(!C_Aux.vacio()){
        C.agregar(C_Aux.extraer());
    }

    return S_Aux;
}

//Menú de selección.
void Menu(Cola<Elector> &C)
{
    int opcion;

    int in_Run;
    string in_Comuna;
    
    Stack<Elector> Pila;
    do{
        system("clear");
        cout << "\e[1mSeleccione una opción:\e[0m" << endl;
        cout << "1.- Búsqueda por RUT." << endl;
        cout << "2.- Búsqueda por Comuna." << endl;
        cout << "3.- Búsqueda por Año." << endl;
        cout << "4.- Búsqueda de inhabilitados para sufragar por Letra (Apellido Paterno)." << endl;
        cout << "5.- Totalizador" << endl;
        cout << "0.- Salir" << endl;
        cout << ">>  ";
        cin >> opcion;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

        switch(opcion){
            case 1:
                cout << "Ingrese el RUT que desea buscar: ";
                cin >> in_Run;
                cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

                ConsultaXRun(C, in_Run);
                break;
            case 2:
                cout << "Ingrese la Comuna que desea buscar: ";
                getline(cin >> ws, in_Comuna);

                Pila = ElectoresXComuna(C, in_Comuna);
                mostrarPila(Pila);
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
    while(!S.empty()){
        Elector Aux = S.pop();
        Aux.verElector();
    }

    if(S.empty())
        cout << "Pila vaciada" << endl;
    PressEnterToContinue();
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