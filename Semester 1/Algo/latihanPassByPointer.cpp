#include <iostream>
using namespace std;

int p = 3;
void UAS(int r, int *q);
int X(int q);

int main()
{
  int q = 4;
  int r = 5;

  cout << "NOMOR 1 : " << p << " " << q << " " << r << endl; // p = 3, q = 4, r = 5

  UAS(q, &r);

  cout << "NOMOR 4 : " << p << " " << q << " " << r << endl; // p = 7, q = 4, r = 9
}

void UAS(int r, int *q)
{
  cout << "NOMOR 2 : " << p << " " << *q << " " << r << endl; // p = 3, q = 5, r = 4

  *q = X(p) - r; // 13 - 4 = 9
  r = X(*q) - p;
  p = r - *q; // 16 - 9 = 7

  cout << "NOMOR 3 : " << p << " " << *q << " " << r << endl; // p = 
}

int X(int q)
{
  return (10 + q);
}