#include <iostream>
using namespace std;

int jumlah, pilihan;
char ulangi;
typedef struct {
  string nama;
  string merek;
  int jumlah;
  int harga;
} data_barang;

int main() {
  int j = 0;

  system("cls");

  cout << "Masukkan jumlah maksimal barang : "; // input jumlah maksimal barang
  cin >> jumlah;

  data_barang barang[jumlah]; // deklarasi array barang dengan struct
  do { // perulangan menu
    cout << "Pilih menu : " << endl;
    cout << "1. Input data" << endl;
    cout << "2. Tampilkan data" << endl;
    cout << "3. keluar program" << endl;

    cout << "\nPilih : "; // pilih menu
    cin >> pilihan;

    system("cls");

    switch (pilihan) {
    case 1: // menu 1
      if (j < jumlah) { // jika jumlah maksimal barang belum terpenuhi
        cout << "Masukkan barang ke-" << j + 1 << endl;

        cout << endl;

        cin.ignore();
        cout << "Masukkan nama barang : "; // input nama barang
        getline(cin, barang[j].nama);

        cout << "Masukkan merek " << barang[j].nama << " : "; // input merek barang
        getline(cin, barang[j].merek);

        cout << "Masukkan jumlah stok " << barang[j].nama << " : "; // input jumlah stok
        cin >> barang[j].jumlah;

        cin.ignore();

        cout << "Masukkan harga " << barang[j].nama << " : "; // input harga
        cin >> barang[j].harga;
      } else { // kondisi jika array sudah penuh
        cout << "Jumlah barang sudah memenuhi batas maksimal" << endl;
      }
      j++; // variabel j terus bertambah setelah input barang
      break;
    case 2:
      // system("cls");
      cout << "Berikut adalah data-data barang yang sudah diinputkan : "
           << endl;
      cout << endl;
      for (int i = 0; i < j; i++) { // perulangan untuk menampilkan data barang

        cout << "Data barang ke-" << i + 1 << endl;

        cout << "\nNama barang : " << barang[i].nama << endl;

        cout << "Merek " << barang[i].nama << "  : " << barang[i].merek << endl;

        cout << "Jumlah " << barang[i].nama << " : " << barang[i].jumlah
             << endl;

        cout << "Harga " << barang[i].nama << "  : " << barang[i].harga << endl;

        cout << endl;
      }
      break;
    case 3:
      return ulangi = 'n'; // keluar dari program
      break;
    default:
      cout << "Pilih menu yang sesuai"; // jika user meng-input selain dari 3 menu
      break;
    }
    cout << "\nKembali ke menu? (y/n) : "; // kembali ke menu
    cin >> ulangi;
  } while (ulangi == 'Y' || ulangi == 'y'); // perulangan selama ulangi true
}
