#include <iostream>
#include <vector>

using namespace std;

class Personaje
{
public:
    int ataque;
    int vida;
    string tipo;

    Personaje()
    {
        tipo="Personaje";
    }

    virtual void poderEspecial()=0;
};

class Guerrero : public Personaje
{
public:

    Guerrero()
    {
        tipo="Guerrero";
    }

    void poderEspecial()
    {
        cout<<"Wraahhh"<<endl;
    }
};

class Arquero : public Personaje
{
public:

    Arquero()
    {
        tipo="Arquero";
    }

    int flechas;
    void poderEspecial()
    {
        cout<<"Swoosh"<<endl;
    }
};

class Mago : public Personaje
{
public:

    Mago()
    {
        tipo="Mago";
    }

    void poderEspecial()
    {
        cout<<"Pirrin!"<<endl;
    }
};

int main()
{
    vector<Personaje*>personajes;
    personajes.push_back(new Guerrero());
    personajes.push_back(new Arquero());
    personajes.push_back(new Mago());
    personajes.push_back(new Mago());
    personajes.push_back(new Guerrero());

    for(int i=0;i<personajes.size();i++)
    {
        personajes[i]->poderEspecial();
    }


//    for(int i=0;i<personajes.size();i++)
//    {
//        if(personajes[i]->tipo=="Guerrero")
//        {
//            Guerrero* guerrero = (Guerrero*)personajes[i];
//            guerrero->poderEspecial();
//        }
//        if(personajes[i]->tipo=="Arquero")
//        {
//            Arquero* arquero = (Arquero*)personajes[i];
//            arquero->poderEspecial();
//        }
//        if(personajes[i]->tipo=="Mago")
//        {
//            Mago* mago = (Mago*)personajes[i];
//            mago->poderEspecial();
//        }
//    }

    return 0;
}




