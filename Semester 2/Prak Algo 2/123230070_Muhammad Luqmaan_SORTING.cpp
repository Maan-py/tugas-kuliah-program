#include <iostream>
#include <stdlib.h>
using namespace std;

int pilih, urutan, sorting, jumlahAngka = 0;
int angka[100];
int first = 0;
int last = 0;
char ulang;
bool sorted = false;

void menuInput();
void menuSorting();
void menuOutput();
void menuPengurutan();

void bubbleSort(int angka[], int jumlahAngka);
void insertionSort(int angka[], int jumlahAngka);
void selectionSort(int angka[], int jumlahAngka);
void shellSort(int angka[], int jumlahAngka);
void quickSort(int angka[], int first, int last);

int main() {
  do {
    system("cls");
    cout << "Menu utama" << endl;
    cout << "1. Input jumlah data" << endl;
    cout << "2. Pilih metode sorting" << endl;
    cout << "3. Output data" << endl;
    cout << "4. Keluar" << endl;

    cout << "\nPilih menu : ";
    cin >> pilih;

    switch (pilih) {
    case 1:
      menuInput();
      break;
    case 2:
      menuSorting();
      break;
    case 3:
      menuOutput();
      break;
    case 4:
      cout << "\nTerima Kasih!" << endl;
      return ulang = 'n';
      break;
    default:
      cout << "Masukkan menu yang sesuai!" << endl;
      break;
    }
    cout << "\nKembali ke menu? (y/n) ";
    cin >> ulang;
  } while (ulang == 'Y' || ulang == 'y');
}

void menuInput() {
  system("cls");
  sorting = 0;
  cout << "Masukkan jumlah data yang diingikan : ";
  cin >> jumlahAngka;

  srand(time(NULL)); // biar tidak selalu return angka yang sama

  for (int i = 0; i < jumlahAngka; i++) {
    angka[i] = rand() % 100 + 1;
  }
}

void menuSorting() {
    system("cls");
    
    if(sorted) {
      cout << "Data sudah pernah di-sort sebelummnya. Sebaiknya, keluar dari program dahulu, lalu input jumlah data baru.\n"
           << endl;
    }

    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Shell Sort" << endl;
    cout << "5. Quick Sort" << endl;

    cout << "\nPilih Jenis Sorting : ";
    cin >> sorting;
    menuPengurutan();
}

void menuOutput() {
  system("cls");
  cout << "Banyaknya data "
       << " : " << jumlahAngka << endl;

  cout << "\nData yang belum di-sorting : " << endl;
  for (int i = 0; i < jumlahAngka; i++) {
    cout << angka[i] << " ";
  }

  cout << endl;

  switch (sorting) {
  case 1:
    sorted = true;
    bubbleSort(angka, jumlahAngka);
    break;
  case 2:
    sorted = true;
    insertionSort(angka, jumlahAngka);
    break;
  case 3:
    sorted = true;
    selectionSort(angka, jumlahAngka);
    break;
  case 4:
    sorted = true;
    shellSort(angka, jumlahAngka);
    break;
  case 5:
    sorted = true;
    last = jumlahAngka - 1;
    cout << "\nQuick Sort"
         << " : ";
    quickSort(angka, first, last);
    break;
  default:
    if (sorting) {
      cout << "Pilih menu yang tersedia!" << endl;
    } else {
      cout << "";
    }
    break;
  }

  if (sorting && urutan) {
    cout << "\n\nData yang sudah di-sorting : " << endl;
    for (int i = 0; i < jumlahAngka; i++) {
      cout << angka[i] << " ";
    }

    cout << endl;
  } else {
    cout << "\n\nData yang sudah di-sorting : " << endl;
    cout << "Pilih metode sorting (menu 2) dahulu." << endl;
  }
}

void menuPengurutan() {
  system("cls");
  cout << "Pilih pengurutan : " << endl;
  cout << "1. Ascending" << endl;
  cout << "2. Descending" << endl;
  cout << "Pilih : ";
  cin >> urutan;
}

void bubbleSort(int angka[], int jumlahAngka) {
  int temp, i, j;

  cout << "\nBubble Sort" << " : ";
  if (urutan == 1) {
    // Ascending sort
    for (i = 0; i < jumlahAngka - 1; i++) {
      for (j = 0; j < jumlahAngka - 1 - i; j++) {
        if (angka[j] > angka[j + 1]) {
          temp = angka[j];
          angka[j] = angka[j + 1];
          angka[j + 1] = temp;
        }
      }
      // menampilkan perubahan data
      cout << endl;
      for (int k = 0; k < jumlahAngka; k++) {
        cout << angka[k] << " ";
      }
    }
  } else if (urutan == 2) {
    // Descending sort
    for (i = 0; i < jumlahAngka - 1; i++) {
      for (j = 0; j < jumlahAngka - 1 - i; j++) {
        if (angka[j] < angka[j + 1]) {
          temp = angka[j];
          angka[j] = angka[j + 1];
          angka[j + 1] = temp;
        }
      }
      // menampilkan perubahan data
      cout << endl;
      for (int k = 0; k < jumlahAngka; k++) {
        cout << angka[k] << " ";
      }
    }
  }
}

void insertionSort(int angka[], int jumlahAngka) {
  int temp, i, j;

  cout << "\nInsertion Sort"
       << " : ";
  if (urutan == 1) {
    // Ascending sort
    for (i = 1; i < jumlahAngka; i++) {
      temp = angka[i];
      j = i - 1;
      while ((temp < angka[j]) && (j >= 0)) {
        angka[j + 1] = angka[j];
        j -= 1;
      }
      angka[j + 1] = temp;
      // menampilkan perubahan data
      cout << endl;
      for (int k = 0; k < jumlahAngka; k++) {
        cout << angka[k] << " ";
      }
    }
  } else if (urutan == 2) {
    // Descending sort
    for (i = 1; i < jumlahAngka; i++) {
      temp = angka[i];
      j = i - 1;
      while ((temp > angka[j]) && (j >= 0)) {
        angka[j + 1] = angka[j];
        j -= 1;
      }
      angka[j + 1] = temp;
      // menampilkan perubahan data
      cout << endl;
      for (int k = 0; k < jumlahAngka; k++) {
        cout << angka[k] << " ";
      }
    }
  }
}

void selectionSort(int angka[], int jumlahAngka) {
  int temp, i, j, minIndex, maxIndex;

  cout << "\nSelection Sort"
       << " : ";
  if (urutan == 1) {
    // Ascending sort
    for (i = 0; i < jumlahAngka - 1; i++) {
      minIndex = i;
      for (j = i + 1; j < jumlahAngka; j++) {
        if (angka[j] < angka[minIndex]) {
          minIndex = j;
        }
      }
      temp = angka[minIndex];
      angka[minIndex] = angka[i];
      angka[i] = temp;
      // menampilkan perubahan data
      cout << endl;
      for (int k = 0; k < jumlahAngka; k++) {
        cout << angka[k] << " ";
      }
    }
  } else if (urutan == 2) {
    // Descending sort
    for (i = 0; i < jumlahAngka - 1; i++) {
      maxIndex = i;
      for (j = i + 1; j < jumlahAngka; j++) {
        if (angka[j] > angka[maxIndex]) {
          maxIndex = j;
        }
      }
      temp = angka[maxIndex];
      angka[maxIndex] = angka[i];
      angka[i] = temp;
      // menampilkan perubahan data
      cout << endl;
      for (int k = 0; k < jumlahAngka; k++) {
        cout << angka[k] << " ";
      }
    }
  }
}

void shellSort(int angka[], int jumlahAngka) {
  int i = 0, j = 0, k = 0, mid = 0;

  cout << "\nShell Sort"
       << " : ";
  if (urutan == 1) {
    // Ascending sort
    for (k = jumlahAngka / 2; k > 0; k /= 2) {
      for (j = k; j < jumlahAngka; j++) {
        for (i = j - k; i >= 0; i -= k) {
          if (angka[i + k] >= angka[i]) {
            break;
          } else {
            mid = angka[i];
            angka[i] = angka[i + k];
            angka[i + k] = mid;
          }
        }
      }
      // menampilkan perubahan data
      cout << endl;
      for (int k = 0; k < jumlahAngka; k++) {
        cout << angka[k] << " ";
      }
    }
  } else if (urutan == 2) {
    // Descending sort
    for (k = jumlahAngka / 2; k > 0; k /= 2) {
      for (j = k; j < jumlahAngka; j++) {
        for (i = j - k; i >= 0; i -= k) {
          if (angka[i + k] <= angka[i]) {
            break;
          } else {
            mid = angka[i];
            angka[i] = angka[i + k];
            angka[i + k] = mid;
          }
        }
      }
      // menampilkan perubahan data
      cout << endl;
      for (int k = 0; k < jumlahAngka; k++) {
        cout << angka[k] << " ";
      }
    }
  }
}

void quickSort(int angka[], int first, int last) {
  int temp, low, high, list_separator;
  low = first;
  high = last;
  list_separator = angka[(first + last) / 2];

  do {
      if (urutan == 1) {
        while (angka[low] < list_separator)
          low++;
        while (angka[high] > list_separator)
          high--;
        // menampilkan perubahan data
        cout << endl;
        for (int k = 0; k < jumlahAngka; k++) {
          cout << angka[k] << " ";
        }
      } else if (urutan == 2) {
        while (angka[low] > list_separator)
          low++;
        while (angka[high] < list_separator)
          high--;
        // menampilkan perubahan data
        cout << endl;
        for (int k = 0; k < jumlahAngka; k++) {
          cout << angka[k] << " ";
        }
      }

    if (low <= high) {
      temp = angka[low];
      angka[low++] = angka[high];
      angka[high--] = temp;
    }

  } while (low <= high);
  if (first < high)
    quickSort(angka, first, high);
  if (low < last)
    quickSort(angka, low, last);
}
