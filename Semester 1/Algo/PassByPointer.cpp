// #include <iostream>
// using namespace std;

// int p = 3;
// void UAS(int r, int *q);
// int X(int q);

// int main()
// {
//   int q = 4;
//   int r = 5;

//   cout << "NOMOR 1 : " << p << " " << q << " " << r << endl; // p = 3, q = 4, r = 5

//   UAS(q, &r);

//   cout << "NOMOR 4 : " << p << " " << q << " " << r << endl; // p = 7, q = 4, r = 9
// }

// void UAS(int r, int *q)
// {
//   cout << "NOMOR 2 : " << p << " " << *q << " " << r << endl; // p = 3, q = 5, r = 4

//   *q = X(p) - r; // 13 - 4 = 9
//   r = X(*q) - p;
//   p = r - *q; // 16 - 9 = 7

//   cout << "NOMOR 3 : " << p << " " << *q << " " << r << endl; // p = 7, q = 9, r = 16
// }

// int X(int q)
// {
//   return (10 + q);
// }

#include <iostream>
using namespace std;

int p = 3;

void UAS_pass_by_value(int r, int q);
void UAS_pass_by_pointer(int r, int *q);
int X_pass_by_value(int q);

int main()
{
  int q = 6; // Ubah nilai q menjadi 6
  int r = 8; // Ubah nilai r menjadi 8

  cout << p << " " << q << " " << r << endl; // 3 6 8

  UAS_pass_by_value(r, q);

  cout << p << " " << q << " " << r << endl; // 12 6 8

  // Reset nilai q dan r
  q = 9;  // Ubah nilai q menjadi 9
  r = 12; // Ubah nilai r menjadi 12

  cout << p << " " << q << " " << r << endl; // 12 9 12

  UAS_pass_by_pointer(r, &q);

  cout << p << " " << q << " " << r << endl; // 3 15 12
}

void UAS_pass_by_value(int r, int q)
{
  q = X_pass_by_value(p) - r; // 18 - 8 = 10
  r = X_pass_by_value(q) - p; // 25 - 3 = 22
  p = r - q;                  // 22 - 10 = 12
}

void UAS_pass_by_pointer(int r, int *q)
{
  *q = X_pass_by_value(p) - r; // 27 - 12 = 15
  r = X_pass_by_value(*q) - p; // 30 - 12 = 18
  p = r - *q;                  // 18 - 15 = 3
}

int X_pass_by_value(int q)
{
  return (15 + q); // Ubah nilai return menjadi 15 + q
}