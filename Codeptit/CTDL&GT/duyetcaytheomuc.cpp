#include<bits/stdc++.h>
using namespace std;



void levelOrder(Node* root) {
    queue<Node* > Q;
    Q.push(root);
    while (!Q.empty()) {
        Node *nd = Q.front();
        Q.pop();
        cout << nd->data << " ";
        if (nd->left != NULL) Q.push(nd->left);
        if (nd->right != NULL) Q.push(nd->right);
    }
}

void insert(Note *root, int n1, int n2, char c) {
    if (root = NULL) return;
    if (root->data == n1) {
        if (c == '1') root->left = new Node(n2);
        else root->right = new Node(n2);
    }
    else {
        insert(root->left, n1, n2, c);
        insert(root->right, n1, n2, c);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {

    }
}