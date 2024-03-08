#include <iostream>
using namespace std;

int pilihan, banyakData;

void menu1();
void menu2();
void binarySearch();

int main() {
  cout << "1. Input data" << endl;
  cout << "2. Cari data" << endl;
  cout << "3. Tampil data" << endl;
  cout << "Pilih Menu : ";
  cin >> pilihan;

  switch(pilihan) {
    case 1:
      menu1();
    break;
    case 2:
      menu2();
    break;
    case 3:
      break;
    default:
      cout << "Masukkan menu yang sesuai";
    break;
  }
}

void menu1(int data[]) {
  cout << "Masukkan banyak data : ";
  cin >> banyakData;

  int data[banyakData];

  cout << "Masukkan data : " << endl;
  for(int i = 0; i < banyakData; i++) {
    cout << "Masukkan data ke-" << i << " : ";
    cin >> data[i];
  }
}

void menu2() {
  cout << "Pilih metode searching yang ingin digunakan : " << endl;
  cout << "1. Sequential Search" << endl;
  cout << "2. Binary Search";
  cout << "Pilih : ";
  cin >> pilihan;

  switch(pilihan) {
    case 1: 
    break;
    case 2:
    break;
    default:
    break;
  }
}

void binarySearch() {
    int cari, awal = 0, akhir, tengah;
    bool found = false;
    akhir = 10;

    cout << "Masukkan nilai yang ingin dicari : ";
    cin >> cari;

    while(!found && awal <= akhir) {
      tengah = (awal + akhir) / 2;
      if(cari == data[tengah]) {
        found = true;
      } else {
        if(cari < data[tengah]) {
          akhir = tengah - 1;
        } else {
          awal = tengah + 1;
        }
      }
    }

    if(found) {
      cout << "Data ditemukan pada index ke- " << tengah << endl;
    } else {
      cout << "Data tidak ditemukan" << endl;
    }
}