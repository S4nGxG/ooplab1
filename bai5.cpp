#include <bits/stdc++.h>
using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Ham kiem tra tinh hop le cua input
bool check(int d, int m, int y) {
    if(d == 29 && m == 2 && y%4 == 0) return true;
    if(d > month[m] || d < 1 || m > 12 || m < 1 || y <= 0)
        return false;
    return true; 
}

//Ham tim ngay ke tiep
void nextday(int d, int m, int y) {
    if(d < month[m] || (y%4 == 0 && m == 2 && d == 28)) { //Neu khong phai ngay cuoi thang hoac cuoi nam
        d++;
    }
    else { //Neu la ngay cuoi thang hoac cuoi nam
        d = 1;
        if(m == 12) {
            m = 1;
            y++;
        } 
        else m++;
    }
    cout << d << "/" << m  << "/" << y << endl;
}

//Ham tim ngay truoc do
void preday(int d, int m, int y) {
    if(d > 1) //Neu khong phai ngay dau thang hoac dau nam
        d--;
    else {  //Neu la ngay dau thang hoac dau nam
        if(m == 1) {
            y--;
            m = 12;
            d = month[12];
        }
        else {
            if(m == 3) {
                if(y%4 == 0) d = 29;
                else d = 28;
            }
            else d = month[m-1];
            m--;
        }
        
    }
    cout << d << "/" << m  << "/" << y << endl;   
}

//Ham tinh ngay thu bao nhieu trong nam
void day(int d, int m, int y) {
    int sum = 0;
    for(int i = 1; i <= m-1; i++) {
        sum += month[i];
    }
    sum += d;
    if(y%4 == 0 && m > 2) sum++; //Neu nam nhuan va tren thang 2 thi cong them 1
    cout << sum;
}

int main() {
    int d = 1, m = 1, y = 1;
    do {
        if(check(d, m, y) == false)
            cout << "Khong Hop Le!\nVui Long Nhap Lai\n";
        cout << "Nhap ngay: "; cin >> d;
        cout << "Nhap thang: "; cin >> m;
        cout << "Nhap nam: "; cin >> y;
    } while(check(d, m, y) == false);

    cout << "Ngay ke tiep la: ";
    nextday(d, m, y);
    cout << "Ngay truoc do la: ";
    preday(d, m, y);
    cout << "Ngay nay la ngay thu ";
    day(d, m, y);
    cout << " trong nam";
    return 0;
}