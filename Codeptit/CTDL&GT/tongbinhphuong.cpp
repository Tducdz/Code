#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int t, i, j, n, F[10002];
    cin >> t;
    F[1] = 1;
    F[2] = 2;
    F[3] = 3;
    for (i = 4; i <= 10000; i++) {
        F[i] = i;
        for (j = 1; j <= sqrt(i); j++) {
            F[i] = min(F[i], F[i - j*j] + 1);
        }
    }
    while (t--) {
        cin >> n;
        cout << F[n] << endl;
    }
}