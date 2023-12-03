#include <iostream>
#include <stdio.h>
using namespace std;

int b = 1;
void UAS(int a, int *c);

int main()
{
  // NOMOR 1

  // int n = 2;

  // for(int p = 1; p <= n; p++) {
  //   cout << p << " ";
  //   for (int q = p; q <= n; q++) {
  //     cout << q << " ";
  //   }
  //   cout << n << endl;
  // }

  // NOMOR 2

  // int i = 1;

  // do {
  //   cout << "SP ";

  //   if(i == 2 || i == 3)
  //     cout << "Algo";
  //   cout << "\n";
  //   i++;

  // } while(i < 5);

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

  // NOMOR 4

  int a, c;
  a = 3;
  b = 1;
  c = 2;
  cout << a << " " << b << " " << c << "\n";
  UAS(a, &c);
  cout << a << " " << b << " " << c << "\n";
  a = 2;
  b = 4;
  c = 3;
  cout << a << " " << b << " " << c << "\n";
  UAS(c, &a);
  cout << a << " " << b << " " << c << "\n";
}

void UAS(int a, int *c)
{
  a = b + *c;
  *c = 10 + b;
  b = 5 - *c;
}