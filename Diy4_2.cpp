#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:

    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;

        cout << "Stack created.\n";
    }


    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!\n";
            return;
        }

        arr[++top] = value;
        cout << value << " pushed.\n";
    }

    // Pop operation
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return -1;
        }

        return arr[top--];
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack: ";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
        cout << "Stack buffer released.\n";
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Popped: " << s.pop() << endl;

    s.display();

    return 0;
}