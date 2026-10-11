#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

public:
    
    Matrix(int m, int n) {
        rows = m;
        cols = n;

        data = new int*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }

        cout << "Matrix created.\n";
    }

    
    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;

        data = new int*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }

        cout << "Deep copy created.\n";
    }


    void input() {
        cout << "Enter matrix elements:\n";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    // Display matrix
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }

        delete[] data;

        cout << "Matrix memory released.\n";
    }
};

int main() {
    Matrix A(2, 3);

    A.input();

    cout << "\nOriginal Matrix:\n";
    A.display();

    // Deep copy
    Matrix B = A;

    cout << "\nCopied Matrix:\n";
    B.display();

    return 0;
}