#include <iostream>
using namespace std;

int pilih, nim, jumlahNilai;
int UTS[100], UAS[100];
int a, b, arab;
string nama;

void menu1()
{
  cout << "**Menu Input Nilai**" << endl;
  cout << endl;
  cout << "Input Data" << endl;
  cout << "   Nama   :  ";
  cin.ignore();
  getline(cin, nama);
  cout << "   NIM   :  ";
  cin >> nim;
  cout << "   Berapa matkul yang akan diinput : ";
  cin >> jumlahNilai;
  system("cls");
  for (int i = 1; i <= jumlahNilai; i++)
  {
    cout << "   Mata Kuliah ke-" << i << " : " << endl;
    cout << "   Nilai UTS: ";
    cin >> UTS[i];
    cout << "   Nilai UAS: ";
    cin >> UAS[i];
  }

  cout << "Lihat Data" << endl;
  cout << "   Nama : " << nama << endl;
  cout << "   NIM  : " << nim << endl;
  cout << "   Nilai Ujian : " << endl;

  for (int i = 1; i <= jumlahNilai; i++)
  {
    cout << "   Mata Kuliah ke-" << i << " : ";
    cout << "   Nilai UTS: " << UTS[i] << endl;
    cout << "   Nilai UAS: " << UAS[i] << endl;
  }
}

void menu2()
{
  cout << "**Menu Convert Bilangan Romawi**" << endl;
  cout << "Sub menu ini akan mengkonversi bilangan arab menjadi bilangan romawi." << endl;
  cout << "Masukkan angka : ";
  cin >> arab;

  if (arab >= 4000)
  {
    cout << "Mohon maaf, angka yang anda masukkan terlalu besar";
  }
  else
  {
    while (arab >= 1000)
    {
      cout << "M";
      arab -= 1000;
    }
    while (arab >= 900)
    {
      cout << "CM";
      arab -= 900;
    }
    while (arab >= 500)
    {
      cout << "D";
      arab -= 500;
    }
    while (arab >= 400)
    {
      cout << "CD";
      arab -= 400;
    }
    while (arab >= 100)
    {
      cout << "C";
      arab -= 100;
    }
    while (arab >= 90)
    {
      cout << "XC";
      arab -= 90;
    }
    while (arab >= 50)
    {
      cout << "L";
      arab -= 50;
    }
    while (arab >= 40)
    {
      cout << "XL";
      arab -= 40;
    }
    while (arab >= 10)
    {
      cout << "X";
      arab -= 10;
    }
    while (arab >= 9)
    {
      cout << "IX";
      arab -= 9;
    }
    while (arab >= 5)
    {
      cout << "V";
      arab -= 5;
    }
    while (arab >= 4)
    {
      cout << "IV";
      arab -= 4;
    }
    while (arab >= 1)
    {
      cout << "I";
      arab -= 1;
    }
  }

  
}

void menu3()
{
  cout << "**Menu Pengecekan Subset**" << endl;
  cout << "Sub menu ini mengecek apakah ArrayB ada di dalam ArrayA atau tidak." << endl;

  cout << "ArrayA : " << endl;
  cout << "Input berapa banyak nilai pada ArrayA : ";
  cin >> a;

  int arrayA[a];

  for (int i = 0; i < a; i++)
  {
    cout << "  ArrayA index ke- " << i << " : ";
    cin >> arrayA[i];
  }

  cout << "ArrayB : " << endl;
  cout << "Input berapa banyak nilai pada ArrayB : ";
  cin >> b;

  int arrayB[b];

  for (int i = 0; i < b; i++)
  {
    cout << "  ArrayB index ke- " << i << " : ";
    cin >> arrayB[i];
  }

  if (b > a)
  {
    cout << "Mohon maaf, ArrayB tidak bisa lebih banyak dari ArrayA";
  }
  else
  {
    for (int i = 0; i < b; i++)
    {
      for (int j = 0; j < a; j++)
      {
        if (arrayB[i] == arrayA[j])
        {
          cout << "ArrayB merupakan subset dari ArrayA";
          return;
        }
        else
        {
          cout << "ArrayB bukan merupakan subset dari ArrayA";
          return;
        }
      }
    }
  }
}

int main()
{
  cout << "===============" << endl;
  cout << "    RESPONSI   " << endl;
  cout << "===============" << endl;

  cout << endl;

  cout << "Menu Utama : " << endl;
  cout << endl;

  cout << "1. Menu Input Nilai" << endl;
  cout << "2. Convert Bilangan Romawi" << endl;
  cout << "3. Subset Array" << endl;
  cout << endl;

  cout << "Pilih Menu (1/2/3) : ";
  cin >> pilih;

  switch (pilih)
  {
  case 1:
    menu1();
    break;
  case 2:
    menu2();
    break;
  case 3:
    menu3();
    break;
  default:
    cout << "Masukkan menu yang sesuai";
    break;
  }
}