#include <iostream>

using namespace std;

class Clase
{
public:

    Clase(int parametro)
    {
        cout<<"Constructor"<<endl;
    }

    ~Clase()
    {
        cout<<"Destructor"<<endl;
    }

    int atributo;
    void funcion()
    {
        cout<<"mi funcion"<<endl;
    }
};

int main()
{
//    Clase clase(10);
//    new Clase(20);
//    Clase *ptr_clase = new Clase(30);

    cout<<"A"<<endl;
    Clase *clase;
    if(true)
    {
        clase = new Clase(10);
        cout<<"B"<<endl;
    }
    cout<<"C"<<endl;
    delete clase;




//    Clase clase;
//    Clase clase2;
//
//    clase.atributo = 10;
//    clase2.atributo = 20;
//
//    cout<<clase.atributo<<endl;
//    cout<<clase2.atributo<<endl;
//
//
//
//
//
//    Clase *ptr_clase = new Clase();
//
//    (*ptr_clase).atributo = 10;
//    cout<<(*ptr_clase).atributo<<endl;
//
//    ptr_clase->atributo = 10;
//    cout<<ptr_clase->atributo<<endl;

    return 0;
}








