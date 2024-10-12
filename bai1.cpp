#include <bits/stdc++.h>
using namespace std;

//Hàm tìm ước chung lớn nhất
int GCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    double n, m;
    bool check = true;
    do{
        if(!check) cout << "Khong hop le!\nVui long nhap lai.\n";
        cout << "Nhap tu so: "; cin >> n;
        cout << "Nhap mau so: "; cin >> m;
        if(m == 0) check = false;
        else check = true;
    } while(!check);
    
    int temp = GCD(abs(n), abs(m));
    n /= temp;
    m /= temp;

    //Xử lý trường hợp nếu cả tử và mẫ là số âm hoặc chỉ 1 trong 2 là số âm
    if(n < 0 || m < 0) {
        if(n*m < 0)
            n = abs(n)*(-1);
        else
            n = abs(n);
        m = abs(m);
    }
    if(m == 1) 
        cout << "Phan so da rut gon la: " << n;
    else 
        cout << "Phan so da rut gon la: " << n << "/" << m;
    return 0;
}