#include<iostream>
#include<vector>
using namespace std;

int giai(vector<int> s) {
    int dem = 0;
    while (s.size()) {
        int sodau = s[0];
        s.erase(s.begin());
        for(int i = 0; i < s.size(); i++) {
            if (sodau < s[i]) {
                sodau = s[i];
                s.erase(s.begin() + i);
                i -= 1;
            }
        }
        dem++;
    }
    return dem;
}

void lietke(vector<int> s) {
    int dem = 0, ss = 0;
    while (s.size()) {
        int sodau = s[0];
        s.erase(s.begin());
        cout << sodau << ' ';
        for(int i = 0; i < s.size(); i++) {
            if (sodau < s[i]) {
                sodau = s[i];
                s.erase(s.begin() + i);
                i -= 1;
                if (ss == 1) {
                    cout << sodau << ' ';
                }
            }
        }
        dem++;
        if (ss == 1) cout << endl;
    }
    ss = 1;
}

int main() {
    long long n;
    cin >> n;
    vector<int> s1;
    vector<int> s2;
    int k;
    for (long long i = 0; i < n; i++) {
        cin >> k;
        s1.push_back(k);       
        s2.push_back(k);       
    }
    cout << giai(s1) << endl;
    lietke(s2);
    return 0;
}