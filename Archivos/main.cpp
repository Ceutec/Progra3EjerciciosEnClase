#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("archivo");

    string str;

    while(in>>str)
    {
        cout<<"->"<<str<<endl;
    }


    return 0;
}





