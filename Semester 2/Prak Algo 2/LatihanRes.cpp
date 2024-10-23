// You are being asked to make a simple program, where they can write and
// read orders which consist of several customers with several orders of
// each customer.
// - They only asked for 3 menu which Write Order, List Order,
// and Exit.
// - Customer data consist of name and address, while order data consist of
// name and amount.
// - They asked that they can sort the order by the customer's name with
// 2 kind which ascending and descending.
// - They allow you to use whatever sort method

// Running program instructions :
// 1. Don't delete the order_list.txt file (for first time) and
//    check the file example
// 2. Try to run program and check Menu List Order first
// 3. After that you can try Menu Write Order

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int menu;
int jumlahCustomer = 1000;
int jumlahPesanan;
int urut;
char kembali;
int count;
string line, cari;
int customerCount;

struct customer
{
  string name, address;
  int jumlahPesanan;
  string pesanan[1000];
  int banyakPesanan[1000];
};

stringstream ss(line);

customer customers;
customer showCustomers[1000];

string fileName = "order_list.txt";

ifstream ifs("order_list.txt");
ofstream ofs(fileName, ios::app);

int countLines()
{
  int count = 0;
  string line;
  while (getline(ifs, line))
  {
    count++;
  }
  return count;
}

int jumlahBaris = countLines();

void bacaData()
{
  ifstream ifs("order_list.txt");
  count = 0;
  while (getline(ifs, line))
  {
    ss.str(line);
    ss.clear();
    getline(ss, showCustomers[count].name, ',');
    getline(ss, showCustomers[count].address, ',');
    ss >> showCustomers[count].jumlahPesanan;
    ss.ignore();
    for (int j = 0; j < showCustomers[count].jumlahPesanan; j++)
    {
      getline(ss, showCustomers[count].pesanan[j], ',');
      ss >> showCustomers[count].banyakPesanan[j];
      ss.ignore();
    }
    count++;
  }
}

int main()
{
menuUtama:
  system("cls");
  cout << "Menu Utama" << endl;
  cout << "1. Write Order" << endl;
  cout << "2. List Order" << endl;
  cout << "3. Cari Data" << endl;
  cout << "4. Hapus Data" << endl;

  cout << "Masukkan pilihan menu : ";
  cin >> menu;
  cin.ignore();

  switch (menu)
  {
  case 1:
    if (ofs.is_open())
    {
      cout << "Masukkan nama : ";
      getline(cin, customers.name);
      ofs << customers.name << ", ";

      cout << "Masukkan address : ";
      getline(cin, customers.address);
      ofs << customers.address << ", ";

      cout << "Masukkan jumlah pesanan : ";
      cin >> customers.jumlahPesanan;
      ofs << customers.jumlahPesanan << ", ";
      cin.ignore();

      for (int j = 0; j < customers.jumlahPesanan; j++)
      {
        cout << "Masukkan menu ke-" << j + 1 << " : ";
        getline(cin, customers.pesanan[j]);
        ofs << customers.pesanan[j] << ", ";

        cout << "Masukkan jumlah " << customers.pesanan[j] << " : ";
        cin >> customers.banyakPesanan[j];
        ofs << customers.banyakPesanan[j];
        if (j < customers.jumlahPesanan - 1)
        {
          ofs << ", ";
        }
        cin.ignore();
      }

      ofs << endl;
      goto menuUtama;

      ofs.close();
    }
    else
    {
      cout << "Gagal membuat file";
    }
    break;
  case 2:
    if (jumlahBaris == 0)
    {
      cout << "Tidak ada data" << endl;
      goto menuUtama;
    }
    else
    {
      bacaData();
      cout << "1. Ascending" << endl;
      cout << "2. Descending" << endl;
      cout << "Masukkan pilihan urutan : ";
      cin >> urut;
      cin.ignore();

      if (urut == 1)
      {
        for (int i = 0; i < count; i++)
        {
          for (int j = 0; j < count - 1; j++)
          {
            if (showCustomers[i].name < showCustomers[j].name)
            {
              customers = showCustomers[i];
              showCustomers[i] = showCustomers[j];
              showCustomers[j] = customers;
            }
          }
        }
      }
      else if (urut == 2)
      {
        for (int i = 0; i < count; i++)
        {
          for (int j = 0; j < count - 1; j++)
          {
            if (showCustomers[i].name > showCustomers[j].name)
            {
              customers = showCustomers[i];
              showCustomers[i] = showCustomers[j];
              showCustomers[j] = customers;
            }
          }
        }
      }

      for (int i = 0; i < count; i++)
      {
        if (showCustomers[i].name != "")
        {
          cout << "Nama : " << showCustomers[i].name << endl;
          cout << "Address :" << showCustomers[i].address << endl;
          cout << "Jumlah Pesanan : " << showCustomers[i].jumlahPesanan << endl;
          for (int j = 0; j < showCustomers[i].jumlahPesanan; j++)
          {
            cout << "Pesanan ke-" << j + 1 << " : " << showCustomers[i].pesanan[j] << endl;
            cout << "Banyak Pesanan : " << showCustomers[i].banyakPesanan[j] << endl;
          }
          cout << endl;
        }
      }
      cout << "Kembali ke menu utama? (y/n) : ";
      cin >> kembali;
      if (kembali == 'y')
      {
        goto menuUtama;
      }
      else
      {
        break;
      }
    }
    break;
  case 3:
    cout << "Masukkan nama yang dicari : ";
    cin >> cari;

    bacaData();

    for (int i = 0; i < count; i++)
    {
      if (cari == showCustomers[i].name)
      {
        cout << "Nama : " << showCustomers[i].name << endl;
        cout << "Address :" << showCustomers[i].address << endl;
        cout << "Jumlah Pesanan : " << showCustomers[i].jumlahPesanan << endl;
        for (int j = 0; j < showCustomers[i].jumlahPesanan; j++)
        {
          cout << "Pesanan ke-" << j + 1 << " : " << showCustomers[i].pesanan[j] << endl;
          cout << "Banyak Pesanan : " << showCustomers[i].banyakPesanan[j] << endl;
        }
      }
    }
    break;
  case 4:
    cout << "Masukkan nama yang ingin dihapus : ";
    cin >> cari;

    bacaData();

    for (int i = 0; i < count; i++)
    {
      if (cari == showCustomers[i].name)
      {
        showCustomers[i].name = "";
        showCustomers[i].address = "";
        showCustomers[i].jumlahPesanan = 0;
        for (int j = 0; j < showCustomers[i].jumlahPesanan; j++)
        {
          showCustomers[i].pesanan[j] = "";
          showCustomers[i].banyakPesanan[j] = 0;
        }
      }
    }

    // ofstream ofs(fileName);

    for (int i = 0; i < count; i++)
    {
      ofs << showCustomers[i].name << ", ";
      ofs << showCustomers[i].address << ", ";
      ofs << showCustomers[i].jumlahPesanan << ", ";
      for (int j = 0; j < showCustomers[i].jumlahPesanan; j++)
      {
        ofs << showCustomers[i].pesanan[j] << ", ";
        ofs << showCustomers[i].banyakPesanan[j];
        if (j < showCustomers[i].jumlahPesanan - 1)
        {
          ofs << ", ";
        }
      }
      ofs << endl;
    }

    ofs.close();
    break;
  default:
    break;
  }
}