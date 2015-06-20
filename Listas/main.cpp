#include <iostream>

using namespace std;

template<typename Tipo>
class Nodo
{
public:
    Tipo valor;
    Nodo<Tipo>* siguiente;

    Nodo(Tipo valor)
    {
        this->valor=valor;
        this->siguiente=NULL;
    }
};

template<typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;
    Lista()
    {
        inicio=NULL;
    }
    void agregar(Tipo valor)
    {
        Nodo<Tipo>* nuevo=new Nodo<Tipo>(valor);
        if(inicio==NULL)//Si la lista esta vacia
        {
            inicio = nuevo;
        }else//Si no esta vacia
        {
            //me voy al final
            Nodo<Tipo>*iterador=inicio;
            while(iterador->siguiente!=NULL)
            {
                iterador=iterador->siguiente;
            }
            //lo enlazo con el ultimo
            iterador->siguiente=nuevo;
        }
    }
    void imprimir()
    {
        for(Nodo<Tipo>* iterador=inicio;
            iterador!=NULL;
            iterador=iterador->siguiente)
        {
            cout<<iterador->valor<<endl;
        }
    }
};

int main()
{
    Lista<string> l;
    l.agregar("Hola");
    l.agregar("Mundo");
    l.agregar("Ejemplo");
    l.imprimir();

    Lista<int> l2;
    l2.agregar(5);
    l2.agregar(21);
    l2.agregar(2);
    l2.imprimir();

    return 0;
}
