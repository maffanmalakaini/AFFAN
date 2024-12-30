#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    bool hadir;
};

vector<Mahasiswa> daftarMahasiswa;

void tampilkanAbsen() {
    if (daftarMahasiswa.empty()) {
        cout << "\nBelum ada data mahasiswa.\n";
        return;
    }

    cout << "\nDaftar Kehadiran Mahasiswa:\n";
    cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "NIM" << "Status" << endl;
    cout << "--------------------------------------------------\n";
    for (size_t i = 0; i < daftarMahasiswa.size(); ++i) {
        cout << left << setw(5) << (i + 1) 
             << setw(20) << daftarMahasiswa[i].nama 
             << setw(15) << daftarMahasiswa[i].nim 
             << (daftarMahasiswa[i].hadir ? "Hadir" : "Tidak Hadir") << endl;
    }
}

void tambahMahasiswa() {
    Mahasiswa mhs;
    cout << "\nTambah Mahasiswa" << endl;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, mhs.nama);
    cout << "Masukkan NIM: ";
    cin >> mhs.nim;
    mhs.hadir = false;
    daftarMahasiswa.push_back(mhs);
    cout << "\nData mahasiswa berhasil ditambahkan!\n";
}

void absenMahasiswa() {
    if (daftarMahasiswa.empty()) {
        cout << "\nBelum ada data mahasiswa untuk diabsen.\n";
        return;
    }

    tampilkanAbsen();
    int nomor;
    cout << "\nMasukkan nomor mahasiswa yang hadir: ";
    cin >> nomor;

    if (nomor < 1 || nomor > daftarMahasiswa.size()) {
        cout << "\nNomor tidak valid.\n";
        return;
    }

    daftarMahasiswa[nomor - 1].hadir = true;
    cout << "\nAbsen berhasil dicatat untuk " << daftarMahasiswa[nomor - 1].nama << ".\n";
}

void menu() {
    int pilihan;
    do {
        cout << "\n=== Sistem Absen Mahasiswa ===" << endl;
        cout << "1. Tampilkan Daftar Absen" << endl;
        cout << "2. Tambah Mahasiswa" << endl;
        cout << "3. Absen Mahasiswa" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanAbsen();
                break;
            case 2:
                tambahMahasiswa();
                break;
            case 3:
                absenMahasiswa();
                break;
            case 4:
                cout << "\nTerima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    } while (pilihan != 4);
}

int main() {
    menu();
    return 0;
}
