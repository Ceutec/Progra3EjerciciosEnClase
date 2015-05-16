#include <iostream>

using namespace std;

int main()
{
    float notas[3];

    for(int i=0; i<3; i++)
    {
        cout<<"Ingrese nota ";
        cout<<i;
        cout<<": ";
        cin>>notas[i];
    }

    float promedio = 0;

    for(int i=0; i<3; i++)
    {
        promedio = promedio + notas[i];
    }

    promedio = promedio/3;

    cout<<"El promedio es: "<<promedio<<endl;

    return 0;
}


//int main()
//{
//    int a;
//    int b;
//    cout<<"Ingrese a: ";
//    cin>>a;
//    cout<<"Ingrese b: ";
//    cin>>b;
//    cout<<"a + b = "<<a+b;
//
//    return 0;
//}
