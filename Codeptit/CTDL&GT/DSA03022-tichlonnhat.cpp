#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int M1, M2, M3, m1, m2, m3;
    M1 = M2 = M3 = INT_MIN;
    m1 = m2 = m3 = INT_MAX;
    while(cin >> n) {
        if(n > M1) {
            M3 = M2;
            M2 = M1;
            M1 = n;
        }
        else if(n > M2) {
            M3 = M2;
            M2 = n;
        }
        else if(n > M3) M3 = n;
        if(n < m1) {
            m3 = m2;
            m2 = m1;
            m1 = n;
        }
        else if(n < m2) {
            m3 = m2;
            m2 = n;
        }
        else if(n < m3) m3 = n;
    }
    cout << max(M1 * M2 * M3, max(m1 * m2 * M1, max(m1 * m2, M1 * M2)));
    return 0;
}