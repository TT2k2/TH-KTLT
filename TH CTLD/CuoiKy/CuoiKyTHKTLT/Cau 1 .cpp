//#include<iostream>
//#include<vector>
//#include<string>
//#include<math.h>
//#include<string.h>
//
//using namespace std;
//
//struct CayBut {
//    int maCB;
//    char tenCB[30];
//    int soLuong;
//    float donGia;
//    char hangSX[30];
//};
//
//struct NodeCayBut {
//    CayBut data;
//    NodeCayBut* next;
//};
//
//typedef NodeCayBut* Nodeptr;
//int count_ = 0;
//Nodeptr pHead;
//
//void insert_(Nodeptr& pHead, CayBut data) {
//
//    Nodeptr n = pHead;
//
//    Nodeptr node;
//    node = new NodeCayBut();
//    node->data = data;
//    node->next = pHead;
//
//    if (pHead == NULL) {
//        pHead = node;
//        return;
//    }
//    if (pHead->next == pHead) {
//        pHead->next = node;
//    }
//    else {
//        while (n != NULL && n->next != NULL && n->next != pHead) n = n->next;
//        n->next = node;
//    }
//    count_++;
//}
//
//void ShowList(Nodeptr pHead) {
//    Nodeptr p;
//    if (pHead == NULL) return;
//    p = pHead;
//    do {
//        cout << p->data.maCB << " " << p->data.tenCB << " " << p->data.donGia << " " << p->data.soLuong << " " << p->data.hangSX << endl;
//        p = p->next;
//    } while (p != pHead);
//}
//
//void cau2(Nodeptr pHead) {
//    Nodeptr p;
//    if (pHead == NULL) return;
//    p = pHead;
//    do {
//        cout << p->data.hangSX << " " << (int)p->data.soLuong << endl;
//        p = p->next;
//    } while (p != pHead);
//}
//
//void sort_(Nodeptr& pHead) {
//    NodeCayBut* t, * s;
//    int i;
//    CayBut v;
//    if (pHead == NULL) {
//        return;
//    }
//    s = pHead;
//    for (i = 0; i < count_; i++) {
//        t = s->next;
//        while (t != pHead) {
//            if (s->data.donGia < t->data.donGia) {
//                v = s->data;
//                s->data = t->data;
//                t->data = v;
//            }
//            t = t->next;
//        }
//        s = s->next;
//    }
//}
//
//void input(CayBut& c) {
//    cout << "nhap ma cay but: ";
//    cin >> c.maCB; cin.ignore();
//    cout << "nhap ten: ";
//    cin.getline(c.tenCB, 30);
//    cout << "nhap so luong: ";
//    cin >> c.soLuong;
//    cout << "nhap don gia: ";
//    cin >> c.donGia; cin.ignore();
//    cout << "nhap hang: ";
//    cin.getline(c.hangSX, 30);
//}
//
//void nhap() {
//    cout << "nhap so luong node: n = ";
//    int n; cin >> n;
//    for (int i = 0; i < n; i++) {
//        CayBut c;
//        input(c);
//        insert_(pHead, c);
//    }
//}
//
//// bai 2
//
//
//int main() {
//    nhap();
//    cout << "------------ket qua---------------" << endl;
//    cout << "danh sach vua nhap: " << endl;
//    ShowList(pHead);
//
//    cout << "---------ten hang va so luong ton kho---------" << endl;
//    cau2(pHead);
//
//    cout << "---sort:--------" << endl;
//
//    sort_(pHead);
//    ShowList(pHead);
//
//
//
//}
