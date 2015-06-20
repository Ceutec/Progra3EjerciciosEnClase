#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Ejemplo
{
public:
    string str;
    int num;
    Ejemplo(string str, int num)
    {
        this->str = str;
        this->num = num;
    }
    Ejemplo(string str)
    {
        this->str = str;
    }
};

int main()
{
    cout<<"Map"<<endl;
    map<float,bool>mi_mapa;
    mi_mapa[32.1]=true;
    mi_mapa[43.23]=false;
    mi_mapa[43.23]=true;
    mi_mapa[53.1]=false;
    cout<<mi_mapa[32.1]<<endl;
    cout<<mi_mapa[43.23]<<endl;
    cout<<mi_mapa[53.1]<<endl;

    for(map<float,bool>::iterator i = mi_mapa.begin();
        i!=mi_mapa.end();
        i++)
        cout<<(*i).first<<","<<(*i).second<<endl;

    cout<<"Multimap"<<endl;
    multimap<string,int>mi_multimapa;
    mi_multimapa.insert(pair<string,int>("A",10));
    mi_multimapa.insert(pair<string,int>("B",20));
    mi_multimapa.insert(pair<string,int>("C",30));
    mi_multimapa.insert(pair<string,int>("A",40));

    for(multimap<string,int>::iterator i = mi_multimapa.begin();
        i!=mi_multimapa.end();
        i++)
        cout<<(*i).first<<","<<(*i).second<<endl;


////    Vector
//    cout<<"Vector"<<endl;
//    vector<int>mi_vector;
//    mi_vector.push_back(10);
//    mi_vector.push_back(20);
//    mi_vector.push_back(30);
//    for(int i=0;i<mi_vector.size();i++)
//    {
//        cout<<mi_vector[i]<<endl;
//    }

////    List
//    cout<<"List"<<endl;
//    list<string>mi_lista;
//    mi_lista.push_back("A");
//    mi_lista.push_back("B");
//    mi_lista.push_back("C");
//    mi_lista.push_front("X");
//    mi_lista.insert(mi_lista.begin(),"Y");
//
//    for(list<string>::iterator i=mi_lista.begin();
//        i!=mi_lista.end();
//        i++)
//        cout<<*i<<endl;


////    Set
//    multiset<int>mi_set;
//    mi_set.insert(20);
//    mi_set.insert(10);
//    mi_set.insert(30);
//    mi_set.insert(10);
//    mi_set.insert(30);
//    mi_set.insert(30);
//
//    if(mi_set.find(10)!=mi_set.end())
//        cout<<"El 10 existe"<<endl;
//
//    if(mi_set.find(30)!=mi_set.end())
//        cout<<"El 30 existe"<<endl;
//
//    if(mi_set.find(40)!=mi_set.end())
//        cout<<"El 40 existe"<<endl;
//
//    for(multiset<int>::iterator i=mi_set.begin();
//        i!=mi_set.end();
//        i++)
//    {
//        cout<<*i<<endl;
//    }


////    Stack
//    stack<char>mi_stack;
//    mi_stack.push('a');
//    mi_stack.push('b');
//    mi_stack.push('c');
//
//    int tam=mi_stack.size();
//
//    for(int i=0;i<tam;i++)
//    {
//        cout<<mi_stack.top()<<endl;
//        mi_stack.pop();
//    }

////    Queue
//    queue<Ejemplo*>mi_cola;
//    mi_cola.push(new Ejemplo("A",10));
//    mi_cola.push(new Ejemplo("B",20));
//    mi_cola.push(new Ejemplo("C",30));
//    mi_cola.push(new Ejemplo("D"));
//
//    while(!mi_cola.empty())
//    {
//        cout<<mi_cola.front()->str<<endl;
//        cout<<mi_cola.front()->num<<endl;
//        mi_cola.pop();
//    }

    return 0;
}
