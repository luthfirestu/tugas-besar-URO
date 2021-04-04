// ROBY PURNOMO (16520331)
// LUTHFI RESTU K (16520110)
/* Program Kecoak vs Urang Robot */

#include <iostream>

using namespace std;

class robot{
public:
    int health=100;
    int att=50;
    int x = 0;
    int y = 0;
};

class kecoak{
public:
    int x;
    int y;
    int health=100;
    int att=2;
};

bool cek_kecoak(int x, int y, kecoak temp[]){
    int salah = 0;
    for (int i = 0; i<20; i++){
        if (x==temp[i].x && y==temp[i].y) {
            salah++;
        }
    }
    if (salah>0) {
        return false;
    }
    else {
        return true;
    }
}

class papan{
public:
    robot karakter;
    kecoak temp[20];
    int total_kecoak = 0;
    int salah;

    void spawn_kecoak() {
        int x;
        int y;
        total_kecoak++;
        salah = 1;
        if (total_kecoak<20) {
            while (salah != 0) {
                x = rand() % 21;
                y = rand() % 21;
                salah = 0;
                for (int i = 0; i < total_kecoak ; ++i) {
                    if (temp[i].x == x && temp[i].y == y) {
                        salah ++;
                    }
                }
            }
            temp[total_kecoak].x = x;
            temp[total_kecoak].y = y;
            cout << "Muncul kecoak";
            cout << total_kecoak+1;
            cout << "(";
            cout << temp[total_kecoak].x;
            cout << ", ";
            cout << temp[total_kecoak].y;
            cout << ")\n";
        }
    }

    void print(){
        for (int i = 21; i > -1 ; --i) {
            if (i==0){
                for (int j = 0; j<22 ;++j){
                    if (j==0) {
                        cout << "   ";
                    }
                    else if (j<11) {
                        cout << " ";
                        cout << j-1;
                        cout << " ";
                    }
                    else {
                        cout << j-1; 
                        cout << " ";
                    }
                }
            }
            else {
                for (int j = 0; j<22; ++j) {
                    if (j==0) {
                        if (i<11) {
                            cout << " ";
                            cout << i-1;
                            cout << " ";
                        }
                        else {
                            cout << i-1;
                            cout << " ";
                        }
                    }
                    else {
                        if (karakter.x == j-1 && karakter.y == i-1) {
                            cout << " R ";
                        }
                        else if (cek_kecoak(j-1,i-1,temp)==false) {
                            cout << " K ";
                        }
                        else {
                            cout << " _ ";
                        }
                    }
                }
            }
            cout << "\n";
        }
    }


};


void pindah(kecoak temp[], robot karakter){
    int salah;
    if (karakter.x != 0 && karakter.y != 20) {
        cout << "A : kiri\n";
        cout << "D : kanan\n";
    } else if (karakter.x != 0)
        cout << "A : kiri\n";
    else if (karakter.x != 20)
        cout << "D : kanan\n";
    if (karakter.y != 0 && karakter.y != 20){
        cout << "W : maju\n";
        cout << "S : mundur\n";
    } else if (karakter.y != 0)
        cout << "S : mundur\n";
    else if (karakter.y != 20)
        cout << "W : maju\n";
    char n;
    cin >> n;
    if (n == 'W'){
        karakter.y++;
        salah = 0;
        for (int i = 0; i < 20; ++i)
            if (karakter.y == temp[i].y && karakter.x == temp[i].y && (temp[i].health != 0 || temp[i].health != -1))
                salah++;
        if (salah > 0)
            cout << "Ada Kecoak X(\n";
    } else if (n == 'A'){
        karakter.x--;
        salah = 0;
        for (int i = 0; i < 20; ++i)
            if (karakter.y == temp[i].y && karakter.x == temp[i].y && (temp[i].health != 0 || temp[i].health != -1))
                salah++;
        if (salah > 0)
            cout << "Ada temp X(\n";
    } else if (n == 'S'){
        karakter.y--;
        salah = 0;
        for (int i = 0; i < 20; ++i)
            if (karakter.y == temp[i].y && karakter.x == temp[i].y && (temp[i].health != 0 || temp[i].health != -1))
                salah++;
        if (salah > 0)
            cout << "Ada Kecoak X(\n";
    } else if (n == 'D'){
        karakter.x++;
        salah = 0;
        for (int i = 0; i < 20; ++i)
            if (karakter.y == temp[i].y && karakter.x == temp[i].y && (temp[i].health != 0 || temp[i].health != -1))
                salah++;
        if (salah > 0)
            cout << "Ada Kecoak X(\n";
    }
}


void tembak(kecoak temp[], robot karakter){
    int jarak = 5;
    int benar;
    char n;
    cout << "Pilih arah tembak\n";
    cout << "I : depan\n";
    cout << "J : kiri\n";
    cout << "K : belakang\n";
    cout << "L : kanan\n";
    cin >> n;
    if (n == 'I') {
        cout << "=================================================\n";
        benar = 0;
        for (int i = 0; i < 20 ; ++i)
            if ((temp[i].y >= karakter.y + 1 && temp[i].y <= karakter.y + jarak) && (temp[i].x == karakter.x)) {
                temp[i].health -= karakter.att;
                benar++;
            }
        if (benar == 0)
            cout << "temp diluar jangkauan\n";
        cout << "=================================================\n";
    } else if (n == 'J'){
        cout << "=================================================\n";
        benar = 0;
        for (int i = 0; i < 20 ; ++i)
            if ((temp[i].x >= karakter.x - 1 && temp[i].x <= karakter.x - jarak) && (temp[i].y == karakter.y)) {
                temp[i].health -= karakter.att;
                benar++;
            }
        if (benar == 0)
            cout << "temp diluar jangkauan\n";
        cout << "=================================================\n";
    } else if (n == 'K'){
        cout << "=================================================\n";
        benar = 0;
        for (int i = 0; i < 20 ; ++i)
            if ((temp[i].y >= karakter.y - 1 && temp[i].y <= karakter.y - jarak) && (temp[i].x == karakter.x)) {
                temp[i].health -= karakter.att;
                benar++;
            }
        if (benar == 0)
            cout << "temp diluar jangkauan\n";
        cout << "=================================================\n";
    } else if (n == 'L'){
        cout << "=================================================\n";
        benar = 0;
        for (int i = 0; i < 20 ; ++i)
            if ((temp[i].x >= karakter.x + 1 && temp[i].x <= karakter.x + jarak) && (temp[i].y == karakter.y)) {
                temp[i].health -= karakter.att;
                benar++;
            }
        if (benar == 0)
            cout << "Kecoak diluar jangkauan\n";
        cout << "=================================================\n";
    }
}

int kecoak_mati(kecoak temp[]){
    int mati =0;
    for (int i = 0; i < 20; ++i)
        if (temp[i].health == 0)
            mati++;
    return mati;
}

int serangan_kecoak(kecoak temp[], robot karakter){
    int total_kecoak = 0;
    for (int i = 0; i < 20; ++i) {
        if (temp[i].x != -1 && temp[i].y != -1){
            if (((karakter.x<=(temp[i].x+11) && karakter.x>=(temp[i].x+1)) || (karakter.x>=temp[i].x-11 && karakter.x<=temp[i].x-1)) && (karakter.y==temp[i].y) && (temp[i].health>0))
                total_kecoak++;
            if (((karakter.y<=(temp[i].y+11) && karakter.y>=(temp[i].y+1)) || (karakter.y>=temp[i].y-11 && karakter.y<=temp[i].y-1)) && (karakter.x==temp[i].x) && (temp[i].health>0))
                total_kecoak++;
        }
    }
    karakter.health -= (total_kecoak*2); // 2 adalah damage kecoak
    return karakter.health;
}

void nyawa_kecoak(kecoak temp[]){
    for (int i = 0; i < 20; ++i) {
        if (temp[i].health != -1 && temp[i].health != 0) {
            cout << "Health kecoak " << i+1 << " (" << temp[i].x << temp[i].y << ") : " << temp[i].health;
        }
    }
}

int main() {
    robot karakter;
    kecoak temp;
    int n;
    papan tes;
    cout << "================================================================\n";
    cout << "                             MULAI\n";
    cout << "================================================================\n";
    int turn = 0;
    while(karakter.health>0) {
        tes.spawn_kecoak();
        tes.print();
        cin >> n;
    };
    return 0;
}
