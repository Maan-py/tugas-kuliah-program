#include <iostream>
#include <cmath>
using namespace std;

void nomorSatu(int j, int *S);
void nomorDua(int j, int *S);
void nomorTiga();
void nomorEmpat();
void nomorLima();

int main()
{
  int j;
  int S;

  cout << "Masukkan nilai j: ";
  cin >> j;

  nomorSatu(j, &S);
  cout << "\nJumlah S = " << S << endl;

  nomorDua(j, &S);
  cout << "\nJumlah S = " << S << endl;

  nomorTiga();

  cout << endl;

  nomorEmpat();

  cout << endl;

  nomorLima();
}

void nomorSatu(int j, int *S)
{
  int i = 1;
  *S = 0;

  cout << "S = ";

  while (i <= j)
  {
    int n;
    if (i % 5 == 0)
    {
      n = i * 3;
    }
    else
    {
      n = i * -3;
    }
    cout << n << ", ";

    *S += n;

    i++;
  }
}

void nomorDua(int j, int *S)
{
  int i = 1;
  *S = 0;

  cout << "S = ";

  while (i <= j)
  {
    int n;
    n = (2 * i - 1) * pow(-1, i - 1);
    cout << n << ", ";

    *S += n;
    i++;
  }
}

void nomorTiga()
{
  int i = 1;
  double F;
  F = 0.0;

  cout << "S = ";

  while (i <= 6)
  {
    if (i == 1)
    {
      cout << i << ", ";
      F += 1;
    }
    else
    {
      if (i % 2 == 0)
      {
        cout << "-1/" << i << ", ";
        F -= 1.0 / i;
      }
      else
      {
        cout << "1/" << i << ", ";
        F += 1.0 / i;
      }
    }
    i++;
  }

  cout << endl;

  cout << "S = " << F;
}

void nomorEmpat()
{

  int i = 1;
  double F;
  F = 0.0;

  cout << "Nomor 4" << endl;
  cout << "S = ";

  while (i <= 8)
  {
    if (i % 4 == 0)
    {
      cout << "1/" << i * 2 << ", ";
      F += 1.0 / (i * 2);
    }
    else
    {
      cout << "-1/" << i * 2 << ", ";
      F -= 1.0 / (i * 2);
    }
    i++;
  }

  cout << endl;

  cout << "Jumlah S = " << F;
}

void nomorLima()
{
  int i = 1;
  double F;
  F = 0.0;

  cout << "Nomor 5" << endl;
  cout << "S = ";

  while (i <= 4)
  {
    if (i % 3 == 0)
    {
      cout << "-" << i * 2 << "/" << i * 3 << ", ";
      F -= 1.0 / i;
    }
    else
    {
      cout << i * 2 << "/" << i * 3 << ", ";
      F += 1.0 / i;
    }
    i++;
  }

  cout << endl;

  cout << "Jumlah S = " << F;
}