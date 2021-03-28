#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
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

bool range_check(int x, int y, int x_kecoa, int y_kecoa ) // fungsi pengecekan jarak guna penyerangan
{
    if (abs(x-x_kecoa) <= 2 && abs(y-y_kecoa) <=2){
        return true;
    }
    else{
        return false;
    }
}

void gerak_robot(string arah, int *x, int *y) {      //Fungsi nentuin koordinat selanjutnya
    if (arah == "kanan") {
        *x = *x + 1;
    }
    else if (arah == "kiri") {
        *x = *x - 1;
    }
    else if (arah == "bawah") {
        *y = *y + 1;
    }
    else { // untuk arah atas
        *y = *y - 1;
    }
}

bool checking_loct(string arah,int x, int y){ //buat check geraknya ke luar zona atau enggak
    if (arah == "kanan") {
        if((x+1)<=9){
            return true;
        }
        else{
            return false;
        }
    }
    else if (arah == "kiri") {
        if((x-1)>=0){
            return true;
        }
        else{
            return false;
        }
    }
    else if (arah == "bawah") {
        if((y+1)<=9){
            return true;
        }
        else{
            return false;
        }
    }
    else { // untuk arah atas
        if ((y-1)>=0){
            return true;
        }
        else{
            return false;
        }
    }
}

//Buat fungsi cetak board yang nerima parameter x,y

// Fungsi cek input arah, pilihan
//Cek bakal keluar peta ato nabrak kecoak ato ngga

int main() {
    // Kamus
    int x, y,x_kecoa,y_kecoa,pilihan;
    bool flag = false;
    char board[10][10];
    srand((unsigned)time(0));

    // initiate
    x_kecoa=(rand()%9)+1; //random x 1-10
    y_kecoa=(rand()%9)+1; //random x 1-10
    x = 0;
    y = 0;

    cout << "=========== ROBOT PEMBASMI KECOA ===========" << endl;
    cout << "============================================" << endl << endl;
    cout << "============== TAMPILAN BOARD ==============" << endl << endl;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if ((i==y) && (j==x)){
                board[i][j] = 'R';
            }
            else if ((i==y_kecoa)&&(j==x_kecoa)){
                board[i][j] = 'K';
            }
            else{
                board[i][j] = '.';
            }
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << "1. Bergerak \n" << "3. Keluar \n";

    cout << "Masukkan pilihan: ";
    cin >> pilihan;



    while (flag == false) {

        if (pilihan == 1) {
            string arah;
            cout << "Masukkan arah gerak (kanan,kiri,atas,bawah) : \n";
            cin >> arah;
            cout << endl;
            if (checking_loct(arah,x,y)){
                gerak_robot(arah, &x,&y); // fungsi update posisi dari robot
            }
            else{
                cout << "PERHATIAN!! ROBOT TIDAK BISA BERGERAK KE LUAR ZONA" << endl;
            }
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if ((i == y) && (j == x)) {
                        board[i][j] = 'R';
                    }
                    else if ((i==y_kecoa) && (j==x_kecoa)){
                        board[i][j] = 'K';
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
