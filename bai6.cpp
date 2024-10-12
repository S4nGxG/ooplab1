#include <bits/stdc++.h>
using namespace std;

bool check = false;
// Ham tinh mang LPS (Longest Prefix Suffix)
void LPS(vector<int> &pattern, vector<int> &lps) {
    int length = 0; // Do dai cua tien to lon nhat cung la hau to
    int i = 1;      // Bat dau tu phan tu thu 2 cua mang pattern
    lps[0] = 0;     // Phan tu dau tien luon la 0

    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } 
        else {
            if (length != 0) {
                // Quay lai lps[length-1]
                length = lps[length - 1];
            } 
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Ham KMP de tim kiem mang con trong mang lon
void KMP(vector<int> &text, vector<int> &pattern) {
    int n = text.size();
    int m = pattern.size();
    int dem = 0;
    vector<int> result;

    // Tao mang LPS
    vector<int> lps(m);
    LPS(pattern, lps);

    int i = 0; // Chi so cho mang text
    int j = 0; // Chi so cho mang pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            // Tim thay mang con tai vi tri i - j
            check = true;
            dem++;
            result.push_back(i-j);
            j = lps[j - 1];
        } 
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } 
            else {
                i++;
            }
        }
    }
    if(check) {
        cout << "So lan mang A xuat hien trong B: " << dem << endl;
        cout << "Cac vi tri xuat hien la: ";
        for(int i = 0; i < dem; i++) {
            cout << result[i];
            if(i != dem-1) cout << ", ";
        }
        cout << endl;
    }
    
}

int main() {
    int n, m;
    vector<int> a, b;
    cout << "Nhap lan luot so phan tu mang A va B: "; cin >> n >> m;
    cout << "Nhap cac phan tu mang A: ";
    for(int i = 0 ; i < n; i++) {
        int e;
        cin >> e;
        a.push_back(e);
    }
    cout << "Nhap cac phan tu mang B: ";
    for(int i = 0 ; i < m; i++) {
        int e;
        cin >> e;
        b.push_back(e);
    }

    // Tim kiem vi tri xuat hien mang con trong mang lon
    KMP(b, a);
    
    if(!check) {
        cout << "Mang A khong xuat hien trong mang B!";
    }
    return 0;
}
