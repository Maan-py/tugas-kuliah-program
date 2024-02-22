#include <iostream>
#include <cmath>
using namespace std;

void nomorSatu(int j, int *S);
void nomorDua(int j, int *S);
void nomorTiga(int j);
void nomorEmpat(int j);
void nomorLima(int j);

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

  nomorTiga(j);

  cout << endl;

  nomorEmpat(j);

  cout << endl;

  nomorLima(j);
}

void nomorSatu(int j, int *S)
{
  int i = 1;
  *S = 0;

  cout << "Nomor 1" << endl;
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

  cout << "Nomor 2" << endl;
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

void nomorTiga(int j)
{
  int i = 1;
  double F;
  F = 0.0;

  cout << "Nomor 3" << endl;
  cout << "S = ";

  while (i <= j)
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

void nomorEmpat(int j)
{

  int i = 1;
  double F;
  F = 0.0;

  cout << "Nomor 4" << endl;
  cout << "S = ";

  while (i <= j)
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

void nomorLima(int j)
{
  int i = 1;
  int ulang = 1;
  double F;
  F = 0.0;

  cout << "Nomor 5" << endl;
  cout << "S = ";

  while (i <= j)
  {
    if (i % 3 == 0)
    {
      cout << "-" << pow(2, i) << "/" << pow(3, i) << ", ";
      F -= pow(2, i) / pow(3, i);
    }
    else
    {
      cout << pow(2, i) << "/" << pow(3, i) << ", ";
      F += pow(2, i) / pow(3, i);
    }
    ulang++;
    i++;
  }

  cout << endl;

  cout << "Jumlah S = " << F;
}