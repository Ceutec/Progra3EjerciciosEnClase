#include <iostream>

using namespace std;

class Numero
{
public:
    int num;
    Numero(int num)
    {
        this->num = num;
    }
    int operator+(int num)
    {
        return this->num + num;
    }
};

int main()
{
    Numero n(10);

    cout<<n+20<<endl;

    return 0;
}
