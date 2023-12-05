#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char nama[100];
    int i;

    cout << "Masukkan kalimat : ";
    cin.getline(nama, 100);

    cout << endl;

    cout << "Kalimatnya adalah : " << nama << endl;
    cout << "Kebalikannya adalah : ";
    for (i = strlen(nama); i >= 0; i--)
    {
        cout << nama[i];
    }
}