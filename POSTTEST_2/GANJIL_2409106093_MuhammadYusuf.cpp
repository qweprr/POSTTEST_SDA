#include <iostream>
#include <string>
using namespace std;

// ==================== Node & Konstanta ====================
struct Node {
    string nama;
    string tipe;
    int jumlah;
    Node* next;
};

const int JUMLAH_AWAL = 93;   // dua digit terakhir NIM (093)
const int POSISI_SISIP = 4;   // digit terakhir 3 + 1 = 4

Node* head = nullptr;

// ==================== Helper ====================
Node* buatNode(const string& n, const string& t) {
    Node* p = new Node;
    p->nama = n;
    p->tipe = t;
    p->jumlah = JUMLAH_AWAL;
    p->next = nullptr;
    return p;
}

void inputItem(string &nama, string &tipe) {
    cout << "Nama Item : "; cin.ignore(); getline(cin, nama);
    cout << "Tipe Item : "; getline(cin, tipe);
}

// ==================== Tambah Data ====================
void addFirst() {
    string n,t; inputItem(n,t);
    Node* p = buatNode(n,t);
    p->next = head;
    head = p;
}

void addLast() {
    string n,t; inputItem(n,t);
    Node* p = buatNode(n,t);
    if (!head) head = p;
    else {
        Node* q = head;
        while (q->next) q = q->next;
        q->next = p;
    }
}

void addSpecific() {
    string n,t; inputItem(n,t);
    Node* p = buatNode(n,t);

    if (POSISI_SISIP <= 1 || !head) { // sisip awal
        p->next = head;
        head = p;
        return;
    }

    Node* q = head;
    for (int i=1; i<POSISI_SISIP-1 && q->next; i++) q = q->next;
    p->next = q->next;
    q->next = p;

    cout << ">> Item disisipkan otomatis di posisi " << POSISI_SISIP << "\n";
}

// ==================== Hapus Data ====================
void deleteFirst() {
    if (!head) { cout << "Inventory kosong!\n"; return; }
    Node* p = head;
    head = head->next;
    delete p;
}

void deleteLast() {
    if (!head) { cout << "Inventory kosong!\n"; return; }
    if (!head->next) { delete head; head = nullptr; return; }
    Node* q = head;
    while (q->next->next) q = q->next;
    delete q->next;
    q->next = nullptr;
}

void deleteSpecific() {
    if (!head) { cout << "Inventory kosong!\n"; return; }
    int pos; cout << "Hapus posisi ke- : "; cin >> pos;
    if (pos <= 1) { deleteFirst(); return; }

    Node* q = head;
    for (int i=1; i<pos-1 && q->next; i++) q = q->next;
    if (!q->next) { cout << "Posisi tidak valid\n"; return; }
    Node* hapus = q->next;
    q->next = hapus->next;
    delete hapus;
}

// ==================== Tampilkan Inventory ====================
void tampilkanInventory() {
    if (!head) { cout << " Inventory kosong!\n"; return; }
    cout << "\n========== INVENTORY ==========\n";
    int i = 1;
    for (Node* p=head; p; p=p->next, ++i)
        cout << i << ". " << p->nama
             << " | Tipe: " << p->tipe
             << " | Jumlah: " << p->jumlah << "\n";
    cout << "==============================\n";
}

// ==================== Main Menu ====================
int main() {
    int pilih;
    do {
        cout << "\n===============================================\n";
        cout << "  GAME INVENTORY SYSTEM                      \n";
        cout << "  Nama : Muhammad Yusuf                        \n";
        cout << "  NIM  : 2409106093                            \n";
        cout << "===============================================\n";
        cout << "[1] Tambah Item (Depan)\n";
        cout << "[2] Tambah Item (Belakang)\n";
        cout << "[3] Tambah Item (Posisi Otomatis " << POSISI_SISIP << ")\n";
        cout << "[4] Hapus Item Pertama\n";
        cout << "[5] Hapus Item Terakhir\n";
        cout << "[6] Hapus Item (Posisi Tertentu)\n";
        cout << "[7] Lihat Semua Item\n";
        cout << "[0] Keluar\n";
        cout << "===============================================\n";
        cout << ">> Pilih Menu : ";
        cin >> pilih;

        switch(pilih){
            case 1: addFirst(); break;
            case 2: addLast(); break;
            case 3: addSpecific(); break;
            case 4: deleteFirst(); break;
            case 5: deleteLast(); break;
            case 6: deleteSpecific(); break;
            case 7: tampilkanInventory(); break;
            case 0: cout << " Terima kasih sudah menggunakan program!\n"; break;
            default: cout << " Input tidak valid!\n";
        }
    } while(pilih!=0);
    return 0;
}

