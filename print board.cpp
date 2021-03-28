#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;


void update_atribut_kecoa(int *health_kecoa,int damage_robot){
    *health_kecoa=*health_kecoa-damage_robot;
}
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

bool checking_loct(string arah,int x, int y){
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
    int x=0,y=0,x_kecoa,y_kecoa,pilihan;
    int health_kecoa=20,health_robot=20;
    int range_attack_robot=2,range_attack_kecoa=1;
    int damage_robot = 6,damage_kecoa=4;
    bool flag = false;
    char board[10][10];
    srand((unsigned)time(0));

    // initiate
    x_kecoa=(rand()%9)+1; //random x 1-10
    y_kecoa=(rand()%9)+1; //random x 1-10

    cout << "=========== ROBOT PEMBASMI KECOA ===========" << endl;
    cout << "============================================" << endl << endl;
    cout << "============== TAMPILAN BOARD ==============" << endl << endl;
    cout << "===============\n";
    cout << "|HP ROBOT : 20|\n";
    cout << "|HP KECOA : 20|\n";
    cout << "===============\n";
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
    cout << "1. Bergerak\n2. Menyerang\n3. Keluar \n" <<endl;

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
                cout << "PERHATIAN !!! ROBOT TIDAK BISA BERGERAK KE LUAR ZONA" << endl;
            }
            cout << "============== UPDATE TAMPILAN BOARD ==============" << endl << endl;
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
            cout << endl;
            if (range_check(x,y,x_kecoa,y_kecoa)){
                cout << "PERHATIAN !!! ROBOT DAPAT MENYERANG" << endl << endl;
            }
            else{
                cout << endl;
            }

        }
        else if (pilihan == 2){
            if (range_check(x,y,x_kecoa,y_kecoa)){
                cout << "\nROBOT MENYERANG KECOA\n";
                cout << endl;
                update_atribut_kecoa(&health_kecoa,damage_robot);
                cout << "===============\n";
                cout << "|HP ROBOT : "<< health_robot << "|\n";
                cout << "|HP KECOA : "<< health_kecoa << "|\n";
                cout << "===============\n\n";

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
                    cout<< endl;
                }
            }
            else{
                cout << "MUSUH DILUAR JANGKAUAN !!! " << endl;
            }

        }
        cout << "1. Bergerak\n2. Menyerang\n3. Keluar \n" <<endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        flag = keluar(pilihan);
    }
    return 0;
}
