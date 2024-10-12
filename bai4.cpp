#include <bits/stdc++.h>
using namespace std;

// Ham tinh giai thua
long long GT(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Ham tinh Sin(x) 
double Tinh(double x) {
    double sin_x = 0;
    double term;
    int n = 0;

    do {
        // Tinh tung phan tu cua chuoi
        term = pow(-1, n) * pow(x, 2 * n + 1) / GT(2 * n + 1);
        sin_x += term;
        n++;
    } while (fabs(term) > 0.00001);  

    return sin_x;
}

int main() {
    double x;
    cout << "Nhap x (do): ";
    cin >> x;
    
    x = fmod(x, 360.0); 

    if (fabs(fmod(x, 180.0)) < 1e-9) { // Su dung fmod de tinh phan du
        cout << "sin(" << x << ") = 0" << endl;
    }
    else {
        // Chuyen tu do sang radian
        double radians = x * (M_PI / 180.0);
        
        // Tinh sin(x) va xuat ket qua
        double sinValue = Tinh(radians);

        cout << "sin(" << x << ") = " << sinValue << endl;
    }
    return 0;
}
