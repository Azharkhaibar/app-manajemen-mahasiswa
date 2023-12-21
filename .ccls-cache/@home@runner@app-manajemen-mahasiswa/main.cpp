#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <chrono>
#include <regex>
#include <ctime>

using namespace std;

const int NUM_DOSEN = 5;
const int NUM_MATKUL = 3;

struct NilaiMataKuliah {
    string mataKuliah;
    int nilai;
};

struct User {
    string namalogin;
    string npm;
    string asal;
    string email;
    string password;
};

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

bool isValidName(const string &name) {
    for (char character : name) {
        if (!isalpha(character) && !isspace(character)) {
            return false;
        }
    }
    return true;
}

bool isValidEmail(const string &email) {
    // Menggunakan regular expression untuk memeriksa format email
    regex emailPattern("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b");
    return regex_match(email, emailPattern);
}

bool isValidPassword(const string &password) {
    for (char character : password) {
        if (!isdigit(character)) {
            return false;
        }
    }
    return true;
}


void menu();

void tampilkanTabel(string nama, string npm, string asal, string email);

string dosen[NUM_DOSEN] = {"Pak Dzanuri", "Pak Jenih", "Bu Ulansari", "Pak William", "Bu Suwarni"};
string matakuliah[NUM_DOSEN][NUM_MATKUL] = {
    {"Aljabar Linier", "Pancasila", "Kewargakenegaraan"},
    {"Algoritma", "Prak.Algoritma", "Pemrograman dasar"},
    {"PTI", "B Inggris", "Kalkulus"},
    {"Kalkulus", "Pemrograman", "Sistem Operasi"},
    {"Logika Informatika", "Kalkulus", "Aljabar"}
};

void tampilkanTabel1(string dosen[], string matakuliah[][NUM_MATKUL]);


string ulang();

void back();

void inputBiodata();

void loginDisplay();

void menu() {
    int nomor;
    string daymapel, nama2;

    do {
        cout<<"=-=-==-=-=-=-=-=-=-=-- WELCOME"<<nama2<<" =--=-=-=-==-=-=-=-=-=-=="<< endl;
        cout << "-=-=-=-=-=-==-=-=- DASHBOARD"<<nama2<<" -=-=-=-=-=-=-=-=-==-=-=" << endl;
        cout<<"\n";
        cout << "1. JADWAL PELAJARAN" << endl;
        cout << "2. DAFTAR NILAI" << endl;
        cout << "3. BIODATA MAHASISWA" << endl;
        cout << "4. DAFTAR MAHASISWA" << endl;
        cout << "5. DAFTAR DOSEN" << endl;
        cout << "6. EXIT PROGRAM" << endl;
        cout << "masukan nomor :";
        cin >> nomor;
        cout<<"\n";
        cout << "-=-=-='-=-=-==-=-=-=-=-=-=-=-=-=-='" << endl;
        cout<<" -=-=-=-==-=-=-==-=-=-=-==-=-=-=-=-=-=-"<<endl;

        if (nomor == 1) {
            cout << " Masukan Hari \t:";
            cin >> daymapel;
            cout<<"\n";
            if (daymapel == "senin") {
                cout << setw(20) << left << "Mata Pelajaran" << setw(10) << "Jam" << endl;
                cout << "-----------------------------------------" << endl;
                cout << setw(20) << left << "Kalkulus" << setw(10) << "07:00" << endl;
                cout << setw(20) << left << "Pancasila" << setw(10) << "09:00" << endl;
                cout << setw(20) << left << "Teknologi informasi" << "11:00" << endl;
            } else if (daymapel == "selasa") {
                cout << setw(20) << left << "Mata Pelajaran" << setw(10) << "Jam" << endl;
                cout << "-----------------------------------------" << endl;
                cout << setw(20) << left << "Kalkulus" << setw(10) << "07:00" << endl;
                cout << setw(20) << left << "algoritma" << setw(10) << "09:00" << endl;
                cout << setw(20) << left << "Logika Informatika" << "11:00" << endl;
            } else if (daymapel == "rabu") {
                cout << setw(20) << left << "Mata Pelajaran" << setw(10) << "Jam" << endl;
                cout << "-----------------------------------------" << endl;
                cout << setw(20) << left << "Kalkulus" << setw(10) << "07:00" << endl;
                cout << setw(20) << left << "Al Jabar Linier " << setw(10) << "09:00" << endl;
                cout << setw(20) << left << "Pancasila" << "11:00" << endl;
            } else if (daymapel == "kamis") {
                cout << setw(20) << left << "Mata Pelajaran" << setw(10) << "Jam" << endl;
                cout << "-----------------------------------------" << endl;
                cout << setw(20) << left << "Aljabar linier" << setw(10) << "07:00" << endl;
                cout << setw(20) << left << "Logika Informatika" << setw(10) << "09:00" << endl;
                cout << setw(20) << left << "agama" << "11:00" << endl;
            } else if (daymapel == "jumat") {
                cout << setw(20) << left << "Mata Pelajaran" << setw(10) << "Jam" << endl;
                cout << "-----------------------------------------" << endl;
                cout << setw(20) << left << "Prak. Algoritma" << setw(10) << "07:00" << endl;
                cout << setw(20) << left << "algoritma" << setw(10) << "09:00" << endl;
                cout << setw(20) << left << "agama" << "11:00" << endl;
            } else if (daymapel == "sabtu") {
                cout << "LIBUR COY" << endl;
            } else if (daymapel == "minggu") {
                cout << "LIBUR COYYY" << endl;
            } else {
                cout << "Input hari NonValid" << endl;
                back();
            }
        } else if (nomor == 2) {
            srand(time(0));

            const int jumlahMataPelajaran = 4;

            int nilai[jumlahMataPelajaran];

            cout << "Daftar Nilai Pribadi:\n";
            cout << "Aljabar: ";
            nilai[0] = rand() % 101;
            cout << nilai[0] << "\n";

            cout << "Algoritma: ";
            nilai[1] = rand() % 101;
            cout << nilai[1] << "\n";

            cout << "Logika Informatika: ";
            nilai[2] = rand() % 101;
            cout << nilai[2] << "\n";

            cout << "Kalkulus: ";
            nilai[3] = rand() % 101;
            cout << nilai[3] << "\n";

            int totalNilai = 0;
            for (int i = 0; i < jumlahMataPelajaran; ++i) {
                totalNilai += nilai[i];
            }
            double rataRata = static_cast<double>(totalNilai) / jumlahMataPelajaran;

            cout << "Rata-rata Nilai: " << rataRata << "\n";
            back();
        } else if (nomor == 3) {
            inputBiodata();
        } else if (nomor == 4) {

        } else if (nomor == 5) {
            tampilkanTabel1(dosen,matakuliah);// Logika atau pemanggilan fungsi untuk DAFTAR DOSEN
        } else if (nomor == 6) {
            // Logika atau pemanggilan fungsi untuk EXIT PROGRAM
            cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << "Program selesai" << endl;
            exit(0);
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
    } while (nomor == 1 || nomor == 2 || nomor == 3 || nomor == 4 || nomor == 5 || nomor == 6);
}


void tampilkanTabel1(string dosen[], string matakuliah[][NUM_MATKUL]) {
    cout << setw(15) << "Nama Dosen" << setw(25) << "Mata Kuliah Diajarkan" << endl;
    cout << "=============================================" << endl;

    for (int i = 0; i < NUM_DOSEN; ++i) {
        cout << setw(15) << dosen[i] << "|";
        for (int j = 0; j < NUM_MATKUL; ++j) {
            cout << setw(15) << matakuliah[i][j];
        }
        cout << endl;
    }
}

void tampilkanTabel(string nama, string npm, string asal, string email) {

    cout << "\n-----------------------------------------'-------\n";
    cout << setw(15) << "Nama" << setw(15) << "NPM" << setw(15) << "Asal" << setw(25) << "Email" << "\n";
    cout << "-------------------------------------------\n";
    cout << setw(15) << nama << setw(15) << npm << setw(15) << asal << setw(25) << email << "\n";
    cout << "------------------------------------------\n";
}

void displayBiodata(const string& nama, const string& npm, const string& tinggal, int tahunKelahiran) {
    cout << "\nBiodata Saya\n";
    cout << setw(35) << setfill('=') << "" << setfill(' ') << endl;
    cout << setw(20) << left << "Nama" << "| " << setw(15) << right << nama << endl;
    cout << setw(20) << left << "NPM" << "| " << setw(15) << right << npm << endl;
    cout << setw(20) << left << "Tempat Tinggal" << "| " << setw(15) << right << tinggal << endl;
    cout << setw(20) << left << "Tahun Kelahiran" << "| " << setw(15) << right << tahunKelahiran << endl;
    cout << setw(35) << setfill('=') << "" << setfill(' ') << endl;
}

void inputBiodata() {
    string nama, npm, tinggal;
    int tahunKelahiran;


    cout << "Masukkan Nama (hanya huruf): ";
    cin.ignore();
    getline(cin, nama);

    if (!cin.good() || nama.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) {
        cerr << "Nama tidak valid. Harap masukkan hanya huruf.\n";
        return;
    }

    cout << "Masukkan NPM (maksimal 7 karakter): ";
    cin >> npm;

    if (!cin.good() || npm.length() > 5  ) {
        cerr << "NPM tidak valid. Harap masukkan maksimal 7 karakter.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    cout << "Masukkan Tempat Tinggal: ";
    getline(cin, tinggal);

    cout << "Masukkan Tahun Kelahiran: ";
    while (!(cin >> tahunKelahiran) || tahunKelahiran < 1900 || tahunKelahiran > 2023) {
        cerr << "Tahun kelahiran tidak valid. Harap masukkan tahun yang benar.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    displayBiodata(nama, npm, tinggal, tahunKelahiran);
}

void back() {
    int balik;
    cout<<"ketik ( 1 ) untuk kembali \t: ";
    cin>>balik;
    if(balik == 1) {
        menu();
    }
    else {
        do {
            cout<<"=-=-=-=--=-==-=-=-=-=-= INPUT SELAIN SATU DITOLAK =-=-=-=-=-=-=-=-=-==-"<<endl;
            cout<<"ketik ( 1 ) untuk kembali \t: ";
            cin>>balik;
        } while(balik != 1);
    }

}



void loadingAnimation() {
    cout << "Bandwidth Test: " << endl;
    cout << "+----------------------------------------------------+" << endl;
    cout << "| Progress   | Bandwidth |" << endl;
    cout << "+----------------------------------------------------+" << endl;

    for (int i = 0; i <= 100; ++i) {
        cout << "| ";
        printf("%-10d", i);
        cout << "| [";

        int numEquals = i / 4;
        for (int j = 0; j < numEquals; ++j) {
            cout << "=";
        }

        cout << ">";

        for (int j = numEquals; j < 25; ++j) {
            cout << " ";
        }

        cout << "] " << i * 4 << " Mbps |" << "\r";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << endl;
    cout << "+----------------------------------------------------+" << endl;
}



string ulang() {
    string ulang1;
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "Ingin cari lagi (Y/N)? ";
    cin >> ulang1;

    if (ulang1 == "y" || ulang1 == "Y") {
        loadingAnimation();
    } else if (ulang1 == "n" || ulang1 == "N") {
        cout << "=-=-=-=-=-=-=-= BYE =-=-=-=-=-=-=-=" << endl;
        exit(0);
    }

    cout << endl;
    return ulang1;
}

void registration(string &nama, string &email, string &password) {
    cout << "=== Registrasi ===" << endl;

    do {
        cout << "Masukkan nama\t: ";
        cin >> ws;
        getline(cin, nama);

        if (!isValidName(nama)) {
            cout << "Nama tidak valid. Harap masukkan hanya huruf.\n";
        }

    } while (!isValidName(nama));

    do {
        cout << "Masukkan email\t: ";
        cin >> email;

        if (!isValidEmail(email)) {
            cout << "Email tidak valid. Harap masukkan email yang sesuai.\n";
        }

    } while (!isValidEmail(email));

    do {
        cout << "Masukkan password\t: ";
        cin >> password;

        if (!isValidPassword(password)) {
            cout << "Password tidak valid. Harap masukkan hanya angka.\n";
        }

    } while (!isValidPassword(password));

    cout << "\nRegistrasi berhasil!\n\n";
}

void login(const string &registeredName, const string &registeredPassword) {
    string inputName, inputPassword;

    cout << "=== Login ===" << endl;

    cout << "Masukkan nama\t: ";
    cin >> ws;
    getline(cin, inputName);

    cout << "Masukkan password\t: ";
    cin >> inputPassword;

    if (inputName == registeredName && inputPassword == registeredPassword) {
        cout << "\nLogin berhasil!\n";
    } else {
        cout << "\nLogin gagal. Cek kembali nama dan password.\n";
    }
}









int main() {
    int day;
    string op, end;
    string opt2,nama;
    string password, nama2, nik;
    string namalogin, npm, asal, email, passwordlogin;

    registration(nama, email, password);
    cout<<"-=-=-=-==-=-=-=-=-= ATTENTION !! =-=-=-=-=-=-=-==-=-="<<endl;
    cout<<" Note : INPUT LOGIN SAMAKAN DENGAN INPUT (REGISTRASI)" <<endl;
    cout<<"\n";
    login(nama, password);

    string ulang();  //deklarasi string ulang #prosedur
    cout<<"\t\t PROGRAM AJAR"<<endl;
    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-==-=-=--==--="<<endl;
    cout<< "Masukkan pilihan (A/G)\t: ";
    cin >> op;

    if (op == "A" || op == "a") {
        cout << "Masukkan hari (1,2,3,4,5,6,7)\t: ";
        cin >> day;
    } else if (op == "G" || op == "g") {
        cout << "Anda tidak berada dalam opsi" << endl;
        do {
            cout << "Ingin akhiri? (Y/N): ";
            cin >> end;
            if (end == "y" || end == "Y") {
                cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                cout << "Program selesai" << endl;
                return 0;
            } else if (end == "n" || end == "N") {
                cout << "Masukkan opsi (A/G): ";
                cin >> op;
                if (op == "A" || op == "a") {
                    do {
                        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                        cout << "=-=-=-=-=-=-=-=-= INPUT HARI DITEMUKAN =-=-=-=-=-=-=-=-==-==-" << endl;
                        cout << "Masukkan hari (1,2,3,4,5,6,7)\t: ";
                        cin >> day;
                    } while (day < 1 || day > 7);
                } else if (op == "G" || op == "g") {
                    do {
                        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
                        cout << "=-=--=-=-=-=-= ANDA KELUAR ==-=-=-=-=-=-==-=-=-=" << endl;
                        return 0;
                    } while (op == "G" || op == "g");
                } else {
                    cout << "Pilihan tidak valid" << endl;
                }
            } else {
                cout << "Pilihan tidak valid" << endl;
            }
        } while (op == "G" || op == "g");
    } else {
        cout<<"=-=-=-==-=-=-==-=-=-=-=-=-=-=-=-=-=-=-==-=-=-="<< endl;
        cout<<"=-=-=-=-=-=-=-=--= PROGRAM TIDAK DITEMUKAN =-=-=-=-=-=-==-=-=-==-=-=" << endl;
        return 0;
    }

    switch (day) {
    case 1:
        cout << "hari terdeteksi : Senin" << endl;
        break;
    case 2:
        cout << "hari terdeteksi : Selasa" << endl;
        break;
    case 3:
        cout << "hari terdeteksi : Rabu" << endl;
        break;
    case 4:
        cout << "hari terdeteksi : Kamis" << endl;
        break;
    case 5:
        cout << "hari terdeteksi : Jumat" << endl;
        break;
    case 6:
        cout << "hari terdeteksi : Sabtu" << endl;
        break;
    case 7:
        cout << "hari terdeteksi : Minggu" << endl;
        break;
    default:
        cout << "=-=-=-=-=-=-==-=--=-=- HARI TIDAK DITEMUKAN =-=-=-=-=-==-=-=-=-==-" << endl;
        ulang(); //memanggil fungsi prosedur ulang
    }
    cout<<"=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-==--==-=-=-=\n";
    cout<<"ingin melanjutkan (YA/NO) ?";
    cin>>opt2;
    cout<<"=-=-=-=-=-=-=-==-=-=-==-=-=-=-=-=-=-=-=-=-=\n";
    if(opt2 == "ya" || opt2 == "YA") {
    } else if(opt2 == "no" || opt2 == "NO") {
        cout<<"=-=-=-=-=-=-==-=-==-==--= BITCH =-=-=--=-=-=-==--=-=-==-=-=-"<< endl;
        return 0;
    }
    cout<<"\n";
    cout<<"=-=-=-=-=-==-=-=-=-=-==- LOGIN PROGRAM -=-=-=-=-=-=-=-='-=-=-==-"<<endl;
    cin.ignore();
    // Input data login
    cout << "Masukkan Nama: ";
    getline(cin, namalogin);
    cout << "\n";

    cout << "Masukkan NPM (tidak lebih dari 5 angka): ";
    getline(cin, npm);

    cout << "Masukkan Asal: ";
    getline(cin, asal);

    cout << "Masukkan Email: ";
    getline(cin, email);

    cout << "Masukkan Password: ";
    getline(cin, passwordlogin);


    if (npm.length() > 5  || passwordlogin != "azharganteng") {
        cout <<"\n =-=-=-=-=-=-=-=-=--== GAGAL LOGIN =-=-=-=-=-=-=-=-=-=-=-=-=";
        return 0;
    } else {

        cout << "Berhasil\n";
        tampilkanTabel(namalogin, npm, asal, email);
    }


    menu();
    cout<<"--------- MENAMPILKAN DAFTAR DOSEN  -----'---"<<endl;


    return 0;

}