// #include <iostream>
// using namespace std;

// int n;
// int deret(int n);

// int main()
// {
//   cout << "Masukkan deret ke : ";
//   cin >> n;

//   cout << "Hasil : " << deret(n) << endl;
//   // cout << "Masukkan pangkat : ";
//   // cin >> pangkat;

//   // cout << perpangkatan(angka, pangkat);
//   // cout << deret(n);
//   cout << "deret"
//        << " : ";
//   for (int i = 1; i <= n; i++)
//   {
//     cout << i * 2 << " ";
//   }
// }

// int deret(int n) {
//   if (n == 1) {
//     return 2;
//   } else
//   {
//     return deret(n - 1) + 2;
//   }
// }

// search pt.3

// sequential tanpa sentinel

// #include <iostream>
// using namespace std;

// int main(){
//   int nilai[10] = {12, 13, 15, 17, 18, 20, 22, 24, 40, 60};
//   int cari;
//   bool found = false;
//   int i = 1;

//   cout << "Masukkan nilai yang ingin dicari : ";
//   cin >> cari;

//   while(!found && i < 10) {
//     if(cari == nilai[i]) {
//       cout << "Nilai yang anda cari ada di index ke : " << i;
//       found = true;
//     } else{
//       i++;
//     }

//     if(i == 9) {
//       cout << "Nilai tidak ditemukan";
//       break;
//     }
//   }
// }

// sequential pake sentinel

// #include <iostream>
// using namespace std;

// int main() {
//   int a[11] = {2, 4, 7, 10, 13, 17, 21, 25, 28};
//   int i, x;
//   bool found;

//   cout << "Masukkan nilai yang dicari : ";
//   cin >> x;

//   i = 0;
//   found = false;

//   a[10] = x; // sentinel

//   while((i <= 10) && (!found) && (a[i] <= x)) {
//     if(a[i] == x) {
//       found = true;
//     } else{
//       i++;
//     }
//   }
    
//     if(i < 10 && (found)) {
//       cout << x << " ditemukan pada array index ke : " << i << endl;
//     } else {
//       cout << x << " tidak ada pada array" << endl; 
//     }
    
//     cout << " " << endl;
// }

// binary tanpa sentinel                      

#include <iostream>
using namespace std;

int main() {
  int nilai[10] = {12, 15, 15, 17, 18, 20, 22, 24, 40, 60};
  int cari, awal = 0, akhir, tengah;
  bool found = false;
  akhir = 10;

  cout << "Masukkan nilai yang ingin dicari : ";
  cin >> cari;

  while(!found && awal <= akhir) {
    tengah = (awal + akhir) / 2;
    if(cari == nilai[tengah]) {
      found = true;
    } else {
      if(cari < nilai[tengah]) {
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