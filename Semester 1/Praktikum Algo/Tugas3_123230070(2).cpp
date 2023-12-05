#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    float tinggi, berat, BMR, aktivitas, stres, energi;
    int umur, tingkatAktivitas, tingkatStres;
    string jenisKelamin;

    puts("=================================================================");
    puts("||                                                             ||");
    puts("||                   Perhitungan Energi                        ||");
    puts("||                                                             ||");
    puts("=================================================================");
    cout << endl;

    cout << "Masukkan Tinggi Badan (cm) : ";
    cin >> tinggi;
    cout << "Masukkan Berat Badan (kg) : ";
    cin >> berat;
    cout << "Masukkan Umur : ";
    cin >> umur;

    cout << endl;
    cin.ignore();

    cout << "Masukkan Jenis Kelamin (pria / wanita) : ";
    getline(cin, jenisKelamin);
    cout << endl;

    if (jenisKelamin == "pria" or jenisKelamin == "wanita") {
        if (jenisKelamin == "pria") {
            BMR = 66 + (13.7 * berat) + (5 * tinggi) + (6.8 * umur);
        } else if (jenisKelamin == "wanita") {
            BMR = 65.5 + (9.6 * berat) + (1.7 * tinggi) + (4.7 * umur);
        }

        puts("=================================================================");
        puts("||                   Tingkat Aktivitas                         ||");
        puts("||                       1. Ringan                             ||");
        puts("||                       2. Sedang                             ||");
        puts("||                       3. Berat                              ||");
        puts("=================================================================");
        cout << endl;

        cout << "Pilihan : ";
        cin >> tingkatAktivitas;

        if (jenisKelamin == "pria") {
            switch (tingkatAktivitas) {
            case 1:
                aktivitas = 1.65;
                break;
            case 2:
                aktivitas = 1.76;
                break;
            case 3:
                aktivitas = 2.10;
                break;
            default:
                cout << "Masukkan angka 1, 2, atau 3" << endl;
            }
        } else if (jenisKelamin == "wanita") {
            switch (tingkatAktivitas) {
            case 1:
                aktivitas = 1.55;
                break;
            case 2:
                aktivitas = 1.7;
                break;
            case 3:
                aktivitas = 2.0;
                break;
            default:
                cout << "Masukkan angka 1, 2, atau 3" << endl;
            }
        }

        if (aktivitas != 0) {
            puts("=================================================================");
            puts("||                     Tingkat Stres                           ||");
            puts("||                       1. Ringan                             ||");
            puts("||                       2. Sedang                             ||");
            puts("||                       3. Berat                              ||");
            puts("=================================================================");
            cout << endl;
            cout << "Pilihan : ";
            cin >> tingkatStres;

            switch (tingkatStres) {
            case 1:
                stres = 1.4;
                break;
            case 2:
                stres = 1.5;
                break;
            case 3:
                stres = 2.0;
                break;
            default:
                cout << "Masukkan 1, 2, atau 3";
            }
        }

        energi = BMR * aktivitas * stres;

        printf("Kebutuhan Energi Anda adalah : %.2f ", energi);
    }
}
