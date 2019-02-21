#include <iostream>
#include <fstream>

using namespace std;

#define PI 3.1415926
#define concat(a, b)  a ##  b
#define str(a) #a

int main()
{
    fstream file;
    file.open("nice.dat", ios::out|ios::trunc);
    file << "Wow, this is wonderful!" << endl;
    file.close();

    string data;
    file.open("nice.dat", ios::in);

    while(file >> data){
        /* code */
        cout << data << endl;
    }

    file.close();

    cout << "Value of PI :" << str(concat(P, I)) << endl;

}