#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        m = 1 << n;
        vector<long long> trl;
        for (int i = 0; i < m; i++) {
            string s = "";
            for (int j = n - 1; ~j; j--) {
                if ((i >> j) & 1) {
                    s += '8';
                }
                else s += '6';
            }
            trl.push_back(stoll(s));
        }
        cout << trl.size() << endl;
        for (long long &i : trl) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}