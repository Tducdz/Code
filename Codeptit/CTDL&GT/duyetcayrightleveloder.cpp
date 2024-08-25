#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node *createNode(int x) {
    node *temp = new node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

void *buildTree(node *&t, int data) {
    if (t == NULL) t = createNode(data);
    else {
        if (t->data->data) buildTree(t->left, data);
        else buildTree
    }
}

int main() {

}