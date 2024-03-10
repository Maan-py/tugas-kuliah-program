#include <iostream>
using namespace std;

int pilihan, banyakData;
char ulangi;

int main() {
  system("cls");

  cout << "Masukkan banyak data : ";
  cin >> banyakData;

  int data[banyakData];

  // int dataLength = (sizeof(data) / sizeof(*(data)));

  // sequential
  int cari;
  bool found;
  int i;

  // binary
  int awal, akhir, tengah;

  do {
    cout << "1. Input data" << endl;
    cout << "2. Cari data" << endl;
    cout << "3. Tampil data" << endl;
    cout << "Pilih Menu : ";
    cin >> pilihan;

    switch (pilihan) {
    case 1:
      system("cls");
      for (int i = 0; i < banyakData; i++) {
        cout << "Masukkan data ke-" << i << " : ";
        cin >> data[i];
      }

      break;
    case 2:
      system("cls");
      cout << "Pilih metode searching yang ingin digunakan : " << endl;
      cout << "1. Sequential Search" << endl;
      cout << "2. Binary Search" << endl;
      cout << "Pilih : ";
      cin >> pilihan;

      switch (pilihan) {
      case 1:
        system("cls");
        for (int i = 0; i < banyakData; i++) {
          cout << "Data ke-" << i << " : " << data[i] << endl;
        }

        // sequential search
        cout << "Masukkan nilai yang ingin dicari : ";
        cin >> cari;

        found = false;
        i = 0;

        while (i < banyakData && !found) {
          if (data[i] == cari) {
            found = true;
          } else {
            i++;
          }
        }

        if (found) {
          cout << "Data ditemukan pada index ke- " << i << endl;
        } else {
          cout << "Data tidak ditemukan" << endl;
        }
        break;
      case 2:
        system("cls");
        // urutkan data
        cout << "Data setelah diurutkan" << endl;
        for (int i = 0; i < banyakData; i++) {
          for (int j = i + 1; j < banyakData; j++) {
            if (data[i] > data[j]) {
              int temp = data[i];
              data[i] = data[j];
              data[j] = temp;
            }
          }
        }

        for (int i = 0; i < banyakData; i++) {
          cout << "Data ke-" << i << " : " << data[i] << endl;
        }

        cout << endl;

        // binary search
        awal = 0;
        akhir = banyakData;
        found = false;

        cout << "Masukkan nilai yang ingin dicari : ";
        cin >> cari;

        while (!found && awal <= akhir) {
          tengah = (awal + akhir) / 2;
          if (cari == data[tengah]) {
            found = true;
          } else {
            if (cari < data[tengah]) {
              akhir = tengah - 1;
            } else {
              awal = tengah + 1;
            }
          }
        }

        if (found) {
          cout << "Data ditemukan pada index ke- " << tengah << endl;
        } else {
          cout << "Data tidak ditemukan" << endl;
        }

        // bmengembalikan data ke semula
        for (int i = 0; i < banyakData; i++) {
          for (int j = i + 1; j < banyakData; j++) {
            if (data[i] < data[j]) {
              int temp = data[i];
              data[i] = data[j];
              data[j] = temp;
            }
          }
        }
        break;
      default:
        cout << "Masukkan menu yang sesuai";
        break;
      }
      break;
    case 3:
      system("cls");
      for (int i = 0; i < banyakData; i++) {
        cout << "Data ke-" << i << " : " << data[i] << endl;
      }
      break;
    default:
      cout << "Masukkan menu yang sesuai";
      break;
    }
    cout << "\nKembali ke menu? (y/n) : "; // kembali ke menu
    cin >> ulangi;
  } while (ulangi == 'Y' || ulangi == 'y');
}