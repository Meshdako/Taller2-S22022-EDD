#ifndef STACK_H
#define STACK_H

using namespace std;
#include <stack>
template <class Tipo>
class Stack : private stack<Tipo> {
public:
    void push(Tipo t){
        stack<Tipo>::push(t);
    }

    Tipo pop(){
        Tipo temp = stack<Tipo>::top();
        stack<Tipo>::pop();
        return temp;
    }

    bool empty(){
        return stack<Tipo>::empty();
    }
};


#endif