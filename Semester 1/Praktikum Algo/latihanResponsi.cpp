#include <iostream>
using namespace std;

int pilih, jumlahUser = 0;
char kembali;
string username[10];
string password[10];

void registrasi() {
  system("cls");
  cout << "Selamat Datang di Menu Registrasi!\n" << endl;
  cout << "Masukkan username : ";
  cin >> username[jumlahUser];

  cout << "Masukkan password : ";
  cin >> password[jumlahUser];

  jumlahUser++;
}

bool login() {
  string usernames, passwords;

  system("cls");
  cout << "Masukkan username : ";
  cin >> usernames;

  cout << "Masukkan password : ";
  cin >> passwords;

  for(int i = 0; i < jumlahUser; i++) {
    if(username[i] == usernames and password[i] == passwords) {
      cout << "Selamat Datang " << usernames << "!";
      return true;
    }
  }

  cout << "Mohon maaf, username atau password anda salah";
  return false;
}

int main() {
  do {
    cout << "Selamat Datang!\n" << endl;
    cout << "1. Registrasi" << endl;
    cout << "2. Login\n" << endl;
    cout << "Pilih Menu : ";
    cin >> pilih;
    
    switch(pilih) {
      case 1:
        registrasi();
      break;
      case 2:
        login();
      break;
      default:
        cout << "Masukkan menu yang benar!";
      break;
    }

    cout << "\nKembali ke menu utama? (y/n)";
    cin >> kembali;
  } while(kembali == 'Y' or kembali == 'y');
}