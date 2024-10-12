#include <bits/stdc++.h>
using namespace std;

//Ham tim uoc chung lon nhat
int GCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//Hàm xu li phan so ket qua
void process(double tu, double mau) {
    int temp = GCD(abs(tu), abs(mau));
    tu /= temp;
    mau /= temp;

    if(tu == 0) {
        cout << 0 << endl;
        return;
    }
    if(tu < 0 || mau < 0) {
        if(tu*mau < 0) 
            tu = abs(tu)*(-1);
           
        else
            tu = abs(tu);
        mau = abs(mau);
    }
    
    if(mau == 1)
        cout << tu << endl;
    else 
        cout << tu << "/" << mau << endl;
}

//Ham tinh tong 2 phan so
void Tong(double tu1, double mau1, double tu2, double mau2) {
    double tu, mau;
    mau = mau1*mau2;
    tu = tu1*mau2 + tu2*mau1;
    process(tu, mau);
}

//Ham tinh hieu 2 phan so
void Hieu(double tu1, double mau1, double tu2, double mau2) {
    double tu, mau;
    mau = mau1*mau2;
    tu = tu1*mau2 - tu2*mau1;
    process(tu, mau);
}

//Ham tinh tich 2 phan so
void Tich(double tu1, double mau1, double tu2, double mau2) {
    double tu, mau;
    int temp1 = GCD(abs(tu1), abs(mau1));
    int temp2 = GCD(abs(tu2), abs(mau2));
    tu1 /= temp1;
    mau1 /= temp1;
    tu2 /= temp2;
    mau2 /= temp2;
    mau = mau1*mau2;
    tu = tu1*tu2;
    process(tu, mau);
}

//Ham tinh thuong 2 phan so
void Thuong(double tu1, double mau1, double tu2, double mau2) {
    double tu, mau;
    mau = mau1*tu2;
    tu = tu1*mau2;
    if(mau == 0) {
        cout << "Invalid value!";
    }
    else 
        process(tu, mau);
}

int main() {
    double a, b, c, d;
    bool check = true;

    do {
        cout << "Nhap tu so thu 1: "; cin >> a;
        cout << "Nhap mau so thu 1: "; cin >> b;
        cout << "Nhap tu so thu 2: "; cin >> c;
        cout << "Nhap mau so thu 2: "; cin >> d;
        //kiem tra tinh hop le cua phan so
        if(b == 0 || d == 0) {
            cout << "Khong hop le!\n";
            check = false;
        }
        else check = true;
    } while(!check);

    cout << "Tong 2 phan so: ";
    Tong(a, b, c, d);
    cout << "Hieu 2 phan so: ";
    Hieu(a, b, c ,d);
    cout << "Tich 2 phan so: ";
    Tich(a, b, c, d);
    cout << "Thuong 2 phan so: ";
    Thuong(a, b, c, d);
    return 0;
}