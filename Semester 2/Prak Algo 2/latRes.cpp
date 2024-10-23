#include <iostream>
#include <fstream>

using namespace std;

struct Item
{
  string itemName;
  int amount;
};

struct Customer
{
  string username, address;
  Item item[100];
  int jmlItem;
};

string replaceSpasi(string str);  // mengubah spasi ke strip saat export file supaya tidak pindah kolom
string replaceHyphen(string str); // mengubah strip ke spasi saat import supaya di tampilan tidak ada strip

void writeFile(Customer customer[], int jmlCustomer);
int readFile(Customer customer[]);

void writeOrder(Customer customer[], int jmlCustomer);
void display(Customer customer[], int jmlCustomer);
void sortAsc(Customer customer[], int jmlCustomer);
void sortDesc(Customer customer[], int jmlCustomer);

int main()
{
  int pilihan, subpilihan;
  char menu;
  Customer customer[100];
  int jmlCustomer = 0;

  do
  {
    system("cls");
    jmlCustomer = readFile(customer);
    cout << "  --Welcome to HIF House--  " << endl;
    cout << "1. Write Order" << endl;
    cout << "2. List Order" << endl;
    cout << "3. Exit" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
      writeOrder(customer, jmlCustomer);
      break;
    case 2:
      system("cls");
      cout << " --- List Menu --- " << endl;
      cout << "1. Sort by name (Ascending)" << endl;
      cout << "2. Sort by name (Descending)" << endl;
      cout << "Menu : ";
      cin >> subpilihan;
      switch (subpilihan)
      {
      case 1:
        cout << "--- Original List ---" << endl;
        display(customer, jmlCustomer);
        cout << "--- List Sort by Name (Ascending) ---" << endl;
        sortAsc(customer, jmlCustomer);
        break;
      case 2:
        cout << "--- Original List ---" << endl;
        display(customer, jmlCustomer);
        cout << "--- List Sort by Name (Descending) ---" << endl;
        sortDesc(customer, jmlCustomer);
        break;
      default:

        break;
      }
      break;
    case 3:
      break;
    default:
      break;
    }
    cout << "Back to Menu? (y/n) : ";
    cin >> menu;
  } while (menu == 'Y' || menu == 'y');
}

string replaceSpasi(string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == ' ')
    {
      str[i] = '-';
    }
  }
  return str;
}

string replaceHyphen(string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '-')
    {
      str[i] = ' ';
    }
  }
  return str;
}

int readFile(Customer customer[])
{
  int jmlCustomer;
  ifstream file("list_order.txt");
  if (!file.is_open())
  {
    cout << "Gagal" << endl;
    return 0;
  }

  file >> jmlCustomer;

  for (int i = 0; i < jmlCustomer; i++)
  {
    file >> customer[i].username >> customer[i].address >> customer[i].jmlItem;
    customer[i].username = replaceHyphen(customer[i].username);
    customer[i].address = replaceHyphen(customer[i].address);
    for (int j = 0; j < customer[i].jmlItem; j++)
    {
      file >> customer[i].item[j].itemName >> customer[i].item[j].amount;
      customer[i].item[j].itemName = replaceHyphen(customer[i].item[j].itemName);
    }
  }
  file.close();
  return jmlCustomer;
}

void writeFile(Customer customer[], int jmlCustomer)
{
  ofstream file("list_order.txt");
  if (!file.is_open())
  {
    cout << "Gagal" << endl;
    return;
  }

  file << jmlCustomer << endl;
  for (int i = 0; i < jmlCustomer; i++)
  {
    customer[i].username = replaceSpasi(customer[i].username);
    customer[i].address = replaceSpasi(customer[i].address);
    file << customer[i].username << " "
         << customer[i].address << " "
         << customer[i].jmlItem << endl;
    for (int j = 0; j < customer[i].jmlItem; j++)
    {
      customer[i].item[j].itemName = replaceSpasi(customer[i].item[j].itemName);
      file << customer[i].item[j].itemName << " "
           << customer[i].item[j].amount << endl;
    }
  }
  file.close();
}

void writeOrder(Customer customer[], int jmlCustomer)
{
  int temp;

  cout << "--- Input Order ---" << endl;
  cout << "How many customer ? : ";
  cin >> temp;
  for (int i = jmlCustomer; i < jmlCustomer + temp; i++)
  {
    cout << i - jmlCustomer + 1 << ". Name : ";
    cin.ignore();
    getline(cin, customer[i].username);
    cout << "Address : ";
    getline(cin, customer[i].address);
    cout << "How many item ? : ";
    cin >> customer[i].jmlItem;
    for (int j = 0; j < customer[i].jmlItem; j++)
    {
      cout << "- Item name : ";
      cin.ignore();
      getline(cin, customer[i].item[j].itemName);
      cout << "  Amount : ";
      cin >> customer[i].item[j].amount;
    }
  }
  jmlCustomer = jmlCustomer + temp;
  writeFile(customer, jmlCustomer);
}

void display(Customer customer[], int jmlCustomer)
{
  if (jmlCustomer > 0)
  {
    for (int i = 0; i < jmlCustomer; i++)
    {
      cout << i + 1 << ". Name : " << customer[i].username << endl;
      cout << "   Address : " << customer[i].address << endl;
      cout << "   Amount : " << customer[i].jmlItem << endl;
      cout << "--------------------------------------" << endl;
      for (int j = 0; j < customer[i].jmlItem; j++)
      {
        cout << "- Name item : " << customer[i].item[j].itemName << endl;
        cout << "  Amount : " << customer[i].item[j].amount << endl;
      }
      cout << "======================================" << endl;
    }
  }
  else
  {
    cout << "Tidak ada" << endl;
  }
}

void sortAsc(Customer customer[], int jmlCustomer)
{
  string tempName, tempAdd, tempIt[100];
  int tempJml, tempAm[100];

  for (int i = 0; i < jmlCustomer - 1; i++)
  {
    int henti = 0;
    for (int j = 0; j < jmlCustomer - 1; j++)
    {
      if (customer[j].username > customer[j + 1].username)
      {
        tempName = customer[j].username;
        tempAdd = customer[j].address;
        tempJml = customer[j].jmlItem;
        for (int k = 0; k < tempJml; k++)
        {
          tempIt[k] = customer[j].item[k].itemName;
          tempAm[k] = customer[j].item[k].amount;
        }

        customer[j].username = customer[j + 1].username;
        customer[j].address = customer[j + 1].address;
        customer[j].jmlItem = customer[j + 1].jmlItem;
        for (int k = 0; k < customer[j].jmlItem; k++)
        {
          customer[j].item[k].itemName = customer[j + 1].item[k].itemName;
          customer[j].item[k].amount = customer[j].item[k].amount;
        }

        customer[j + 1].username = tempName;
        customer[j + 1].address = tempAdd;
        customer[j + 1].jmlItem = tempJml;
        for (int k = 0; k < customer[j + 1].jmlItem; k++)
        {
          customer[j + 1].item[k].itemName = tempIt[k];
          customer[j + 1].item[k].amount = tempAm[k];
        }
        henti++;
      }
    }
    if (henti == 0)
    {
      break;
    }
  }
  for (int i = 0; i < jmlCustomer; i++)
  {
    cout << i + 1 << ". Name : " << customer[i].username << endl;
    cout << "   Address : " << customer[i].address << endl;
    for (int j = 0; j < customer[i].jmlItem; j++)
    {
      cout << "     - Item name : " << customer[i].item[j].itemName << endl;
      cout << "       Amount : " << customer[i].item[j].amount << endl;
    }
  }
}

void sortDesc(Customer customer[], int jmlCustomer)
{
  string tempName, tempAdd, tempIt[100];
  int tempJml, tempAm[100];

  for (int i = 0; i < jmlCustomer - 1; i++)
  {
    int henti = 0;
    for (int j = 0; j < jmlCustomer - 1; j++)
    {
      if (customer[j].username < customer[j + 1].username)
      {
        tempName = customer[j].username;
        tempAdd = customer[j].address;
        tempJml = customer[j].jmlItem;
        for (int k = 0; k < tempJml; k++)
        {
          tempIt[k] = customer[j].item[k].itemName;
          tempAm[k] = customer[j].item[k].amount;
        }

        customer[j].username = customer[j + 1].username;
        customer[j].address = customer[j + 1].address;
        customer[j].jmlItem = customer[j + 1].jmlItem;
        for (int k = 0; k < customer[j].jmlItem; k++)
        {
          customer[j].item[k].itemName = customer[j + 1].item[k].itemName;
          customer[j].item[k].amount = customer[j].item[k].amount;
        }

        customer[j + 1].username = tempName;
        customer[j + 1].address = tempAdd;
        customer[j + 1].jmlItem = tempJml;
        for (int k = 0; k < customer[j + 1].jmlItem; k++)
        {
          customer[j + 1].item[k].itemName = tempIt[k];
          customer[j + 1].item[k].amount = tempAm[k];
        }
        henti++;
      }
    }
    if (henti == 0)
    {
      break;
    }
  }
  for (int i = 0; i < jmlCustomer; i++)
  {
    cout << i + 1 << ". Name : " << customer[i].username << endl;
    cout << "   Address : " << customer[i].address << endl;
    for (int j = 0; j < customer[i].jmlItem; j++)
    {
      cout << "     - Item name : " << customer[i].item[j].itemName << endl;
      cout << "       Amount : " << customer[i].item[j].amount << endl;
    }
  }
}