#include <bits/stdc++.h>
using namespace std;

ifstream fileInput("b6b.txt");

struct student {
    string name;
    float DiemToan, DiemVan, DiemNN;
    float dtb;
    string xeploai;
};

//Ham nhap thong tin hoc sinh
void Nhap(student &a) {

    bool check = true;
    do {
        if(!check) cout << "Khong hop le!\nvui long nhap lai!\n";
        cout << "Nhap ho ten hoc sinh: ";
        fileInput.ignore();  
        getline(fileInput, a.name);
        int n = a.name.size();
        check = true;
        if(n > 50) check = false;   //Kiem tra tinh hop le cua du lieu
        for(int i = 0; i < n; i++) { 
            if(a.name[i] >= '0' && a.name[i] <= '9') {
                check = false;
                break;
            }
        }
    } while(!check);
    
    check = true;
    do {
        if(!check) cout << "Khong hop le!\nVui long nhap lai!\n";
        cout << "Nhap diem Toan: "; fileInput >> a.DiemToan;
        cout << "Nhap diem Van: "; fileInput >> a.DiemVan;
        cout << "Nhap diem Ngoai Ngu: "; fileInput >> a.DiemNN;
        check = a.DiemToan >= 0 && a.DiemToan <= 10 && a.DiemVan >= 0 && a.DiemVan <= 10 && a.DiemNN >= 0 && a.DiemNN <= 10;
    } while (!check);
}

//Tinh diem trung binh tung hoc sinh
void DTB(student a[], int n) {
    for(int i = 0; i < n; i++) {
        a[i].dtb = (2*a[i].DiemToan + a[i].DiemVan + a[i].DiemNN) / 4;
        if(a[i].dtb >= 9) a[i].xeploai = "Xuat sac";
        else if(a[i].dtb >= 8) a[i].xeploai = "Gioi";
        else if(a[i].dtb >= 6.5) a[i].xeploai = "Kha";
        else if(a[i].dtb >= 5) a[i].xeploai = "Trung binh";
        else a[i].xeploai = "Yeu";
        cout << "Diem trung binh cua hoc sinh " << i + 1 << " la: " << a[i].dtb << " - Xep loai: " << a[i].xeploai << endl;
        cout << "----------------------------" << endl;
    }
}

//Ham tim cac hoc sinh co DTB cao nhat
void geths(student a[], int n) {
    int index = 0;
    for(int i = 1; i < n; i++) {
        if(a[i].dtb > a[index].dtb) {
            index = i;
        }
    }
    cout << "Hoc sinh co DTB cao nhat la: " << a[index].name << endl;
}

//Ham tim cac hoc sinh co Diem Toan thap nhat
void getdt(student a[], int n) {
    float minDiemToan = a[0].DiemToan;
    for(int i = 1; i < n; i++) {
        if(a[i].DiemToan < minDiemToan) {
            minDiemToan = a[i].DiemToan;
        }
    }
    cout << "Danh sach hoc sinh co diem Toan thap nhat la:\n";
    for(int i = 0; i < n; i++) {
        if(a[i].DiemToan == minDiemToan) 
            cout << a[i].name << endl;
    }
}

//Ham tim hoc sinh theo ten
void search(student a[], int n) {
    string res;
    cout << "Nhap ten hoc sinh can tim: "; 
    getline(cin, res);
    for(char &c : res) {    //Chuyen ten can tim ve ki tu thuong 
        c = tolower(c);
    }
    bool found = false;
    for(int i = 0; i < n; i++) { //Chuyen cac ten hoc sinh ve ki tu thuong de tim kiem
        string temp = a[i].name;
        for(char &c : temp) {
            c = tolower(c);
        }
        if(temp.find(res) != string::npos) {
            cout << "Ho ten: " << a[i].name << endl;
            cout << "Diem Toan: " << a[i].DiemToan << endl;
            cout << "Diem Van: " << a[i].DiemVan << endl;
            cout << "Diem Ngoai Ngu: " << a[i].DiemNN << endl;
            cout << "Diem TB: " << a[i].dtb << " - Xep loai: " << a[i].xeploai << endl; 
            cout << "----------------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "Khong co hoc sinh nay!" << endl;
}

int main() {
    student a[100];
    int n;
    cout << "Nhap so luong hoc sinh: "; fileInput >> n;
    fileInput.ignore();
    for(int i = 0; i < n; i++) {
        cout << "Nhap thong tin hoc sinh " << i + 1 << endl;
        Nhap(a[i]);
    }
    DTB(a, n);
    geths(a, n);
    getdt(a, n);
    search(a, n);
    return 0;
}
