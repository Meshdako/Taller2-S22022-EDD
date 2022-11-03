#include "Persona.h"

Persona::Persona()
{
    nombres = "-";
    paterno = "-";
    materno = "-";
}

Persona::Persona(string names, string f_name, string m_name, RUN su_rut, Fecha su_fecha, Direccion su_direccion)
{
    nombres = names;
    paterno = f_name;
    materno = m_name;
    miRUN = su_rut;
    miFecha = su_fecha;
    miDireccion = su_direccion;
}

void Persona::verPersona()
{
    cout << "*********" << endl;
    cout << "Nombres: " << nombres << endl;
    cout << "Apellido paterno: " << paterno << endl;
    cout << "Apellido materno: " << materno << endl;
    miRUN.verRun();
    miFecha.verFecha();
    miDireccion.verDireccion();
}