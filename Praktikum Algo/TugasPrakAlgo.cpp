#include <iostream>
using namespace std;

int main()
{
    string nama;
    int NIM, tugas1, tugas2;
    char plug;
    cout << "Inputkan data!" << endl;
    cout << "Nama  : ";
    getline(cin, nama);

    cout << "NIM   : ";
    cin >> NIM;

    cout << "Plug  : ";
    cin >> plug;

    cout << endl;
    cout << "Inputkan nilai Tugas 1 untuk NIM " << NIM << " : ";
    cin >> tugas1;
    cout << "Inputkan nilai Tugas 2 untuk NIM " << NIM << " : ";
    cin >> tugas2;

    cout << endl;
    cout << "Input data selesai!" << endl;
    cout << "Data mahasiswa" << endl;
    cout << "Nama\t   : " << nama << endl;
    cout << "NIM\t   : " << NIM << endl;
    cout << "Plug\t   : " << plug << endl;
    cout << "Nilai" << endl;
    cout << "  Tugas 1  : " << tugas1 << endl;
    cout << "  Tugas 2  : " << tugas2;
}