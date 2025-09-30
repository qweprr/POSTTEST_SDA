#include <iostream>
#include <string>
using namespace std;

// ==================== Node & Konstanta ====================
struct Node {
    string nama;
    string tipe;
    int jumlah;
    Node* next;
    Node* prev;
};

const int JUMLAH_AWAL = 93;   // dua digit terakhir NIM (093)
const int POSISI_SISIP = 4;   // digit terakhir 3 + 1 = 4

Node* head = nullptr;
Node* tail = nullptr;

// ==================== Helper ====================
Node* buatNode(const string& n, const string& t) {
    Node* p = new Node;
    p->nama = n;
    p->tipe = t;
    p->jumlah = JUMLAH_AWAL;
    p->next = nullptr;
    p->prev = nullptr;
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
    if (!head) {
        head = tail = p;
    } else {
        p->next = head;
        head->prev = p;
        head = p;
    }
}

void addLast() {
    string n,t; inputItem(n,t);
    Node* p = buatNode(n,t);
    if (!head) {
        head = tail = p;
    } else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
}

void addSpecific() {
    string n,t; inputItem(n,t);
    Node* p = buatNode(n,t);

    if (POSISI_SISIP <= 1 || !head) { // sisip awal
        addFirst();
        return;
    }

    Node* q = head;
    for (int i=1; i<POSISI_SISIP-1 && q->next; i++) q = q->next;

    p->next = q->next;
    if (q->next) q->next->prev = p;
    else tail = p;
    q->next = p;
    p->prev = q;

    cout << ">> Item disisipkan otomatis di posisi " << POSISI_SISIP << "\n";
}

// ==================== Hapus Data ====================
void deleteFirst() {
    if (!head) { cout << "Inventory kosong!\n"; return; }
    Node* p = head;
    if (head == tail) { head = tail = nullptr; }
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete p;
}

void deleteLast() {
    if (!head) { cout << "Inventory kosong!\n"; return; }
    Node* p = tail;
    if (head == tail) { head = tail = nullptr; }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete p;
}

void deleteSpecific() {
    if (!head) { cout << "Inventory kosong!\n"; return; }
    int pos; cout << "Hapus posisi ke- : "; cin >> pos;
    if (pos <= 1) { deleteFirst(); return; }

    Node* q = head;
    for (int i=1; i<pos && q; i++) q = q->next;
    if (!q) { cout << "Posisi tidak valid\n"; return; }

    if (q == tail) { deleteLast(); return; }

    q->prev->next = q->next;
    q->next->prev = q->prev;
    delete q;
}

// ==================== Tampilkan Inventory ====================
void tampilkanInventory() {
    if (!head) { cout << " Inventory kosong!\n"; return; }
    cout << "\n========== INVENTORY (Depan -> Belakang) ==========\n";
    int i = 1;
    for (Node* p=head; p; p=p->next, ++i)
        cout << i << ". " << p->nama
             << " | Tipe: " << p->tipe
             << " | Jumlah: " << p->jumlah << "\n";
    cout << "==================================================\n";
}

void tampilkanInventoryReverse() {
    if (!tail) { cout << " Inventory kosong!\n"; return; }
    cout << "\n========== INVENTORY (Belakang -> Depan) ==========\n";
    int i = 1;
    for (Node* p=tail; p; p=p->prev, ++i)
        cout << i << ". " << p->nama
             << " | Tipe: " << p->tipe
             << " | Jumlah: " << p->jumlah << "\n";
    cout << "==================================================\n";
}

// ==================== Cari Data ====================
void cariData() {
    if (!head) { cout << " Inventory kosong!\n"; return; }
    cin.ignore();
    string key;
    cout << "Masukkan Nama Item yang dicari: ";
    getline(cin, key);

    Node* p = head;
    int i = 1;
    while (p) {
        if (p->nama == key) {
            cout << "\n>> Data ditemukan di posisi ke-" << i << ":\n";
            cout << "Nama   : " << p->nama << "\n";
            cout << "Tipe   : " << p->tipe << "\n";
            cout << "Jumlah : " << p->jumlah << "\n";
            return;
        }
        p = p->next;
        i++;
    }
    cout << ">> Data dengan nama '" << key << "' tidak ditemukan!\n";
}

// ==================== Main Menu ====================
int main() {
    int pilih;
    do {
        cout << "\n===============================================\n";
        cout << "  GAME INVENTORY SYSTEM                        \n";
        cout << "  Nama : Muhammad Yusuf                        \n";
        cout << "  NIM  : 2409106093                            \n";
        cout << "===============================================\n";
        cout << "[1] Tambah Item (Depan)\n";
        cout << "[2] Tambah Item (Belakang)\n";
        cout << "[3] Tambah Item (Posisi Otomatis " << POSISI_SISIP << ")\n";
        cout << "[4] Hapus Item Pertama\n";
        cout << "[5] Hapus Item Terakhir\n";
        cout << "[6] Hapus Item (Posisi Tertentu)\n";
        cout << "[7] Lihat Semua Item (Depan -> Belakang)\n";
        cout << "[8] Lihat Semua Item (Belakang -> Depan)\n";
        cout << "[9] Cari Data (berdasarkan Nama)\n";
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
            case 8: tampilkanInventoryReverse(); break;
            case 9: cariData(); break;
            case 0: cout << " Terima kasih sudah menggunakan program!\n"; break;
            default: cout << " Input tidak valid!\n";
        }
    } while(pilih!=0);
    return 0;
}
