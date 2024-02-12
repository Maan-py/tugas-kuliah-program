#include <iostream>
#include <string>
using namespace std;

typedef struct {
  int ISBN;
  string judul;
  string penulis;
  string penerbit;
  int tahunTerbit;
  string genre;
  int jumlahEksemplar;
} Buku;

typedef struct {
  string nama;
  string alamat;
  int nomorTelepon;
  string email;
  int tglLahir;
  string statusAnggota;
} Anggota;

typedef struct {
  int tglPeminjaman;
  int tglJatuhTempo;
  Buku bukuYangDipinjam;
  string statusPeminjaman;
} Peminjaman;

int main() {
}