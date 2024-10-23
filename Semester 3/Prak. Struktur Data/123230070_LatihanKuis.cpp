#include <iostream>
using namespace std;

int pilih;

struct Node
{
  int info;
  string noRek;
  int tabungan;
  Node *next;
};

string noRek;
int tabungan, input;
char ulang;

Node *kepala, *NB, *bantu, *hapus;
int jumlahNode = 0;

void buatList()
{
  kepala = new Node();
  kepala->info = 0;
  kepala->next = kepala;
}

bool listKosong()
{
  if (kepala->next == kepala)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void sisipNode(string noRek, int tabungan)
{
  NB = new Node();
  NB->noRek = noRek;
  NB->tabungan = tabungan;
  NB->next = NULL;

  if (listKosong())
  {
    NB->next = kepala;
    kepala->next = NB;
    jumlahNode++;
    kepala->info = jumlahNode;
  }
  else
  {
    bantu = kepala;
    while (bantu->next->tabungan < tabungan && bantu->next != kepala)
    {
      bantu = bantu->next;
    }

    if (bantu->next != kepala)
    {
      NB->next = bantu->next;
      bantu->next = NB;
    }
    else
    {
      NB->next = kepala;
      bantu->next = NB;
    }
    jumlahNode++;
    kepala->info = jumlahNode;
  }
}

void hapusNode(string noRek)
{
  if (listKosong())
  {
    cout << "List kosong" << endl;
  }
  else
  {
    bantu = kepala;
    while (bantu->next->noRek != noRek && bantu->next != kepala)
    {
      bantu = bantu->next;
    }

    if (bantu->next != kepala)
    {
      hapus = bantu->next;
      bantu->next = hapus->next;
      free(hapus);
      cout << "Rekening " << noRek << " berhasil dihapus" << endl;
    }
    else
    {
      hapus = bantu->next;
      bantu->next = kepala;
      free(hapus);
      cout << "Rekening " << noRek << " berhasil dihapus" << endl;
    }
    jumlahNode--;
    kepala->info = jumlahNode;
  }
}

void bacaMaju()
{
  if (listKosong())
  {
    cout << "List masih kosong" << endl;
    return;
  }

  bantu = kepala->next;
  while (bantu != kepala)
  {
    cout << "No. Rekening : " << bantu->noRek << endl;
    cout << "Tabungan : " << bantu->tabungan << endl;
    bantu = bantu->next;
  }
}

void search(string noRek)
{
  if (listKosong())
  {
    cout << "List masih kosong" << endl;
    return;
  }

  bantu = kepala->next;
  bool found = false;

  while (bantu != kepala)
  {
    if (bantu->noRek == noRek)
    {
      cout << "No. Rekening : " << bantu->noRek << endl;
      cout << "Tabungan : " << bantu->tabungan << endl;
      found = true;
      break;
    }
    bantu = bantu->next;
  }

  if (!found)
  {
    cout << "Rekening " << noRek << " tidak ditemukan" << endl;
  }
}

int main()
{

  buatList();
  do
  {
    system("cls");
    cout << "ADMIN BANK" << endl;
    cout << "==========" << endl;
    cout << "1. Input" << endl;
    cout << "2. Output" << endl;
    cout << "3. Search" << endl;
    cout << "4. Delete" << endl;
    cout << "5. Exit" << endl;
    cout << "==========" << endl;
    cout << "Pilih menu (1-5) : ";
    cin >> pilih;
    cin.ignore();

    switch (pilih)
    {
    case 1:
      cout << "Jumlah input :";
      cin >> input;

      for (int i = 1; i <= input; i++)
      {
        cin.ignore();
        cout << "Masukkan nomor rekening : ";
        getline(cin, noRek);
        cout << "Masukkan tabungan : ";
        cin >> tabungan;
        sisipNode(noRek, tabungan);
      }
      break;
    case 2:
      bacaMaju();
      cout << kepala->info;
      break;
    case 3:
      cout << "Masukkan nomor rekening yang ingin dicari : ";
      getline(cin, noRek);
      search(noRek);
      break;
    case 4:
      cout << "Masukkan rekening yang ingin dihapus :";
      getline(cin, noRek);
      hapusNode(noRek);
      break;
    case 5:
      exit(1);
      break;
    default:
      cout << "Masukkan menu yang sesuai" << endl;
      break;
    }
    cout << "Kembali ke menu ? (y/n) :";
    cin >> ulang;
  } while (ulang == 'Y' || ulang == 'y');
}