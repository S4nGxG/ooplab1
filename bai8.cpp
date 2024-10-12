#include <bits/stdc++.h>
using namespace std;

ifstream fileInput("data.txt");

struct flight {
    string code;
    int day, month, year;
    int hour, minute;
    string source, des;
};

//Kiểm tra tính hợp lệ của ngày bay
bool checkDate(int day, int month, int year) {
    if (year < 0) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1) return false;

    int m[15] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0) {
        m[1] = 29; 
    }
    return day <= m[month - 1];
}

//Kiểm tra tính hợp lệ của giờ bay
bool checkTime(int hour, int minute) {
    if(hour >= 0 && hour < 24 && minute >= 0 && minute < 60)
        return true;
    return false;
}

//Kiểm tra tính hợp lệ của mã chuyến bay, nơi đi và nơi đến
bool checkStr(string code, string source, string des) {
    if(source.size() > 20 || des.size() > 20 || code.size() > 5)
        return false;
    return true;
}

//Hàm nhập dữ liệu chuyến bay
void Nhap(flight &a) {
    bool check = true;
    string datestr, timestr;
    do {
        if(check == false) 
            cout << "Du lieu khong hop le! Vui long nhap lai.\n";
        cout << "Nhap ma chuyen bay: "; fileInput >> a.code;
        cout << "Nhap ngay bay(dd/mm/yyyy): "; fileInput >> datestr;
        cout << "Nhap gio bay(hh:mm): "; fileInput >> timestr;
        cout << "Nhap noi di: "; getline(fileInput, a.source);
        cout << "Nhap noi den: "; getline(fileInput, a.des);

        // Tách ngày, tháng, năm từ chuỗi
        stringstream d(datestr);
        string temp;
        getline(d, temp, '/');
        a.day = stoi(temp);
        getline(d, temp, '/');
        a.month = stoi(temp);
        getline(d, temp);
        a.year = stoi(temp);

        // Tách giờ và phút từ chuỗi
        stringstream t(timestr);
        getline(t, temp, ':');
        a.hour = stoi(temp);
        getline(t, temp);
        a.minute = stoi(temp);

        //Kiểm tra tính hợp lệ của dữ liệu
        if(!checkDate(a.day, a.month, a.year) || !checkTime(a.hour, a.minute) || !checkStr(a.code, a.source, a.des)) 
            check = false;
        else check = true;
            
    } while(!check);
}

//Hàm xuất dữ liệu chuyến bay
void Xuat(flight &a) {
    cout << "Ma chuyen bay: " << a.code << endl;
    cout << "Ngay bay: " << setw(2) << setfill('0') << a.day << "/" 
         << setw(2) << setfill('0') << a.month << "/" << a.year << endl;
    cout << "Gio bay: " << setw(2) << setfill('0') << a.hour << ":" 
         << setw(2) << setfill('0') << a.minute << endl;
    cout << "Noi di: " << a.source << endl;
    cout << "Noi den: " << a.des << endl;
    cout << "-----------------------------\n";
}


//Hàm tìm thông tin chuyến bay theo mã chuyến bay
void search(flight a[], int n) {
    string temp;
    cout << "Nhap ma chuyen bay can tim: "; cin >> temp;
    for(int i = 1; i <= n; i++) {
        if(temp == a[i].code) {
            Xuat(a[i]);
            break;
        }
    }
}

//Hàm điều kiện để sắp xếp các chuyến bay theo ngày và giờ từ sớm đến muộn
bool compareflight(flight &a, flight &b) {
    if (a.year != b.year)
        return a.year < b.year;
    if (a.month != b.month)
        return a.month < b.month;
    if (a.day != b.day)
        return a.day < b.day;
    if (a.hour != b.hour)
        return a.hour < b.hour;
    return a.minute < b.minute;
}

//Hàm hiển thị tất cả chuyến bay khởi hành từ 1 nơi cụ thể trong 1 ngày được chỉ định
void getflight(flight a[], int n) {
    string searchSource, searchDate;
    int searchDay, searchMonth, searchYear;
    bool check = false;

    cin.ignore();
    cout << "Nhap noi can tim: "; getline(cin, searchSource);
    cout << "Nhap ngay bay can tim (dd/mm/yyyy): "; cin >> searchDate;

    // Tách ngày, tháng, năm từ chuỗi
    stringstream d(searchDate);
    string temp;
    getline(d, temp, '/');
    searchDay = stoi(temp);
    getline(d, temp, '/');
    searchMonth = stoi(temp);
    getline(d, temp);
    searchYear = stoi(temp);

    //Tìm các chuyến bay phù hợp
    cout << "Danh sach cac chuyen bay" << endl;
    for(int i = 1; i <= n; i++) {
        if(a[i].source == searchSource && a[i].day == searchDay && a[i].month == searchMonth && a[i].year == searchYear) {
            Xuat(a[i]);
            check = true;
        }
    }
    if(!check) cout << "Khong co chuyen bay nao!\n";
}

//Hàm đếm số lượng chuyến bay từ một nơi đến 1 nơi nhất định
void dem(flight a[], int n) {
    string s, d;
    int res = 0;
    bool check = false;

    cin.ignore();
    cout << "Nhap noi di: "; cin >> s;
    cin.ignore();
    cout << "Nhap noi den: "; cin >> d;

    //Tìm các chuyến bay phù hợp
    for(int i = 1; i <= n; i++) {
        if(a[i].source == s && a[i].des == d) {
            res++;
            check = true;
        }
    }

    if(!check) cout << "Khong co chuyen bay nao!\n";
    else cout << "Co " << res << " chuyen bay tu " << s << " den " << d << endl;
}

int main() {
    flight a[100];
    int n;
    cout << "Nhap so chuyen bay: "; fileInput >> n;
    for(int i = 1; i <= n; i++) {
        cout << "Nhap thong tin chuyen bay " << i << endl;
        Nhap(a[i]);
    }

    //sắp xếp các chuyến bay theo thứ thự thời gian 
    sort(a + 1, a + n + 1, compareflight);

    cout << "Chon chuc nang can tim:\n";
    cout << "1. Danh sach cac chuyen bay\n";
    cout << "2. Tim chuyen bay theo ma chuyen bay\n";
    cout << "3. Tim cac chuyen bay tu mot noi và thoi gian cu the\n";
    cout << "4. Dem so luong cac chuyen bay tu mot noi den mot noi nhat dinh\n";
    cout << "5. Thoat\n";

    int e = 1;

    do {
        if(e < 0 || e > 5) cout << "Invalid value!\n";
        cout << "> ";
        cin >> e;
        if(e == 1) {
            cout << "Danh sach cac chuyen bay la \n";
            for(int i = 1; i <= n; i++) {
                Xuat(a[i]);
            }
        }
        if(e == 2) 
            search(a, n);
        if(e == 3)
            getflight(a, n);
        if(e == 4)
            dem(a, n);
    } while(e != 5);
}