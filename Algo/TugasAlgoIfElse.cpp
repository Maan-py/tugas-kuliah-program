#include <iostream>
using namespace std;

int main() {
  char jk;
  int umur;
  string pddk;

  cout << "Masukkan jenis kelamin (L/P) : ";
  cin >> jk;

  cout << "Masukkan umur : ";
  cin >> umur;
  cin.ignore();
  
  cout << "Masukkan Pendidikan : ";
  getline(cin, pddk);

  if(jk == 'P' && umur >= 20 && pddk == "s1") {
    cout << "Kelompok A";
  } else if(jk == 'P' && umur >= 30 && pddk == "sma") {
    cout << "Kelompok B";
  } else if(jk == 'L' && umur <= 45 && pddk == "s2") {
    cout << "Kelompok C";
  } else if(jk == 'L' && umur >= 20 && pddk == "smp") {
    cout << "Kelompok D";
  }else {
    cout << "Kelompok E";
  }
}