#include <iostream>
using namespace std;

int pilihan, banyakData;
char ulangi;

int main()
{
  system("cls");

  cout << "Masukkan banyak data : ";
  cin >> banyakData;

  int data[banyakData];

  int dataLength = (sizeof(data) / sizeof(*(data)));

  // sequential
  int i, x;
  bool found;

  // binary
  int cari, awal = 0, akhir, tengah;
  akhir = dataLength;
  do
  {
    cout << "1. Input data" << endl;
    cout << "2. Cari data" << endl;
    cout << "3. Tampil data" << endl;
    cout << "Pilih Menu : ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
      for (int i = 0; i < banyakData; i++)
      {
        cout << "Masukkan data ke-" << i << " : ";
        cin >> data[i];
      }

      break;
    case 2:
      cout << "Pilih metode searching yang ingin digunakan : " << endl;
      cout << "1. Sequential Search" << endl;
      cout << "2. Binary Search" << endl; // Tambahkan endl untuk pemisah
      cout << "Pilih : ";
      cin >> pilihan;

      switch (pilihan)
      {
      case 1:
        cout << "Masukkan nilai yang dicari : ";
        cin >> x;

        i = 0;
        found = false;

        data[dataLength - 1] = x; // sentinel

        while ((i <= 10) && (!found) && (data[i] <= x))
        {
          if (data[i] == x)
          {
            found = true;
          }
          else
          {
            i++;
          }
        }

        if (i < banyakData && (found))
        {
          cout << x << " ditemukan pada array index ke : " << i << endl;
        }
        else
        {
          cout << x << " tidak ada pada array" << endl;
        }

        cout << " " << endl;

        break;
      case 2:

        cout << "Masukkan nilai yang ingin dicari : ";
        cin >> cari;

        cout << "Data setelah diurutkan" << endl;
        for (int i = 0; i < banyakData; i++)
        {
          for (int j = i + 1; j < banyakData; j++)
          {
            if (data[i] > data[j])
            {
              int temp = data[i];
              data[i] = data[j];
              data[j] = temp;
            }
          }
        }


        for (int i = 0; i < banyakData; i++)
        {
          cout << "Data ke-" << i << data[i] << endl;
        }

        cout << endl;

        while (awal <= akhir)
        {
          tengah = (awal + akhir) / 2;
          if (data[tengah] == cari)
          {
            cout << cari << " ditemukan pada array index ke : " << tengah << endl;
            break;
          }
          else if (data[tengah] < cari)
          {
            awal = tengah + 1;
          }
          else
          {
            akhir = tengah - 1;
          }
        }

        if (awal > akhir)
        {
          cout << cari << " tidak ada pada array" << endl;
        }





        break;
      default:
        break;
      }
      break;
    case 3:

      for (int i = 0; i < banyakData; i++)
      {
        cout << "Data ke-" << i << " : " << data[i] << endl;
      }
      break;
    default:
      cout << "Masukkan menu yang sesuai";
      break;
    }
    cout << "\nKembali ke menu? (y/n) : "; // kembali ke menu
    cin >> ulangi;
  } while (ulangi == 'Y' || ulangi == 'y');
}
