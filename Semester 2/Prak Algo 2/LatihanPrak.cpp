#include <iostream>
using namespace std;

int n;
int deret(int n);

int main()
{
  cout << "Masukkan deret ke : ";
  cin >> n;

  cout << "Hasil : " << deret(n) << endl;
  // cout << "Masukkan pangkat : ";
  // cin >> pangkat;

  // cout << perpangkatan(angka, pangkat);
  // cout << deret(n);
  cout << "deret"
       << " : ";
  for (int i = 1; i <= n; i++)
  {
    cout << i * 2 << " ";
  }
}

int deret(int n) {
  if (n == 1) {
    return 2;
  } else
  {
    return deret(n - 1) + 2;
  }
}