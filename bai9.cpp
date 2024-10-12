#include <bits/stdc++.h>
using namespace std;

struct Ngay {
    int ngay, thang, nam;

    // Kiem tra ngay hop le
    bool hopLe() {
        if (nam < 0 || thang < 1 || thang > 12 || ngay < 1) return false;
        vector<int> ngayTrongThang = { 31, (namNhuan() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return ngay <= ngayTrongThang[thang - 1];
    }

    bool namNhuan() {
        return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    }
};

struct SoTK {
    string maSo, loaiTK, tenKhachHang;
    int soCMND;
    Ngay ngayMo;
    float soTienGui;
    float laiSuat;

    // Kiem tra ma so hop le
    bool hopLeMaSo() {
        if (maSo.size() > 5 || maSo.empty()) return false;
        for (char ch : maSo) {
            if (!isalnum(ch)) return false;
        }
        return true;
    }

    // Kiem tra CMND hop le
    bool hopLeCMND() {
        int doDai = to_string(soCMND).size();
        return doDai == 9 || doDai == 12;
    }

    // Kiem tra ho ten hop le 
    bool hopLeHoTen() {
        if (tenKhachHang.size() > 30 || tenKhachHang.empty()) return false;
        for (char ch : tenKhachHang) {
            if (!isalpha(ch) && ch != ' ') return false;
        }
        return true;
    }

    // Kiem tra so tien gui hop le
    bool hopLeSoTienGui() {
        return soTienGui > 0;
    }

    // Tinh lai suat
    float tinhLai(int thangGui) const {
        return soTienGui * laiSuat * thangGui / 12 / 100;
    }

    void hienThiThongTin() const {
        cout << "Ma so: " << maSo << endl;
        cout << "Loai tiet kiem: " << loaiTK << endl;
        cout << "Ho ten khach hang: " << tenKhachHang << endl;
        cout << "CMND: " << soCMND << endl;
        cout << "Ngay mo so: " << ngayMo.ngay << "/" << ngayMo.thang << "/" << ngayMo.nam << endl;
        cout << "So tien gui: " << soTienGui << endl;
        cout << "----------------------------" << endl;
    }
};

// Nhap ngay
Ngay nhapNgay() {
    Ngay ngay;
    while (true) {
        cout << "Nhap ngay (dd mm yyyy): ";
        cin >> ngay.ngay >> ngay.thang >> ngay.nam;
        if (ngay.hopLe()) break;
        cout << "Ngay khong hop le! Vui long nhap lai." << endl;
    }
    return ngay;
}

// Nhap thong tin so tiet kiem
SoTK nhapThongTinSoTK() {
    SoTK stk;
    cin.ignore();
    while (true) {
        cout << "Nhap ma so: ";
        getline(cin, stk.maSo);
        if (stk.hopLeMaSo()) break;
        cout << "Ma so khong hop le! Vui long nhap lai." << endl;
    }
    cout << "Nhap loai tiet kiem: ";
    getline(cin, stk.loaiTK);
    while (true) {
        cout << "Nhap ho ten khach hang: ";
        getline(cin, stk.tenKhachHang);
        if (stk.hopLeHoTen()) break;
        cout << "Ho ten khong hop le! Vui long nhap lai." << endl;
    }
    while (true) {
        cout << "Nhap CMND: ";
        cin >> stk.soCMND;
        if (stk.hopLeCMND()) break;
        cout << "CMND khong hop le! Vui long nhap lai." << endl;
    }
    stk.ngayMo = nhapNgay();
    while (true) {
        cout << "Nhap so tien gui: ";
        cin >> stk.soTienGui;
        if (stk.hopLeSoTienGui()) break;
        cout << "So tien gui khong hop le! Vui long nhap lai." << endl;
    }
    cout << "Nhap lai suat (%/nam): ";
    cin >> stk.laiSuat;
    return stk;
}

// Tinh tien lai
float tinhTienLai(const SoTK& stk, const Ngay& ngayHienTai) {
    int thangGui = (ngayHienTai.nam - stk.ngayMo.nam) * 12 + (ngayHienTai.thang - stk.ngayMo.thang);
    return stk.tinhLai(thangGui);
}

// Tim kiem so tiet kiem
SoTK* timSoTK(vector<SoTK>& danhSach, const string& keyword) {
    for (SoTK& stk : danhSach) {
        if (stk.maSo == keyword || to_string(stk.soCMND) == keyword) {
            return &stk;
        }
    }
    return nullptr;
}

// Liet ke so tiet kiem theo khoang thoi gian
void lietKeSoTKTheoKhoangThoiGian(const vector<SoTK>& danhSach, const Ngay& tuNgay, const Ngay& denNgay) {
    for (const SoTK& stk : danhSach) {
        if ((stk.ngayMo.nam > tuNgay.nam || (stk.ngayMo.nam == tuNgay.nam && stk.ngayMo.thang >= tuNgay.thang)) &&
            (stk.ngayMo.nam < denNgay.nam || (stk.ngayMo.nam == denNgay.nam && stk.ngayMo.thang <= denNgay.thang))) {
            stk.hienThiThongTin();
        }
    }
}

int main() {
    int soLuongSoTK;
    cout << "Nhap so luong so tiet kiem: ";
    cin >> soLuongSoTK;
    vector<SoTK> danhSachSoTK;
    
    for (int i = 0; i < soLuongSoTK; i++) {
        cout << "Nhap thong tin so tiet kiem thu " << i + 1 << endl;
        danhSachSoTK.push_back(nhapThongTinSoTK());
    }

    string keyword;
    cout << "Nhap CMND hoac ma so de tim kiem: ";
    cin >> keyword;
    SoTK* ketQuaTimKiem = timSoTK(danhSachSoTK, keyword);
    if (ketQuaTimKiem) {
        cout << "Thong tin so tiet kiem tim thay:" << endl;
        ketQuaTimKiem->hienThiThongTin();
    } else {
        cout << "Khong tim thay so tiet kiem voi CMND hoac ma so: " << keyword << endl;
    }

    cout << "Nhap khoang thoi gian de liet ke so tiet kiem:" << endl;
    Ngay tuNgay = nhapNgay();
    Ngay denNgay = nhapNgay();
    cout << "Danh sach so tiet kiem mo trong khoang thoi gian:" << endl;
    lietKeSoTKTheoKhoangThoiGian(danhSachSoTK, tuNgay, denNgay);

    return 0;
}
