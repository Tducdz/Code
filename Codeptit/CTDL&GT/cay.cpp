#include<iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node *insertNode(node *t, int x) {
    if (t == NULL) {
        node *temp = new node;
        temp->left = NULL;
        temp->right = NULL;
        temp->data = x;
        return temp;
    }
    else {
        if (x < t->data) {
            t->left = insertNode(t->left, x);
        } else {
            t->right = insertNode(t->right, x);
        }
        return t;
    }
}

void duyetGiua(node *t) {
    if (t != NULL) {
        cout << t->data << " ";        
        duyetGiua(t->right); 
        duyetGiua(t->left);
    }
}

int main() {
    int n;
    cin >> n;
    int x;
    node *t = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        t = insertNode(t, x);
    }
    duyetGiua(t);
    return 0;
}
