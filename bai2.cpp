#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, d;
    bool check = true;
    do {
        cout << "Nhap tu so thu 1: "; cin >> a;
        cout << "Nhap mau so thu 1: "; cin >> b;
        cout << "Nhap tu so thu 2: "; cin >> c;
        cout << "Nhap mau so thu 2: "; cin >> d;
        if(b == 0 || d == 0) {
            cout << "Khong hop le!\n";
            check = false;
        }
        else check = true;
    } while(!check);

    double tu, mau, hieu;
    hieu = (a/b) - (c/d);
    if(hieu == 0) {
        cout << "Hai phan so bang nhau!";
    }
    else {
        if(hieu > 0) {
            tu = a;
            mau = b;
        }
        else {
            tu = c;
            mau = d;
        }
        cout << "Phan so lon hon la: " << tu << "/" << mau;
    }   
    return 0;
}