/* Program Kecoak vs Urang Robot */

#include <iostream>
#include <stdlib.h>
using namespace std;

int i;
int j;
int x_robot; int y_robot;
int x_kecoak; int y_kecoak;
int k;

bool kecoak (int x, int y, int x_kecoak[k], int y_kecoak[k]){
    for (k=0; k<20; k++){
        if (x == x_kecoak[k] && y == y_kecoak[k]){
            return true;
        }
    }

}

// fungsi papan
void papan(){
    for (i=19; i >-1; i--){
        for (j=0; j<20; j++){
            if (x_robot == j && y_robot == i){
                cout<< "R "<<endl;
            }
            else if (kecoak(j,i,x_kecoak,y_kecoak) == true){
                cout<<"K "<<endl;
            }
            else {
                cout<<"_ "<<endl;
            }
        }
        cout<<endl;
    }
}

// fungsi cekkecoak
void cekkecoak(int x, int y, int x_kecoak, int y_kecoak){
    int salah = 0;
    for (i=0, i<20, i++){
        if (x == x_kecoak[i] || y == y_kecoak[i]){
            salah = salah + 1;
        }
    }
    if (salah > 0) {
        return false;
    }
    else{
        return true;
    }
}

// fungsi kecoak baru
void kecoak_baru(int x, int y, int x_kecoak, int y_kecoak){
    int urut;
    if (cekkecoak(-1,-1,x_kecoak,y_kecoak) == false){
        x = rand()%21;
        y = rand()%21;

        while (x!=x_robot && y!=y_robot && cekkecoak(x,y,x_kecoak,y_kecoak) == true){
            x = rand()%21;
            y = rand()%21;
        }
    }
    for (i=0, i<20, i++){
        if (-1==x_kecoak[i] || -1 == y_kecoak[i]){
            urut = i;
            break;
        }
    }
    int x_kecoak[urut] = x;
    int y_kecoak[urut] = y;
    int health_kecoak[urut] = 100;
    cout << "Muncul kecoak" << urut << "("<< str(x)<< ", " << str(y) << ")" <<endl;
}
// fungsi pindah tempat
void pindah(int x_robot,int y_robot,int x_kecoak,int y_kecoak){
    int salah;
    if (x_robot != 0 && x_robot != 20) {
        cout <<"A : kiri" <<endl;
        cout <<"D : kanan" <<endl;
    }
    else if (x_robot != 0){
        cout<<"A : kiri"<<endl;
    }
    else if (x_robot != 20){
        cout<<"D : kanan"<<endl;
    }
    if (y_robot != 0 && y_robot != 20){
        cout<<"W : maju"<<endl;
        cout<<"S : mundur"<<endl;
    }
    else if (y_robot != 0){
        cout<<"S : mundur"<<endl;
    }
    else if (y_robot != 20){
        cout<< "W : maju"<<endl;
    }
    char n;
    cin >> n;
    if (n=="W"){
        y_robot = y_robot + 1;
        salah = 0;
        for (i=0, i<20, i++){
            if (y_robot == y_kecoak[i]){
                salah = salah + 1;
            }
        }
        if (salah > 0){
            cout<<"Ada Kecoak X"<<endl;
        }
        else {
            return (x_robot, y_robot);
        }
    }
    else if (n=="A"){
        x_robot=x_robot - 1;
        salah = 0;
        for (i=0, i<20, i++){
            if (x_robot==x_kecoak[i]){
                salah = salah + 1;
            }
        }
        if (salah > 0){
            cout<<"Ada Kecoak X(";
        }
        else {
            return x_robot, y_robot;
        }
    }
    else if (n=="S"){
        y_robot = y_robot - 1;
        salah = 0;
        for (i=0, i<20, i++){
            if (y_robot == y_kecoak[i]) {
                salah = salah + 1;
            }
        }
        if (salah > 0){
            cout << "Ada Kecoak X(";
        }
        else {
            return x_robot, y_robot;
        }
    }
    else if (n == "D"){
        x_robot = x_robot + 1;
        salah = 0;
        for (i=0, i<20, i++){
            if (x_robot == x_kecoak[i]){
                salah = salah + 1;
            }
        }
        if (salah > 0) {
            cout << "Ada Kecoak X"<<endl;
        }
        else{
            return x_robot, y_robot;
        }
    }
}

void tembak(int x_robot, int y_robot, int x_kecoak, int y_kecoak,int health_kecoak,int att) {
    int jarak = 5;
    int benar;
    cout <<"Pilih arah tembak"<<endl;
    cout <<"I : depan"<<endl;
    cout <<"J : kiri"<<endl;
    cout <<"K : belakang"<<endl;
    cout <<"L : kanan"<<endl;
    char n;
    cin >> n;
    if (n == "I"){
        cout<<"================================================="<<endl;
        int benar = 0;
        for (i=20, i<20, i++){
            if (y_kecoak[i] >= y_robot + 1 && y_kecoak[i] <= y_robot + jarak){
                health_kecoak[i] = health_kecoak[i] - att;
                cout<<"Health Kecoak" << i << "=" << health_kecoak[i]<<endl;
                benar = benar + 1;
            }
        }
        if (benar == 0){
            cout<<"Kecoak diluar jangkauan"<<endl;
        }
        cout<<"================================================="<<endl;
    }
    else if (n=="J"){
        cout<<"================================================="<<endl;
        benar = 0;
        for (i=20, i<20, i++){
            if (x_kecoak[i] >= x_robot - 1 && x_kecoak[i] <= x_robot - jarak){
                health_kecoak[i] = health_kecoak[i] - att;
                cout<<"Health Kecoak"<< i << "=" << health_kecoak[i]<<endl;
                benar = benar +1;
            }
        }
        if (benar == 0) {
            cout<<"Kecoak diluar jangkauan"<< endl;
        }
        cout<<"================================================="<<endl;
    }
    else if (n =="K"){
        cout<<"================================================="<<endl;
        benar = 0;
        for (i=20, i<20, i++){
            if (y_kecoak[i] >= y_robot - 1 && y_kecoak[i] <= y_robot - jarak){
                health_kecoak[i] = health_kecoak[i] - att;
                cout<<"Health Kecoak"<< i<< "="<< health_kecoak[i];
                benar = benar + 1;
            }
        }
        if (benar == 0){
            cout<<"Kecoak diluar jangkauan"<<endl;
        }
        cout<<"================================================="<<endl;
    }
    else if (n=="L"){
        cout<<"================================================="<<endl;
        benar = 0;
        for (i=0, i<20, i++){
            if (x_kecoak[i] >= x_robot + 1 && x_kecoak[i] <= x_robot + jarak){
                health_kecoak[i] = health_kecoak[i] - att;
                cout<<"Health Kecoak"<<i<<"="<< health_kecoak[i];
                benar = benar + 1;
            }
        }
        if (benar == 0){
            cout<<"Kecoak diluar jangkauan"<<endl;
        }
        cout<<"================================================="<<endl;
    }
}

void robot(int health, int att){
    cout<<"Health robotmu ="<< health << endl;
}

void kecoakmati(int health_kecoak){
    int mati = 0;
    for (i=0, i<20, i++){
        if (health_kecoak[i] == 0){
            mati = mati +1;
        }
    }
    return mati;
}

main()
{
    cout <<"================================================="<<endl;
    cout <<"MULAI"<<endl;
    cout <<"================================================="<<endl;
    int x_robot = 0;
    int y_robot = 0;
    int health_robot = 100;
    int att_robot = 50;
    int x_kecoak = [-1 for i in range (20)];
    int y_kecoak = [-1 for i in range (20)];
    int health_kecoak = {-1 for (i=0; i<20;i++)};
    while (health_robot > 0 || kecoakmati(health_kecoak)==20){
        kecoak_baru(x_robot,y_robot,x_kecoak,y_kecoak);
        papan();
        cout<<"================================================="<<endl;
        cout<<"Pindah(1) atau tembak(2) ?"<<endl;
        int a;
        cin >> a;
        if (a == 1){
            x_robot, y_robot = pindah(x_robot,y_robot,x_kecoak,y_kecoak);
        }
        else if (a == 2){
            tembak(x_robot,y_robot,x_kecoak,y_kecoak,health_kecoak,att_robot);
        }
        cout<<"=================================================";
    }
    return 0;


}