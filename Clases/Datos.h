#ifndef DATOS_H
#define DATOS_H

class Datos
{
    private:
        int HaPaSufragar;
        int VocalMesa;
        int MesaVotacion;
    public:
        //Constructor
        Datos();
        Datos(int, int, int);

        //Sets
        void setSufragar(int x){HaPaSufragar = x;}
        void setVocal(int x){VocalMesa = x;}
        void setMesa(int x){MesaVotacion = x;}

        //Gets
        int getSufragar(){return HaPaSufragar;}
        int getVocal(){return VocalMesa;}
        int getMesa(){return MesaVotacion;}

        void verDatos();
};

#endif  //DATOS_H