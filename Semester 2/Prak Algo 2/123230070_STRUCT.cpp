#include <iostream>
using namespace std;

int jumlah, pilihan;
char ulangi;

typedef struct
{
  string nama;
  string merek;
  int jumlah;
  int harga;
} data_barang;

int main()
{

  int j = 0;

  system("cls");

  cout << "Masukkan jumlah maksimal barang : ";
  cin >> jumlah;

  data_barang barang[jumlah];
  do
  {
    cout << "Pilih menu : " << endl;
    cout << "1. Input data" << endl;
    cout << "2. Tampilkan data" << endl;
    cout << "3. keluar program" << endl;

    cout << "\nPilih : ";
    cin >> pilihan;

    system("cls");

    switch (pilihan)
    {
    case 1:
      if (j < jumlah)
      {
        cout << "Masukkan barang ke-" << j + 1 << endl;

        cout << endl;

        cin.ignore();
        cout << "Masukkan nama barang : ";
        getline(cin, barang[j].nama);

        cout << "Masukkan merek " << barang[j].nama << " : ";
        getline(cin, barang[j].merek);

        cout << "Masukkan jumlah stok " << barang[j].nama << " : ";
        cin >> barang[j].jumlah;

        cin.ignore();

        cout << "Masukkan harga " << barang[j].nama << " : ";
        cin >> barang[j].harga;
      }
      else
      {
        cout << "Jumlah barang sudah memenuhi batas maksimal" << endl;
      }
      j++;
      break;
    case 2:
      // system("cls");
      cout << "Berikut adalah data-data barang yang sudah diinputkan : " << endl;
      cout << endl;
      for (int i = 0; i < j; i++)
      {

        cout << "Data barang ke-" << i + 1 << endl;

        cout << "\nNama barang : " << barang[i].nama << endl;

        cout << "Merek " << barang[i].nama << "  : " << barang[i].merek << endl;

        cout << "Jumlah " << barang[i].nama << " : " << barang[i].jumlah << endl;

        cout << "Harga " << barang[i].nama << "  : " << barang[i].harga << endl;

        cout << endl;
      }
      break;
    case 3:
      return ulangi = 'n';
      break;
    default:
      cout << "Pilih menu yang sesuai";
      break;
    }
    cout << "\nKembali ke menu? (y/n) : ";
    cin >> ulangi;
  } while (ulangi == 'Y' || ulangi == 'y');
}
