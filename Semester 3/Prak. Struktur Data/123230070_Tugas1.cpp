#include <iostream>
using namespace std;

int pilihan;
char ulangi;

struct Node
{
  string nama;
  int harga;
  Node *next;
};

string nama;
int harga;

Node *head, *tail;

void buatList();
void sisipDepan(string nama, int harga);
void sisipTengah(string nama, int harga);
void sisipBelakang(string nama, int harga);
void hapusNode(string nama);
void printList();

void menu1();
void menu2();
void menu3();

int main()
{
  buatList();
  do
  {
    system("cls");
    puts("===================================================================");
    puts("||                             Menu                              ||");
    puts("===================================================================");
    puts("||                      1. Input Kosan                           ||");
    puts("||                      2. Lihat Data Kosan                      ||");
    puts("||                      3. Hapus Data Kosan                      ||");
    puts("||                      4. Exit                                  ||");
    puts("===================================================================");
    cout << "Pilihan : ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan)
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
    case 4:
      exit(0);
      break;
    default:
      cout << "Pilih menu yang sesuai" << endl;
      break;
    }
    cout << "\nKembali ke menu? (y/n) : ";
    cin >> ulangi;
  } while (ulangi == 'Y' || ulangi == 'y');
}

void buatList()
{
  head = NULL;
  tail = NULL;
}

void sisipDepan(string nama, int harga)
{
  Node *nodeBaru = new Node();
  nodeBaru->nama = nama;
  nodeBaru->harga = harga;
  nodeBaru->next = NULL;

  if (head == NULL)
  {
    head = nodeBaru;
    tail = nodeBaru;
  }
  else
  {
    nodeBaru->next = head;
    head = nodeBaru;
  }
}

void sisipTengah(string nama, int harga)
{
  Node *nodeBaru = new Node();
  nodeBaru->nama = nama;
  nodeBaru->harga = harga;
  nodeBaru->next = NULL;

  Node *current = head;

  while (current->next->harga < harga)
  {
    current = current->next;
  }
  nodeBaru->next = current->next;
  current->next = nodeBaru;
}

void sisipBelakang(string nama, int harga)
{
  Node *nodeBaru = new Node();
  nodeBaru->nama = nama;
  nodeBaru->harga = harga;
  nodeBaru->next = NULL;

  if (head == NULL)
  {
    head = nodeBaru;
    tail = nodeBaru;
  }
  else
  {
    tail->next = nodeBaru;
    tail = nodeBaru;
  }
}

void hapusNode(string nama)
{
  Node *current = head;

  if (current->nama == nama)
  {
    head = current->next;
    free(current);
    cout << "Data " << nama << " berhasil dihapus" << endl;
  }
  else
  {
    while (current->next->nama != nama && current->next->next != NULL)
    {
      current = current->next;
    }

    if (current->next->nama == nama)
    {
      Node *del = current->next;
      current->next = del->next;
      free(del);
      cout << "Data " << nama << " berhasil dihapus" << endl;
    }
    else
    {
      cout << "Data " << nama << " tidak ditemukan" << endl;
    }
  }
}

void printList()
{
  if (head != NULL)
  {
    Node *current = head;

    while (current != NULL)
    {
      cout << "Nama kos : " << current->nama << endl;
      cout << "Harga kos : " << current->harga << endl;
      cout << endl;
      current = current->next;
    }
  }
  else
  {
    cout << "Data masih kosong" << endl;
  }
}

void menu1()
{
  system("cls");
  puts("===================================================================");
  puts("||                       Input Data Kosan                        ||");
  puts("===================================================================");
  cout << "Nama Kosan : ";
  getline(cin, nama);
  cout << "Harga/Bulan : ";
  cin >> harga;
  cout << endl;
  cout << "Pilihan Sisip" << endl;
  cout << "1. Sisip Depan" << endl;
  cout << "2. Sisip Tengah" << endl;
  cout << "3. Sisip Belakang" << endl;
  cout << "Pilih : ";
  cin >> pilihan;
  switch (pilihan)
  {
  case 1:
    sisipDepan(nama, harga);
    break;
  case 2:
    sisipTengah(nama, harga);
    break;
  case 3:
    sisipBelakang(nama, harga);
    break;
  default:
    cout << "Pilih menu yang sesuai" << endl;
    break;
  }
}

void menu2()
{
  system("cls");
  puts("===================================================================");
  puts("||                       Daftar Data Kosan                       ||");
  puts("===================================================================");
  printList();
}

void menu3()
{
  system("cls");
  puts("===================================================================");
  puts("||                       Hapus Data Kosan                        ||");
  puts("===================================================================");
  cout << "Masukkan nama kos yang ingin digusur : ";
  getline(cin, nama);
  hapusNode(nama);
}