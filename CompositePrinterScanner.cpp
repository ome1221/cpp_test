#include <iostream>
#include <string>
using namespace std;

class Device {
    protected:
        string _name, _location, _model;
    
    public:
        Device() {
            cout << "Default constructor for Device" << endl;
        }
        
        Device(string name, string location, string model) 
            : _name(name), _location(location), _model(model) {
            cout << "Overloading constructor for Device" << endl;
            cout << "Name: " << _name << endl;
            cout << "Location: " << _location << endl;
            cout << "Model: " << _model << endl;
        }

};

class Printer : public Device {
    private:
        string _type;

    public:
        Printer() {
            cout << "Default constructor for Printer" << endl;
        }
        
        Printer(string name, string location, string model, string type) 
            : Device(name, location, model), _type(type) {
            cout << "Overloading constructor for Printer" << endl;
            cout << "Type: " << _type << endl;
        }
        
        void print() {
            cout << "Printing document..." << endl;
        }
};

class Scanner : public Device {
    public:
        Scanner() {
            cout << "Default constructor for Scanner" << endl;
        }
        
        Scanner(string name, string location, string model) 
            : Device(name, location, model) {
            cout << "Overloading constructor for Scanner" << endl;
        }

        void scan() {
            cout << "Scanning document..." << endl;
        }
};

class PrinterScanner : public Device {
    private:
        Printer _printer;
        Scanner _scanner;
        
    public:
        PrinterScanner(string name, string location, string model, string type)
            : Device(name, location, model), _printer(name, location, model, type), _scanner(name, location, model) {
            cout << "Constructor for PrinterScanner" << endl;
        }

        // Combining print and scan functionalities
        void printAndScan() {
            _printer.print();
            _scanner.scan();
        }
};

int main() {
    PrinterScanner psInstance("HP", "Office", "3000", "Laser");
    psInstance.printAndScan();

    return 0;
}
