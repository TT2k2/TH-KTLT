#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<string.h>
using namespace std;

struct CuaHang {
    char maCH[5];
    char tenCH[30];
    int soNha;
    char tenDuong[30];
    char phuong[10];
    char quan[10];
    char thanhPho[30];
};

struct DaySo {
    vector<CuaHang> arr;
};

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void print(CuaHang c) {
    cout << c.maCH << " " << c.tenCH << " " << c.soNha << " " << c.tenDuong << " " << c.phuong << " " << c.quan << " " << c.thanhPho << endl;
}

void printDs(DaySo ds) {
    for (int i = 0; i < ds.arr.size(); i++) {
        print(ds.arr[i]);
    }
}

void printIfPrime(DaySo ds) {
    for (int i = 0; i < ds.arr.size(); i++) {
        if (isPrime(ds.arr[i].soNha)) {
            print(ds.arr[i]);
        }
    }
}

void reverses(DaySo& ds) {
    int n = ds.arr.size();
    for (int i = 0; i < n / 2; i++) {
        swap(ds.arr[i], ds.arr[n - i - 1]);
    }
}

void input(CuaHang& c) {
    cout << "\nnhap ma cua hang: ";
    cin >> c.maCH; cin.ignore();
    cout << "\nnhap ten cua hang: ";
    cin.getline(c.tenCH, 30);
    cout << "\nnhap so nha cua hang: ";
    cin >> c.soNha; cin.ignore();
    cout << "\nnhap ten duong: ";
    cin.getline(c.tenDuong, 30);
    cout << "\nnhap ten phuong: ";
    cin.getline(c.phuong, 10);
    cout << "\nnhap ten quan: ";
    cin.getline(c.quan, 10);
    cout << "\nnhap ten thanh pho: ";
    cin.getline(c.thanhPho, 30);
}


// -------------------- bai 2


struct Node {
    CuaHang data;
    Node* next;
};

Node* newNode(CuaHang data) {
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

void insertIncrease(Node*& n, CuaHang data) {

    Node* n2 = n;
    while (n2->next != NULL && strcmp(data.maCH, n2->next->data.maCH) < 0) {
        n2 = n2->next;
    }
    Node* n1 = newNode(data);
    n1->next = n2->next;
    n2->next = n1;
}

void insert_(Node*& node, CuaHang data) {
    if (node == NULL) {
        node = newNode(data);
        return;
    }
    insert_(node->next, data);
}



int isIncrease(Node* node) {
    while (node != NULL && node->next != NULL) {
        if (node->data.maCH > node->next->data.maCH) return 0;
        node = node->next;
    }
    return 1;
}

void printList(Node* node) {
    while (node) {
        print(node->data);
        node = node->next;
    }
}


int main() {
    DaySo ds;
    Node* list = NULL;

    cout << "nhap vao 4 cua hang\n";
    CuaHang c1, c2, c3, c4;
    input(c1);
    input(c2);
    input(c3);
    input(c4);

    ds.arr.push_back(c1);
    ds.arr.push_back(c2);
    ds.arr.push_back(c3);
    ds.arr.push_back(c4);

    cout << "in ra neu so nha la so nguyen to" << endl;
    printIfPrime(ds);

    cout << "dao nguoc" << endl;
    reverses(ds);
    printDs(ds);

    cout << "------------BAI 2-----------" << endl;
    insert_(list, c1);
    insert_(list, c2);
    insert_(list, c3);
    insert_(list, c4);

    cout << "list cua hang: \n";
    printList(list);
    insertIncrease(list, c1);
    cout << "\nlist sau khi insert ko thay doi thu tu: \n";
    printList(list);
    cout << "\nkiem tra list tang dan: " << isIncrease(list) << endl;

}
