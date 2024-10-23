#include <iostream>
using namespace std;

int pilihan;
char ulangi;

struct Node
{
  int info;
  string nama;
  int harga;
  Node *next;
};

string nama;
int harga;

Node *head, *tail;
int jmlnode = 0;

void buatList();
void sisipNode(string nama, int harga);
void hapusNode(string nama);
void printListMaju();
void printListMundur();

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
  head = new Node();
  head->info = 0;
  head->next = head;
}

bool listKosong()
{
  if (head->next == head)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void sisipNode(string nama, int harga)
{
  Node *nodeBaru = new Node();
  nodeBaru->nama = nama;
  nodeBaru->harga = harga;
  nodeBaru->next = NULL;

  if (listKosong())
  {
    nodeBaru->next = head;
    head->next = nodeBaru;
    jmlnode++;
    head->info = jmlnode;
  }
  else
  {
    Node *bantu = head;
    while (bantu->next->harga < harga && bantu->next != head)
    {
      bantu = bantu->next;
    }

    if (bantu->next != head)
    {
      nodeBaru->next = bantu->next;
      bantu->next = nodeBaru;
    }
    else
    {
      nodeBaru->next = head;
      bantu->next = nodeBaru;
    }
  }
  jmlnode++;
  head->info = jmlnode;
}

void hapusNode(string nama)
{
  if (listKosong())
  {
    cout << "List masih kosong" << endl;
  }
  else
  {
    Node *bantu = head;
    while (bantu->next->nama != nama && bantu->next != head)
    {
      bantu = bantu->next;
    }

    if (bantu->next != head)
    {
      Node *hapusList = bantu->next;
      bantu->next = hapusList->next;
      free(hapusList);
      jmlnode--;
      head->info = jmlnode;
      cout << "Data " << nama << " berhasil dihapus" << endl;
    }
    else
    {
      cout << "Data " << nama << " tidak ditemukan" << endl;
    }
  }
}

void printListMaju()
{
  if (listKosong())
  {
    cout << "List masih kosong" << endl;
    return;
  }
  Node *bantu = head->next;
  while (bantu != head)
  {
    cout << "Nama Kos : " << bantu->nama << endl;
    cout << "Harga Kos : " << bantu->harga << endl;
    bantu = bantu->next;
  }
}

void printListMundur()
{
  if (listKosong())
  {
    cout << "List masih kosong" << endl;
    return;
  }

  Node *depan = head;
  Node *bantu = head->next;
  Node *nextNode;

  Node *tail = head->next;

  while (bantu != head)
  {
    nextNode = bantu->next;
    bantu->next = depan;
    depan = bantu;
    bantu = nextNode;
  }
  head->next = depan;
  tail->next = head;

  // Node *bantu = head->next;
  // while (bantu != head)
  // {
  //   cout << "Nama Kos : " << bantu->nama << endl;
  //   cout << "Harga Kos : " << bantu->harga << endl;
  //   bantu = bantu->next;
  // }
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
  sisipNode(nama, harga);
}

void menu2()
{
  system("cls");
  cout << "1. Tampilkan list maju" << endl;
  cout << "2. Tampilkan list mundur" << endl;
  cout << "Pilih : ";
  cin >> pilihan;

  switch (pilihan)
  {
  case 1:
    system("cls");
    puts("===================================================================");
    puts("||                       Daftar Data Kosan Ascending              ||");
    puts("===================================================================");
    printListMaju();
    break;
  case 2:
    system("cls");
    puts("===================================================================");
    puts("||                       Daftar Data Kosan Descending             ||");
    puts("===================================================================");
    printListMundur();
    printListMaju();
    printListMundur();
    break;
  default:
    break;
  }
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