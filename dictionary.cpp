#include <iostream>
#include <vector>
using namespace std;

// Custom Map class to store key-value pairs
template<typename K, typename V>
class MyMap {
private:
    vector<pair<K, V>> items; // Vector of pairs to hold key-value pairs

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

    // Operator overload for accessing elements using []
    V& operator[](K key) {
        for (auto& item : items) {
            if (item.first == key) {
                return item.second; // Return reference to the value
            }
        }
        // If the key does not exist, insert it with a default value and return the reference
        items.push_back(make_pair(key, V()));
        return items.back().second;
    }

    // Friend function to overload the << operator
    friend ostream& operator<<(ostream& os, const MyMap& myMap) {
        os << "Key : Value" << endl;
        for (const auto& item : myMap.items) {
            os << item.first << " : " << item.second << endl;
        }
        return os;
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

    // Access a specific value by key using the overloaded [] operator
    string deviceName = deviceCodeMap[2];
    cout << "Accessed device: " << deviceName << endl; // Output: D2

    // Output all key-value pairs using the overloaded << operator
    cout << "\nDump all key-value pairs:" << endl;
    cout << deviceCodeMap;

    return 0;
}
