#include <iostream>
using namespace std;

int main() {
    int pilihanMenu, pilihanSubmenu, tahun;
    float panjang, lebar, alas, tinggi, jari_jari, penghasilan, pph, pkp;
    char menikah;
    const float phi = 3.14;
    float ptkp = 54000000;

    cout << "** Sistem Informasi Kuis Algo 1 **";
    cout << endl;
    cout << "Menu Utama" << endl;

    cout << "1. Menu Luas Bangun Datar" << endl;
    cout << "2. Menu Cek Tahun Kabisat" << endl;
    cout << "3. Menu Cek Pajak Penghasilan" << endl;

    cout << "Pilih Menu (1/2/3) : ";
    cin >> pilihanMenu;

    switch (pilihanMenu) {
    case 1:
        cout << "-----------------------------------------------------------------------------------------" << endl;
        cout << "Sub Menu Luas Bangun Datar" << endl;
        cout << "1. Luas Persegi Panjang" << endl;
        cout << "2. Luas Segitiga" << endl;
        cout << "3. Luas Lingkaran" << endl;
        cout << "Pilih Sub Menu (1/2/3) : ";
        cin >> pilihanSubmenu;

        switch (pilihanSubmenu) {
        case 1:
            cout << "-----------------------------------------------------------------------------------------" << endl;
            cout << "** Luas Persegi Panjang **" << endl;
            cout << "Input Panjang : ";
            cin >> panjang;
            cout << "Input Lebar : ";
            cin >> lebar;

            cout << "Luas Persegi Panjang = " << panjang * lebar;
            break;
        case 2:
            cout << "-----------------------------------------------------------------------------------------" << endl;
            cout << "** Luas Segitiga **" << endl;
            cout << "Input Alas : ";
            cin >> alas;
            cout << "Input Tinggi : ";
            cin >> tinggi;

            cout << "Luas Segitiga = " << alas * tinggi / 2;
            break;
        case 3:
            cout << "-----------------------------------------------------------------------------------------" << endl;
            cout << "** Luas Lingkaran **" << endl;
            cout << "Input Jari-Jari : ";
            cin >> jari_jari;

            cout << "Luas Lingkaran = " << phi * jari_jari * jari_jari;
            break;

        default:
            cout << "-----------------------------------------------------------------------------------------" << endl;
            cout << "Anda menginputkan angka yang salah.";
            break;
        }
        break;

    case 2:
        cout << "-----------------------------------------------------------------------------------------" << endl;
        cout << "Sub Menu Cek Tahun Kabisat" << endl;
        cout << "Input Tahun : ";
        cin >> tahun;

        if (tahun < 1582) {
            if (tahun % 4 == 0) {
                cout << "Tahun " << tahun << " merupakan kalender Julian berjumlah 366 hari" << endl;
            }
            else if (tahun % 4 != 0) {
                cout << "Tahun " << tahun << " merupakan kalender Julian berjumlah 365 hari" << endl;
            }
        }
        else if (tahun > 1583) {
            if (tahun % 400 != 0 and tahun % 100 == 0) {
                cout << "Tahun " << tahun << " merupakan kalender Julian berjumlah 365 hari" << endl;
            }
            else if (tahun % 400 != 0 and tahun % 100 != 0 and tahun % 4 == 0) {
                cout << "Tahun " << tahun << " merupakan kalender Gregorian berjumlah 366 hari" << endl;
            }
            else if (tahun % 400 != 0 and tahun % 100 != 0 and tahun != 0) {
                cout << "Tahun " << tahun << " merupakan kalender Julian berjumlah 365 hari" << endl;
            }
            else if (tahun % 400 == 0) {
                cout << "Tahun " << tahun << " merupakan kalender Gregorian berjumlah 366 hari" << endl;
            }
        }
        else if (tahun == 1582) {
            cout << "Tahun " << tahun << " merupakan kalender Julian berjumlah 355 hari";
        }
        break;

    case 3:
        cout << "-----------------------------------------------------------------------------------------" << endl;
        cout << "Sub Menu Cek Pajak Penghasilan" << endl;
        cout << "Input Penghasilan per Bulan : Rp.";
        cin >> penghasilan;

        cout << endl;

        cout << "Apakah Anda sudah menikah (y/n) ? ";
        cin >> menikah;

        switch (menikah) {
        case 'y':
            pkp = (penghasilan * 12) - (ptkp + 4500000);
            break;
        case 'n':
            pkp = (penghasilan * 12) - ptkp;
        default:
            break;
        }

        if (pkp <= 0) {
            cout << "Anda bebas pajak penghasilan";
        }
        else {
            pph = 0.05 * pkp; 
            cout << "Pajak penghasilan Anda setahun adalah " << "Rp." << pph;
        }

        break;

    default:
        cout << "Anda menginputkan angka yang salah.";
        break;
    }
    return 0;
}