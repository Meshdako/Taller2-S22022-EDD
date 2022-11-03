#ifndef COLA_H
#define COLA_H

#include <queue>
template <class Tipo>
class Cola : private std::queue<Tipo>{
    public:
        Cola(){};
        void agregar(Tipo _valor);
        Tipo extraer();
        bool vacio();
    protected:

    private:
};

template <class Tipo>
void Cola<Tipo>::agregar(Tipo _valor){
   std::queue<Tipo>::push(_valor);
}

template <class Tipo>
Tipo Cola<Tipo>::extraer(){
    Tipo aux;
    aux = std::queue<Tipo>::front();
    std::queue<Tipo>::pop();
    return aux;
}

template <class Tipo>
bool Cola<Tipo>::vacio(){
    return std::queue<Tipo>::empty();
}



#endif