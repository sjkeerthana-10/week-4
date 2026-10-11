#include <iostream>
using namespace std;

class Tracer {
private:
    int id;

public:
    Tracer(int i) {
        id = i;
        cout << "Tracer " << id << " constructed." << endl;
    }

    ~Tracer() {
        cout << "Tracer " << id << " destroyed." << endl;
    }
};

int main() {

    for (int i = 1; i <= 5; i++) {

        Tracer* t = new Tracer(i);

        // Use the object here
        cout << "Using Tracer " << i << endl;

        // Correctly release memory
        delete t;
    }

    cout << "Program finished." << endl;

    return 0;
}