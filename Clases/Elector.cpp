#include "Elector.h"

Elector::Elector()
{
    int Sufragar = 0;
    int Vocal = 0;
    int Mesa = 0;    
}

Elector::Elector(string names, string f_name, string m_name, RUN su_rut, Fecha su_fecha, Direccion su_direccion, int habilitado, int es_vocal, int su_mesa) : Persona(names, f_name, m_name, su_rut, su_fecha, su_direccion)
{
    int Sufragar = habilitado;
    int Vocal = es_vocal;
    int Mesa = su_mesa;
}

void Elector::verElector()
{
    verPersona();
    cout << "¿Está habilitado para sufragar? ";
    (Sufragar == 1) ? cout << "Sí" << endl : cout << "No" << endl;
    
    cout << "¿Es vocal de mesa? ";
    (Vocal == 1) ? cout << "Sí" << endl : cout << "No" << endl;
    
    cout << "Mesa de votación: ";
    (Mesa == 1) ? cout << "Sí" << endl : cout << "No" << endl;
}