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

string line, cari;
// stringstream ss(line);

struct Order
{
  string name;
  int amount;
};

struct Customer
{
  string name, address;
  int jumlahOrder;
  Order order[1000];
};

Customer customer;
Customer showCustomer[1000];
Order order;

int menu, count, urut;
string fileName = "order_list.txt";

void writeData();
void readData();
void cariData(string *cari);
void deleteSeluruhData();

int main()
{
menuUtama:
  system("cls");
  cout << "Menu Utama" << endl;
  cout << "1. Write Data" << endl;
  cout << "2. List Data" << endl;
  cout << "3. Edit Data" << endl;
  cout << "4. Delete Data" << endl;
  cout << "5. Exit" << endl;
  cout << "Pilih Menu : ";
  cin >> menu;
  cin.ignore();

  switch (menu)
  {
  case 1:
    writeData();
    goto menuUtama;
    break;
  case 2:
    readData();
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    cout << "Pilih metode sorting : ";
    cin >> urut;

    if (urut == 1)
    {
      for (int i = 0; i < count; i++)
      {
        for (int j = 0; j < count - 1; j++)
        {
          if (showCustomer[j].name > showCustomer[j + 1].name)
          {
            customer = showCustomer[j];
            showCustomer[j] = showCustomer[j + 1];
            showCustomer[j + 1] = customer;
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
          if (showCustomer[j].name < showCustomer[j + 1].name)
          {
            customer = showCustomer[j];
            showCustomer[j] = showCustomer[j + 1];
            showCustomer[j + 1] = customer;
          }
        }
      }
    }

    for (int i = 0; i < count; i++)
    {
      cout << "Nama : " << showCustomer[i].name << endl;
      cout << "Address : " << showCustomer[i].address << endl;
      cout << "Jumlah Pesanan : " << showCustomer[i].jumlahOrder << endl;
      for (int j = 0; j < showCustomer[i].jumlahOrder; j++)
      {
        cout << "Pesanan ke-" << i + 1 << " : " << showCustomer[i].order[j].name << endl;
        cout << "Jumlah pesanan ke-" << i + 1 << " : " << showCustomer[i].order[j].amount << endl;
      }
    }
    break;
  case 3:
    readData();
    cout << "Nama yang ingin dicari : ";
    getline(cin, cari);
    cariData(&cari);
    break;
  case 4:
    deleteSeluruhData();
    break;
  case 5:
    break;
  default:
    break;
  }
}

void writeData()
{
  ofstream ofs(fileName, ios::app);
  if (ofs.is_open())
  {
    cout << "Masukkan nama : ";
    getline(cin, customer.name);
    ofs << customer.name << ", ";

    cout << "Masukkan address : ";
    getline(cin, customer.address);
    ofs << customer.address << ", ";

    cout << "Masukkan jumlah order : ";
    cin >> customer.jumlahOrder;
    ofs << customer.jumlahOrder << ", ";
    cin.ignore();

    for (int i = 0; i < customer.jumlahOrder; i++)
    {
      cout << "Masukkan menu order ke-" << i + 1 << " : ";
      getline(cin, customer.order[i].name);
      ofs << customer.order[i].name << ", ";

      cout << "Masukkan jumlah " << customer.order[i].name << " : ";
      cin >> customer.order[i].amount;
      ofs << customer.order[i].amount;
      cin.ignore();

      if (i != customer.jumlahOrder - 1)
      {
        ofs << ", ";
      }
    }
    ofs << endl;
  }
  else
  {
    cout << "Gagal membuat file";
  }
}

// void readData()
// {
//   count = 0;
//   while (getline(ifs, line))
//   {
//     getline(ss, showCustomer[count].name, ',');
//     getline(ss, showCustomer[count].address, ',');
//     ss >> showCustomer[count].jumlahOrder;
//     ss.ignore();

//     for (int i = 0; i < showCustomer[count].jumlahOrder; i++)
//     {
//       getline(ss, showCustomer[count].order[i].name, ',');
//       ss >> showCustomer[count].order[i].amount;
//       ss.ignore();
//     }
//     count++;
//   }
// }

void readData()
{
  ifstream ifs("order_list.txt");
  count = 0;
  while (getline(ifs, line))
  {
    stringstream ss(line);
    getline(ss, showCustomer[count].name, ',');

    getline(ss, showCustomer[count].address, ',');
    ss >> showCustomer[count].jumlahOrder;
    ss.ignore();

    for (int i = 0; i < showCustomer[count].jumlahOrder; i++)
    {
      getline(ss, showCustomer[count].order[i].name, ',');

      ss >> showCustomer[count].order[i].amount;
      ss.ignore();
    }

    count++;
  }
}

void cariData(string *cari)
{

  for (int i = 0; i < count; i++)
  {
    if (*cari == showCustomer[i].name)
    {
      cout << "Nama : " << showCustomer[i].name << endl;
      cout << "Address : " << showCustomer[i].address << endl;
      cout << "Jumlah Pesanan : " << showCustomer[i].jumlahOrder << endl;
      for (int j = 0; j < showCustomer[i].jumlahOrder; j++)
      {
        cout << "Pesanan ke-" << i + 1 << " : " << showCustomer[i].order[j].name << endl;
        cout << "Jumlah pesanan ke-" << i + 1 << " : " << showCustomer[i].order[j].amount << endl;
      }
    }
  }
}

void deleteSeluruhData()
{

  ofstream ofs(fileName, ios::trunc);

  if (!ofs.is_open())
  {
    cout << "Gagal" << endl;
    return;
  }

  ofs.close();

  cout << "Berhasil dihapus" << endl;
}