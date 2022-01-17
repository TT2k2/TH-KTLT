#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<string.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* Nodeptr;

struct Queue {
    Nodeptr front, rear;
};

struct STACK {
    Nodeptr top;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

void insert_(Node*& node, int data) {
    if (node == NULL) {
        node = newNode(data);
        return;
    }
    insert_(node->next, data);
}

void print(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
}

void delete_(Node*& node, int data) {

    while (node != NULL && node->data == data) {
        node = node->next;
    }

    if (node == NULL) return;
    Node* tail = node;
    Node* prev = tail;
    tail = tail->next;

    while (tail != NULL) {
        if (tail->data == data) {
            prev->next = tail->next;
        }
        else {
            prev = tail;
        }
        tail = tail->next;
    }

}

void deleteStack(STACK& stc, int x) {
    delete_(stc.top, x);
}

int main() {
    STACK stc; stc.top = NULL;
    insert_(stc.top, 1);
    insert_(stc.top, 2);
    insert_(stc.top, 3);
    insert_(stc.top, 5);

    cout << "Stack ban dau: ";
    print(stc.top);

    int x;
    cout << "\nNhap phan tu can xoa: ";
    cin >> x;
    cout << endl << "Stack sau khi xoa phan tu " << x << " la: ";
    deleteStack(stc, x);
    print(stc.top);

}

