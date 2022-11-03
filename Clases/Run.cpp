#include "Run.h"

RUN::RUN()
{
    suRun = 0;
    dv = ' ';
}

RUN::RUN(long su_rut, char digito)
{
    suRun = su_rut;
    dv = digito;
}

void RUN::verRun()
{
    cout << "RUN: " << suRun  << "-" << dv << endl;
}