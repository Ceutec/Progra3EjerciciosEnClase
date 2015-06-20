#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string nombre_archivo;
    cout<<"Ingrese el nombre de la agenda: ";
    cin>>nombre_archivo;

    int opcion;
    do
    {
        cout<<"Menu"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"1. Ingresar contacto"<<endl;
        cout<<"2. Imprimir agenda"<<endl;
        cout<<"3. Editar contacto"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        string contacto;
        int numero;
        int posicion;
        ofstream out;
        ifstream in;
        char* contacto_leido;
        int* numero_leido;
        int tamano;
        switch(opcion)
        {
            case 1:
                cout<<"Contacto: "<<endl;
                cin>>contacto;
                cout<<"Numero: "<<endl;
                cin>>numero;

                out.open(nombre_archivo.c_str(),ios::app);
                out.write(contacto.c_str(),10);
                out.write((char*)&numero,4);
                out.close();

            break;
            case 2:
                cout<<"Lista de contactos: "<<endl;
                in.open(nombre_archivo.c_str());
                contacto_leido=new char[10];
                numero_leido=new int;


                in.seekg(0,ios::end);
                tamano = in.tellg()/14;
                in.seekg(0,ios::beg);

                for(int i=0;i<tamano;i++)
                {
                    in.read(contacto_leido,10);
                    in.read((char*)numero_leido,4);
                    cout<<contacto_leido<<","<<*numero_leido<<endl;
                }
            break;
            case 3:
                cout<<"Posicion: "<<endl;
                cin>>posicion;
                cout<<"Contacto: "<<endl;
                cin>>contacto;
                cout<<"Numero: "<<endl;
                cin>>numero;
                out.open(nombre_archivo.c_str(),ios::in);
                out.seekp(posicion*14,ios::beg);
                out.write(contacto.c_str(),10);
                out.write((char*)&numero,4);
                out.close();

            break;
        }

    }while(opcion!=0);

    return 0;
}
