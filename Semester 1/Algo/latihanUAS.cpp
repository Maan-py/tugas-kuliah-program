#include <iostream>
#include <stdio.h>
using namespace std;

// NOMOR 4 -7
// int b = 1;
// void UAS(int a, int *c);

// NOMOR 8
// int x[3] = {10, 20, 30};
// int y[6];
// int i;

// NOMOR 10
int a = 1;
void UAS(int b, int *c);
int X(int b);

int main()
{
  // NOMOR 1

  // int n = 2;

  // for (int p = 1; p <= n; p++)
  // {
  //   cout << p << " ";
  //   for (int q = p; q <= n; q++)
  //   {
  //     cout << q << " ";
  //   }
  //   cout << n << endl;
  // }

  // 1 1 2 2
  // 2 2 2

  // NOMOR 2

  // int i = 1;

  // do {
  //   cout << "SP ";

  //   if(i == 2 || i == 3)
  //     cout << "Algo";
  //   cout << "\n";
  //   i++;

  // } while(i < 5);

  // SP
  // SP Algo
  // SP Algo
  // SP

  // NOMOR 3
  // int n = 2;
  // int x = 2;
  // for (int p = 0; p <= n; p++)
  // {
  //   for (int q = 1; q <= p; q++)
  //   {
  //     x = x + p * q;
  //     printf("%d", x);
  //   }
  // }

  // D

  // NOMOR 4 - 7

  // int a, c;
  // a = 3;
  // b = 1;
  // c = 2;
  // cout << a << " " << b << " " << c << "\n"; // NOMOR 4 a = 3, b = 1, c = 2
  // UAS(a, &c);
  // cout << a << " " << b << " " << c << "\n"; // NOMOR 5 a = 3, b =-6, c = 11
  // a = 2;
  // b = 4;
  // c = 3;
  // cout << a << " " << b << " " << c << "\n"; // NOMOR 6 a = 2, b = 4, c = 3
  // UAS(c, &a);
  // cout << a << " " << b << " " << c <<  "\n"; // NOMOR 7 a = 14, b = -9, c = 3

  // NOMOR 8
  // for (i = 0; i < 6; i++)
  // {
  //   y[i] = x[i / 2] + x[i % 3];
  //   cout << y[i] << endl;
  // }

  // y[0]=20
  // y[1]=30{
  // y[2]=50
  // y[3]=30
  // y[4]=50
  // y[5]=60

  // NOMOR 10
  int b = 2;
  int c = 3;
  UAS(b, &c);
  cout << a << " " << b << " " << c << endl; // NOMOR 3 a = 4, b = 2, c = 7
}

// NOMOR 10
void UAS(int b, int *c) {
  cout << a << " " << b << " " << *c << endl; // NOMOR 1 a = 1, b = 2, *c = 3
  b = X(a) - *c; 
  *c = X(b) - a; // 7
  a = *c - b; // 7 - 3
  cout << a << " " << b << " " << *c << endl; // NOMOR 2 a = 4, b = 3, *c = 7
}

int X(int b) {
  return (5 + b);
}

// NOMOR 4 - 7
// void UAS(int a, int *c) {
//   a = b + *c;
//   *c = 10 + b;
//   b = 5 - *c;
// }