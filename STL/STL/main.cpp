#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int>mi_vector;
    mi_vector.push_back(10);
    mi_vector.push_back(20);
    mi_vector.push_back(30);

    for(int i=0;i<3;i++)
        cout<<mi_vector[i]<<endl;


    list<int>mi_lista;
    mi_lista.push_back(543);
    mi_lista.push_back(643);
    mi_lista.push_back(24);
    mi_lista.erase(mi_lista.begin());

    for(list<int>::iterator i = mi_lista.begin();
        i!=mi_lista.end();
        i++)
    {
        cout<<*i<<endl;
    }

    return 0;
}
