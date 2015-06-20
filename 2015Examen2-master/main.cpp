// queue::push/pop

#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Planeta.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Planeta*planeta, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    out.seekp(43*posicion);
    out.write(planeta->nombre.c_str(),30);
    out.write((char*)&planeta->habitantes,4);
    out.write((char*)&planeta->diametro,8);
    out.write((char*)&planeta->categoria,1);
    out.close();
}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Planeta* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    char nombre[30];
    int habitantes;
    double diametro;
    char categoria;

    in.seekg(43*posicion);

    in.read(nombre,30);
    in.read((char*)&habitantes,4);
    in.read((char*)&diametro,8);
    in.read((char*)&categoria,1);

    in.close();

    Planeta *p = new Planeta(nombre, habitantes, diametro, categoria);
    return p;
}

//Devuelve el primer valor fue ingresado en mi_pila (dada)
//Nota: devuelve el valor mas viejo
string getFondo(stack<string> mi_pila)
{
    string resultado;
    return resultado;
}

//Devuelve el ultimo valor que fue ingresado en mi_cola (dada)
//Nota: devuelve el valor mas nuevo
char getUltimo(queue<char> mi_cola)
{
    char resultado;
    return resultado;
}

//Dado una lista, devuelve un vector que contenga los datos de la lista en el mismo orden
vector<int> convertirAVector(list<int> mi_lista)
{
    vector<int> mi_vector;
    return mi_vector;
}

//Dado un numero, devuelve un mapa que contenga su tabla de multiplicacion
//Ejemplo:
//Dado num = 5
//Devuelve el siguiente mapa
//{1=>5,2=>10,3=>15,4=>20,5=>25,6=>30,7=>35,8=>40,9=>45,10=>50}
map<int,int> getTabla(int num)
{
    map<int,int> mi_mapa;
    for(int i=1;i<=10;i++)
        mi_mapa[i]=i*num;
    return mi_mapa;
}

//Dado un arbol con raiz dada, devuelve un set que contenga todos los valores almacenados en el arbol
//Nota los valores estan almacendados en el atributo valor en la clase NodoBinario
set<string> getValores(NodoBinario* raiz)
{
    set<string> mi_set;
    return mi_set;
}

//Dado un arbol con raiz dada, busca el nodo que contenga el valor buscado (dado) y lo reemplaza con la variable reemplazo (dada)
//Nota los valores estan almacendados en el atributo valor en la clase NodoBinario
void buscarYReemplazar(NodoBinario* raiz, string buscado, string reemplazo)
{
    if(raiz==NULL)
        return;

    if(raiz->valor==buscado)
        raiz->valor=reemplazo;

    buscarYReemplazar(raiz->hijo_izq,buscado,reemplazo);
    buscarYReemplazar(raiz->hijo_der,buscado,reemplazo);
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

