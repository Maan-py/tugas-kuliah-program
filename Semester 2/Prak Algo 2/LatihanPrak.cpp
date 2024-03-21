// // #include <iostream>
// // using namespace std;

// // int n;
// // int deret(int n);

// // int main()
// // {
// //   cout << "Masukkan deret ke : ";
// //   cin >> n;

// //   cout << "Hasil : " << deret(n) << endl;
// //   // cout << "Masukkan pangkat : ";
// //   // cin >> pangkat;

// //   // cout << perpangkatan(angka, pangkat);
// //   // cout << deret(n);
// //   cout << "deret"
// //        << " : ";
// //   for (int i = 1; i <= n; i++)
// //   {
// //     cout << i * 2 << " ";
// //   }
// // }

// // int deret(int n) {
// //   if (n == 1) {
// //     return 2;
// //   } else
// //   {
// //     return deret(n - 1) + 2;
// //   }
// // }

// // search pt.3

// // sequential tanpa sentinel

// // #include <iostream>
// // using namespace std;

// // int main(){
// //   int nilai[10] = {12, 13, 15, 17, 18, 20, 22, 24, 40, 60};
// //   int cari;
// //   bool found = false;
// //   int i = 1;

// //   cout << "Masukkan nilai yang ingin dicari : ";
// //   cin >> cari;

// //   while(!found && i < 10) {
// //     if(cari == nilai[i]) {
// //       cout << "Nilai yang anda cari ada di index ke : " << i;
// //       found = true;
// //     } else{
// //       i++;
// //     }

// //     if(i == 9) {
// //       cout << "Nilai tidak ditemukan";
// //       break;
// //     }
// //   }
// // }

// // sequential pake sentinel

// // #include <iostream>
// // using namespace std;

// // int main() {
// //   int a[11] = {2, 4, 7, 10, 13, 17, 21, 25, 28};
// //   int i, x;
// //   bool found;

// //   cout << "Masukkan nilai yang dicari : ";
// //   cin >> x;

// //   i = 0;
// //   found = false;

// //   a[10] = x; // sentinel

// //   while((i <= 10) && (!found) && (a[i] <= x)) {
// //     if(a[i] == x) {
// //       found = true;
// //     } else{
// //       i++;
// //     }
// //   }
    
// //     if(i < 10 && (found)) {
// //       cout << x << " ditemukan pada array index ke : " << i << endl;
// //     } else {
// //       cout << x << " tidak ada pada array" << endl; 
// //     }
    
// //     cout << " " << endl;
// // }

// // binary tanpa sentinel                      

// #include <iostream>
// using namespace std;

// int main() {
//   int nilai[10] = {12, 15, 15, 17, 18, 20, 22, 24, 40, 60};
//   int cari, awal = 0, akhir, tengah;
//   bool found = false;
//   akhir = 10;

//   cout << "Masukkan nilai yang ingin dicari : ";
//   cin >> cari;

//   while(!found && awal <= akhir) {
//     tengah = (awal + akhir) / 2;
//     if(cari == nilai[tengah]) {
//       found = true;
//     } else {
//       if(cari < nilai[tengah]) {
//         akhir = tengah - 1;
//       } else {
//         awal = tengah + 1;
//       }
//     }
//   }

//   if(found) {
//     cout << "Data ditemukan pada index ke- " << tengah << endl;
//   } else {
//     cout << "Data tidak ditemukan" << endl;
//   }
// }

#include <iostream>
#include <string>
using namespace std;

int pilihan;
char inputData = 'y';
char ulang;

typedef struct
{
  int kode;
  string judul;
  typedef struct
  {
    string nama;
    int usia;
  } dataPenyanyi;
  string album;
} dataLagu;

// menu 4
int awal, akhir;
int deretGanjil(awal, akhir);
{
  if (awal % 2 == 0)
  {
    awal + 1;
  }
  else if (akhir % 2 == 0)
  {
    akhir - 1;
  }
  else
  {
    return deretGanjil(n - 1) + 2;
  }
}

int main()
{
  dataLagu lagu[2];
  dataLagu::dataPenyanyi penyanyi[2];

  do
  {
    int i = 0;
    cout << "Menu utama" << endl;
    cout << "1. Input data lagu" << endl;
    cout << "2. Output data lagu" << endl;
    cout << "3. Pencarian data lagu" << endl;
    cout << "4. Deret bilangan ganjil" << endl;

    cout << "Pilih menu : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
      while (inputData == 'Y' || inputData == 'y' && i <= 1)
      {
        cout << "Masukkan kode lagu : ";
        cin >> lagu[i].kode;

        cout << "Masukkan judul lagu : ";
        cin.ignore();
        getline(cin, lagu[i].judul);

        cout << "Masukkan nama penyanyi : ";
        getline(cin, penyanyi[i].nama);

        cout << "Masukkan usia penyanyi : ";
        cin >> penyanyi[i].usia;

        cout << "Masukkan album lagu : ";
        cin.ignore();
        getline(cin, lagu[i].album);

        /* if(i >= 0 && i <= 1) {
          cout << "Input lagi? (y/n) ";
          cin >> inputData;
        } else {
          cout << "input data sudah memasuki jumlah maksimal" << endl;
          break;
        } */

        cout << "Input lagi? (y/n) ";
        cin >> inputData;
        i++;
      }
      break;
    case 2:
      for (i = 0; i <= 1; i++)
      {
        cout << "Output data ke- " << i + 1 << endl;
        cout << "Kode lagu : " << lagu[i].kode << endl;
        cout << "Judul lagu : " << lagu[i].judul << endl;
        cout << "Nama Penyanyi : " << penyanyi[i].nama << endl;
        cout << "Usia Penyanyi : " << penyanyi[i].usia << endl;
        cout << "Album lagu : " << lagu[i].album << endl;
      }
      break;
    case 3:
      break;
    case 4:
      cout << "Masukkan angka awal : ";
      cin >> awal;

      cout << "Masukkan angka akhir : ";
      cin >> akhir;

      cout << deretGanjil(awal, akhir);
      break;
    default:
      cout << "Pilih menu yang sesuai" << endl;
      break;
    }
    cout << "Kembali ke menu utama? (y/n) ";
    cin >> ulang;
  } while (ulang == 'Y' || ulang == 'y');
}
