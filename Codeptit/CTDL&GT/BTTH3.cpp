#include<iostream>
using namespace std;

struct node {
    char data;
    node *next;
    node *pre;
};

struct duoList {
    node *head;
    node *tail;
};

duoList *createList(char x) {
    duoList *l = new duoList;
    l->head = new node;
    l->head->data = x;
    l->head->next = NULL;
    l->head->pre = NULL;
    l->tail = l->head;
    return l;
}

duoList *addHead(duoList *l, char x, node* p) {
    node *temp = new node;
    temp->data = x;
    temp->next = l->head;
    temp->pre = NULL;
    l->head->pre = temp;
    l->head = temp;
    p = l->head;
    return l;
}

duoList *addTail(duoList *l, char x, node* p) {
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    temp->pre = l->tail;
    l->tail->next = temp;
    l->tail = temp;
    p = l->tail;
    return l;
}

duoList *addAt(duoList *l, char x, node* p) {
    node *temp = new node;
    temp->data = x;
    temp->pre = p;
    temp->next = p->next;
    p->next = temp;
    p->next->pre = temp;
    p = temp;
    return l;
}

duoList *deleteNode(duoList *l, node* p) {
    if (p->next == NULL) {
        node *temp = p;
        p->pre->next = NULL;
        temp->pre = NULL;
        delete(temp);
        return l;
    }
    else {
        node *temp = p;
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre;
        delete(temp);
        return l;
    }
}

void printList(duoList *l) {
    node *t = l->head;
    while (t != NULL) {
        cout << t->data << " ";
    }
}

int main() {
    string s;
    int k;
    getline(cin, s);
    duoList *l =  createList('0');
    node* p = l->head;
    for (int i = 0; i < s.length(); i++) {
        while (((s[i] <= 'z') && (s[i] >= 'a')) || ((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= '0') && (s[i] <= '9'))) {
            duoList *l = addTail(l, s[i], p);
        }
        k = i; 
    }
    for (int i = k; i < s.length(); i++) {
        if (s[i] == '<') {
            if (p != NULL && p->pre != NULL) {
                p = p->pre;
            }
        }
        else if (s[i] == '>') {
            if (p != NULL && p->next != NULL) {
                p = p->next;
            }
        }
        else if (s[i] == '-') {
            if (p != NULL) {
            l = deleteNode(l, p);
            }
        }
        else {
            if (p->next == NULL) {
                l = addTail(l, s[i], p);
            }
            if (p->pre == NULL) {
                l = addHead(l, s[i], p);
            }
            else {
                l = addAt(l, s[i], p);
            }
        }
    }
    printList(l);
    return 0;
}