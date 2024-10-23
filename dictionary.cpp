#include <iostream>
#include <vector>
using namespace std;

// Custom Map class to store key-value pairs
template<typename K, typename V>
class MyMap {
private:
    // Vector of pairs to hold key-value pairs
    vector<pair<K, V>> items;

public:
    // Function to add key-value pairs
    void add(K key, V value) {
        for (auto& item : items) {
            if (item.first == key) {
                item.second = value; // Update if key already exists
                return;
            }
        }
        // Add new key-value pair if key does not exist
        items.push_back(make_pair(key, value));
    }

    // Function to get value by key
    V get(K key) {
        for (auto& item : items) {
            if (item.first == key) {
                return item.second;
            }
        }
        throw out_of_range("Key not found"); // Throw an exception if key not found
    }

    // Function to print all key-value pairs
    void print() {
        cout << "Key : Value" << endl;
        for (auto& item : items) {
            cout << item.first << " : " << item.second << endl;
        }
    }
};

int main() {
    // Create an instance of MyMap with int keys and string values
    MyMap<int, string> deviceCodeMap;

    // Add key-value pairs
    deviceCodeMap.add(1, "D1");
    deviceCodeMap.add(2, "D2");
    deviceCodeMap.add(3, "D3");
    deviceCodeMap.add(4, "D4");

    // Access a specific value by key
    try {
        string deviceName = deviceCodeMap.get(2);
        cout << "Accessed device: " << deviceName << endl; // Output: D2
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    // Print all key-value pairs
    cout << "\nDump all key-value pairs:" << endl;
    deviceCodeMap.print();

    return 0;
}
