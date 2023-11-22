#include <iostream>
using namespace std;

int main() {
    float celsius, fahrenheit, reamur, kelvin;

    cout << "Inputkan suhu dalam derajat celsius : ";
    cin >> celsius;

    cout << endl;

    fahrenheit = celsius * 9 / 5 + 32;
    reamur = celsius * 4 / 5;
    kelvin = celsius + 273;
    
    cout << "Suhu dalam Reamur : " << reamur << endl;
    cout << "Suhu dalam Fahrenheit : " << fahrenheit << endl;
    cout << "Suhu dalam Kelvin : " << kelvin << endl;
}
