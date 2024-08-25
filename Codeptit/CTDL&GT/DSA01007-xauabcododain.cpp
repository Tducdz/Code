#include<iostream>

using namespace std;

int n;
char a[25] = {};

void print() {
    for (int i = 0; i < n; i++) cout << a[i];
    cout << ' ';
}
 
void Try(int i) {
    for (int j = 'A'; j <= 'B'; j++) {
        a[i] = j;
        if (i == n - 1) {
            print();
        }        
        else Try(i + 1);
    }
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        cin >> n;
        Try(0);
        cout << endl;
    }
    return 0;
}