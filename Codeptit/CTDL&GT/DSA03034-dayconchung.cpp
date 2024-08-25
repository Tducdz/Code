#include<bits/stdc++.h>

using namespace std;

int main() {
    int t = 1, x, y, z, a;
    cin >> t;
    while(t--) {
        cin >> x >> y >> z;
        int a[x], b[y], c[z];
        bool check = 0;
        for (int i = 0; i < x; i++) cin >> a[i];
        for (int i = 0; i < y; i++) cin >> b[i];
        for (int i = 0; i < z; i++) cin >> c[i];
        int idxA, idxB, idxC;
        idxA = idxB = idxC = 0;
        while(idxA < x && idxB < y && idxC < z) {
            if(a[idxA] == b[idxB] && b[idxB] == c[idxC]) {
                cout << a[idxA] << ' ';
                check = 1;
                ++idxA;
                ++idxB;
                ++idxC;
            }
            else if(a[idxA] < b[idxB]) ++idxA;
            else if(b[idxB] < c[idxC]) ++idxB;
            else ++idxC;
        }
        if(!check) cout << "NO";
        cout << endl;
    }
    return 0;
}