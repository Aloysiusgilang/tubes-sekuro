#include <iostream>
using namespace std;

bool keluar(int pilihan) {      //Fungsi keluar
    if (pilihan == 3) {
        cout << "Anda telah mengalahkan 10 kecoak";
        return true;
    }
    else {
        return false;
    }
}

int gerak_x(string arah, int x) {      //Fungsi nentuin koordinat x selanjutnya
    if (arah == "kanan") {
        x = x + 1;
        return x;
    }
    else if (arah == "kiri") {
        x = x - 1;
        return x;
    }
    else {
        return x;
    }
}

int gerak_y(string arah, int y) {       //Fungsi nentuin koordinat y selanjutnya
    if (arah == "bawah") {
        y = y + 1;
        return y;
    }
    else if (arah == "atas") {
        y = y - 1;
        return y;
    }
    else {
        return y;
    }
}
//Buat fungsi cetak board yang nerima parameter x,y

// Fungsi cek input arah, pilihan
//Cek bakal keluar peta ato nabrak kecoak ato ngga

int main() {
    cout << "1. Bergerak \n" << "3. Keluar \n";

    int pilihan;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    int x, y;
    x = 1;
    y = 1;
    bool flag = false;

    while (flag == false) {
        
        if (pilihan == 1) {
            string arah;
            cout << "Masukkan arah gerak (kanan,kiri,atas,bawah) : \n";
            cin >> arah;
            x = gerak_x(arah, x);
            y = gerak_y(arah, y);
            
            char board[10][10];        
            for (int i = 1; i < 11; i++) {
                for (int j = 1; j < 11; j++) {
                    if ((i == y) && (j == x)) {
                        board[i][j] = 'R';                        
                    }
                    else {
                        board[i][j] = '.';
                    }
                    cout << board[i][j];
                }
                cout << "\n";
            }
  
        }
        cout << "1. Bergerak \n" << "3. Keluar \n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        flag = keluar(pilihan);
    }
    return 0;
}