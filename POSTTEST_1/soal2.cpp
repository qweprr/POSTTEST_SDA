#include <iostream>
using namespace std;

int main() {
    int matriks[3][3];

    cout << "Masukkan elemen matriks 3x3:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriks[i][j];
        }
    }

    int jumlahDiagonal = 0;

    for (int i = 0; i < 3; i++) {
        jumlahDiagonal += matriks[i][i];           // diagonal utama
        jumlahDiagonal += matriks[i][2 - i];       // diagonal sekunder
    }

    cout << "\nMatriks:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jumlah diagonal utama + sekunder = " << jumlahDiagonal << endl;

    return 0;
}
