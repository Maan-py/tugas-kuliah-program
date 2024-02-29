#include <iostream>
using namespace std;

int angka, pangkat;
int perpangkatan(int angka, int pangkat);

int main()
{
  cout << "Masukkan angka : ";
  cin >> angka;

  cout << "Masukkan pangkat : ";
  cin >> pangkat;
  
  cout << perpangkatan(angka, pangkat);
}

int perpangkatan(int angka, int n)
{
  if (n == 1)
  {
    return angka;
  }

  if (n == 0)
  {
    return 1;
  }
  else
  {
    return angka * perpangkatan(angka, n - 1);
  }
}