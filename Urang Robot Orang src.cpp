#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;


void update_atribut_kecoa(int *health_kecoa,int damage_robot){
    *health_kecoa=*health_kecoa-damage_robot;
}

void update_atribut_robot(int *health_robot,int damage_kecoa){
    *health_robot=*health_robot-damage_kecoa;
}

void update_loct_kecoa(int x,int y,int *x_kecoa, int *y_kecoa){
    srand((unsigned)time(0));
    *x_kecoa=(rand()%9)+1; //random x 1-10
    *y_kecoa=(rand()%9)+1; //random x 1-10
    if ((*x_kecoa == x) || (*y_kecoa==y)){
        update_loct_kecoa(x,y,*&x_kecoa,*&y_kecoa);
    }

}
bool keluar(int pilihan) {      //Fungsi keluar
    if (pilihan == 3) {
        cout << "TERIMA KASIH TELAH BERMAIN \n";
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

void gerak_robot(int arah, int *x, int *y) {      //Fungsi nentuin koordinat selanjutnya
    if (arah == 1) {
        *x = *x + 1;
    }
    else if (arah == 2) {
        *x = *x - 1;
    }
    else if (arah == 4) {
        *y = *y + 1;
    }
    else { // untuk arah atas
        *y = *y - 1;
    }
    
}

bool checking_loct(int arah,int x, int y){
    if (arah == 1) {
        if((x+1)<=9){
            return true;
        }
        else{
            return false;
        }
    }
    else if (arah == 2) {
        if((x-1)>=0){
            return true;
        }
        else{
            return false;
        }
    }
    else if (arah == 4) {
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

void check_arah(int *arah){
    if( *arah > 4 || *arah < 1){
        cout << "Masukkan tidak tersedia. Ulangi lagi. \n";
        cout << "Masukkan arah gerak (angka)  \n";
        cout << "1. Kanan  \n";
        cout << "2. Kiri  \n";
        cout << "3. Atas  \n";
        cout << "4. Bawah  \n";
        cin >> *arah;
        check_arah(*&arah);
    }
}

void check_pilihan(int *pilihan){
    if( *pilihan > 3 || *pilihan < 1){
        cout << "Masukkan tidak tersedia. Ulangi lagi. \n";
        cout << "1. Bergerak\n2. Menyerang\n3. Keluar \n" <<endl;
        cout << "Masukkan pilihan :  \n";
        
        cin >> *pilihan;
        check_pilihan(*&pilihan);
    }
}

int main() {
    // Kamus
    srand((unsigned)time(0));
    int x=0,y=0,x_kecoa,y_kecoa,pilihan;
    int health_kecoa=20,health_robot=20;
    int range_attack_robot=2,range_attack_kecoa=1;
    int damage_robot = 6,damage_kecoa=(rand() % 4) + 1 ;
    int death_count = 0;
    bool flag = false;
    char board[10][10];
    

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
    if (pilihan > 3 || pilihan < 1){
        check_pilihan(&pilihan);
    }

    while (flag == false) {

        if (pilihan == 1) {
            int arah;
            cout << "Masukkan arah gerak (angka)  \n";
            cout << "1. Kanan  \n";
            cout << "2. Kiri  \n";
            cout << "3. Atas  \n";
            cout << "4. Bawah  \n";

            cin >> arah;
            if (arah >4 || arah<1){
                check_arah(&arah);
            }
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

                if(health_kecoa >0){
                    update_atribut_robot(&health_robot,damage_kecoa);
                }

                cout << "===============\n";
                cout << "|HP ROBOT : "<< health_robot << "|\n";
                cout << "|HP KECOA : "<< health_kecoa << "|\n";
                cout << "===============\n\n";
                cout << "DAMAGE KECOA =" << damage_kecoa << endl;
                cout << "DAMAGE ROBOT =" << damage_robot << endl;

                if(health_kecoa <= 0){
                    srand((unsigned)time(0));
                    cout << "\nANDA TELAH MEMBUNUH 1 KECOAK\n" << endl;
                    death_count = death_count + 1 ;
                    health_kecoa = 20;
                    damage_kecoa=(rand() % 4) + 1 ;
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
                }

                if(health_robot <= 0 ){
                    cout << "ROB0T TELAH MEMBUNUH KECOA SEBANYAK" << death_count;
                    exit(1);
                }

                else {
                    update_loct_kecoa(x,y,&x_kecoa,&y_kecoa); // kecoa pindah  tempat
                    cout << "\nWASPADA !!! KECOA TELAH BERPINDAH LOKASI\n\n";
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
                
            }
            else{
                cout << "MUSUH DILUAR JANGKAUAN !!! " << endl;
            }

        }

        else {
            cout << "Masukkan invalid, dikembalikan ke menu awal" << endl;
            main();
        }
        cout << "1. Bergerak\n2. Menyerang\n3. Keluar \n" <<endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan > 3 || pilihan < 1){
            check_pilihan(&pilihan);
        }
        flag = keluar(pilihan);
        
    }
    cout << "\nANDA TELAH MENGALAHKAN " << death_count << " KECOAK" << endl;
    return 0;
}
