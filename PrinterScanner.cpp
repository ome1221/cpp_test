#include <iostream>
#include <string>
using namespace std;

class Printer{
    
    private:
    string _name, _location, _model, _type;
    
    public:
    
    Printer()
    {
        cout<<"Default constructor for Printer"<<endl;
    }
    
    Printer(string name,string location,string model,string type):_name(name),_location(location), _model(model),
    _type(type)
    {
        cout<<"Overloading constructor for Printer"<<endl;
        cout<<"Name:"<<_name<<endl;
        cout<<"Location:"<<_location<<endl;
        cout<<"Model:"<<_model<<endl;
        cout<<"Type:"<<_type<<endl;
    }
    
    void print() {
        cout << "Printing document..." << endl;
    }

    void print(const string& documentName) {
        cout << "Printing document: " << documentName << endl;
    }
};
class Scanner{
    private:
    string _name, _location, _model;
    
    public:
    Scanner()
    {
        cout<<"Default constructor for Scanner"<<endl;
    }
    
    Scanner(string name,string location,string model):_name(name),_location(location), _model(model)
    {
        cout<<"Overloading constructor for Scanner"<<endl;
        cout<<"Name:"<<_name<<endl;
        cout<<"Location:"<<_location<<endl;
        cout<<"Model:"<<_model<<endl;
    }
    
    void scan() 
    {
        cout << "Scanning document..." << endl;
    }

    void scan(const string& documentName) 
    {
        cout << "Scanning document: " << documentName << endl;
    }
};
int main()
{
    Printer pinstance;
    Printer pinstance2("Bosch","Hyd","111","XYZ");
    pinstance.print();
    pinstance.print("doc.pdf");
    
    Scanner sinstance;
    Scanner sinstance2("Bosch"," Hyd","222");
    sinstance.scan();
    sinstance.scan("doc");
    return 0; 
}
