#include <iostream>

using namespace std;

class Nodo
{
public:
    int valor;
    Nodo* hijo_izq;
    Nodo* hijo_der;

    Nodo(int valor)
    {
        this->valor=valor;
        this->hijo_izq=NULL;
        this->hijo_der=NULL;
    }
};

class Arbol
{
public:
    Nodo* raiz;

    Arbol()
    {
        Nodo* n1=new Nodo(1);
        Nodo* n2=new Nodo(2);
        Nodo* n3=new Nodo(3);
        Nodo* n4=new Nodo(4);
        Nodo* n5=new Nodo(5);
        Nodo* n6=new Nodo(6);

        n1->hijo_izq=n2;
        n1->hijo_der=n3;
        n2->hijo_izq=n4;
        n2->hijo_der=n5;
        n3->hijo_izq=n6;

        raiz=n1;
    }

    void imprimir(Nodo* raiz)
    {
        if(raiz==NULL)
            return;
        cout<<raiz->valor<<endl;
        imprimir(raiz->hijo_izq);
        imprimir(raiz->hijo_der);
    }
};

int main()
{
    Arbol a;
    a.imprimir(a.raiz);
    return 0;
}
