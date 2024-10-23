#include <iostream>
#include <vector>
using namespace std;

class ElectronicItem {
protected:
    ElectronicItem() {
        cout << "hp" << endl;
        cout << "Located at Hyd" << endl;
        cout << "model 1" << endl;
    }
};

class Printer : public ElectronicItem {
public:
    Printer() {
        cout << "type - jet printer" << endl;
    }

    void print() {
        cout << "Printing document..." << endl;
    }

    void print(const string& documentName) {
        cout << "Printing document: " << documentName << endl;
    }
};

class Scanner : public ElectronicItem {
public:
    Scanner() {
        cout << "type - flatbed scanner" << endl;
    }

    void scan() {
        cout << "Scanning document..." << endl;
    }

    void scan(const string& documentName) {
        cout << "Scanning document: " << documentName << endl;
    }
};

int main() {
    Printer p;
    p.print();
    p.print("Report.pdf");

    Scanner c;
    c.scan();
    c.scan("Image.jpg");

    return 0;
}
