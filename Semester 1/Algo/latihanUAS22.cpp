// #include <iostream>
// using namespace std;
// string tim[13] = {"Argentina", "Prancis", "Kroasia", "Brazil", "Jerman", "Belgia", "Portugal", "Spanyol", "Inggris", "Uruguay", "Swiss", "Kolombia", "Meksiko"};
// string pelatih[13];
// string kapten[13];

// int pilihan;
// char ulang;

// void inputDataTim()
// {
//   cin.ignore();
//   for (int i = 0; i < 13; i++)
//   {
//     cin.ignore();
//     cout << "Masukkan nama pelatih dari tim " << tim[i] << " : ";
//     cin >> pelatih[i];

//     cin.ignore();
//     cout << "Masukkan nama kapten dari tim " << tim[i] << " : ";
//     cin >> kapten[i];
//   }
// }

// void outputTim()
// {
//   int i = 0;
//   while (i < 3)
//   {
//     cout << "Tim ke " << i +  << " : " << tim[i] << endl;
//     i++;
//   }
// }

// void outputDataTim()
// {
//   int i = 0;
//   while (i < 13)
//   {
//     cout << "Pelatih dari tim"
//          << " : " << tim[i] << " adalah " << pelatih[i] << endl;
//     cout << "Kapten dari tim"
//          << " : " << tim[i] << " adalah " << kapten[i] << endl;
//     i++;
//   }
// }

// int main()
// {
//   do
//   {
//     system("cls");
//     cout << "Menu piala dunia" << endl;
//     cout << "1. Lihat tim" << endl;
//     cout << "2. Input data tim" << endl;
//     cout << "3. Lihat data tim" << endl;
//     cout << "Pilih menu : ";
//     cin >> pilihan;

//     switch (pilihan)
//     {
//     case 1:
//       outputTim();
//       break;
//     case 2:
//       inputDataTim();
//       break;
//     case 3:
//       outputDataTim();
//       break;
//     default:
//       cout << "Pilihan menu tidak ada" << endl;
//       break;
//     }

//     cout << "Ulangin? (y/n) : ";
//     cin >> ulang;
//   } while (ulang == 'y' || ulang == 'Y');
// }

#include <iostream>
using namespace std;

void InputTeam();
void LihatTeam();

string Team[12][12];
string Pelatih[12][12];
string Asal[12][12];

int main()
{
  char kembali;
  do
  {
    system("cls");
    char Menu;
    cout << "Selamat Datang di Piala Dunia" << endl;
    cout << "Silahkan Pilih Menunya : " << endl;
    cout << "1. Input Team" << endl;
    cout << "2. Lihat Team" << endl;
    cout << "Input Menu : ";
    cin >> Menu;

    switch (Menu)
    {
    case '1':
      InputTeam();
      break;

    case '2':
      LihatTeam();
      break;

    default:
      cout << "Pilihan Tidak Valid" << endl;
      break;
    }
    cout << "Kembali : ";
    cin >> kembali;
  } while (kembali == 'y');
}

void InputTeam()
{

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << "Grup ke-" << i + 1 << " Tim ke-" << j + 1 << ": ";
      cin >> Team[i][j];
      cin.ignore();
      cout << "Pelatih : ";
      getline(cin, Pelatih[i][j]);
      cout << "Asal : ";
      getline(cin, Asal[i][j]);
      cout << endl;
    }
  }
}

void LihatTeam()
{
  int i = 0;
  int j = 0;
  while (i < 4)
  {
    while (j < 3)
    {
      cout << "Grup ke-" << i + 1 << " Tim ke-" << j + 1 << ": " << Team[i][j] << endl;
      cout << "Pelatih : " << Pelatih[i][j] << endl;
      cout << "Asal : " << Asal[i][j] << endl;
      cout << endl;
      j++;
    }
    j = 0;
    i++;
  }
}