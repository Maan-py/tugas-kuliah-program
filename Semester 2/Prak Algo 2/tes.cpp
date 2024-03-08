#include <iostream>
#include <string>
using namespace std;

// Deklarasi struct untuk data barang
struct Barang
{
  string nama;
  string merek;
  int jumlahStok;
  double harga;
};

int main()
{
  int maxBarang; // Jumlah maksimal barang
  cout << "Masukkan jumlah maksimal barang yang akan diinput: ";
  cin >> maxBarang;

  Barang daftarBarang[maxBarang]; // Array untuk menyimpan data barang
  int jumlahBarang = 0;           // Jumlah barang yang telah diinput
  int pilihan;

  // Menu perulangan
  do
  {
    cout << "\nMenu:" << endl;
    cout << "1. Input data" << endl;  
    cout << "2. Tampilkan data" << endl;
    cout << "3. Keluar program" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
      if (jumlahBarang < maxBarang)
      {
        // Input data barang
        cout << "Masukkan data barang ke-" << jumlahBarang + 1 << ":" << endl;
        cout << "Nama: ";
        cin >> daftarBarang[jumlahBarang].nama;
        cout << "Merek: ";
        cin >> daftarBarang[jumlahBarang].merek;
        cout << "Jumlah Stok: ";
        cin >> daftarBarang[jumlahBarang].jumlahStok;
        cout << "Harga: ";
        cin >> daftarBarang[jumlahBarang].harga;
        jumlahBarang++;
      }
      else
      {
        cout << "Maaf, jumlah barang sudah mencapai batas maksimal." << endl;
      }
      break;
    case 2:
      // Tampilkan data barang
      if (jumlahBarang > 0)
      {
        cout << "\nData Barang:" << endl;
        for (int i = 0; i < jumlahBarang; ++i)
        {
          cout << "Barang ke-" << i + 1 << ":" << endl;
          cout << "Nama: " << daftarBarang[i].nama << endl;
          cout << "Merek: " << daftarBarang[i].merek << endl;
          cout << "Jumlah Stok: " << daftarBarang[i].jumlahStok << endl;
          cout << "Harga: " << daftarBarang[i].harga << endl;
        }
      }
      else
      {
        cout << "Belum ada data barang yang dimasukkan." << endl;
      }
      break;
    case 3:
      cout << "Terima kasih. Program selesai." << endl;
      break;
    default:
      cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
    }
  } while (pilihan != 3);

  return 0;
}
