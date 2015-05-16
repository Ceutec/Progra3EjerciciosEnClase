#include <iostream>

using namespace std;

template <typename Tipo1,typename Tipo2>
Tipo2 sumar(Tipo1 v1, Tipo2 v2)
{
    return v1 + v2;
}

int main()
{
    int n2 = 10;
    float n1 = 20.5;
    cout<<sumar(n1,n2)<<endl;

    return 0;
}
