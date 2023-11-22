#include <iostream>
using namespace std;

int pilihan;
char pilihan2, ulang;
string notasi, sifat;

int maksWarna(int warna) {
    if (warna > 12) {
        warna -= 12;
    }
    return warna;
}

void analogous() {
    int warna1 = maksWarna((pilihan + 1));
    int warna2 = maksWarna((pilihan + 2));
    int warna3 = maksWarna((pilihan + 10));
    int warna4 = maksWarna((pilihan + 11));

    cout << "Perpaduan Warna Analogous dengan warna nomor: " << warna1 << ", " << warna2 << " atau " << warna3 << ", " << warna4 << " atau " << warna1 << " ," << warna4 << endl;
}

void complementary() {
    int warna = maksWarna((pilihan + 6));

    cout << "Perpaduan Warna Complementary dengan warna nomor: " << warna << endl;
}

void splitComplementary() {
    int warna1 = maksWarna((pilihan + 5));
    int warna2 = maksWarna((pilihan + 7));

    cout << "Perpaduan Warna Split Complementary dengan warna nomor: " << warna1 << ", " << warna2 << endl;
}

void triadicComplementary() {
    int warna1 = maksWarna((pilihan + 4));
    int warna2 = maksWarna((pilihan + 8));

    cout << "Perpaduan Warna Triadic Complementary dengan warna nomor: " << warna1 << ", " << warna2 << endl;
}

void tetradComplementary() {
    int warna1 = maksWarna((pilihan + 6));
    int warna2 = maksWarna((pilihan + 3));
    int warna3 = maksWarna((pilihan + 9));

    cout << "Perpaduan Warna Tetrad Complementary dengan warna nomor: " << warna1 << ", " << warna2 << ", " << warna3 << endl;
}

int main() {
    do {
        system("cls");
        puts("-------------------------------------------------------------------------------------");
        puts("                           Nama      : Muhammad Luqmaan                              ");
        puts("                           NIM       : 123230070                                     ");
        puts("-------------------------------------------------------------------------------------");
        cout << endl;

        cout << "Program Menentukan Notasi, Sifat Warna, dan Perpaduan Warna Harmonis" << endl;
        cout << "Warna-warna : " << endl;
        cout << endl;

        puts("1. Orange          5. Violet             9. Green");
        puts("2. Red-Orange      6. Blue-Violet        10. Yellow-Green");
        puts("3. Red             7. Blue               11. Yellow");
        puts("4. Red-Violet      8. Blue-Green         12. Yellow-Orange");
        cout << endl;

        cout << "Pilihan warna nomor : ";
        cin >> pilihan;

        cout << endl;

        if (pilihan == 1 or pilihan == 5 or pilihan == 9) {
            notasi = "Sekunder";
        } else if (pilihan == 3 or pilihan == 7 or pilihan == 11) {
            notasi = "Primer";
        } else {
            notasi = "Tersier";
        }

        if (pilihan >= 1 and pilihan <= 6) {
            sifat = "Hangat";
        } else {
            sifat = "Sejuk";
        }

        if(pilihan >= 1 and pilihan <= 12) {
            cout << "Notasi warna : " << notasi << endl;
            cout << "Sifat warna : " << sifat;

            cout << endl;

            cout << "Perpaduan warna harmonis\n" << endl;
            cout << "a. Perpaduan Warna Analogous" << endl;
            cout << "b. Perpaduan Warna Complementary" << endl;
            cout << "c. Perpaduan Warna Split Complementary" << endl;
            cout << "d. Perpaduan Warna Triadic Complementary" << endl;
            cout << "e. Perpaduan Warna Tetrad Complementary" << endl;

            cout << endl;

            cout << endl;

            cout << "Pilihan : ";
            cin >> pilihan2;

            switch (pilihan2) {
            case 'a':
                analogous();
                break;
            case 'b':
                complementary();
                break;
            case 'c':
                splitComplementary();
                break;
            case 'd':
                triadicComplementary();
                break;
            case 'e':
                tetradComplementary();
                break;
            default:
                cout << "Pilihan tidak tersedia";
                break;
            }
        } else {
            cout << "Pilihan warna tidak tersedia";
        }

        cout << "\nUlangi program? (y/n) : ";
        cin >> ulang;

    } while(ulang == 'y' or ulang == 'Y');
}