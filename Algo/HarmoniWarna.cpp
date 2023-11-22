#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Struktur untuk menyimpan informasi warna
struct ColorInfo
{
    string name;
    string notation;
    string properties;
};

// Fungsi untuk memeriksa apakah string hanya mengandung angka
bool isNumber(const string &str)
{
    for (char const &c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Inisialisasi informasi warna dalam vector
    vector<ColorInfo> colors = {
        {"Orange", "", ""},
        {"Red-Orange", "", ""},
        {"Red", "", ""},
        {"Red-Violet", "", ""},
        {"Violet", "", ""},
        {"Blue-Violet", "", ""},
        {"Blue", "", ""},
        {"Blue-Green", "", ""},
        {"Green", "", ""},
        {"Yellow-Green", "", ""},
        {"Yellow", "", ""},
        {"Yellow-Orange", "", ""}};

    string inputColor;
    string notasi, sifat;
    bool validInput = false;

    // Menampilkan pilihan warna
    cout << "Pilih warna berdasarkan nomor: " << endl;
    for (int i = 0; i < colors.size(); ++i)
    {
        cout << i + 1 << ". " << colors[i].name << endl;
    }

    // Mengulangi permintaan input sampai input yang valid diberikan
    while (!validInput)
    {
        cout << "Masukkan nomor warna: ";
        getline(cin, inputColor);

        // Memeriksa apakah input hanya terdiri dari angka
        if (isNumber(inputColor))
        {
            int colorIndex = stoi(inputColor);
            if (colorIndex > 0 && colorIndex <= colors.size())
            {
                colorIndex--; // Mengurangi 1 karena indeks dimulai dari 0

                // Penentuan notasi
                if (colorIndex == 0 || colorIndex == 4 || colorIndex == 8)
                {
                    notasi = "Sekunder";
                }
                else if (colorIndex == 2 || colorIndex == 6 || colorIndex == 10)
                {
                    notasi = "Primer";
                }
                else
                {
                    notasi = "Tersier";
                }

                // Penentuan sifat
                if (colorIndex >= 0 && colorIndex <= 5)
                {
                    sifat = "Hangat";
                }
                else
                {
                    sifat = "Sejuk";
                }

                cout << "Notasi Warna: " << notasi << endl;
                cout << "Sifat Warna: " << sifat << endl;

                // Menampilkan pilihan perpaduan warna
                cout << "Perpaduan Warna Harmonis" << endl;
                cout << "a. Perpaduan Warna Analogous" << endl;
                cout << "b. Perpaduan Warna Complementary" << endl;
                cout << "c. Perpaduan Warna Split Complementary" << endl;
                cout << "d. Perpaduan Warna Triadic Complementary" << endl;
                cout << "e. Perpaduan Warna Tetrad Complementary" << endl;

                char choice;
                cout << "Pilih jenis perpaduan warna (a, b, c, d, e): ";
                cin >> choice;

                switch (choice)  {
                case 'a':
                    cout << "Perpaduan Warna Analogous dengan warna nomor: " << (colorIndex % 12) + 2 << ", " << (colorIndex % 12) + 3 << " atau " << (colorIndex % 12) + 11 << ", " << (colorIndex % 12) + 12 << " atau " << (colorIndex % 12) + 2 << ", " << (colorIndex % 12) + 12 << endl;
                    break;
                case 'b':
                    if (colorIndex <= 6)
                    {
                        cout << "Perpaduan Warna Complementary dengan warna nomor: " << (colorIndex % 12) + 7 << endl; // "nomor warna" = "nomor warna + 6
                    }
                    else
                    {
                        cout << "Perpaduan Warna Complementary dengan warna nomor: " << (colorIndex % 12) - 5 << endl; // "nomor warna" = "nomor warna + 6
                    }
                    break;
                case 'c':
                    cout << "Perpaduan Warna Split Complementary dengan warna nomor: " << (colorIndex % 12) + 5 << ", " << (colorIndex % 12) + 7 << endl;
                    break;
                case 'd':
                    cout << "Perpaduan Warna Triadic Complementary dengan warna nomor: " << (colorIndex % 12) + 4 << ", " << (colorIndex % 12) + 8 << endl;
                    break;
                case 'e':
                    cout << "Perpaduan Warna Tetrad Complementary dengan warna nomor: " << (colorIndex % 12) + 3 << ", " << (colorIndex % 12) + 6 << ", " << (colorIndex % 12) + 9 << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid." << endl;
                }
                validInput = true;
            }
            else
            {
                cout << "Nomor warna tidak valid. Harap masukkan nomor yang sesuai dengan pilihan." << endl;
            }
        }
        else
        {
            cout << "Input tidak valid. Harap masukkan hanya angka." << endl;
        }
    }

    return 0;
}
