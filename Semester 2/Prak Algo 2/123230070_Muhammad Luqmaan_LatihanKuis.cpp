
#include <iostream>
using namespace std;

int i = 0;
int pilihan, j, menuMakan, jumlahMakanan;
char lagi, pesananBaru;

typedef struct {
  string namaPembeli;
  int harga = 0;
} orderan;

int main() {
  orderan pesanan[100];

  system("cls");

  cout << "Menu utama" << endl;
  cout << "1. Pesan makanan" << endl;
  cout << "2. Exit" << endl;
  cout << "Pilih : ";
  cin >> pilihan;

  switch (pilihan) {
  case 1:
    system("cls");
    while (i < 100 && j != 2) {
      do {
        system("cls");
        cout << "No. Antrean : " << i + 1 << endl;
        cout << "Masukkan Nama : ";

        cin.ignore();

        getline(cin, pesanan[i].namaPembeli);

        do {
          cout << "1. Tambah makanan" << endl;
          cout << "2. Exit" << endl;
          cout << "Pilih : ";
          cin >> j;

          if (j == 1) {
            cout << "                    Menu  \"Warung Makan Sentosa\"                    " << endl;
            cout << "======================================================================" << endl;
            cout << "||  No.  ||             Menu             ||         Harga           ||" << endl;
            cout << "======================================================================" << endl;
            cout << "||  1.   ||          Nasi Goreng         ||        Rp15.000         ||" << endl;
            cout << "||  2.   ||          Magelangan          ||        Rp20.000         ||" << endl;
            cout << "||  3.   ||          Bakmie Goreng       ||        Rp18.000         ||" << endl;
            cout << "||  4.   ||          Bakmie Ghodog       ||        Rp18.000         ||" << endl;
            cout << "||  5.   ||          Nasi Ghodog         ||        Rp15.000         ||" << endl;
            cout << "||  6.   ||          Mie Lethek          ||        Rp25.000         ||" << endl;
            cout << "======================================================================" << endl;

            cout << "Pilih makanan : ";
            cin >> menuMakan;

            cout << "Masukkan jumlah makanan : ";
            cin >> jumlahMakanan;

            switch (menuMakan) {
            case 1:
              pesanan[i].harga += 15000 * jumlahMakanan;
              break;
            case 2:
              pesanan[i].harga += 20000 * jumlahMakanan;
              break;
            case 3:
              pesanan[i].harga += 18000 * jumlahMakanan;
              break;
            case 4:
              pesanan[i].harga += 18000 * jumlahMakanan;
              break;
            case 5:
              pesanan[i].harga += 15000 * jumlahMakanan;
              break;
            case 6:
              pesanan[i].harga += 25000 * jumlahMakanan;
              break;
            default:
              cout << "Pilih menu makanan yang sesuai!" << endl;
              break;
            }
            cout << "Pesan lagi? (y/n) : ";
            cin >> lagi;
          } else if(j == 2) {
            break;
          } else {
            cout << "Masukkan menu yang sesuai!" << endl;
          }
        } while (lagi == 'Y' || lagi == 'y');

        cout << "\nStruk Pembelian" << endl;
        cout << "\nNomor antrian : " << i + 1 << endl;
        cout << "Nama pemesan : " << pesanan[i].namaPembeli << endl;
        cout << "Total harga : " << pesanan[i].harga << endl << endl;

        i++;

        cout << "Pesanan untuk pelanggan Baru? (y/n) : ";
        cin >> pesananBaru;

      } while (pesananBaru == 'Y' || pesananBaru == 'y');
      if (pesananBaru == 'N' || pesananBaru == 'n') {
        return i = 101;
      }
    }
    break;
  case 2:
    break;
  default:
    cout << "Pilih menu yang sesuai!" << endl;
    break;
  }
}