// #include <iostream>
// #include <stdio.h>
// using namespace std;

// // NOMOR 4 -7
// // int b = 1;
// // void UAS(int a, int *c);

// // NOMOR 8
// // int x[3] = {10, 20, 30};
// // int y[6];
// // int i;

// // NOMOR 10
// int a = 1;
// void UAS(int b, int *c);
// int X(int b);

// int main()
// {
//   // NOMOR 1

//   // int n = 2;

//   // for (int p = 1; p <= n; p++)
//   // {
//   //   cout << p << " ";
//   //   for (int q = p; q <= n; q++)
//   //   {
//   //     cout << q << " ";
//   //   }
//   //   cout << n << endl;
//   // }

//   // 1 1 2 2
//   // 2 2 2

//   // NOMOR 2

//   // int i = 1;

//   // do {
//   //   cout << "SP ";

//   //   if(i == 2 || i == 3)
//   //     cout << "Algo";
//   //   cout << "\n";
//   //   i++;

//   // } while(i < 5);

//   // SP
//   // SP Algo
//   // SP Algo
//   // SP

//   // NOMOR 3
//   // int n = 2;
//   // int x = 2;
//   // for (int p = 0; p <= n; p++)
//   // {
//   //   for (int q = 1; q <= p; q++)
//   //   {
//   //     x = x + p * q;
//   //     printf("%d", x);
//   //   }
//   // }

//   // D

//   // NOMOR 4 - 7

//   // int a, c;
//   // a = 3;
//   // b = 1;
//   // c = 2;
//   // cout << a << " " << b << " " << c << "\n"; // NOMOR 4 a = 3, b = 1, c = 2
//   // UAS(a, &c);
//   // cout << a << " " << b << " " << c << "\n"; // NOMOR 5 a = 3, b =-6, c = 11
//   // a = 2;
//   // b = 4;
//   // c = 3;
//   // cout << a << " " << b << " " << c << "\n"; // NOMOR 6 a = 2, b = 4, c = 3
//   // UAS(c, &a);
//   // cout << a << " " << b << " " << c <<  "\n"; // NOMOR 7 a = 14, b = -9, c = 3

//   // NOMOR 8
//   // for (i = 0; i < 6; i++)
//   // {
//   //   y[i] = x[i / 2] + x[i % 3];
//   //   cout << y[i] << endl;
//   // }

//   // y[0]=20
//   // y[1]=30{
//   // y[2]=50
//   // y[3]=30
//   // y[4]=50
//   // y[5]=60

//   // NOMOR 10
//   int b = 2;
//   int c = 3;
//   UAS(b, &c);
//   cout << a << " " << b << " " << c << endl; // NOMOR 3 a = 4, b = 2, c = 7
// }

// // NOMOR 10
// void UAS(int b, int *c)
// {
//   cout << a << " " << b << " " << *c << endl; // NOMOR 1 a = 1, b = 2, *c = 3
//   b = X(a) - *c;
//   *c = X(b) - a;                              // 7
//   a = *c - b;                                 // 7 - 3
//   cout << a << " " << b << " " << *c << endl; // NOMOR 2 a = 4, b = 3, *c = 7
// }

// int X(int b)
// {
//   return (5 + b);
// }

// // NOMOR 4 - 7
// // void UAS(int a, int *c) {
// //   a = b + *c;
// //   *c = 10 + b;
// //   b = 5 - *c;
// // }

// // NOMOR 9
// #include <iostream>
// using namespace std;

// int main() {
//   int a = 10;
//   do {
//     if (a % 2 == 0) {
//       cout << "oke";
//     }
//     else {
//       cout << "Sip";
//     }

//     a = a - 2;
//   } while (a < 1);
// }

// NOMOR 11
// #include <iostream>
// using namespace std;

// int main()
// {
//   for (int a = 1; a <= 3; a++)
//   {
//     for (int b = a; b <= 3; b++)
//     {
//       cout << b << " ";
//     }
//     cout << endl;
//   }
// }

// NOMOR 12
// #include <iostream>
// using namespace std;

// void cetak(int n, int i);

// int main()
// {
//   char a;
//   int i, n;

//   cout << "Masukkan digit terakhir nim : ";
//   cin >> n;

//   cout << "Masukkan huruf pertama nama : ";
//   cin >> a;

//   if (n > 7)
//   {
//     n = n / 2;
//   }

//   if (n >= 4)
//   {
//     n = n - 2;
//   }
//   else if (n <= 3)
//   {
//     n = n + 2;
//   }

//   i = n;

//   while (i >= -2)
//   {
//     cout << a << " ";
//     i = i - 1;
//   }

//   cout << endl;

//   cetak(n, i);
// }

// void cetak(int n, int i)
// {
//   do
//   {
//     n = n - 2;
//     cout << n << endl;
//     if (i == n)
//     {
//       cout << "Selesai";
//     }
//   } while (i >= n);
// }

// NOMOR 13
// #include <iostream>
// using namespace std;
// void MinMax(int i, int *x, int *min, int *max);
// int NIM[9] = {1, 2, 3, 2, 3, 0, 0, 7, 0};

// int main() {
//     int i, x = 0, min = NIM[0], max = min;
//     for(i = 1; i < 9; i++) {
//         MinMax(i, &x, &min, &max); // 1, 
//         cout << "ke = " << i << ", x = " << x << ", min = " << min << ", max = " << max << endl; //
//     }
//     cout << "ke = " << i << ", x = " << x << ", min = " << min << ", max = " << max << endl;
// }

// void MinMax(int i, int *x, int *min, int *max) {
//     if(NIM[i] < *min) {
//         *min = NIM[i];
//         *x = i;
//     }

//     if(NIM[i] > *max) {
//         *max = NIM[i];
//         *x = i;
//     }
// }

// // ke = 1, x = 1, min = 1, max = 2
// // ke = 2, x = 2, min = 1, max = 3
// // ke = 3, x = 2, min = 1, max = 3
// // ke = 4, x = 2, min = 1, max = 3
// // ke = 5, x = 5, min = 0, max = 3
// // ke = 6, x = 5, min = 0, max = 3
// // ke = 7, x = 7, min = 0, max = 7
// // ke = 8, x = 7, min = 0, max = 7
// // ke = 9, x = 7, min = 0, max = 7

// // NOMOR 14
// #include <iostream>
// using namespace std;
// int c = 2;
// void X(int a, int *b, int c);

// int main()
// {
//     int a, b;
//     b = 3;
//     a = 0;
//     X(b, &a, c);                               // 4 2 6
//     cout << a << " " << b << " " << c << endl; // 5 3 2
// }

// void X(int a, int *b, int c)
// {
//     a = a + 1;
//     *b = 2 + *b;
//     c = a + *b;

//     cout << a << " " << *b << " " << c << endl;
// }

// NOMOR 15
#include <iostream>
using namespace std;

string kalimat[100];

void balikKalimat()
{
  
}

int main()
{
  balikKalimat();
}

// NOMOR 16
// #include <iostream>
// using namespace std;

// void konversi(int bilangan, int &KM, int &M, int &CM, int &MM);

// int main()
// {
//   int bilangan, KM, M, CM, MM;

//   cout << "Masukkan bilangan dalam mm : ";
//   cin >> bilangan;

//   konversi(bilangan, KM, M, CM, MM);

//   cout << "Hasil konversi : " << KM << " km, " << M << " m, " << CM << " cm, " << MM << " mm";
// }

// void konversi(int bilangan, int &KM, int &M, int &CM, int &MM)
// {
//   KM = bilangan / 1000000;
//   bilangan = bilangan % 1000000;
//   M = bilangan / 1000;
//   bilangan = bilangan % 1000;
//   CM = bilangan / 10;
//   bilangan = bilangan % 10;
//   MM = bilangan % 10;
// }

// NOMOR 17
// #include <iostream>
// using namespace std;

// void banyakPecahan(long uang, long pecahan[]);
// int main()
// {
//   long uang, pecahan[9] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100};
//   int lembar[9], i;
//   cout << "Jumlah Uang Kembali : Rp ";
//   cin >> uang;

//   cout << "Pecahan uang kembali: " << endl;
//   banyakPecahan(uang, pecahan);

// }

// void banyakPecahan(long uang, long pecahan[])
// {
//   int lembar[9], i;
//   for (i = 0; i < 9; i++)
//   {
//     lembar[i] = uang / pecahan[i];
//     uang = uang % pecahan[i];
//   }

//   for (i = 0; i < 9; i++)
//   {
//     cout << pecahan[i] << " : " << lembar[i] << endl;
//   }
// }

// NOMOR 18
// #include <iostream>
// using namespace std;
// void Konversi(int bilangan, int *jam, int *menit, int *detik);
// int main()
// {
//     int bilangan;
//     // lengkapi dengan variabel-variabel lain jika dibutuhkan
//     int jam, menit, detik;
//     cout << "bilangan = ";
//     cin >> bilangan;
//     Konversi(bilangan, &jam, &menit, &detik);

//     cout << "Hasil konversi : " << jam << " Jam, " << menit << " Menit," << detik << " Detik";
//     // dan menampilkan hasil konversi
// }
// void Konversi(int bilangan, int *jam, int *menit, int *detik)
// {
//     *jam = bilangan / 3600;
//     bilangan = bilangan % 3600;
//     *menit = bilangan / 60;
//     bilangan = bilangan % 60;
//     *detik = bilangan;
// }